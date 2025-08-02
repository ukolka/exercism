#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};


struct list {
   struct list_node *first, *last;
};

struct list* list_create(void) {
    struct list* list = (struct list*) realloc(NULL, sizeof(struct list));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void list_destroy(struct list* list) {
    struct list_node* current = list->first;
    struct list_node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current = realloc(current, 0);
        current = next;
    }

    list = realloc(list, 0);
}

void list_push(struct list* list, ll_data_t item_data) {
    struct list_node* current = list->last;

    if (current == NULL) {
        current = realloc(NULL, sizeof(struct list_node));
        current->data = item_data;
        current->prev = NULL;
        current->next = NULL;

        list->first = current;
        list->last = current;
    } else {
        current->next = realloc(NULL, sizeof(struct list_node)); 
        current->next->data = item_data;
        current->next->prev = current;
        current->next->next = NULL;

        list->last = current->next;
    }
}

void list_unshift(struct list* list, ll_data_t item_data) {
    struct list_node* current = list->first;

    if (current == NULL) {
        current = realloc(NULL, sizeof(struct list_node));
        current->data = item_data;
        current->prev = NULL;
        current->next = NULL;

        list->first = current;
        list->last = current;
    } else {
        current->prev = realloc(NULL, sizeof(struct list_node)); 
        current->prev->data = item_data;
        current->prev->prev = NULL;
        current->prev->next = current;

        list->first = current->prev;
    }
}

ll_data_t list_pop(struct list* list) {
    struct list_node* last = list->last;
    struct list_node* newLast;
    ll_data_t data;

    if (last != NULL) {
        data = last->data; 
        newLast = last->prev;

        if (list->first == last) {
            list->first = NULL; 
            list->last = NULL;
        }

        if (newLast != NULL) {
            list->last = newLast;
            list->last->next = NULL;
        }

        last = realloc(last, 0);

        return data;
    }

    return -1;
}

ll_data_t list_shift(struct list* list) {
    struct list_node* first = list->first;
    struct list_node* newFirst;
    ll_data_t data;

    if (first != NULL) {
        data = first->data; 
        newFirst = first->next;

        if (list->last == first) {
            list->first = NULL; 
            list->last = NULL;
        }

        if (newFirst != NULL) {
            list->first = newFirst;
            list->first->prev = NULL;
        }

        first = realloc(first, 0);

        return data;
    }

    return -1;
}

size_t list_count(const struct list* list) {
    struct list_node* current = list->first;
    size_t count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void list_delete(struct list* list, ll_data_t data) {
    struct list_node* current = list->first;
    struct list_node* toDelete = NULL;

    while (current != NULL) {
        if (current->data == data) {
            toDelete = current; 
            break;
        }
        current = current->next;
    }

    if (toDelete != NULL) {
        if (toDelete == list->first) {
            if (list->first->next != NULL) {
                list->first = list->first->next;
                list->first->prev = NULL;
            } else {
                list->first = NULL; 
            } 
        }
        if (toDelete == list->last) {
            if (list->last->prev != NULL) {
                list->last = list->last->prev;
                list->last->next = NULL;
            } else {
                list->last = NULL;
            }
        }

        if (toDelete->prev != NULL) {
            toDelete->prev->next = toDelete->next;
        }
        if (toDelete->next != NULL) {
            toDelete->next->prev = toDelete->prev;
        }
       
        toDelete = realloc(toDelete, 0);
    } 
}
