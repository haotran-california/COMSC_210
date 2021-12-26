//Programmer: Hao Tran
//ID: 1872272
//Question: the power to enter people's dreams 

#include <iostream>
#include <string>
#include <fstream>
#include "DynamicArray.h"
using namespace std; 

#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>

//structs 
struct subject{
  string subjectCode; 
  int count; 
}; 

//prototypes
DynamicArray<string> nonDuplicateClasses; 
DynamicArray<subject> subjectCount; 

int main(){
  srand(time(0)); rand(); //seed number generator 

  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  string bigOh = "O(n^2)";

  //variables for parsing input file 
  char* token; 
  char buf[1000]; 
  const char* const tab = "\t"; 
  int lines; 
  int classIndex = 0; 
  int subjectIndex = 0; 
  int duplicates = 0; 

  //output formating 
  cout.setf(ios::fixed); 
  cout.precision(4); 
  double elapsedSecondsNorm = 0; 
  double expectedSeconds = 0; 
  int n = 800; 

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
      strcpy(buf, line.c_str()); 

      if(buf[0] == 0) continue; //skip blank lines 

      //parsing the line
      const string term(token = strtok(buf, tab)); 
      const string section((token = strtok(0, tab)) ? token : ""); 
      const string course((token = strtok(0, tab)) ? token : ""); 
      const string instructor((token = strtok(0, tab)) ? token : ""); 
      const string whenWhere((token = strtok(0, tab)) ? token : ""); 
      if (course.find('-') == string::npos) continue; 
      const string subjectCode(course.begin(), course.begin() + course.find('-')); 
      string classCode = term + section; 

      //check for duplicates 
      for(int i = 0; i < classIndex + 1; i++){
        //if any duplicates found then increment duplicates and break 
        if(nonDuplicateClasses[i] == classCode){
          duplicates++; 
          break; 
        }
        //if last index is reached add class code to the end of array 
        if(i == classIndex){
          nonDuplicateClasses[classIndex] = classCode; 
        }
      }
      classIndex++; 

      //find subject code 
      int s = 0; 
      for(s = 0; s < subjectIndex; s++){
        if(subjectCount[s].subjectCode == subjectCode){
          subjectCount[s].count ++; 
          break; 
        }
      }
      
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
    }else if(bigOh == "O(n^2)"){
      expectedSeconds = factor * factor * elapsedSecondsNorm; 
    }

    //reporting block
    cout << elapsedSeconds; 
    if(cycle == 0) cout << " (expected " << bigOh << ")"; 
    else cout << " (expected " << expectedSeconds << ")"; 
    cout << "for n=" << n << endl; 
  }
}