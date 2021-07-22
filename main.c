//
// Created by Giovanni Manfredi on 22/04/2021
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Opening of the file from which I want to read
    FILE *in;
    in = fopen("/mnt/d/Giovanni/MyRepositories/ProjectAPI/open_tests/input_1.txt","r");
    if(in == NULL)
    {
        printf("I failed to open the file input_1.txt\n");
        return -1;
    }
    //Reading the first line and extrapolating d and k
    long int d, k; // d = # of nodes in the graphs, k = number of top graphs I want
//    Part of code alternative to fscanf()
//    char first_str[30];
//    char * check1 = fgets(first_str, 30, in);
//    if (check1 == NULL)
//    {
//        return -1;
//    }
//    char * mod_first_str, * bin_str;
//
//    d = strtol(first_str, &mod_first_str, 10);
//    k = strtol(mod_first_str, &bin_str, 10);
    int check1  = fscanf(in, "%ld %ld\n", &d, &k); // WARNING I'm unable to fix - Alternative with fscanf that generates a warning
    if (check1 == 0)
        return -1;
    printf("d = %ld and k = %ld\n", d, k);
//    //Creation and opening of the file on which I want to write
//    FILE *out;
//    out = fopen(""D:\\Giovanni\\MyRepositories\\ProjectAPI\\open_tests\\myoutput_1.txt","w");
//    if(out == NULL)
//    {
//        printf("I failed to create the file myoutput_1.txt\n");
//        return -1;
//    }
    char second_str[20];
    char * check2 = fgets(second_str, 20, in);
    if (check2 == NULL && feof(in) == 0)
    {
        return -1;
    }
    else if (check2 == NULL && feof(in)!=0)
    {
        //It's the case of EOF
    }
    else if (sr)
    fclose(in);
    return 0;
}
