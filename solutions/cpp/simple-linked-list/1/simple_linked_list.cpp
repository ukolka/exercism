#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    Element* element = new Element(entry);
    element->next = head;
    head = element;
    ++current_size;
}

int List::pop() {
    if (head == nullptr) {
        return -1;
    }
    Element* toPop = head;
    int val = toPop->data;
    head = toPop->next;
    --current_size;
    delete toPop;
    return val;
}

void List::reverse() {
    Element* prev = nullptr;
    Element* current = head;
    Element* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;    
        prev = current;
        current = next;
    }
    
    head = prev;
}

List::~List() {
     while (head != nullptr) {
        Element* current = head;
        head = head->next;
        delete current;
    }
}

}  // namespace simple_linked_list
