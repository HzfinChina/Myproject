#include <iostream>
using namespace std;

class Box {
    double width; 
public:
    friend void printWidth(const Box &box){
        cout << "Width of box :" << box.width << endl;
    }
    void setWidth(double wid)
    {
        width = wid;
    }
    friend class Simbox;
};

class Simbox{
public:
    void Print(int width, Box &box)
    {
        box.setWidth(width);
        cout << "Width of box:" << box.width << endl;
    }
};

int main()
{
    Box box;
    Simbox simbox;
    box.setWidth(10.2);
    printWidth(box);
    simbox.Print(1234,box);
    printWidth(box);
}
