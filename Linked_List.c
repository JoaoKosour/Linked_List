#include <stdio.h>
#include <stdlib.h>


typedef struct NODE {
    int data;
    struct NODE *next;
}NODE;

typedef struct START{
    NODE *start;
    int size;
} START;


void linked_list_add(int data, START *first){
    if(!first->start)
        first->start = create_linked_list_node(data);
    
    NODE *new_node = create_linked_list_node(data);
    NODE *aux = first->start;
    while(aux->next){
        aux = aux->next;
        if(aux->next == NULL){
            aux->next = new_node;
            return;
        }
    }
}


NODE *linked_list_search(int data, START *first) {
    if(!first) return NULL;
    NODE *aux = first->start;
    while(aux && data != aux->data)
        aux = aux->next;

    if(aux && aux->data == data)
        return aux;

    return NULL;
}


void linked_list_remove(int data, START *first) {
    if(!first) return;
    NODE *aux = first->start, *prev;
    while(aux && aux->data != data){
        prev = aux;
        aux = aux->next;
        if(aux && aux->data == data) {
            prev->next = aux->next;
            free(aux);
            return;
        }
    }
}


NODE *create_linked_list_node(int data) {
    NODE *new_node = calloc(1, sizeof(NODE));
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
}