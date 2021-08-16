#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define WEIGHT_MAX (long int) INT_MAX + 2

#define getLine(buf, s)    fgets(buf, s, stdin)

typedef int data;
typedef long int data_long;

typedef struct Node {
    data graphNumber;
    data_long result;
}Graph;

typedef struct List {
    data heap_size;
    data heap_length;
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

void heap_increase_result(Rank * top, data index, data_long result);

void heap_max_heapify(Rank * top, data i);


int main() {
    char first_line[30];
    if (getLine(first_line, sizeof(first_line)) == NULL){
        return -1;
    }
    char const delim1[]=" ";
    char * token;
    token = strtok(first_line,delim1);
    data const d = (int) strtol(token,NULL,10);
    token = strtok(NULL,delim1);
    data const k = (int) strtol(token,NULL,10);
    data graphRead_count = 0;
    int edgesWeightLineSize = d*11+1;
    char * edgesWeightLine = malloc(edgesWeightLineSize);
    char second_line_firstC = (int) getchar_unlocked();
    char const comma_delim[] = ",";
    int i,j;
    data_long * * graph = NULL;
    Rank * top = NULL;
    data_long weight, result;
    char bin[sizeof("ggiungiGrafo") + 1];
    while (second_line_firstC != EOF){
        if(getLine(bin,sizeof("ggiungiGrafo") + 1) == NULL) {
            return -1;
        }
        if (second_line_firstC == (int)'A' && graphRead_count == 0) {
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
            for (i = 0; i < d; ++i) {
                if (getLine(edgesWeightLine, edgesWeightLineSize) == NULL) {
                    return -1;
                }
                char *l;
                l = edgesWeightLine;
                for (j = 0; j < d; ++j) {
                    token = strtok(l, comma_delim);
                    l = NULL;
                    weight = strtol(token,NULL,10);
                    graph[i][j] = weight;
                }
            }
            result = paths_Sum(graph,d);
            if (top->heap_size < top->heap_length){
                heap_insert(top, result, graphRead_count);
            }
            else{
                if (top->heap[0].result > result){
                    heap_extract_max(top);
                    heap_insert(top, result, graphRead_count);
                }
            }
            graphRead_count++;
        }
        else if (second_line_firstC == (int)'T') {
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
        }
        second_line_firstC = (int) getchar_unlocked();
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
    for (int i = 0; i < d; ++i) {
        result = result + dist[i];
    }
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
    if (maximum != i){
        data_long tmp_result = i_result;
        data tmp_graphNumber = top->heap[i].graphNumber;
        top->heap[i].result = top->heap[maximum].result;
        top->heap[i].graphNumber = top->heap[maximum].graphNumber;
        top->heap[maximum].result = tmp_result;
        top->heap[maximum].graphNumber = tmp_graphNumber;
        heap_max_heapify(top, maximum);
    }
}

Graph * heap_maximum(Rank * top){
    return &(top->heap[0]);
}

void heap_extract_max(Rank * top){
    top->heap[0].result = top->heap[top->heap_size - 1].result;
    top->heap[0].graphNumber = top->heap[top->heap_size - 1].graphNumber;
    top->heap_size = (top->heap_size) - 1;
    heap_max_heapify(top, 0);
}

void heap_increase_result(Rank * top, data index, data_long result){
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
        index = heapParent_index;
    }
}

void heap_insert(Rank * top, data_long result, data graphNumber){
    top->heap_size = top->heap_size + 1;
    top->heap[top->heap_size - 1].result = (data_long) -1;
    top->heap[top->heap_size - 1].graphNumber = graphNumber;
    heap_increase_result(top, top->heap_size - 1, result);
}
