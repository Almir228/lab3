#pragma

struct ListPair_t{
    int data;
    ListPair_t *next;
};

ListPair_t* add_node (int data, ListPair_t* head);
ListPair_t* get_adress (ListPair_t* head, int number);
int get_data (ListPair_t* head, int number);
void PrintList (ListPair_t* head);
bool add_after (ListPair_t* head, int number, int data);
void add_after (ListPair_t* ptr, int data);
bool remove_after (ListPair_t* head, int number);
void remove_after (ListPair_t* ptr);
void erase (ListPair_t* head);
int recursion_remove (ListPair_t* head);
ListPair_t* reverse_itr (ListPair_t* head);
ListPair_t* reverse_rec(ListPair_t* curr, ListPair_t* prev = nullptr);
int len (ListPair_t* head);