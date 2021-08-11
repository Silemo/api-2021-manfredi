//
// Created by Giovanni Manfredi on 10/08/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DBG

#ifdef DBG
    #define P(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
    #define P(fmt, ...)
#endif

#define getLine(buf, s)    fgets(buf, s, in)

typedef int data;
typedef long int data_long;


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
    data const d = (int) strtol(token,NULL,10);
    token = strtok(NULL,delim1);
    data const k = (int) strtol(token,NULL,10);
    //while (strtok(NULL,delim1));
    P("d=%d, k=%d\n", d, k);

    //Reading the second line - 3 options: AggG, TopK or EOF
    data graphRead_count = 0;
    int edgesWeightLineSize = d*11+1;
    char * edgesWeightLine = malloc(edgesWeightLineSize);
    char second_line_firstC = (int) getc_unlocked(in);
    char const comma_delim[] = ",";
    int i,j;
    data_long * * graph = NULL;
    data_long weight;
    char bin[sizeof("ggiungiGrafo") + 1]; // This skip could be done with fseek()
    while (second_line_firstC != EOF){
        if(getLine(bin,sizeof("ggiungiGrafo") + 1) == NULL) { // I throw away the rest of the line and the newline char
            P("Error in throwing away the second line\n");
            return -1;
        }
        if (second_line_firstC == (int)'A' && graphRead_count == 0) { // Allocating the graph
            graph = (data_long **) malloc(d*sizeof(data_long *));
            for (i = 0; i < d; i++) {
                graph[i] = (data_long *) malloc(d*sizeof(data_long));
            }
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
                P("%s", l);
                for (j = 0; j < d; ++j) {
                    token = strtok(l, comma_delim);
                    l = NULL;
                    //P("%p\n", token);
                    weight = strtol(token,NULL,10);
                    graph[i][j] = weight;

                }
                graphRead_count++;
            }
#ifdef DBG
            for (i = 0; i < d; i++) {
                for (j= 0; j < d; j++) {
                    P("%ld ",graph[i][j]);
                }
                P("\n");
            }
#endif
        }//AddG ends
        else if (second_line_firstC == (int)'T') {
            //TopK
        }//TopK ends
        second_line_firstC = (int) getc_unlocked(in); // I update the character
    }

    return 0;
}

