#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

Graph graph;
int vertex[] = {'a','b','c','d','e','g','h'};
int edge[][2] = {
    {'a','b'},
    {'a','c'},
    {'b','c'},
    {'c','d'},
    {'d','e'},
    {'e','g'},
    {'g','h'}
};
int main() {
    Graph_init(&graph, vertex, sizeof(vertex)/sizeof(int), edge, (sizeof(edge)/sizeof(edge[0])));
    List_print(graph.vertex);
    Graph_free(&graph);
}