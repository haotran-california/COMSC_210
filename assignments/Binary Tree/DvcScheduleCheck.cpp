//Programmer: Hao Tran
//ID: 1872272

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#include <cstring> 

int main() {
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  // for parsing the inputfile
  char *token;
  char buf[1000];
  const char *const tab = "\t";

  // open the input file
  ifstream fin;

  //  fin.open("test-sched.txt");
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  map<string, map<string, set<string> > > records;

  // read the input file
  while (fin.good()) {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    records[term][section].insert(course);
  }
  fin.close();

  cout << endl;
  cout << "The program will print out how many, if any, term-section pairs there are with multiple courses associated with them." << endl;
  cout << endl;

  for (auto it1 : records) {
    //it1.first is first key, string
    for(auto it2 : it1.second) {
      //it2.first is second key, string
      //it2.second is second data, set
      set<string> v = it2.second;
      if(v.size() > 1){
        cout << "Invalid entries have been found in " << it1.first << ": " << endl;
        for(auto itt : v){
         cout << ".." << itt << "-" << it2.first << endl;
        }
      }
    }
  }
}