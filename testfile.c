//
// Created by mario on 04/08/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data;

int main () {
    FILE *in;
    in = fopen("/mnt/d/Giovanni/MyRepositories/ProjectAPI/test_txt.txt","r");
    if (in == NULL) {
        printf("I failed to open the file input_1.txt\n");
        return -1;
    }
    char first_line[30];
    char * check1 = fgets(first_line,30,in);
    if (check1 == NULL) {
        printf("Error in the fgets - first_line\n");
        return -1;
    }
    printf("This is first string: %s",first_line);
    char const delim[]=" ";
    char * token;
    token = strtok(first_line,delim);
    printf("This is d as a string: %s\n",token);
    data d = (int) strtol(token, NULL, 10);
    token = strtok(NULL,delim);
    data k = (int) strtol(token,NULL,10);
    printf("These are d = %d and k = %d\n",d,k);

    return 0;
}

