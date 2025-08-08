#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
    bool match=1;
    Stack s;
    char data;
    for(int j=1;j<argc;j++){
        for (int i=0; strlen(argv[1]);i++){
            switch(argv[j][i]){
                case '[':
                     s.push(argv[j][i]);
                     break;
                case '{':
                    s.push(argv[j][i]);
                    break;
                case '(' : 
                    s.push(argv[j][i]);
                    break;
                case ']':
                    data=s.pop();
                    if (data != '[' ) match=0;
                    break;
                case '}':
                    data=s.pop();
                    if (data != '{' ) match=0;
                    break;
                case ')':
                    data = s.pop();
                    if(data != '(') match=0;
                    break;
                default: break;
            }
        if (match==0)
            cout<<"Parentheses do not match"<<endl;
        else if(match==0 && s.getSize()>0)
            cout<<"Parenthese has too many open"<<endl;
        else if(match==0 && s.getSize()==0)
            cout<<"Parenthese has too many close"<<endl;
        else
            cout<<"Parentheses match"<<endl;
        }
    }
}