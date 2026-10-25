#include<iostream>
using namespace std;

class complex{
private:
    float real;
    float imag;
public:
    complex(){
        real = 0;
        imag = 0;
    }
    complex(float r, float i){
        real = r;
        imag = i;
    }
    ~complex(){
        // Destructor
    }
    void display(){
        cout << real << " + " << imag << "i" << endl;
    }
    complex operator+(complex c){
        return complex(real + c.real, imag + c.imag);
    }
    complex operator-(complex c){
        return complex(real - c.real, imag - c.imag);
    }
    complex operator*(complex c){
        float r = (real * c.real) - (imag * c.imag);
        float i = (real * c.imag) + (imag * c.real);
        return complex(r, i);
    }
};

int main(){
    complex c1(4, 5), c2(2, 3);
    
    cout << "\nFirst complex number: ";
    c1.display();
    
    cout << "Second complex number: ";
    c2.display();
    
    complex sum = c1 + c2;
    cout << "\nSum: ";
    sum.display();

    complex diff = c1 - c2;
    cout << "\nDifference: ";
    diff.display();

    complex prod = c1 * c2;
    cout << "\nProduct: ";
    prod.display();
    
    return 0;
}

//OUTPUT
//PS D:\Rahul> g++ operatoroverloading.cpp
//PS D:\Rahul> ./operatoroverloading
//First complex number: 4 + 5i
//Second complex number: 2 + 3i
//Sum: 6 + 8i
//Difference: 2 + 2i
//Product: -7 + 22i
//PS D:\Rahul>