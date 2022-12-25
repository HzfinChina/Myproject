#include <iostream> 
using namespace std;

class Box {
    public:
        static int length;
        void setLength(float len)
        {
            length = len;
        }
        int GetLength()
        {
            cout << length << endl;
            return length;
        }
        int compare(Box box)
        {
            return this->GetLength() > box.GetLength();
        }
};

int Box::length = 0;
int main()
{
    Box box1;
    box1.setLength(10);
    cout << Box::length <<endl;
    cout << box1.GetLength();
}
