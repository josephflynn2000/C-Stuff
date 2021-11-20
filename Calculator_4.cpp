//
//  main.cpp
//  Assignment 11
//
//  Created by Joseph Flynn
//  Due on 5/5/21.
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

//Calculation data type
struct Calculation{
    double num1;
    double num2;
    char symbol;
};

//file object
fstream MyWriteFile;

//function prototypes (string manipulation)
string noSpaces(string input);
char findOperator(string no_space, int *split);
double string_num1(string no_space, int split);
double string_num2(string no_space, int split);
void calculator(double num1, double num2, char oper);
char go_continue(string test);

//function prototypes (file input)
void saveCalculations(struct Calculation *num);
void readCalculations();

int main(){
    
    //stores value for user wanting to continue or not
    char cont;
    
    //loop than ends when user inputs 'n' or 'N'
    do{
        
        //structured Array
        struct Calculation myCalculationArray[3];
        
        //loop to fill myCalculationArray
        for(int i = 0; i<3; i++){
            
            //strings that resets with the loop
            string input;
            string no_space;
            char oper;
            
            //doubles that resets with the loop
            double num1;
            double num2;
            
            //int that resets with the loop
            int split;
            
            //input problem
            cout << "Input Calculation: ";
            getline(cin,input);
            
            //removes whitespaces from input
            no_space = noSpaces(input);
            
            //finds operator and operator location
            oper = findOperator(no_space, &split);
            
            //removes numbers from string and saves them as a double
            num1 = string_num1(no_space, split);
            num2 = string_num2(no_space, split);
            
            //prints out solution to the problem
            calculator(num1,num2,oper);
            
            //saves numbers and operator into myCalculationArray
            myCalculationArray[i] = {num1,num2,oper};
        }
        
        //input to be tested
        string test;
        
        //User inputs if they want to continue or not
        cout << "Do you want to continue? (Y/N): " << '\n';
        cin >> test;
        
        
        //sets user input to 'Y' or 'N'
        cont = go_continue(test);
        
        //clears getline() so it does skip first input if loop is repeated
        cin.ignore();
        
        //saves calculations to file using pointer argument
        saveCalculations(myCalculationArray);
        
    }while(toupper(cont) != 'N'); //ends if count = 'N'
    
    string STRING;
    cout << "Do you wants to see the previous calculations? (Y/N): ";
    cin >> STRING;
    if(toupper(go_continue(STRING))=='Y'){
    //reads out calculations
        readCalculations();
    }
    
     //clears file
    /*
    ofstream clear;
    clear.open("CalculatorOutput.txt", ofstream::out | ofstream::trunc);
    clear.close();
    */
    
    return 0;
}



//removes spaces from input
string noSpaces(string input){
    
    string no_space;
    
    //goes through each character and saves non-whitespace characters
    for(int i = 0; i < input.length(); i++){
        if(input[i]!= ' '){
            no_space += input[i];
        }
    }
    
    //returns string with no whitespaces
    return no_space;
}



//detects operator in no_space string
char findOperator(string no_space, int *split){
    
    //value to be returned
    char oper;
    
    //if the first number is negative
    if(no_space[0]=='-'){
        
        //creates character array
        char arr[(no_space.length()-1)];
        
        //turns string into character array
        for(int i = 1; i < no_space.length(); i++){
            arr[i] = no_space[i];
        }
        
        //if statements to find operator (addition)
        if(strstr(arr,"+")){
            oper = '+';
            //finds location of operator (+)
            for(int i = 0;  i < no_space.length(); i++){
                if(arr[i] == '+'){
                    *split = i;
                }
            }
        }
        
        //if statements to find operator (substitution)
        if(strstr(arr,"-")){
                oper = '-';
                //finds location of operator (-)
                for(int i = 0;  i < no_space.length(); i++){
                    if(arr[i] == '-'){
                        *split = i;
                        //break because problem might be (-a)-(-b)
                        //no-break (-a)-(-b) turns to -a-b
                        break;
                    }
                }
            }
        
        //if statements to find operator (division)
        if(strstr(arr,"/")){
            oper = '/';
            //finds location of operator (/)
            for(int i = 0;  i < no_space.length(); i++){
                if(arr[i] == '/'){
                    *split = i;
                }
            }
        }
        
        //if statements to find operator (multiplication)
        if(strstr(arr,"*")){
            oper = '*';
            //finds location of operator (*)
            for(int i = 0;  i < no_space.length(); i++){
                if(arr[i] == '*'){
                    *split = i;
                }
            }
        }
    }
    
    //positive first number
    else{
        
        //creates character array
        char arr[no_space.length()];
        
        //turns string into character array
        for(int i = 0; i < no_space.length(); i++){
            arr[i] = no_space[i];
        }
        
        //if statements to find operator (addition)
        if(strstr(arr,"+")){
            oper = '+';
            //finds location of operator (+)
            for(int i = 0;  i < no_space.length(); i++){
                if(arr[i] == '+'){
                    *split = i;
                }
            }
        }
        
        //if statements to find operator (substitution)
        if(strstr(arr,"-")){
            oper = '-';
            //finds location of operator (-)
            for(int i = 0;  i < no_space.length(); i++){
                if(arr[i] == '-'){
                    *split = i;
                    break;
                }
            }
        }
        
        //if statements to find operator (division)
        if(strstr(arr,"/")){
            oper = '/';
            //finds location of operator (/)
            for(int i = 0;  i < no_space.length(); i++){
                if(arr[i] == '/'){
                    *split = i;
                }
            }
        }
        
        //if statements to find operator (multiplication)
        if(strstr(arr,"*")){
            oper = '*';
            //finds location of operator (*)
            for(int i = 0;  i < no_space.length(); i++){
                if(arr[i] == '*'){
                    *split = i;
                }
            }
        }
    }
    
    //returns operation symbol
    return oper;
}



