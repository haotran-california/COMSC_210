//Programmer: Hao Tran
//ID: 1872272

//Question: the power to enter people's dreams 

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "DynamicArray.h"

using namespace std; 

#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>


//function prototypes
void swap(double *xp, double *yp); 
DynamicArray<double> bubbleSort(DynamicArray<double> arr, int n);

int main(){
  srand(time(0)); rand(); //seed number generator 

  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  string bigOh = "O(n log n)";

  //output formating 
  cout.setf(ios::fixed); 
  cout.precision(4); 
  double elapsedSecondsNorm = 0; 
  double expectedSeconds = 0; 
  int n = 1000; 

  //cycle through 4 times 
  clock_t startTime = clock(); 
  int cycle = 0; 
  DynamicArray<double> randomArray; 
  DynamicArray<double> sortedArray; 

  for(cycle = 0; cycle < 4; cycle++, n *= 2){
    //populate the array with n ramdom elements
    for(int i = 0; i < n; i++){
      randomArray[i] = rand(); 
    }
    sortedArray = bubbleSort(randomArray, n); 
    clock_t endTime = clock();

    //check that the array is sorted correctly  
    for (int i = 1; i < n; i++) assert(sortedArray[i - 1] <= sortedArray[i]);

    //compute timing results 
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC; 
    double factor = pow(2.0, double(cycle)); 

    if(cycle == 0){
      elapsedSecondsNorm = elapsedSeconds; 
    }else if(bigOh == "O(n)"){
      expectedSeconds = factor * elapsedSecondsNorm; 
    }else if(bigOh == "O(n log n)"){
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm; 
    }

    //reporting block
    cout << elapsedSeconds; 
    if(cycle == 0) cout << " (expected " << bigOh << ")"; 
    else cout << " (expected " << expectedSeconds << ")"; 
    cout << "for n=" << n << endl; 
    }
}

//function definitions 
void swap(double *xp, double *yp){
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

DynamicArray<double> bubbleSort(DynamicArray<double> arr, int n){
    int i, j;
    double a, b, temp; 
    for (i = 0; i < n-1; i++){    
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]); 
            // temp = arr[j]; 
            // arr[j] = arr[j + 1]; 
            // arr[j + 1] = temp; 

    }

    return arr; 
}
