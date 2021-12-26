//Programmer: Hao Tran
//ID: 1872272

//Question: the power to enter people's dreams 

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>

int main(){
  srand(time(0)); rand(); //seed number generator 

  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  string bigOh = "O(n)";

  //output formating 
  cout.setf(ios::fixed); 
  cout.precision(4); 
  double elapsedSecondsNorm = 0; 
  double expectedSeconds = 0; 
  int n = 8000; 

  //cycle through n lines of file and output time
  clock_t startTime = clock(); 
  for(int cycle = 0; cycle < 4; cycle++, n *= 2){

    //open file 
    ifstream fin; 
    fin.open("dvc-schedule.txt");

    //read n lines of input file
    for(int i = 0; i < n; i++){
      string line; 
      getline(fin, line); 
    }
    fin.close();

    clock_t endTime = clock(); 

    //compute timing results 
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC; 
    double factor = pow(2.0, double(cycle)); 
    if(cycle == 0){
        elapsedSecondsNorm = elapsedSeconds; 
    }else if(bigOh == "O(n)"){
        expectedSeconds = factor * elapsedSecondsNorm; 
    }

    //reporting block
    cout << elapsedSeconds; 
    if(cycle == 0) cout << " (expected " << bigOh << ")"; 
    else cout << " (expected " << expectedSeconds << ")"; 
    cout << "for n=" << n << endl; 
  }
}