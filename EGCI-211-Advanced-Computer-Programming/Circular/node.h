class node{
private:
    int value;
    node* next;
public:
    node(int);
    ~node();
};
typedef node* nodePtr;

node::node(int v){
    value = v;
    cout<<"Constructing node "<<value<<endl;
    next = NULL;
}

node::~node(){
    cout<<"Deleting "<<value<<endl;
}