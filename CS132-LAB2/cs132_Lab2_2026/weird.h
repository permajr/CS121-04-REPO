#include <iostream>
using namespace std;

template <class T>
class weird
{
public:
    weird();
    void operator %(float);
    void write();
private:
    T x;
};

template <class T>
weird<T>::weird()
{
    x = T(10000);
}

template <class T>
void weird<T>::operator %(float z)
{
    x = float(x) * z;
    return ;
}

//TODO:
//place the definition of function write here
//it should send the contents of the object to the screen

template <class T>
void weird<T>::write()
{
    cout << x << endl;
}