#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int name;
    Node* next;
}Node;

typedef struct {
    Node* first;
    Node* last;
}List;

typedef struct Connection {
    int* node_1;
    int* node_2;
    Connection* next;
} Connection;

typedef struct {
    Connection* first;
    Connection* last;
} Edge;

typedef struct {
    List* vertex;
    Edge* edge;
} Graph;

void List_init(List* list_t, int* list, int list_n){

    printf("Start init vertex: %d node \n", list_n);

    if(list_n == 0) return;

    int count = 0;
    list_t->first = (Node*)malloc(sizeof(Node));
    if(list_t->first == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    list_t->first->name = list[count];
    printf("First node: %c\n", list_t->first->name);
    list_t->first->next = NULL;
    count++;
    
    Node * current = list_t->first;
    Node * temp = NULL;

    while(count < list_n){
        temp = (Node*)malloc(sizeof(Node));
        if(temp == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        current->next = temp;
        temp->name = list[count];
        count ++; 
        temp->next = NULL;
        current = temp;
        if(count == list_n - 1) {
            list_t->last = temp;
        }
        printf("Node: %c\n", temp->name);
    }
    printf("Done init vertex\n");
}

void List_print(List* list_t){
    Node* current = list_t->first;
    if(current == NULL) {
        printf("Empty list\n");
        return;
    }
    while(current != NULL){
        printf("%c ", current->name);
        current = current->next;
    }
    printf("Done print\n");
}

void Graph_init(Graph* graph, int* list, int list_n, int edge[][2], int edge_n){
    graph->vertex = (List*)malloc(sizeof(List));
    graph->edge = (Edge*)malloc(sizeof(Edge));
    graph->vertex->first = NULL;
    graph->vertex->last = NULL;
    graph->edge->first = NULL;
    graph->edge->last = NULL;

    List_init(graph->vertex, list, list_n);
    List_print(graph->vertex);

}

void Graph_free(Graph* graph){
    // free Vertex
    Node* current = graph->vertex->first;
    Node* temp = NULL;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    free(graph->vertex);
    free(graph->edge);
    printf("Done free\n");
}