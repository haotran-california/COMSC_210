//Programmer: Hao Tran
//ID: 1872272

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#include <cstring> // for strtok and strcpy

#include "AssociativeArray.h"

int main() {
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  //for parsing the inputfile
  char *token;
  char buf[1000];
  const char *const tab = "\t";

  //open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  AssociativeArray<string, AssociativeArray<string, bool> > alreadySeen;
  AssociativeArray<string, AssociativeArray<string, int> > record;
  int duprecord = 0;

  //read input file
  while (fin.good()) {
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

    // using associative array
    if (alreadySeen[term].containsKey(section)){
      duprecord++;
    }
    else{
      alreadySeen[term][section] = true;
      record[subjectCode][course]++;
    }
  }
  fin.close();
  
  AssociativeArray<int, string> rsKeys;
  queue<string> qs = record.keys();
  for(unsigned int i = 0; !qs.empty(); i++){
    rsKeys[i] = qs.front();
    qs.pop();
  }
  
  for(int i = 0; i < rsKeys.size(); i++){
    for(int j = i + 1; j < rsKeys.size(); j++){
      if(rsKeys[i] > rsKeys[j]){
        swap(rsKeys[i], rsKeys[j]);
      }
    }
  }  

  for(int i = 0; i < record.size(); i++){
    int numBlank = 0;

    //innner set of keys, is all actual classes, i.e. SUBJ-###
    AssociativeArray<int, string> rcKeys;
    queue<string> qc = record[rsKeys[i]].keys();
    for(unsigned int i = 0; !qc.empty(); i++){
      rcKeys[i] = qc.front();
      qc.pop();
    }
    
    for(int x = 0; x < record[rsKeys[i]].size(); x++){
      for(int y = x + 1; y < record[rsKeys[i]].size(); y++){
        if(rcKeys[x] > rcKeys[y]){
          swap(rcKeys[x], rcKeys[y]);
        }
      }
    }

    AssociativeArray<int, string> outputs;
  
    for(int j = 0; j < record[rsKeys[i]].size(); j++){
      string s = "  " + rcKeys[j] + ", " + to_string(record[rsKeys[i]][rcKeys[j]]) + " section(s)";
      outputs[j] = s;
    }

    if(rsKeys[i] != "" && (record[rsKeys[i]].size()) > 0){
      cout << rsKeys[i] << ", " << record[rsKeys[i]].size() << " course(s)" << endl;
    }
    for(int z = 0; z < outputs.size(); z++){
      cout << outputs[z] << endl;
    }
  }

  cout  << "Number of duplicates: " << duprecord << endl;
}