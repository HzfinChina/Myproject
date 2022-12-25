#include<iostream>
using namespace std;

template <typename T>
class Matrix{
    public:
    Matrix operator+(const Matrix a);
    Matrix operator++();
    Matrix operator++(int); //这个只是为了和前置++区分开，无意义
    Matrix(T const (&inmat)[4][4]){
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                this->matrix[i][j] = inmat[i][j];
    }
    Matrix operator+= (const Matrix &a);
    T* operator[](int roc) //row or line
    {
        return this->matrix[roc];
    }
    friend ostream &operator<<(ostream &out, const Matrix<T> &mat)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                out << mat.matrix[i][j] << " ";
            out << endl;
        }
        return out;
    }
    private:
    T matrix[4][4];
};

template<typename T>
Matrix<T> Matrix<T>::operator++()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->matrix[i][j] ++;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator++(int)
{
    ++*this;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix &a)
{
    *this = *this + a;
    return a;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix a)
{
    Matrix retmat[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            retmat[i][j] = this->matrix[i][j] + a.matrix[i][j];
    return retmat;
}

int main()
{
    Matrix<double> mat({{1,2,3,4},{2,3,4,5},{2,2,2,2},{3,3,3,3}});
    cout << mat[1][1];
}
