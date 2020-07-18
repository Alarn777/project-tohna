//#include <stdio.h>
#include "fileHandler.h"



int main() {
    printf("Hello, World!\n");
    Graph new = {0,NULL};
    struct Graph *myGraph = &new;
//    myGraph = { 0, NULL };

    int a = readFile("graph.in", myGraph);
    assert(a == 0);

//    printf("%d\n",myGraph->number_of_nodes);

    printf("LOL %d",myGraph->data[18][1]);
    return 0;
}