//gets first number
double string_num1(string no_space, int split){
    
    //returned string
    string str_num;
    
    //places every character before operator into a new string
    for(int i = 0; i < split; i++){
        str_num += no_space[i];
    }
    
    //returns string with characters before operator
    return stod(str_num);
}



//gets second number
double string_num2(string no_space, int split){
    
    //returned string
    string str_num;
    
    //places every character after operator into a new string
    for(int i = split+1; i < no_space.length(); i++){
        str_num += no_space[i];
    }
    
    //returns string with characters after operator
    return stod(str_num);
}



//calculates problem
void calculator(double num1, double num2, char oper){
    
    //adds (num1+num2)
    if(oper == '+'){
        cout << num1+num2 << '\n';
    }
    
    //subtracts (num1 - num2)
    if(oper == '-'){
        cout << num1-num2 << '\n';
    }
    
    //multiplies (num*num2)
    if(oper == '*'){
        cout << num1*num2 << '\n';
    }
    
    //divides (num1/num2)
    if(oper == '/'){
        //division by zero error
        if(num2 == 0){
            cout << "Division by zero" << '\n';
        }
        
        //normal division
        else{
            cout << num1/num2 << '\n';
        }
        
    }
}



//whether user wants to do 3 more problems or stop
char go_continue(string test){
    
    //loop stops once a string of length 1 is given
    do{
        
        //if length of string is 1
        if(test.length() == 1){
            //checks if the 1 length string is n or y
            if(toupper(test[0]) != 'N' && toupper(test[0]) != 'Y'){
                //repeats unless first character is a y or
                do{
                    cout << "INVALID! Input a valid response"<< '\n';
                    cout << "Do you want to continue? (Y/N): ";
                    cin >> test;
                }while(toupper(test[0]) != 'N' && toupper(test[0]) != 'Y');
            }
        }
        
        //if length of string is not 1
        //repeats input
        else{
            cout << "INVALID! Input a valid response"<< endl;
            cout << "Do you want to continue? (Y/N): " << endl;
            cin >> test;
        }
        
    //loop only breaks when either y, Y, n, or N is entered
    }while(test.length() != 1);
    
    //converts 1 character string into character
    char cont = test[0];
    
    //returns y, Y, n, or N character
    return cont;
}



//writes previous to file
void saveCalculations(struct Calculation *num){
    
    //opens text file
    MyWriteFile.open("CalculatorOutput.txt", ios::out | ios::binary | ios:: app);
    for(int i = 0; i<3; i++){
        MyWriteFile.write(reinterpret_cast<char*>(&num[i]), sizeof(*num));
        //array of three is sent, so a loop is used to get every values
    }
    //closes file
    MyWriteFile.close();
}

void readCalculations(){
    struct Calculation myCalculationArray2;
    int number = 1;
    MyWriteFile.open("CalculatorOutput.txt", ios::in | ios::binary);
    MyWriteFile.read(reinterpret_cast<char*>(&myCalculationArray2), sizeof(myCalculationArray2));
    if (!MyWriteFile)
    {
    cout << "Error opening file. Program aborting.\n";
    }
    while (!MyWriteFile.eof()){
        cout << number << ". ";
        cout << myCalculationArray2.num1 << " ";
        cout << myCalculationArray2.symbol << " ";
        cout << myCalculationArray2.num2 << " = ";
        calculator(myCalculationArray2.num1,myCalculationArray2.num2,myCalculationArray2.symbol);
        MyWriteFile.read(reinterpret_cast<char *>(&myCalculationArray2), sizeof(myCalculationArray2));
        number++;
    }
    MyWriteFile.close();

}
