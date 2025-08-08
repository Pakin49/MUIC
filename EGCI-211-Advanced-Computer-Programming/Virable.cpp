#include<iostream>
using namespace std;
int main()
{
    int room_width{0},room_lenght{0};
    cout << "Enter the width of the room: ";
    cin >> room_width;
    cout << "Enter the lenght of the room: ";
    cin >> room_lenght;
    cout << "The area of the room is " << room_width*room_lenght << " square feet" << endl;
}
