//
// Created by Giovanni Manfredi on 17/08/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

//#define DBG

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

data_long power10(data exponent);

void arrayToNum_and_initializeArray(data_long * arrayOfDigits, data numberOfDigits, data_long * result);

data min_Path(data_long const dist[], bool const MST_set[], data const d);

void dijkstra(data_long ** graph, data const d, data_long dist[]);

void paths_Sum(data_long ** graph, data const d, data_long dist[], data_long * result);

void heap_insert(Rank * top, data_long result, data graphNumber);

void heap_extractAndInsert_max(Rank * top, data_long result, data graphNumber);

void heap_increase_result(Rank * top, data index, data_long result);

void heap_max_heapify(Rank * top, data i);


int main() {
    data d,k;
    if(scanf("%d %d\n",&d,&k) == EOF){
        P("Error in the scanf\n");
        return -1;
    }
    P("d=%d, k=%d\n", d, k);

    //Reading the second line - 3 options: AggG, TopK or EOF
    //GENERAL VARIABLES
    int i,j;
    data_long * result = malloc(sizeof(data_long));
    //NUMBER ACQUISITION VARIABLES
    data_long arrayOfDigits[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    data digit, numberOfDigits;
    //CHAR ACQUISITION VARIABLES
    char second_line_firstC = (int) getchar_unlocked();
    char bin[sizeof("ggiungiGrafo") + 1];
    //GRAPH VARIABLES
    data_long dist[d];
    data graphRead_count = 0;
    data_long * * graph = NULL;
    //RANK VARIABLES
    Rank * top = NULL;

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
            for (i = 0; i < d; i++) {
                for (j = 0; j < d; j++) {
                    numberOfDigits = 0;
                    do {
                        digit = getchar_unlocked();
                        if(digit != ',' && digit != '\n'){
                            arrayOfDigits[numberOfDigits] = digit - '0';
                            numberOfDigits++;
                        }
                    }while(digit != ',' && digit != '\n');
                    arrayToNum_and_initializeArray(arrayOfDigits, numberOfDigits, result);
                    graph[i][j] = *result;
                    //P("%ld:%d ",graph[i][j], numberOfDigits);
                }
                //P("\n");
            }
            paths_Sum(graph,d,dist,result);
            P("graphNumber:%d, result:%ld\n",graphRead_count,*result);
            if (top->heap_size < top->heap_length){ // the number of graphs in top is still minor than k
                P("Still space in heap. size:%d\n",top->heap_size);
                heap_insert(top, *result, graphRead_count);
                P("Space in heap updated. size:%d\n",top->heap_size);
            }
            else{ // the number of graphs in top is equal (or more) than k
                if (top->heap[0].result > *result){
                    P("No more space in heap. let's replace top:%d\n",top->heap_size);
                    heap_extractAndInsert_max(top, *result, graphRead_count);
                    P("Top replaced!. size:%d\n",top->heap_size);
                }
            }
//#ifdef DBG
//            for (i = 0; i < top->heap_size; i++) {
//                if(i != top->heap_size - 1){
//                    P("%d ",top->heap[i].graphNumber);
//                }
//                else{
//                    P("%d\n",top->heap[i].graphNumber);
//                }
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

data_long power10(data exponent){
    if(exponent == 0){
        return (data_long) 1;
    }
    else if(exponent == 1){
        return (data_long) 10;
    }
    else if(exponent == 2){
        return (data_long) 100;
    }
    else if(exponent == 3){
        return (data_long) 1000;
    }
    else if(exponent == 4){
        return (data_long) 10000;
    }
    else if(exponent == 5){
        return (data_long) 100000;
    }
    else if(exponent == 6){
        return (data_long) 1000000;
    }
    else if(exponent == 7){
        return (data_long) 10000000;
    }
    else if(exponent == 8){
        return (data_long) 100000000;
    }
    else if (exponent == 9){
        return (data_long) 1000000000;
    }
    else if (exponent == 10){
        return (data_long) 10000000000;
    }
    else{
        return (data_long) 2;
    }
}

void arrayToNum_and_initializeArray(data_long * arrayOfDigits, data numberOfDigits, data_long * result){
    *result = 0;
    for (int i = 0; i < numberOfDigits; i++) {
        *result = *result + arrayOfDigits[i] * power10(numberOfDigits - 1 - i);
        arrayOfDigits[i] = -1;
    }
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

void paths_Sum(data_long ** graph, data const d, data_long dist[], data_long * result) {
    dijkstra(graph, d, dist);
    *result = 0;
    //P("This is the heap with the MPT paths\n");
    for (int i = 0; i < d; ++i) {
        if (dist[i]< WEIGHT_MAX-1){
            *result = *result + dist[i];
        }
        //P("%ld ",dist[i]);
    }
    //P("\n");
}
void heap_max_heapify(Rank * top, data i){
    data l = 2*i + 1;
    data r = 2*i + 2;
    data maximum;
    if(l < top->heap_size && (top->heap[l].result > top->heap[i].result || (top->heap[l].result == top->heap[i].result && //NEED TO CHECK that <=
    top->heap[l].graphNumber > top->heap[i].graphNumber))){
        maximum = l;
    }
    else{
        maximum = i;
    }
    if (r < top->heap_size && (top->heap[r].result > top->heap[maximum].result ||  //NEED TO CHECK that <=
    (top->heap[r].result == top->heap[maximum].result &&
    top->heap[r].graphNumber > top->heap[maximum].graphNumber))){
        maximum = r;
    }
    if (maximum != i){ //swap
        data_long tmp_result = top->heap[i].result ;
        data tmp_graphNumber = top->heap[i].graphNumber;
        top->heap[i].result = top->heap[maximum].result;
        top->heap[i].graphNumber = top->heap[maximum].graphNumber;
        top->heap[maximum].result = tmp_result;
        top->heap[maximum].graphNumber = tmp_graphNumber;
        heap_max_heapify(top, maximum);
    }
}


void heap_extractAndInsert_max(Rank * top, data_long result, data graphNumber){
    #ifdef DBG
    if(top->heap_size < 0){
        P("heap underflow - heap_extract_max\n");
    }
    #endif
    top->heap[0].result = result;
    top->heap[0].graphNumber = graphNumber;
    heap_max_heapify(top, 0);
}

void heap_increase_result(Rank * top, data index, data_long result){
    #ifdef DBG
    if(result < top->heap[index].result){
        P("the new result is smaller than the current one - heap_increase_key\n");
    }
    #endif
    top->heap[index].result = result;
    data heapParent_index = floor((double) (index-1)/2);
    while (index > 0 && (top->heap[heapParent_index].result < top->heap[index].result
    ||  (top->heap[heapParent_index].result == top->heap[index].result
    && top->heap[heapParent_index].graphNumber < top->heap[index].graphNumber))) {
        data_long tmp_result = top->heap[index].result;
        data tmp_graphNumber = top->heap[index].graphNumber;
        top->heap[index].result = top->heap[heapParent_index].result;
        top->heap[index].graphNumber = top->heap[heapParent_index].graphNumber;
        top->heap[heapParent_index].result = tmp_result;
        top->heap[heapParent_index].graphNumber = tmp_graphNumber;
        index = heapParent_index;
    }
}

void heap_insert(Rank * top, data_long result, data graphNumber){
    top->heap_size = top->heap_size + 1;
    top->heap[top->heap_size - 1].result = (data_long) -1;
    top->heap[top->heap_size - 1].graphNumber = graphNumber;
    heap_increase_result(top, top->heap_size - 1, result);
    heap_max_heapify(top, 0);
}

