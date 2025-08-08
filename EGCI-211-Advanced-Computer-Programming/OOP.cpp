#include <iostream>
using namespace std;
class student{
private:
  string name,aka;
  int age;
  float gpa;

public:
    student(string n="Za", int a=18, float b = 3.00 ){
    name = n;
    age = a;
    gpa = b;
    cout<<name<<" has enter MUIC"<<endl;
  }
    ~student(){
    cout<<name<<" is dead"<<endl;
  }
    void operator++(){
    gpa++;
    age++;
  }
    void print(){
  cout<<"Name: "<<name<<endl;
  cout<<"Gpa: "<<gpa<<endl;
  cout<<"Age: "<<age<<endl;
}
    void setname(){

    }

};


int main() {
  student Prom("Prom",19,4.50);

  student *st = new student("Phil",21,2.00);
  Prom.print();
  ++Prom;
  ++(*st);
  Prom.print();
  st->print();
}
