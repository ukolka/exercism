#include "list_ops.h"

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
    list_t* result = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
    for (size_t i = 0; i < length; i++) {
        result->elements[i] = elements[i];
    }
    result->length = length;
    return result;
}
 
// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
    size_t new_len = list1->length + list2->length;
    list_element_t new_elements[new_len];
    list_t* result = new_list(new_len, new_elements);
    size_t current = 0;
    for (size_t i = 0; i < list1->length;  i++) {
        result->elements[current++] = list1->elements[i];
    }
    for (size_t i = 0; i < list2->length;  i++) {
        result->elements[current++] = list2->elements[i];
    }
    return result;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    size_t len = 0;
    list_element_t new_elements[list->length];

    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            new_elements[len++] = list->elements[i];
        }
    }

    return new_list(len, new_elements);
}

// returns the length of the list
size_t length_list(list_t *list) {
    return list->length;
}
 
// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    list_element_t new_elements[list->length];
    for (size_t i = 0; i < list->length; i++) {
        new_elements[i] = map(list->elements[i]); 
    }
    return new_list(list->length, new_elements);
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    list_element_t accumulator = initial;
    for (size_t i = 0; i < list->length; i++) {
        accumulator = foldl(accumulator, list->elements[i]);
    }

    return accumulator;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    list_element_t accumulator = initial;
    for (int i = list->length - 1; i >= 0; i--) {
        accumulator = foldr(list->elements[i], accumulator);
    }

    return accumulator;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
    list_t* result = new_list(list->length, list->elements);

    if (result->length == 0) {
        return result;
    }

    list_element_t tmp;
    for (
        size_t i = 0, j = result->length - 1;
        i < j;
        i++, j--) {

        tmp = result->elements[i]; 
        result->elements[i] = result->elements[j];
        result->elements[j] = tmp;
    }
    return result;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {
    free(list);
    list = NULL;
}
