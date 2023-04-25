#include <iostream>
#include "../Libaries/Lincked_list/Lincked_list.h"


int main(){
    auto head = add_node(1, nullptr);
    //std::cout<<head<<std::endl;
    head = add_node(2, head);
    head = add_node(4, head);
    add_after(head,0,3);
    head = add_node(5, head);
    add_after(head->next, 8);
    PrintList(head);
    remove_after(head);
    PrintList(head);
    //return_reverse(&head);
    //PrintList(head);
    PrintList(head);
    head = reverse_itr(head);
    PrintList(head);
    head = reverse_rec(head);
    PrintList(head);
    std::cout<<len(head)<<std::endl;
    std::cout<<get_data(head,2)<<std::endl;

    return 0;
}