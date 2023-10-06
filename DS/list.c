// Touron Hugo

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }
    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    if(list->last == NULL){
        ListNode *listnode = (ListNode*)malloc(sizeof(ListNode));
        listnode->data = item_data;
        listnode->next = NULL;
        listnode->prev = NULL; 
        list->first = listnode;
        list->last = listnode;
    }
    else{
        ListNode *listnode = (ListNode*)malloc(sizeof(ListNode));
        listnode->data = item_data;
        listnode->next = NULL;
        listnode->prev = list->last;
        list->last->next = listnode;
        list->last = listnode;
    }
}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    ListNode *dernier = list->last;
    ListNode *avantDernier = dernier->prev;
    data_t value = dernier->data;
    free(dernier);
    avantDernier->next = NULL;
    list->last = avantDernier;
    return value;
}

void list_print(List *l){
    ListNode *p=l->first;
    while(p!=NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}


int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);

    return 0;
}