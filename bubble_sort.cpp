//
// main.cpp
// Assignment 7
//
// Created by Joseph Flynn
// Due on 4/14/21.
//
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main(){

    //random time
    srand (time(NULL));

    //intializes variable and array
    int myArray[5][9];
    int min;

    //block for user inputs in myArray
    //index of row
    for (int i = 0; i<5; i++){
        int input = rand() % 10 + 1;
        //index of column
        for (int q = 0; q<9; q++){
            input = rand() % 10 + 1;
            //allows input into myArray at row i, column q
            myArray[i][q]=input;
        }
    }

    //sets min to first element
    min = myArray[0][0];

    //search and store min value
    //index of row
    for (int i = 0; i<5; i++){
        //index of column
        for (int q = 0; q<9; q++){
            //checks if min value is larger than current value at an index
            //if true
            if(myArray[i][q] < min){
                //the value at the index is lower and replaces the previous min value
                min = myArray[i][q];
            }
        }
    }

    //print unsorted matrix
    cout << "Unsorted Matrix: " << '\n';
    for (int i = 0; i<5; i++){
        //index of column
        for (int q = 0; q<9; q++){
            //allows input into myArray at row i, column q
            cout << myArray[i][q] << " ";
        }
        cout << '\n';
    }

    //displays min value
    cout << '\n' << "minimum value: " << min << '\n'<< '\n';

    //bubble sort
    //intializes variable that will stop running the code, if there is no more sorting
    int flag;

    //do block that ends if flag equals 0
    do{
        //sets flag to zero, which resets when the loop reruns
        flag = 0;

        //loop for index of row
        for (int i = 0; i<5; i++){
            //loop for index of column
            for (int q = 0; q<9; q++){
                //when q is less than 8, checks value nest to it
                if(q<8){
                    //if the current index is greater than the next value
                    if(myArray[i][q] > myArray[i][q+1]){
                        //swaps these two values if condition met
                        swap (myArray[i][q],myArray[i][q+1]);
                        //changes flag value, this causes the loop to rerun
                        flag = 1;
                    }
                }

                //when q is 8, first value on next line
                if(q == 8){
                    //when the array isn't on its last row
                    if(i<4){
                        //if the current index is greater than the first value on the next line
                        if(myArray[i][q] > myArray[i+1][0]){
                            //swaps these two values if condition met
                            swap (myArray[i][q],myArray[i][q+1]);
                            //changes flag value, this causes the loop to rerun
                            flag = 1;
                        }
                    }
                }
            }
        }

    //if flag doesn't change, means sorting is complete and ends
    }while(flag != 0);

    //print unsorted matrix
    cout << "Sorted Matrix: " << '\n';
    for (int i = 0; i<5; i++){
        //index of column
        for (int q = 0; q<9; q++){
            //allows input into myArray at row i, column q
            cout << myArray[i][q] << " ";
        }
        cout << '\n';
    }

    return 0;
}