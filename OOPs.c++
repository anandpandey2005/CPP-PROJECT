/*
++++++++++++++++++++++++  Object Oriented Programming ++++++++++++++++++

those library are in stl are implemented by the helpp  of oops

==> THE FOUR BASIC PILLAR OF OOPs ARE : -

->  ENCAPSULATIONN
->  ABSTRACTION
->  INHERITANCE
->  POLYMORPHISM

++++++++++++++++++++++++   Class & Object ++++++++++++++++++

->  object are entities in the real world
->  class are blue print or template of the object / group of the object

method => it is nothing it is a function that written under a class

+++++++++++++++++++++++  ACCESS MODIFIER ++++++++++++++++++++++++++

-> public          ---> members are accessible  from anywhere in the program
-> private         ---> members are accessible only within the same class
-> protected       ---> members are accessible within the same class and in derived class

+++++++++++++++++++++++++ ENCAPSULATION +++++++++++++++++++++++++++++

Encapsulaton is WRAPPING UP of  data & member function in a single unit called class

-->  IT  HELP  in DATA HIDING

++++++++++++++++++++++++  CONSTRUCTOR  +++++++++++++++++++++++++++++++

special method invoked automatically at time of OBJECT CREATION. used for Initialisation

-> same name as class
-> constructor doesn't have a return type
-> only  called once (automatically),at object creation
-> memorey allocation happens when constructor is called

3-TYPES CONSTRUCTOR

->  PARAMETERISED CONSTRUCTOR
->  NON- PARAMETERISED CONSTRUCTOR
->  COPY CONSTRUCTOR

constructor overloading is an example of polymorphism


++++++++++++++++++++++++++++  THIS CONSTRUCTOR   ++++++++++++++++++++++++

this is a special  pointer in c++ that points to the current object

this->prop is same as *(this).prop


*/

#include <bits/stdc++.h>
using namespace std;

class teacher
{

public:
    string name;
    string dept;
    string subject;
    double salary;

    void changeDept(string newDept)
    {
        dept = newDept;
    };
    // set  the private value
    void setName(string newname)
    {
        name = newname;
    };
    //  get private value
    string getDept()
    {
        return dept;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    };
    // NON-PARAMETERISED CONSTRUCTOR
    teacher()
    {

        cout << "iam a constructor" << endl;
    }
    // PARAMETERISED CONSTRUCTOR
    teacher(string n, string d, string su, int s)
    {
        name = n;
        dept = d;
        subject = su;
        salary = s;

        dept = "computer science ";
        cout << "iam a constructor" << endl;
    }
};




int main()
{

    teacher t1("anand", "computer science", "c++", 25000);

    // t1.name = "anandpanddey";
    // t1.subject = "c++";
    // t1.salary = 50000;
    // t1.changeDept("manager");
    // cout << t1.dept;
    t1.getInfo();
}