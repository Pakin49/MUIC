#include "node.h"

class ll{
private:
    nodePtr head;
    int size;
public:
    ll();
    ~ll();
    void insertFront(int);
    void insertBack();
    void deleteNode(int)
};

ll::ll(){
    head = NULL;
    size = 0;
}
ll::~ll(){
    cout<<"Deleting LinkList"<<endl;
}

void ll::insertFront(int v){
    nodePtr newNode = new node(v);
    if(newNode)
}

void ll::deleteNode(int v){
    nodePtr currentPtr;
    currentPtr = head;

}