#include <stdio.h>
#include <stdlib.h>

#include "Graph_2.h"

Graph graph;
int vertex[] = {'a','b','c','d','e','g','h'};
int edge[][2] = {
    {'a','b'},
    {'a','e'},
    {'a','h'},
    {'a','d'},

    {'b','d'},
    {'b','c'},
    {'b','g'},

    {'c','b'},
    {'c','d'},
    {'c','h'},

    {'d','c'},
    {'d','h'},
    {'d','g'},
    {'d','a'},

    {'e','g'},
    {'e','b'},
    {'e','d'},
    {'e','h'},

    {'g','a'},
    {'g','b'},
    {'g','c'},
    {'g','e'},
    {'g','h'},

    {'h','e'}
};
int main() {
    Graph_init(&graph, vertex, sizeof(vertex)/sizeof(int), edge, (sizeof(edge)/sizeof(edge[0])));
    Graph_print(&graph);

    Graph_surf_DFS(&graph);

    Graph_surf_BFS(&graph);

    Graph_free(&graph);
}