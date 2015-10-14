#include <iostream>
#include <string>
#include <ctype.h> //for tolower and isdigit function
using namespace std;

struct Student{
    string firstName;
    string lastName;
    string rollNo;
    int courcesMarks[5];//stores markes of cources
}student[40]; // array of struct ,declared as global

//function protopype
void SetStudRec(); // to set student record or update student record
void GetIndStudRec(); //to cheack indivisual students record
void GetAllStudRec();   //to cheack record of all students
void GetAvgMarks(); //display average markes of a perticular subject
bool cheakValidRollNo(string rollNo);

int noStud; // to keep track total no of students

int main(){
    bool exit = false;
    int response;
    while(exit == false){
        cout<<endl;
        cout<<"1. Set Student Record"<<endl;    //display menu
        cout<<"2. Get Individual's Record"<<endl;
        cout<<"3. Get All Students Record"<<endl;
        cout<<"4. Get Average of a Subject"<<endl;
        cout<<"5. Exit"<<endl;

        cin>>response;

        switch(response){
            case 1:
                SetStudRec();
                break;
            case 2:
                GetIndStudRec();
                break;
            case 3:
                GetAllStudRec();
                break;
            case 4:
                GetAvgMarks();
            case 5:
                exit=true;//for exiting while loop
                break;
        }
    }
    return 0;
}


void SetStudRec(){

// to set student record or update student record
//input : nothing
//output :nothing
    int responce;
    cout<<"1. Add new Students"<<endl;
    cout<<"2. Update Existance record"<<endl;

    cin>>responce;

    if(responce==1){
            int index=noStud;
            int newStud;
            cout<<"How many students do u want to add:";
            cin>>newStud;
            noStud+=newStud;
            string rollNo;
            for(int i=0;i<newStud;i++){
                cout<<"Enter First Name : ";
                cin>>student[index].firstName;

                cout<<"Enter Last Name : ";
                cin>>student[index].lastName;

                cout<<"Enter Marks in order and space saperated (Subject_1,Subject_2,Subject_3,Subject_4,Subject_5)"<<endl;
                for(int i=0;i<5;i++){
                    cin>>student[index].courcesMarks[i];
                }

                cout<<"Enter Roll No. : ";
                cin>>rollNo;
                while(!cheakValidRollNo(rollNo)){
                    cout<<"Invalid Roll No.! \n Enter again:";
                    cin>>rollNo;
                }
                student[index].rollNo="";
                for(int j=0;j<8;j++){
                    student[index].rollNo+=tolower(rollNo[j]);
                }

                index++;
        }
    }
    else if(responce==2){
        if(noStud>0){
            string rollNo;
            cout<<"Enter Roll no:";
            cin>>rollNo;
            for(int i=0;i<noStud;i++){
                if(rollNo==student[i].rollNo){
                    cout<<"Enter First Name : ";
                    cin>>student[i].firstName;

                    cout<<"Enter Last Name : ";
                    cin>>student[i].lastName;

                    cout<<"Enter Marks in order and space saperated (Subject_1,Subject_2,Subject_3,Subject_4,Subject_5)"<<endl;
                    for(int i=0;i<5;i++){
                        cin>>student[i].courcesMarks[i];
                    }

                    cout<<"Enter Roll No. : ";
                    cin>>rollNo;

                    while(!cheakValidRollNo(rollNo)){
                        cout<<"Invalid Roll No.! \n Enter again:";
                        cin>>rollNo;
                    }
                    student[i].rollNo="";
                    for(int j=0;j<8;j++){
                        student[i].rollNo+=tolower(rollNo[j]);
                    }

                }
            }
        }
        else cout<<"there is no student in record"<<endl;
    }
    else cout<<"Not Valid responce"<<endl;
}

void GetIndStudRec(){
    //display record of indivisual student
    string rollNo;
    int flag=0;
    cout<<"Enter Roll No. : ";
    cin>>rollNo;
    for(int i=0;i<noStud;i++){//searching for student
        if(rollNo == student[i].rollNo){
            cout<<"Name : "<<student[i].firstName<<" "<<student[i].lastName<<endl;
            cout<<"Roll No : "<<student[i].rollNo<<endl;
            cout<<"Marks"<<endl;
            cout<<"_________________________________________________________"<<endl;
            cout<<"subject1"<<"\t"<<student[i].courcesMarks[0]<<endl;
            cout<<"subject2"<<"\t"<<student[i].courcesMarks[1]<<endl;
            cout<<"subject3"<<"\t"<<student[i].courcesMarks[2]<<endl;
            cout<<"subject4"<<"\t"<<student[i].courcesMarks[3]<<endl;
            cout<<"subject5"<<"\t"<<student[i].courcesMarks[4]<<endl;
            cout<<"__________________________________________________________"<<endl;
            break;
        }
    }
    if(flag==0) cout<<"student not found in record"<<endl;
}

void GetAllStudRec(){
    if(noStud>0){
    //to display record of all students
        int subIndex;
        cout<<"Enter subject index : ";
        cin>>subIndex;
        cout<<endl;
        cout<<"Name\t\tRoll No\t\tmarks"<<endl;
        cout<<"____________________________________________________________________"<<endl;
        for(int i=0;i<noStud;i++){
            cout<<student[i].firstName<<" "<<student[i].lastName<<"\t\t"<<student[i].rollNo<<"\t\t"<<student[i].courcesMarks[subIndex]<<endl;
        }
        cout<<"____________________________________________________________________"<<endl;
    }
    else cout<<"there is no student in record"<<endl;
}

void GetAvgMarks(){
    if(noStud>0){
        //display avg marks of a perticular subject
        int subIndex; //for cheaking for which subject we are displaying avg marks
        float avg;
        int sum=0;
        cout<<"Enter subject index : ";
        cin>>subIndex;
        for(int i=0;i<noStud;i++){
            sum+=student[i].courcesMarks[subIndex];
        }
        avg=sum/(float)noStud;
        cout<<"Average markes in subject"<<subIndex+1<<" = "<<avg<<endl;
    }
    else cout<<"there is no student in record"<<endl;
}

bool cheakValidRollNo(string rollNo){

//for cheaking validity of roll no
//input :: roll no in string format
//outpu:: bool output ,  true for valid ,false for invalid
    int rollNoLen=rollNo.length();
    string first="";
    string last="";
    if(rollNoLen != 8) return false;
    for(int i=0;i<5;i++){
            first+=tolower(rollNo[i]);//converting lower case
    }
    for(int i=5;i<8;i++){
        if(!isdigit(rollNo[i])) return false;//cheacking last three digit id integer or not

        else{
            last+=rollNo[i];
        }
    }
    if(first !="cs15b") return false;//cheaking first 5 charecters

    return true;
}

