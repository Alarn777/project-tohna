
#include "fileHandler.h"


int readFile(char *fineName, struct Graph *graph) {


    int buffer;
    FILE * stream;
    stream = fopen(fineName, "r");
    if(stream == NULL){
        printf("Error reading file\n");
        return 1;
    }
    int n = 0;
    int node_value_flag = 0;
    int numberOfNodes = 0;
    fread(&n, sizeof(int), 1, stream);
    printf("There are %d nodes in the graph\n",n);
    graph->number_of_nodes = n;

    int **array = NULL;
    array = (int**) malloc( n * sizeof(int*));

    int count = 0;
    int big_array_count = 0;
    while (!feof(stream)){
        unsigned long a = fread(&buffer, sizeof(int), 1, stream);
        //assert(a == 1);
        if (a == 0)
            break;
        if(!node_value_flag) {
            printf("V: %d\n", buffer);
            numberOfNodes = buffer;
            array[big_array_count] = (int*)malloc(numberOfNodes * sizeof(int));
            node_value_flag = 1;
            printf("nodes:[");
        }
        if(numberOfNodes == count){
            count = 0;
            node_value_flag = 0;
            big_array_count++;
            printf("]\n");
            continue;
        }
        if(count < numberOfNodes){
            array[big_array_count][count] = buffer;
            printf("%d ", buffer);
            count++;
        }
    }
    printf("]\n");

    graph->data = array;
    fclose(stream);
    return 0;

}

int writeToFile(char* fineName){

    return 0;
}