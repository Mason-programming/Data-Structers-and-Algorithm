#include <iostream>
#include "2DArray.h"
using namespace std; 

void start_program();

int main(){

    start_program();
    
    return 0; 
}

void start_program(){
     //intializes the varibles 
     int a ,b ,c, d = 0; 

    //allows user to enter the size of the array 
    cout << "Enter the rows and coloumn of the first array (seperated by a space): "; 
    cin >> a >> b; 
    cout << "Enter the rows and coloumn of the second array (seperated by a space): ";
    cin >> c >> d;

    //check if the values entered will make the same size arrays 
    if(b != d || b != c || a != b){
        //indicates the vlue sentered will not make the arrays that same size then calls the function again 
        cout << "please enter the same values for each array" << endl;
        start_program();

    }else{
        //creating the twoDArray object 
        twoDArray array(a,b,c,d);

        //if the arrays are the same size the program calls the functions of the class 
        array.createArray();

        array.multiplyArray();

        array.printArrays(); 
    }
}

