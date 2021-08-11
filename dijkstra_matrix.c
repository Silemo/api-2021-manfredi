//
// Created by Giovanni Manfredi on 10/08/2021.
//

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

//#define DBG

#ifdef DBG
    #define P(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
    #define P(fmt, ...)
#endif

#define WEIGHT_MAX (long int) INT_MAX + 2
#define V 3

typedef int data;
typedef long int data_long;

data min_Path(data_long dist[], bool MST_set[], data const d);

void dijkstra(data_long ** graph, data const d, data_long dist[]);

data_long paths_Sum(data_long ** graph, data const d);


int main() {
    data_long * * graph = NULL;
    P("Trying to find Bug 1\n");
    graph = (data_long **) malloc(V*sizeof(data_long *));
    for (int i = 0; i < V; i++) {
        graph[i] = (data_long *) malloc(V*sizeof(data_long));
    }
    P("Trying to find Bug 3\n");
//    for (int i = 0; i < V; i++) {
//        for (int j = 0; j < V; j++) {
//            P("Trying to find Bug i=%d, j=%d\n",i,j);
//            graph[i][j] = i + j ;
//        }
//    }
    graph[0][0]=0;
    graph[0][1]=0;
    graph[0][2]=2;
    graph[1][0]=7;
    graph[1][1]=0;
    graph[1][2]=4;
    graph[2][0]=0;
    graph[2][1]=1;
    graph[2][2]=0;
//    P("Trying to find Bug 4\n");
//    data_long dist[V];
//    P("Trying to find Bug 5\n");
//    dijkstra(graph, V, dist);
//    P("Trying to find Bug 6\n");
//    printf("This is the array with the MPT paths\n");
//    for (int i = 0; i < V; ++i) {
//        printf("%ld ",dist[i]);
//    }
//    printf("\n");
    printf("This is the paths Sum result: %ld\n", paths_Sum(graph, V));
    return 0;
}

data min_Path(data_long dist[], bool MST_set[], data const d){
    data_long min = WEIGHT_MAX;
    data min_index = 0;
    P("Trying to find Bug 11\n");
    for (int i = 0; i < d; ++i) {
        if (MST_set[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    P("Trying to find Bug 12\n");
    return min_index;
}

void dijkstra(data_long ** graph, data const d, data_long dist[]){
    bool SPT_set[d];
    P("Trying to find Bug 7\n");
    for (int i = 0; i < d; ++i) {
        dist[i] = WEIGHT_MAX;
        SPT_set[i] = false;
    }
    P("Trying to find Bug 8\n");
    dist[0] = 0;
    for (int count = 0; count < d - 1; count++) {
        int i = min_Path(dist, SPT_set, d);
        SPT_set[i] = true;
        P("Trying to find Bug 9 - for loop\n");
        for (int j = 0; j < d; ++j) {
            if(SPT_set[j] == false && graph[i][j] != 0 && (i != j) &&
             dist[i] != WEIGHT_MAX && dist[i] + graph[i][j] < dist[j] ) {
                dist[j] = dist[i] + graph[i][j];
                P("Trying to find Bug 10\n");
            }
        }
    }
}

data_long paths_Sum(data_long ** graph, data const d) {
    data_long dist[d];
    dijkstra(graph, d, dist);
    data_long paths_Sum = 0;
    printf("This is the array with the MPT paths\n");
    for (int i = 0; i < d; ++i) {
        paths_Sum = paths_Sum + dist[i];
        printf("%ld ",dist[i]);
    }
    printf("\n");
    return paths_Sum;
}
