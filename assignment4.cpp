#include <iostream>
#include <string>
#include <cmath>

#include "polynomial.h"

using namespace std;


Polynomial::Polynomial(){///default constructer
    size = 49;
    ptr = new float[50];
    for(int i=0;i<50;i++){
        this->ptr[i]=0;
    }
}

Polynomial::Polynomial(int tempSize){
    size = tempSize;
    ptr = new float[tempSize];
    for(int i=0;i<tempSize;i++){
        this->ptr[i]=0;
    }
}
Polynomial::Polynomial(const Polynomial &p1){///copy constructor
    ptr = new float[p1.size];
    size = p1.size;
    for(int i=0;i<size;i++){
        this->ptr[i]=p1.ptr[i];
    }
}

Polynomial::~Polynomial(){///destructor
    delete this->ptr;
}
void Polynomial::setCoeff(int pos,float value){///for setting a perticular coifficent
    this->ptr[pos]=value;
}

float Polynomial::retriveCoeff(int pos){
    return this->ptr[pos];
}

void Polynomial::incrementCoeff(int pos,float value){
    this->ptr[pos] += value;
}

int Polynomial::degree(){///returns degree of polynmomial
    int tempDegree = size;
    for(int i=size;i>=0;i--){
        if(this->ptr[i]==0){
            tempDegree--;
        }
        else break;
    }
    return tempDegree;
}
int Polynomial::numOfTerms(){///returns no of terms in polynomial
    int count=0;
    for(int i=size;i>=0;i--){
        if(this->ptr[i]!=0){
            count++;
        }
    }
return count;
}
void Polynomial::displayPolynomial(){///displays cofficents of polynomial
    for(int i=this->degree();i>=0;i--){
        cout<<this->ptr[i]<<" ";
    }
    cout<<endl;
}
int Polynomial::getSize(){
    return this->size;
}

float Polynomial::evaluate(float x){///evaluats value of polynomial for a perticular value of x
    float tempSum=0;
    for(int i=0;i<size;i++){
        tempSum+=(pow(x,i)*(this->ptr[i]));
    }
return tempSum;
}


Polynomial Polynomial::derivative(){///derivate a polynomial
    Polynomial p1(this->degree());
    for(int i=1;i<=p1.degree();i++){
        p1.setCoeff(i,(i+1)*this->retriveCoeff(i+1));
    }
    return p1;
}

Polynomial operator*(Polynomial p1,float value){/// for polynomial*value
    Polynomial p2;
    for(int i=0;i<p1.getSize();i++)
        p2.setCoeff(i,value*p1.retriveCoeff(i));
    return p2;
}
Polynomial operator*(float value,Polynomial p1){///for value*polynomial
    Polynomial p2;
    for(int i=0;i<p1.getSize();i++)
        p2.setCoeff(i,value*p1.retriveCoeff(i));
    return p2;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {///assignment operator
 if (this == &rhs)
   return *this;
size = rhs.size;
//delete ptr;
ptr= new float[size];
ptr=rhs.ptr;
for(int i=0;i<rhs.size;i++){
    this->ptr[i] = rhs.ptr[i];
}
return *this;
}



//Polynomial Polynomial::operator+(Polynomial p1){
//    bool flag=0;
//    int tempSize = max(p1.getSize(),this->getSize());
//    Polynomial p2(tempSize);
//    for(int i=0;i<=min(p1.getSize(),this->getSize());i++){
//        p2.setCoeff(i,this->retriveCoeff(i)+ p1.retriveCoeff(i));
//    }
//    if(p1.getSize() > this->getSize()) flag=1;
//
//    for(int i=min(p1.getSize(),this->getSize())+1 ; i<max(p1.getSize(),this->getSize());i++){
//        if(flag == 1)
//            p2.setCoeff(i,p1.retriveCoeff(i));
//        else
//            p2.setCoeff(i,this->retriveCoeff(i));
//    }
//return p2;
//}

Polynomial operator+(Polynomial p1,Polynomial p3){///operator + overloading using friend function
    bool flag=0;
    int tempSize = max(p1.getSize(),p3.getSize());
    Polynomial p2(tempSize);
    for(int i=0;i<=min(p1.getSize(),p3.getSize());i++){
        p2.setCoeff(i,p3.retriveCoeff(i)+ p1.retriveCoeff(i));
    }
    if(p1.getSize() > p3.getSize()) flag=1;

    for(int i=min(p1.getSize(),p3.getSize())+1 ; i<max(p1.getSize(),p3.getSize());i++){
        if(flag == 1)
            p2.setCoeff(i,p1.retriveCoeff(i));
        else
            p2.setCoeff(i,p3.retriveCoeff(i));
    }
return p2;
}

Polynomial operator-(Polynomial p1,Polynomial p2){
    bool flag=0;
    int tempSize = max(p1.getSize(),p2.getSize());
    Polynomial p3(tempSize);
    for(int i=0;i<=min(p1.degree(),p2.degree());i++){
        p3.setCoeff(i,p1.retriveCoeff(i)-p2.retriveCoeff(i));
    }
    if(p1.degree() > p2.degree()) flag= 1;
    for(int i=min(p1.degree(),p2.degree())+1;i<=max(p1.degree(),p2.degree());i++){
        if(flag ==1){
            p3.setCoeff(i,p1.retriveCoeff(i));
        }
        else{
            p3.setCoeff(i,-1*p2.retriveCoeff(i));
        }
    }
return p3;
}
bool operator==(Polynomial p1,Polynomial p2){
    if(p1.degree()!= p2.degree()) return false;
    else{
        for(int i=0;i<p1.degree();i++){
            if(p1.degree()!=p2.degree()) return false;
        }
        return true;
    }
}
int main(){
    Polynomial p1,p2;
    p1.setCoeff(2,5);
    p1.setCoeff(1,9);

    p2.setCoeff(3,7);

    p1.displayPolynomial();
    p2.displayPolynomial();


///for retrive coffecient
cout<<p2.retriveCoeff(2)<<endl;

///for increment coefficient
p2.incrementCoeff(3,5);
cout<<p2.retriveCoeff(3)<<endl;

///for degree
cout<<p2.degree()<<endl;

///for num of terms
cout<<p2.numOfTerms()<<endl;

///evaluate
cout<<p2.evaluate(2)<<endl;


///operator + overloading
Polynomial x = (p1+p2);
    x.displayPolynomial();

///working - overloading
//Polynomial x =p1-p2;
//x.displayPolynomial();
//cout<<x.degree();

///working * overloading
Polynomial y=2*p2;
y.displayPolynomial();


///working == operator
cout<< (p1==p2) <<endl;

///derivative working
    Polynomial z = p2.derivative();
    z.displayPolynomial();


return 0;
}

