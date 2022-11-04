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
        int GetCapacity() const;


    private:
        int size; //size of elements
        int capacity; //nb of allocated bytes
        type* ptr; 
        friend ostream& operator<< (ostream&, const MyVector&);
};

const MyVector operator+(MyVector v1, const MyVector& v2);
//(v1+v2)++ doit etre inacceptable donc on met const

//implementation
MyVector::MyVector(int c):
capacity(c),size(0),ptr(new int[capacity]){
    for (int i=0; i<c; ++i){
        ptr[i]=0;
    }
}
MyVector::MyVector(type* p, int n)
:capacity(n),size(n){
    ptr= new type [capacity];
 //   for (int i=0; i<size; ++i){
   //     ptr[i]= p[i];
    //}
   memcpy(ptr,p,size*sizeof(type));
}
MyVector::~MyVector(){
    delete ptr;
    ptr=nullptr;

}
int MyVector::GetCapacity() const{
    return capacity;
}

ostream& operator<< (ostream& os, const MyVector& v){
    os << "{";
    //int i;
    for (int i=0; i<v.size-1 ; ++i){
        os << v.ptr[i] << ", ";
    }
    os << v.ptr[v.size-1] << "}";
    return os;
}

void MyVector::push_back(type a){
    if (size==capacity){
        type* old=ptr;
        ptr= new type[capacity*2];
        memcpy(ptr,old,size*sizeof(type));
        delete[] old;
        for (int i=size; i< capacity ; ++i){
            ptr[i]=0;
        }
    }
    ptr[size]=a;
    size++;
}

type MyVector::pop_back(){
    type a= ptr[size-1];
    size --;
    if (capacity >= size*4){
        type* old =ptr;
        capacity /=2;
        ptr = new type [capacity];
        memcpy(ptr,old,size*sizeof(type));
        delete [] old;
    }
    return a;
}


int main(){
    type tab[] ={1,2,3,4,5};
    MyVector v1(tab,5);
    cout << "v1= " << v1 << endl;
    v1.push_back(6);
    cout << v1 << endl;
    type a=v1.pop_back();
    cout << a << endl;
    type b= v1.pop_back();
    cout << b << endl;
    type c= v1.pop_back();
    cout << c << endl;
    type d= v1.pop_back();
    cout << d << endl;
    type e= v1.pop_back();
    cout << e << endl;
    cout << "v1= " << v1 << endl;
    cout << v1.GetCapacity() << endl;
    return 0;
}