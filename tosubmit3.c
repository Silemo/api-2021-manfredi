//
// Created by Giovanni Manfredi on 14/08/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define DBG

#ifdef DBG
    #define P(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
    #define P(fmt, ...)
#endif

#define WEIGHT_MAX (long int) INT_MAX + 2

#define getLine(buf, s)    fgets(buf, s, stdin)

typedef int data;
typedef long int data_long;

typedef struct Node {
    data graphNumber;
    data_long result;
}Graph;

typedef struct List {
    data heap_size;   // space currently used by the heap
    data heap_length; // maximum dimension of the array
    struct Node * heap;
}Rank;

data min_Path(data_long const dist[], bool const MST_set[], data const d);

void dijkstra(data_long ** graph, data const d, data_long dist[]);

data_long paths_Sum(data_long ** graph, data const d);

data heap_parent(data i);

data heap_left(data i);

data heap_right(data i);

void heap_insert(Rank * top, data_long result, data graphNumber);

void heap_extract_max(Rank * top);

void heap_increase_result(Rank * top, data * index_pointer, data_long result);

Graph * heap_maximum(Rank * top);

//void heap_build_max(Rank * top);

void heap_max_heapify(Rank * top, data i);


int main() {
    //Opening of the file from which I want to read
//    FILE *in;
//    in = fopen("/mnt/d/Giovanni/MyRepositories/API202148/open_tests/input_1.txt","r");
//    if (in == NULL) {
//        P("I failed to open the file input_1.txt\n");
//        return -1;
//    }
    P("I read the file\n");
    //Reading the first line and extrapolating d and k
    char first_line[30];
    if (getLine(first_line, sizeof(first_line)) == NULL){
        P("Error in the fgets - first_line\n");
        return -1;
    }
    char const delim1[]=" ";
    char * token;
    token = strtok(first_line,delim1);
    data const d = (int) strtol(token,NULL,10);
    token = strtok(NULL,delim1);
    data const k = (int) strtol(token,NULL,10);
    //while (strtok(NULL,delim1));
    P("d=%d, k=%d\n", d, k);

    //Reading the second line - 3 options: AggG, TopK or EOF
    data graphRead_count = 0;
    int edgesWeightLineSize = d*11+1;
    char * edgesWeightLine = malloc(edgesWeightLineSize);
    char second_line_firstC = (int) getchar_unlocked();
    char const comma_delim[] = ",";
    int i,j;
    data_long * * graph = NULL;
    Rank * top = NULL;
    data_long weight, result;
    char bin[sizeof("ggiungiGrafo") + 1]; // This skip could be done with fseek()
    while (second_line_firstC != EOF){
        if(getLine(bin,sizeof("ggiungiGrafo") + 1) == NULL) { // I throw away the rest of the line and the newline char
            P("Error in throwing away the second line\n");
            return -1;
        }
        if (second_line_firstC == (int)'A' && graphRead_count == 0) { // Allocating the graph
            graph = (data_long * *) malloc(d*sizeof(data_long *));
            for (i = 0; i < d; i++) {
                graph[i] = (data_long *) malloc(d*sizeof(data_long));
            }
            top = malloc(sizeof(Rank));
            top->heap_size = 0;
            top->heap_length = k;
            top->heap = malloc(k*sizeof(struct Node));
        }
        if(second_line_firstC == (int)'A'){
            //AddG
            P("AddG read! This is the graph number %d\n",graphRead_count);
            for (i = 0; i < d; ++i) {
                //P("reading graph %d\n", i);
                if (getLine(edgesWeightLine, edgesWeightLineSize) == NULL) {
                    P("Error in the fgets - capture line_line - i = %d\n",i);
                    return -1;
                }
                char *l;
                l = edgesWeightLine;
                //P("%s", l);
                for (j = 0; j < d; ++j) {
                    token = strtok(l, comma_delim);
                    l = NULL;
                    //P("%p\n", token);
                    weight = strtol(token,NULL,10);
                    graph[i][j] = weight;
                }
            }
            result = paths_Sum(graph,d);
            P("graphNumber:%d, result:%ld\n",graphRead_count,result);
            if (top->heap_size < top->heap_length){ // the number of graphs in top is still minor than k
                P("Still space in heap. size:%d",top->heap_size);
                heap_insert(top, result, graphRead_count);
                P("Space in heap updated. size:%d",top->heap_size);
            }
            else{ // the number of graphs in top is equal (or more) than k
                if (heap_maximum(top)[0].result > result){
                    P("No more space in heap. let's free size:%d",top->heap_size);
                    heap_extract_max(top);
                    P("I freed one space in heap. Now is size:%d",top->heap_size);
                    heap_insert(top, result, graphRead_count);
                    P("Now the heap is full again. size:%d",top->heap_size);
                }
            }
            //#ifdef DBG
            //            for (i = 0; i < d; i++) {
            //                for (j= 0; j < d; j++) {
            //                    P("%ld ",graph[i][j]);
            //                }
            //                P("\n");
            //            }
            //#endif
            graphRead_count++;
        }//AddG ends
        else if (second_line_firstC == (int)'T') {
            //TopK
            if (top == NULL){
                printf("\n");
            }
            else {
                for (i = 0; i < top->heap_size; i++) {
                    if(i == (int) top->heap_size - 1) {
                        printf("%d\n",top->heap[i].graphNumber);
                    }
                    else{
                        printf("%d ",top->heap[i].graphNumber);
                    }
                }
            }
        }//TopK ends
        second_line_firstC = (int) getchar_unlocked(); // I update the character
    }
    return 0;
}


