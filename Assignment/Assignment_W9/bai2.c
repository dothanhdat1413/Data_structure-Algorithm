#include "Node_VN.h"

void count_words(List* L, char* most_frequent_word, int* unique_word_count);
void remove_duplicate_words(List* L);
int is_duplicate_word(Node* word);
void print_list(List* L);

void count_words(List* L, char* most_frequent_word, int* unique_word_count) {
    Node* current = L->first;
    Node* check;
    int max_count = 0;
    int word_count = 0;
    int frequency;

    while (current) {
        frequency = 1;
        check = current->next;
        
        while (check) {
            if (strcmp(current->data, check->data) == 0) {
                frequency++;
            }
            check = check->next;
        }

        if (frequency > max_count) {
            max_count = frequency;
            strcpy(most_frequent_word, current->data);
        }

        if (frequency == 1) {
            word_count++;
        }

        current = current->next;
    }

    *unique_word_count = word_count;
}

void remove_duplicate_words(List* L) {
    Node* current = L->first;
    Node* prev = NULL;

    while (current) {
        if (is_duplicate_word(current)) {
            if (prev) {
                prev->next = current->next;
            } else {
                L->first = current->next;
            }
            
            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int is_duplicate_word(Node* word) {
    int len = strlen(word->data);
    if (len % 2 != 0) return 0;

    int half_len = len / 2;
    return strncmp(word->data, word->data + half_len, half_len) == 0;
}

void print_list(List* L) {
    Node* p = L->first;
    while (p) {
        printf("%s ", p->data);
        p = p->next;
    }
    printf("\n");
}
