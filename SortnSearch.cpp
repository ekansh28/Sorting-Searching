#include <iostream>

// ARRAY CREATION FUNCTION
int* createArray(int x) {
    // CREATING A NEW ARRAY
    int* Array = new int[x]; 
    
    // ASSIGNING VALUES TO THE ARRAY
    for(int i = 0; i < x; i++){
            std::cout << "value for arr[" << i << "]" << std::endl;
               std::cin >> Array[i]; 
    }
    
    // DISPLAYING VALUES FROM THE ARRAY
    std::cout << "ARRAY VALUES :" << std::endl;  
        for(int i = 0; i < x; i++){
            std::cout << Array[i] << " ";
    }
    std::cout << std::endl;
    // RETURNING THE ARRAY
    return Array;
}

// LINEAR SEARCHING
void linSearch(int Array[], int size, int value) {
    // FOR SEARCHING THE VALUE
    for (int i = 0; i < size; i++) {
        // IF VALUE IS FOUND
        if (Array[i] == value) {
            std::cout << "Value '" << value << "' was found at Array [" << i << "]" << std::endl;
            return; 
        }
    }

    // IF THE VALUE IS NOT FOUND
    std::cout << "Value not found" << std::endl;
}

// SELECTION SORTING
void selSort(int Array[], int size){
    int pass = size - 1;

    // LOOP FOR PASSES
    for(int i = 0; i < pass; i++){
        // LOOP FOR COMPARISION
        for(int j = i + 1; j < size ; j++){
            if(Array[i] > Array[j]){
                int temp = Array[i];
                Array[i] =  Array[j];
                Array[j] = temp;       
            }
        }
    }
    
    // DISPLAYING THE SORTED ARRAY
    std::cout << "SORTED ARRAY :" << std::endl;  
    for(int i = 0; i < size; i++){
      std::cout << Array[i] << " ";
    }
     std::cout << std::endl;
}

// BUBBLE SORTING
void bubSort(int Array[], int size){
    int pass = size - 1;
    
    // LOOP FOR PASSES
    for(int i = 0; i < pass; i++){
        // LOOP FOR COMPARISON
        for(int j = 0; j < ( pass - i); j++){
            if(Array[j] > Array[j + 1]){
                int temp = Array[j];
                Array[j] =  Array[j + 1];
                Array[j + 1] = temp;                
            }
        }
    }
    // DISPLAYING THE SORTED ARRAY
    std::cout << "SORTED ARRAY :" << std::endl;  
    for(int i = 0; i < size; i++){
      std::cout << Array[i] << " ";
    }
      std::cout << std::endl;
}


// BINARY SEARCH
void binSearch(int Array[], int size, int value) {

    int sortArg;
    std::cout << "Would you like to perform :" << std::endl;
    std::cout << "[1] Bubble Sort" << std::endl;
    std::cout << "[2] Selection Sort" << std::endl;
    std::cin >> sortArg; 
    if( sortArg == 1 ){
        bubSort(Array, size);
    } else if ( sortArg == 2 ){
        selSort(Array, size);
    } 
    
    
    int ls = 0; // CALCULATING THE FIRST INDEX OF THE ARRAY
    int rs = size - 1; // CALCULATING THE LAST INDEX OF THE ARRAY
    
    while (ls <= rs) {
        int med = (ls + rs) / 2; // CALCULATING THE MIDDLE INDEX OF THE ARRAY
        
        // IF THE VALUE IS FOUND
        if (Array[med] == value) {
            std::cout << "Value found at Array [" << med << "]" << std::endl;
            return; 
        } 
        else if (Array[med] < value) {
            ls = med + 1; 
        } 
        else {
            rs = med - 1; 
        }
    }

    // IF VALUE NOT FOUND
    std::cout << "Value not found" << std::endl;
}

int main() {
    int a; 
    int b;
    std::cout << "Write the size of the array" << std::endl;
    std::cin >> a; 
    std::cout << "Write the value you want to search in the array" << std::endl;
    std::cin >> b; 
    
    int* arr = createArray(a);

    int c;
    std::cout << "Would you like to perform :" << std::endl;
    std::cout << "[1] Linear Search" << std::endl;
    std::cout << "[2] Binary Search" << std::endl;
    std::cin >> c; 
    if( c == 1 ){
        linSearch(arr, a, b);
    } else if ( c == 2 ){
        binSearch(arr, a, b);
    } 
    
   

    delete[] arr; 
    return 0;
}