data min_Path(data_long const dist[], bool const MST_set[], data const d){
    data_long min = WEIGHT_MAX;
    data min_index = 0;
    for (int i = 0; i < d; ++i) {
        if (MST_set[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(data_long ** graph, data const d, data_long dist[]){
    bool MST_set[d];
    for (int i = 0; i < d; ++i) {
        dist[i] = WEIGHT_MAX;
        MST_set[i] = false;
    }
    dist[0] = 0;
    for (int count = 0; count < d - 1; count++) {
        int i = min_Path(dist, MST_set, d);
        MST_set[i] = true;
        for (int j = 0; j < d; ++j) {
            if(MST_set[j] == false && graph[i][j] != 0 && (i != j) &&
            dist[i] != WEIGHT_MAX && dist[i] + graph[i][j] < dist[j] ) {
                dist[j] = dist[i] + graph[i][j];
            }
        }
    }
}

data_long paths_Sum(data_long ** graph, data const d) {
    data_long dist[d];
    dijkstra(graph, d, dist);
    data_long result = 0;
    P("This is the heap with the MPT paths\n");
    for (int i = 0; i < d; ++i) {
        result = result + dist[i];
        P("%ld ",dist[i]);
    }
    P("\n");
    return result;
}

data heap_parent(data i){
    return (data) floor((double) (i-1)/2);
}

data heap_left(data i){
    return (data) 2*i +1;
}

data heap_right(data i){
    return (data) 2*i + 2;
}

void heap_max_heapify(Rank * top, data i){
    data l = heap_left(i);
    data r = heap_right(i);
    data maximum;
    data_long l_result = top->heap[l].result;
    data_long i_result = top->heap[i].result;
    if(l <= top->heap_size && (l_result > i_result || (l_result == i_result &&
    top->heap[l].graphNumber > top->heap[i].graphNumber))){
        maximum = l;
    }
    else{
        maximum = i;
    }
    data_long r_result = top->heap[r].result;
    if (r <= top->heap_size && (r_result > top->heap[maximum].result ||
    (r_result == top->heap[maximum].result &&
    top->heap[r].graphNumber > top->heap[maximum].graphNumber))){
        maximum = r;
    }
    if (maximum != i){ //swap
        data_long tmp_result = i_result;
        data tmp_graphNumber = top->heap[i].graphNumber;
        top->heap[i].result = top->heap[maximum].result;
        top->heap[i].graphNumber = top->heap[maximum].graphNumber;
        top->heap[maximum].result = tmp_result;
        top->heap[maximum].graphNumber = tmp_graphNumber;
        heap_max_heapify(top, maximum);
    }
}

//void heap_build_max(Rank * top){
//    top->heap_size = top->heap_length;
//    for (int i = (int) floor((double)((top->heap_length)-1)/2); i < 0; i--) {     //!!!!! Possible problems
//        heap_max_heapify(top, i);
//    }
//}

Graph * heap_maximum(Rank * top){
    return &(top->heap[0]);
}

void heap_extract_max(Rank * top){
    if(top->heap_size < 0){
        P("heap underflow - heap_extract_max\n");
    }
    top->heap[0].result = top->heap[top->heap_size].result;
    top->heap[0].graphNumber = top->heap[top->heap_size].graphNumber;
    top->heap_size = (top->heap_size) - 1;
    heap_max_heapify(top, 0);
}

void heap_increase_result(Rank * top, data * index_pointer, data_long result){
    data index = *index_pointer;
    if(result < top->heap[index].result){
        P("the new result is smaller than the current one - heap_increase_key\n");
    }
    top->heap[index].result = result;
    data heapParent_index = heap_parent(index);
    while (index > 0 && (top->heap[heapParent_index].result < top->heap[index].result
                     ||  (top->heap[heapParent_index].result == top->heap[index].result
                          && top->heap[heapParent_index].graphNumber < top->heap[index].graphNumber))) {
        data_long tmp_result = top->heap[index].result;
        data tmp_graphNumber = top->heap[index].graphNumber;
        top->heap[index].result = top->heap[heapParent_index].result;
        top->heap[index].graphNumber = top->heap[heapParent_index].graphNumber;
        top->heap[heapParent_index].result = tmp_result;
        top->heap[heapParent_index].graphNumber = tmp_graphNumber;
        *index_pointer = heapParent_index;
    }
}

void heap_insert(Rank * top, data_long result, data graphNumber){
    top->heap_size = top->heap_size + 1;
    top->heap[top->heap_size].result = (data_long) -1;
    top->heap[top->heap_size].graphNumber = graphNumber;
    heap_increase_result(top, &(top->heap_size), result);
}
