#include<iostream>
using namespace std;
class Stack{
    int top;//for keeping track of top element
    int length;//maximum length of stack
    int * p;//pointer for stack
    //int st[1000];
public:
    Stack(int size=0);
    ~Stack();
    void push(int key);
    void pop();
    int peep();
    void traversal();
};

Stack::Stack(int size){
    length=size;
    if(length==0){
        p=0;//if user give length 0
    }
    else{
        p=new int[length];//allocating memory for stack
    }
    top=-1;
}


Stack::~Stack(){
    if(p!=0)
        delete [] p;
}

void Stack::push(int key){
    if(p==0){//if stack has not allocating memory
        cout<<"Enter the size of stack:";
        cin>>length;
        p=new int[length];//allocat memory
        top++;
        p[top]=key;
    }
    else if(top>=length-1){//overflow condition
        cout<<"overflow"<<endl;
    }
    else{
        top++;
        p[top]=key;
    }
}

void Stack::pop(){
//pop top element of stack
//inpot nothing
//return void
    if(top>=0)//cheaking stack contain elements or not
        top--;
    else{
        cout<<"stack is empty"<<endl;//underflow
    }
}

int Stack::peep(){
    if(top<0){      //cheaking stack stack is empty or not
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else
        return p[top];// returning top element
}

void Stack::traversal(){
//display elements in the stack
    int temp=top;//making local copy of top
    while(temp>=0){
        cout<<p[temp]<<" ";
        temp--;
    }
}

int main(){
    int length;
    cout<<"Enter size of stack:";
    cin>>length;
    Stack s(length);
    bool exit = false;
    int response;
    while(exit == false){
        cout<<endl;
        cout<<"1. Push an item"<<endl;    //display menu
        cout<<"2. Pop an item"<<endl;
        cout<<"3. Peep into the stack"<<endl;
        cout<<"4. Show the elements"<<endl;
        cout<<"5. Exit"<<endl;

        cin>>response;//for getting responce from user
        switch(response){
            case 1:
                int temp;
                cout<<"Enter element:";
                cin>>temp;
                s.push(temp);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(s.peep()!= -1)//cheaking stack contain elements or not
                    cout<<s.peep()<<endl;
                break;
            case 4:
                s.traversal();
                break;
            case 5:
                exit=true;  //for exiting while loop
                break;

        }
    }
    return 0;
}
