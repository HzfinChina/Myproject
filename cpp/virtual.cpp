#include <iostream>
using namespace std;
class Animal 
{
    public:
        void Bark()
        {
            cout <<"Animal bark" << endl;
        }
};

class Dog: public Animal
{
    public:
        void Bark()
        {
            cout << "Dog bark"<< endl;
        }
};
int main()
{
    Animal *pa = new Dog;
    pa->Bark();
}
