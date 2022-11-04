#include <iostream>
using namespace std;

typedef int type;


//header file

class MyVector{
    public:
        MyVector(int=1);
        MyVector(type*, int);
        MyVector(const MyVector&);
        ~MyVector();
        MyVector& operator= (const MyVector&);
        const type operator[] (int i) const;
        //cout car const
        type& operator[] (int i);
        //on peut faire v1[0]=2
        MyVector& operator += (const MyVector&); 


        void push_back(type);
        //on ne peut pas faire v1= v.push_back()
        type pop_back();
        


    private:
        int size; //size of elements
        int capacity; //nb of allocated bytes
        type* ptr; 
        friend ostream& operator<< (ostream&, const MyVector&);
};

const MyVector operator+(MyVector v1, const MyVector& v2);
//(v1+v2)++ doit etre inacceptable donc on met const

//implementation

int main(){
    return 0;
}