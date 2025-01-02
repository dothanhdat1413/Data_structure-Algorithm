#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TEST
#define TEST 0
#endif

typedef struct Node {
    int name;
    struct Node *next;
    struct Node_list *list;
} Node;


/**
 * @brief Chỉ có 1 List chứa các Node_list ở phía đầu, mỗi Node_list lại có 1 chuối các Node là nối nhau (để khi duyệt thì có thể so sánh và tìm các Node chuẩn)
 * 
 */
typedef struct Node_list {
    int name;
    struct Node_list *next;
    int visited;
    struct Node *first;
    struct Node *last;
} Node_list;

typedef struct Graph {
    Node_list *first;
    Node_list *last;
} Graph;

Node_list* Node_list_find(Graph *graph, int name){
    Node_list* temp = graph->first;

    while(temp != NULL){
        if(temp->name == name){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void Node_list_init(Graph* graph, Node_list* node_list, int edge[][2], int edge_n){

    if(TEST) printf("Start init Node %c\n", node_list->name);

    Node* temp = NULL;
    Node* current = NULL;
    int count = 0;

    for(int i = 0; i < edge_n; i++){
            if(edge[i][0] == node_list->name){
                temp = (Node*)malloc(sizeof(Node));
                temp->name = edge[i][1];
                temp->next = NULL;
                temp->list = Node_list_find(graph, edge[i][1]);
                if(count == 0){
                    node_list->first = temp;
                } else {
                    current->next = temp;
                }
                current = temp;
                count++;
                if(TEST) printf("Node: %c\n", temp->name);
            }
        }

    node_list->last = current;
    if(node_list->last != NULL) node_list->last->next = NULL;

    temp = node_list->first;

    if(TEST){
        while(temp != NULL){
            printf("%c ", temp->name);
            temp = temp->next;
        }
    }

    if(TEST) printf("Done init Node\n");
}

void Node_list_print(Node_list* node_list){
    printf("Node_list %c: ", node_list->name);
    Node* temp = node_list->first;

    while(temp != NULL){
        printf("%c ", temp->name);
        temp = temp->next;
    }
    printf("\n");

    if(TEST) printf("Done print Node\n");
}


void Graph_init(Graph* graph, int* list, int list_n, int edge[][2], int edge_n){
    Node_list* temp = NULL;
    Node_list* current = NULL;

    temp = (Node_list*)malloc(sizeof(Node_list));
    temp->name = list[0];
    temp->next = NULL;
    temp->visited = 0;

    graph->first = temp;
    current = temp;

    for(int i = 1; i < list_n; i++){
        temp = (Node_list*)malloc(sizeof(Node_list));
        temp->name = list[i];
        temp->next = NULL;
        temp->visited = 0;

        current->next = temp;
        current = temp;
    }

    if(TEST) printf("Done init Node_list\n");

    for(int i = 0; i < list_n; i++){
        Node_list_init(graph, Node_list_find(graph, list[i]), edge, edge_n);
        Node_list_print(Node_list_find(graph, list[i]));
    }

}

void Graph_print(Graph* graph){
    Node_list* temp = graph->first;

    while(temp != NULL){
        printf("%c ", temp->name);
        temp = temp->next;
    }
    printf("\n");
    if(TEST) printf("Done print Node_list\n");
}

void Graph_free(Graph* graph){
    Node_list* temp_list = graph->first;
    Node_list* current_list = NULL;
    Node* temp_node = NULL;
    Node* current_node = NULL;

    while(temp_list != NULL){
        current_list = temp_list;
        temp_node = current_list->first;
        while(temp_node != NULL){
            current_node = temp_node;
            temp_node = temp_node->next;
            free(current_node);
        }
        temp_list = temp_list->next;
        free(current_list);
    }
    if(TEST) printf("Done free Graph\n");
}

void Graph_surf_DFS(Graph* graph){
    Node_list* temp_list = graph->first;
    Node* temp_node = NULL;

    while(temp_list != NULL){
        temp_node = temp_list->first;
        while(temp_node != NULL){
            if(temp_node->list->visited == 0){
                temp_node->list->visited = 1;
                printf("%c ", temp_node->list->name);
            }
            temp_node = temp_node->next;
        }
        temp_list = temp_list->next;
    }
    if(TEST) printf("Done DFS surf\n");
}

void Graph_surf_BFS(Graph* graph){
    Node_list* temp_list = graph->first;
    Node* temp_node = NULL;

    int count_node_list = 0;
    while(temp_list != NULL){
        count_node_list++;
        temp_list = temp_list->next;
    }

    Node_list* queue[count_node_list];
    int front = 0;
    temp_list = graph->first;
    while(temp_list != NULL){
        if(temp_list->visited == 0){
            queue[front] = temp_list;
            front++;
            temp_list->visited = 1;
            printf("%c ", temp_list->name);
        }
        temp_list = temp_list->next;
    }
    if(TEST) printf("Done BFS surf\n");
}

void Graph_refresh_visited(Graph* graph){
    Node_list* temp_list = graph->first;
    while(temp_list != NULL){
        temp_list->visited = 0;
        temp_list = temp_list->next;
    }
}