using namespace std; 

class twoDArray{
    int userInputN, userInputM, userInputS, userInputT; 
    int** first_array;
    int** second_array;
    int** third_array; 
public: 
    twoDArray(){
        userInputM = 0; 
        userInputN = 0;
        userInputT = 0; 
        userInputS = 0; 
    }
    twoDArray(int m, int n, int s, int t){
        userInputM = m; 
        userInputN = n;
        userInputS = s;
        userInputT = t; 
    }
    void createArray();
    void multiplyArray(); 
    void printArrays(); 

}; 
void twoDArray::createArray(){
    //creating the first 2 2d arrays determined by the size of the user inputs
    
    first_array = new int*[userInputM];
    second_array = new int*[userInputS]; 
      
    for(int i = 0; i < userInputM; i++){
        first_array[i] = new int[userInputN];
    }
    for(int i = 0; i < userInputS; i++){
        second_array[i] = new int[userInputT];
    }
    //populating the arrays with index numbers 
    for(int i = 0; i < userInputM; i++){
        for(int j = 0; j< userInputN; j++){
            first_array[i][j] = i + j; 
            second_array[i][j] = i + j;     
        }
        cout << endl; 
    }
    //creating the third array size out of inputs from the first two arrays 
    third_array = new int*[userInputM];
    for(int i = 0; i < userInputM; i++){
        third_array[i] = new int[userInputT];
    }
}
void twoDArray::multiplyArray(){
       //mutiplying the two arrays to make a third one
       for(int i = 0; i < userInputM; i++){
         for(int j = 0; j< userInputT; j++){
             for(int k = 0; k < userInputS; k++){
                //multiplying the first 2 arrays 
                third_array[i][j] += first_array[i][k] * second_array[k][j];  
              }   
           }
        }  
}

void twoDArray::printArrays(){

    // Print first array
        cout << "the first array: " << endl; 
        for(int i = 0; i < userInputM; i++){
            for(int j = 0; j< userInputN; j++){
                cout << first_array[i][j] << " ";    
            }
            cout << endl; 
        }
        // print second array
        cout << "the second array: " << endl; 
        for(int i = 0; i < userInputM; i++){
            for(int j = 0; j< userInputN; j++){
                cout << second_array[i][j] << " ";    
            }
            cout << endl; 
        }
        //print third array 
        cout << "the third array: " << endl; 
        for(int i = 0; i < userInputM; i++){
            for(int j = 0; j< userInputT; j++){
                cout << third_array[i][j] << " ";    
            }
            cout << endl; 
        }
    }
