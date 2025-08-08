#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int i;
  for(i=1;i<argc;i++){
    if (argv[i][0]=='x')
     s.pop();
    else
      s.push(atoi(argv[i]));
  }
  
 // s.push(5);
 //  s.push(1);
 //  s.push(7);
 //  s.push(6);
 //  s.pop();//6
 //  s.pop();//7
}