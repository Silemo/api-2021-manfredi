//
// Created by Giovanni Manfredi on 22/04/2021 - --/--/2021
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long int data;

struct node
{
    data index;
    data weight;
    struct node * next;
};
typedef struct node * list;

void enqueue_top(list * l, data index, data weight);

void enqueue_bot(list * l, data index, data weight);

void initialize_graph(list * l, data d);

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
    if (fscanf(in, "%ld %ld\n", &d, &k) == 0) // WARNING I'm unable to fix - Alternative with fscanf that generates a warning
    {
        printf("Error in the fscanf - first_line\n");
        return -1;
    }
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
    while(feof(in) == 0)
    {
//        ranking Top;
        if (fgets(second_str, 20, in) == NULL)
        {
            printf("Error in the fgets - second_str\n");
            return -1;
        }
        char TopK_str[]="TopK";
        char AddG_str[]="AggiungiGrafo";
        if (strcmp(second_str,AddG_str) == 0)
        {//AggiungiGrafo
            list graph[d];
            initialize_graph(&graph,d);
            int i = 0, j = 0;
            for (i = 0; i < d; i++) //I scan the lines
            { // Here we need to fill graph[d] - Complexity: O(d^2)
                char third_str[15 * d];
                if ( fgets(third_str, (int)(15 * d), in) == NULL )
                {
                    printf("Error in the fgets - third_str\n");
                    return -1;
                }
                long int tmp;
                char *tmp_str, *mod_tmp_str;
                for (j = 0; j < d; j++) //I scan the columns (of a single line)
                {
                    if (j == 0)
                    {
                        tmp = strtol(tmp_str, &mod_tmp_str, 10);
                    }
                    else
                    {
                        tmp = strtol(NULL, &mod_tmp_str, 10);
                    }
                    if (tmp != 0 && i != j) //tmp is not zero and it does not represent an auto-ring -> I want to save this weight and node
                    {
                        enqueue_bot(&(graph[i]), j, tmp);
                    }
                }
            } //At this point I should have a vector of lists   ready to be scanned by the Dijkstra Algorithm

        }
        else if (strcmp(second_str,TopK_str) == 0)
        {//TopK
            printf("Shut the fuck up CLION\n");
        }
    }
    //if it's out of this while we have reached the EOF
        fclose(in);
    return 0;
}

void initialize_graph(list * l, data d)
{
    for (int i = 0; i < d; ++i)
    {
        ((*l)[i]).next = NULL;
    }
}

void enqueue_top(list * l, data index, data weight)
{
    list tmp = malloc(sizeof(struct node));
    tmp->index = index;
    tmp->weight = weight;
    tmp->next = *l;
    *l = tmp;
}

void enqueue_bot(list * l, data index, data weight)
{
    if (*l == NULL)
    {
        enqueue_top(l, index, weight);
    }
    else
    {
        enqueue_bot(&((*l)->next), index, weight);
    }
}











