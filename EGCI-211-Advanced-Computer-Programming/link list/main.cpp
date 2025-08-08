#include<iostream>
#include<iomanip>
using namespace std;
#include "node.h"
#include "LL.h"


int main(){
    LL l;
    l.insert_node(3);
    l.insert_node(5);
    l.insert_node(6);
    l.print_all();

    return 1;
}
