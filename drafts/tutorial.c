//
// Created by Manf_ on 16/08/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define getLine(buf, s)    fgets(buf, s, stdin)

//#define DBG

#ifdef DBG
    #define P(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
    #define P(fmt, ...)
#endif

typedef int data;
typedef long int data_long;


int main(){
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
    printf("%d\n",d+k);
    return 0;
}