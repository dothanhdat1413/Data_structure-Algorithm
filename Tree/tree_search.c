#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{   
    char data[4];
    struct Node *Left;
    struct Node *Right;
} Node;

#define LEFT 0
#define RIGHT 1
#define SIZE 4
/**
 * @brief List add node to tree
 * 
 * @param root 
 * @param new_node 
 * @param L_R trái / phải
 * @return int 
 */
int Tree_add(Node* root, char* data, int L_R){ 
    if(root == NULL){
        return 0;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        return 0;
    }
    strncpy(new_node->data,data,SIZE);

    if(L_R == LEFT){
        if(root->Left != NULL){
            return 0;
        }
        root->Left = new_node;
    }
    else{
        if(root->Right != NULL){
            return 0;
        }
        root->Right = new_node;
    }

    new_node->Left = NULL;
    new_node->Right = NULL;

    return 1;
}

char data[17][SIZE] = {"-", "+", "+", "a", "*", "^", "*", "b", "/", "c", "8", "^","d","5","c", "e", "0.5"};
/*
                -
        +               +
    a      *        ^       *
        b    /    c   8   ^   d
            5 c          e 0.5
*/
/**
 * @brief In theo thứ tự giữa, hậu tố
 * 
 * @param root 
 */
void Tree_print(Node* root){
    if(root == NULL){
        return;
    }
    
    Tree_print(root->Left);
    printf("%s ", root->data);
    Tree_print(root->Right);
    
    return;
}

int main() {    
    Node* root = (Node*)malloc(sizeof(Node));
    strcpy(root->data, data[0]);
    root->Left = NULL;
    root->Right = NULL;

    Tree_add(root, data[1], LEFT);
    Tree_add(root, data[2], RIGHT);
    Tree_add(root->Left, data[3], LEFT);
    Tree_add(root->Left, data[4], RIGHT);
    Tree_add(root->Right, data[5], LEFT);
    Tree_add(root->Right, data[6], RIGHT);
    Tree_add(root->Left->Right, data[7], LEFT);
    Tree_add(root->Left->Right, data[8], RIGHT);
    Tree_add(root->Right->Left, data[9], LEFT);
    Tree_add(root->Right->Left, data[10], RIGHT);
    Tree_add(root->Right->Right, data[11], LEFT);
    Tree_add(root->Right->Right, data[12], RIGHT);
    Tree_add(root->Left->Right->Right, data[13], LEFT);
    Tree_add(root->Left->Right->Right, data[14], RIGHT);
    Tree_add(root->Right->Right->Left, data[15], LEFT);
    Tree_add(root->Right->Right->Left, data[16], RIGHT);

    Tree_print(root);


    return 0;
}