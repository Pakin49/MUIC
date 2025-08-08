#ifndef node_h
#define node_h

class node{
public:
    int value;
    node* next;
    
    node(int);
    ~node();
};

node::node(int x){
    value=x;
    next=NULL;
}

node::~node(){
    cout<<"Deleting "<<value<<endl;
}

#endif