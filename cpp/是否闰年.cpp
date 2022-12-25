#include <iostream>
using namespace std;
int main()
{
    int year;
    cin >> year;
    if ((year % 4 == 0 && year % 400 != 0) || year % 400 == 0)
    {
        cout << year << "是闰年" << endl;
    }
    else 
        cout << "it's not leap year" << endl;
}
