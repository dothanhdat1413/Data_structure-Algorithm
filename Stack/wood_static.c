#include "stack_static.h"


data_type data[10] = {
    // id, size, age
    {1, 12, 4},
    {1, 15, 4},
    {2, 18, 4},
    {1, 12, 3},
    {3, 13, 5},
    {1, 14, 8},
    {4, 15, 2},
    {2, 13, 3},
    {1, 16, 4},
    {1, 19, 5}
};

Stack wood;

typedef struct {
    unsigned int age;
    unsigned int count;
} wood_info;

typedef struct wood_count {
    wood_info info;
    wood_count* next;

} wood_count;

typedef struct {
    wood_count* first;
    wood_count* last;
} wood_count_list;

void wood_count_init(wood_count_list* list, wood_count* first, wood_count* last) {
    list->first = first;
    list->first->next = last;
    list->last = last;

    list->first->info.age = -1;
    list->first->info.count = 0;
    list->last->info.age = -1;
    list->last->info.count = 0;
}

void wood_count_add(wood_count_list* list, int age) {
    wood_count* new_wood = (wood_count*)malloc(sizeof(wood_count));
    new_wood->info.age = age;
    new_wood->info.count = 1;

    // if(list->first == NULL) {
    //     list->first = new_wood;
    //     list->first->next = NULL;
    //     return;    
    // }
    
    // if(list->last == NULL) {
    //     list->first->next = new_wood;
    //     list->last = new_wood;
    //     list->last->next = NULL;
    //     return;
    // }

    list->last->next = new_wood;
    new_wood->next = NULL;
    list->last = new_wood;
}

void wood_count_printf(wood_count_list* list) {
    wood_count* current = list->first;
    while(current->next != NULL) {
        printf("Tuoi: %d, So luong: %d\n", current->info.age, current->info.count);
        current = current->next;
    }
}

void count_wood(Stack* s, wood_count_list* list) {
    while(!Stack_isEmpty(s)) {
        data_type temp;
        Stack_pop(s, &temp);

        wood_count* current = list->first;
        if(current->info.age == -1) {
            current->info.age = temp.age;
            current->info.count = 1;
            continue;
        }

        while(current->next != NULL) {
            if(current->info.age == temp.age) {
                current->info.count++;
                break;
            }
            current = current->next;
        } // Nếu ko có thì thêm mới
        wood_count_add(list, temp.age);
    }
}

int main() {
    Stack_init(&wood);
    for(int i = 0; i < 10; i++) {
        Stack_push(&wood, data[i]);
    }

    wood_count_list list;
    wood_count_init(&list, NULL, NULL);
    count_wood(&wood, &list);
    wood_count_printf(&list);

    Stack_printf(&wood);
    return 0;
}