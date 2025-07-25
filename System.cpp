#include<iostream>
#include "Link_List.h"
#include<string>

using namespace std;

class Student{
public:
    string name;
    int rollnumber;
    float gpa;

    Student():name("Defualt"),rollnumber(0),gpa(0.0){}
    Student(string nam,int rollnu,float gp):name(nam),rollnumber(rollnu),gpa(gp){}
    Student(Student& obj):name(obj.name),rollnumber(obj.rollnumber),gpa(obj.gpa){}
    friend ostream& operator<<(ostream& os,const Student obj){
        os<<obj.name<<" - "<<obj.rollnumber<<" - "<<obj.gpa<<endl;
        return os;
    }
    Student& operator=(const Student& obj){
        if(this!=&obj){
            name = obj.name;
            rollnumber = obj.rollnumber;
            gpa = obj.gpa;
        }
        return *this;
    }
};
class Management{
private:
    node<Student>* head;
    int count;
public: 
    Management():head(nullptr),count(0){}
    void addStudent(Student& obj){
         addToTail(head,obj);
    }
    bool isValidStudent(int roll){
        return search(head,roll);
    }
    void update(int rollnu){
        if(this->isValidStudent(rollnu)){
            string name;
            cout<<"Name : ";
            cin>>name;
            int rollnum;
            cout<<"Roll number :";
            cin>>rollnum;
            float gpa;
            cout<<"Gpa : ";
            cin>>gpa;
            Student latest(name,rollnum,gpa);
            linkupdate(head,rollnu,latest);
        }
    }
    void delte(Student& obj){

    }
    friend ostream& operator<<(ostream& os,Management& obj){
        os<<"-----------------\n";
        os<<"Name - RollNo - GPa\n";
        display(obj.head);
        os<<endl;
        return os;
    }

    ~Management(){ 
        head = nullptr;
    }
};
int main(){

    Management system;
    Student obj1("Ali",23,2.4);
    Student obj2("Ali2e",213,2.4);
    Student obj3("Ali2",232,22.4);
    Student obj4("Ali22",233,2.4);
    Student obj5("Ali2d",235,2.4);
    system.addStudent(obj1);
    system.addStudent(obj2);
    system.addStudent(obj3);
    system.addStudent(obj4);
    system.addStudent(obj5);

    cout<<system<<endl;

    int roll;
    cout <<"Enter Roll number :" ;
    cin>>roll;

    if(system.isValidStudent(roll)){
        cout<<roll<<" is valid student\n";
    }
    else {
        cout<<roll<<" is not valid\n";
    }

    cout<<"Update : ";
    
    

    return 0;
}
