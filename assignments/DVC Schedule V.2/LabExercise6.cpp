//Programmer: Hao Tran
//ID: 1872272
//mathew embree: skyline gtr, Henry Olsen: Tesla Model X 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DynamicArray.h"
#include "StaticArray.h"
using namespace std; 

#include <cstring>

struct termSection{
  string term; 
  int numberOfSectionSeen; 
  DynamicArray<string> seenSectionNumber; 
};

struct subject{
  string subjectCode; 
  int count; 
}; 

StaticArray<termSection, 100> alreadySeen; 
DynamicArray<string>subjectCount(100); 

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  //parse input file 
  char* token; 
  char buf[1000]; 
  const char* const tab = "\t"; 
  int lines; 
  
  //open file 
  ifstream fin; 
  fin.open("dvc-schedule.txt"); 
  if(!fin.good()) throw "I/O error"; 

  //read input file 
  while(fin.good()){
      lines++; 
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

      int count = 0; 
      int duplicates = 0; 
      int classIndex = 0; 
      int numberOfTerm = 0; 
    
      int i = 0; 
      int j = 0; 
      bool d_check = false; 
      for(i = 0; i < numberOfTerm; i++){
        if(alreadySeen[i].term == term){
          break;
        }
      }

      if(i == numberOfTerm){
        alreadySeen[i] = {term, 1}; 
        alreadySeen[i].seenSectionNumber[0] = section; 
        numberOfTerm++; 
      }else{
        for(int j = 0; j < alreadySeen[i].numberOfSectionSeen; j++){
          if(alreadySeen[i].seenSectionNumber[j] == section){
            d_check = true; 
            duplicates++; 
            break; 
          } 
        }
        if(j == alreadySeen[i].numberOfSectionSeen){
          alreadySeen[i].seenSectionNumber[j] = section; 
          alreadySeen[i].numberOfSectionSeen++; 
        }
      }
      if(d_check) continue; 
  }
}