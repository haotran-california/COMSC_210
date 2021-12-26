//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

#include <cstring>

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

      //cout << term << '|' << section << "|" << course << "|" << instructor << "|" << whenWhere << "|" << subjectCode << "|" << endl; 
      //cout << term << " " << section << " " << subjectCode << endl; 
      
  }
  cout << "The total amount of lines processed is: " << lines; 
    
}