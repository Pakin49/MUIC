#include "node.h"

typedef node* nodePtr;

class LL{
    nodePtr hol;
    int size;
public:
    LL();
    void insert_node(int);
    void print_all();
    ~LL();    
};

LL::LL(){
    hol = NULL;
    size =0;    
}

LL::~LL(){
    nodePtr temp = hol;
    while (hol != NULL){
        hol = hol->next;
        delete temp;
        temp = hol;
    }
}

void LL::insert_node(int x){
    if (hol==NULL) hol = new node(x);
    else{
        nodePtr temp = hol;
        while(temp->next) temp=temp->next;
        temp->next=new node(x);
    }
}

void LL::print_all(){
    nodePtr temp;
    for (temp =hol;temp;temp=temp->next)
    std::cout<<setw(5)<<temp->value;
}
