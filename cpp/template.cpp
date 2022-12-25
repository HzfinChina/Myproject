#include <iostream>
using namespace std;

template <typename T>
T Get(T a, T b){
    return a + b;
}

template <typename T, typename B>
class A{
    public:
        void Add(T a, T b);
        int Ret(T a);
        void Add(float a, int b)
        {
            cout << "in class Function reload it" << endl;
        }
};

template <typename T,typename B>
void A<T, B>::Add(T a, T b)
{
    cout << a << b << endl;
}

template <>
void A<int, int>::Add(int a, int b)
{
    cout << "int ! " << a << b <<endl;
}



int main()
{
    
}
