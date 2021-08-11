//
// Created by Giovanni Manfredi on 03/08/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DBG

#ifdef DBG
    #define P(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
    #define P(fmt, ...)
#endif

#define getLine(buf, s)    fgets(buf, s, in)

    // Adjacency list data structure
    typedef int data;
    typedef long int data_long;

    struct Edge {
        data dest;
        data_long weight;
        struct Edge * next;
    };

    struct EdgeList {
        struct Edge * head;
    };

//    struct GraphR { this should save the results
//        data graphNumber;
//        data_long result;
//        struct GraphR* next;
//    };
//    struct GraphR* createGraphR(data graphNumber);

    //Graph data structure
    typedef struct Graph {
        data graphNumber;
        data numberOfVertex;
        struct EdgeList * nodesArray;
    } Graph;

    struct Graph* createGraph(data V);
    
    void resetGraph(struct Graph* graph, data graphNumber);
    
//    struct GraphR* calcGraph(struct Graph * g);

    struct Edge* newEdge(data dest, data_long weight);

    void addEdge_topEdgeList(struct Graph* graph, data src, data dest, data_long weight);

    void topK(data k);

    int main() {
        //Opening of the file from which I want to read
        FILE *in;
        in = fopen("/mnt/d/Giovanni/MyRepositories/ProjectAPI/open_tests/input_1.txt","r");
        if (in == NULL) {
            P("I failed to open the file input_1.txt\n");
            return -1;
        }
        printf("I read the file\n");
        //Reading the first line and extrapolating d and k
        char first_line[30];
        if (getLine(first_line, sizeof(first_line)) == NULL){
            P("Error in the fgets - first_line\n");
            return -1;
        }
        char const delim1[]=" ";
        char * token;
        token = strtok(first_line,delim1);
        data d = (int) strtol(token,NULL,10);
        token = strtok(NULL,delim1);
        data k = (int) strtol(token,NULL,10);
        while (strtok(NULL,delim1)) ;
        P("d=%d, k=%d\n", d, k);

        char const AddG_str[]="AggiungiGrafo";
        char const TopK_str[]="TopK";
        char const delim2[]=",";
#define ADDLEN   strlen(AddG_str)
#define ADDSIZE   sizeof(AddG_str)
        char second_line[ADDSIZE+1];
        data_long weight;
        data i, j;
        data graphs = 0;

        struct Graph * graph = createGraph(d);
        int nodeWeightLineSize = d*11+1;
        char* nodeWeightLine = malloc(nodeWeightLineSize);

        while (getLine(second_line, sizeof(second_line)) != NULL) {
            P("In the while %d %d\n", strlen(second_line), ADDLEN);
            if (strncmp(second_line, AddG_str, ADDLEN)==0) {
                P("in the first if - in the while\n");
                //AggiungiGrafo
                P("AddG read!\n");
                if (0) resetGraph(graph, graphs++);
                for (i = 0; i < d; ++i) {
                    P("reading graph %d\n", i);
                    if (getLine(nodeWeightLine, nodeWeightLineSize) == NULL) {
                        P("Error in the fgets - capture line_line - i = %d\n",i);
                        return -1;
                    }
                    char *l;
                    l = nodeWeightLine;
                    P("%s\n", l);
                    for (j = 0; j < d; ++j) {
                        token = strtok(l, delim2);
                        l = NULL;
                        if (i!=j) {
                            P("%p\n", token);
                            weight = strtol(token,NULL,10);
                            if (weight) {
                                addEdge_topEdgeList(graph, i, j, weight);
                            }
                        }
                    }
                }
//                return -1;

#ifdef DBG
                struct Edge * edge;
                for (i = 0; i < d; ++i) {
                    P("%d ", i);
                    edge = graph->nodesArray[i].head;
                    while (edge != NULL) {
                        P("%d:%ld ", edge->dest, edge->weight);
                        edge = edge->next;
                    }
                    P("\n");
                }
#endif
//                calcGraph(graph);

              }//AggiungiGrafo_end
              else {  //TopK
                topK(k);
            }//TopK_end
        }
        printf("Out of the while\n");
        return 0;
    }

// A utility function that creates a graph of numberOfVertex vertices
    struct Graph* createGraph(data V) {
        struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
        graph->numberOfVertex = V;
        // Create an nodesArray of adjacency lists.
        // Size of nodesArray will be numberOfVertex
        size_t size = V * sizeof(struct EdgeList);
        graph->nodesArray = (struct EdgeList *) malloc(size);
        memset(graph->nodesArray, 0, size);

        // Initialize each adjacency list
        // as empty by making head as NULL
//        struct EdgeList * a = graph->nodesArray;
//        for (int i = 0; i < numberOfVertex; i++, a++) {
// //            graph->nodesArray[i].head = NULL;
//            a->head = NULL;
//        }
        return graph;
    }

    void resetGraph(struct Graph* graph, data graphNumber) {
        graph->graphNumber = graphNumber;
        graph->graphNumber++; graph->graphNumber--;
        struct EdgeList * a = graph->nodesArray;
        for (int i = 0; i < graph->numberOfVertex; i++, a++) {
            struct Edge * h;
            while (a->head) {
                h = a->head->next;
                free(a->head);
                a->head = h;
            }
        }
    }

// A utility function to create a new adjacency list node
    struct Edge* newEdge(data dest, data_long weight) {
        struct Edge* newNode = (struct Edge*) malloc(sizeof(struct Edge));
        newNode->dest = dest;
        newNode->dest++;
        newNode->dest--;
        newNode->weight = weight;
        newNode->next = NULL;
        return newNode;
    }

// Adds an edge to a graph
    void addEdge_topEdgeList(struct Graph* graph, data src, data dest, data_long weight) {
        // Add an edge from src to dest. A new node is added to the adjacency
        // list of src. The node is added at the beginning
        struct Edge* newNode = newEdge(dest, weight);
        struct EdgeList * a;
        newNode->next = (a = graph->nodesArray + src)->head;
        a->head = newNode;
    }

//    struct GraphR* createGraphR(data graphNumber) {
//        struct GraphR* graph = (struct GraphR*) malloc(sizeof(struct GraphR));
//        graph->graphNumber = graphNumber;
//        graph->graphNumber++; graph->graphNumber--;
//        graph->result = 0;
//        graph->result++; graph->result--;
//        graph->next = NULL;
//        return graph;
//    }

    struct GraphR* calcGraph(struct Graph * g) {
        return NULL;
    }

    void topK(data k) {
        P("TopK read! K = %d\n",k);
    }
