#include <iostream>

struct ListPair_t{
    int data;
    ListPair_t *next;
};


ListPair_t* add_node (int data, ListPair_t *const head){
    return new ListPair_t {data, head};

}


ListPair_t* get_adress (ListPair_t * const head, int number){
    auto h = head;
    for( int i = 0; i!=number; ++i) {
        if (h == nullptr) return h;
        h = h->next;
    }
    return h;
}

int get_data (ListPair_t * const head, int number){
    return get_adress(head, number)->data;
}

void PrintList (ListPair_t * const head){
    auto h = head;
    while (h != nullptr){
        std::cout<< h->data<< ' ';
        h = h->next;
    }
    std::cout<<'\n';
}

bool add_after (ListPair_t * const head, int number, int data){
    auto h = head;
    for( int i = 0; i != number; ++i) {
        if ( h->next == nullptr) {
            std::cout<<"List index out of range"<<std::endl;
            return false;
        }
        h = h->next;
    }
    ListPair_t *new_ell = add_node(data, h->next);
    h->next = new_ell;
    return true;
}

void add_after (ListPair_t * const ptr, int data){
    auto new_ell = add_node(data,ptr->next);
    ptr->next = new_ell;
}

bool remove_after (ListPair_t* head, int number){
    auto h = head;
    for( int i = 0; i != number; ++i) {
        if ( h->next == nullptr) {
            std::cout<<"List index out of range"<<std::endl;
            return false;
        }
        h = h->next;
    }
    auto hh = h->next->next;
    delete h->next;
    h->next = hh;
    return true;
}

void remove_after (ListPair_t* ptr){
    auto h = ptr->next;
    ptr->next= ptr->next->next;
    delete h;
}

void erase (ListPair_t* head){
    while (head->next!= nullptr){
        remove_after(head,0);
    }
    delete head;
}


int recursion_remove (ListPair_t* head) {
    if (head->next != nullptr) {
        remove_after(head, 0);
        return recursion_remove(head);
    } else {
        delete head;
        return 1;
    }
}

ListPair_t* reverse_itr (ListPair_t* head){
    ListPair_t* nextNode = nullptr;
    ListPair_t* prev = nullptr;
    ListPair_t* curr = head;
    while(curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
    return head;
}

ListPair_t* reverse_rec(ListPair_t* curr, ListPair_t* prev = nullptr) {
    if (curr == nullptr) {
        return prev;
    }
    ListPair_t* next = curr->next;
    curr->next = prev;
    return reverse_rec(next, curr);
}


int len (ListPair_t* head){
    auto h = head;
    int len = 0;
    while (h != nullptr){
        h = h->next;
        ++len;
    }
    return len;
}