//
//  main.cpp
//  Assignment 12
//
//  Created by Joseph Flynn
//  Due on 5/10/2021

#include <iostream>
using namespace std;

class Employee{
    private:
    //private variables
        string name;
        int idNumber;
        string department;
        string position;
    
    public:
    //constructors
    //all four arguments needed
    Employee(string name2, int idNumber2, string department2, string position2){
        name = name2;
        idNumber = idNumber2;
        department = department2;
        position = position2;
    }
    
    //two arguments needed
    Employee(string name3,int idNumber3){
        name = name3;
        idNumber = idNumber3;
        department = "";
        position = "";
    }
    
    //default (no arguments needed)
    Employee(){
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }
    
    //mutators
    //sets new value for name
    void addName(string newName){
        name = newName;
    }
    //sets new value for idNumber
    void addNumber(int newNumber){
        idNumber = newNumber;
    }
    //sets new value for department
    void addDepartment(string newDepartment){
        department = newDepartment;
    }
    //sets new value for position
    void addPosition(string newPosition){
        position = newPosition;
    }
    
    //accessor
    //returns name for Employee
    string showName(){
        return name;
    }
    //returns idNumber for Employee
    int showNumber(){
        return idNumber;
    }
    //returns department for Employee
    string showDepartment(){
        return department;
    }
    //returns position for Employee
    string showPosition(){
        return position;
    }
    
    //shows all values for a given Employee (prototype)
    void showEverything();
};

//displays values for an Employee, by calling multiple accessor functions
void Employee :: showEverything(){
    cout << showName() << " - ";
    cout << showNumber()<< " - ";
    cout << showDepartment()<< " - ";
    cout << showPosition()<< endl;
}

int main() {
    //adds all arguments at once
    Employee employee_1("Susan Meyers",47899,"Accounting","Vice President");
    
    //starts with only name and idNumber
    Employee employee_2("Mark Jones",39119);

    //adds department and position to employee_2
    employee_2.addDepartment("IT");
    employee_2.addPosition("Programmer");
    
    //no arguments to start
    Employee employee_3;
    
    //adds the arguments to employee_3
    employee_3.addName("Joy Rogers");
    employee_3.addNumber(81774);
    employee_3.addDepartment("Manufacturing");
    employee_3.addPosition("Engineer");
    
    //heading for output
    cout << "Name - ID Number - Department - Position" << endl;
    
    //displays all the content of each Employee
    employee_1.showEverything();
    employee_2.showEverything();
    employee_3.showEverything();
    
    return 0;
}
