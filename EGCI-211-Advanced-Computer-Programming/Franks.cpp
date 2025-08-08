#include<iostream>

using namespace std;
int main()
{

    const double sales_tax{0.06};
    const int estimate_expiry{30};

    cout << "Hello, welcome to Frank's carpet cleaning service\n\nHow many small rooms would you like cleaned? ";
    int number_of_small_room{0};
    cin >> number_of_small_room;

    cout << "How many large rooms would you like cleaned? ";
    int number_of_large_room{0};
    cin >> number_of_large_room;

    const double price_per_small_room{25.0};
    const double price_per_large_room{35.0};

    cout << "\nEstimate for carpet cleaning service\n";
    cout << "Number of small rooms: " << number_of_small_room << endl << "Number of large room" << number_of_large_room <<endl;
    cout << "Price per small room: $" << price_per_small_room <<endl << "Price per large room: $" << price_per_large_room <<endl;
    double cost{(number_of_small_room*price_per_small_room)+ (number_of_large_room*price_per_large_room)};
    cout << "Cost: $" << cost <<endl;
    double tax{((number_of_small_room*price_per_small_room)+ (number_of_large_room*price_per_large_room))*sales_tax};
    cout << "Tax: &" << tax << endl;
    cout << "===============================\n";
    cout << "Total estimate: $" << cost+tax << endl;
    cout << "This estimate is valid for" << estimate_expiry << " days\n";

    return 0;
}
