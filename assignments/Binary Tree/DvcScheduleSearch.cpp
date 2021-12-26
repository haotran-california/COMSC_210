//Programmer: Hao Tran
//ID: 1872272

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

#include <cstring> 

vector<string> parser(const string& uInput, const string& delim) {
  vector<string> inputs;
  inputs.push_back(uInput.substr(0, uInput.find(delim)));
  inputs.push_back(uInput.substr(uInput.find(delim)+1,uInput.length()));
  return inputs;
}

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
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  map<string, map<string, vector<string> > > records;

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
    records[subjectCode][course].push_back(term);
  }
  fin.close();

  cout << "Enter a SubjectCode-#, like COMSC-210. Also, enter x to quit." << endl;
  cout << endl;
  string uInput;

  do {
    cout << "SubjectCode-#: ";
    cin >> uInput;
    vector<string> v = records[parser(uInput, "-")[0]][uInput];

    if(!v.empty()) {
      string latest = v.front();
      for (auto it : v) {
          vector<string> curParts = parser(it, " ");
          vector<string> latestParts = parser(latest, " ");
          if (curParts[1] >= latestParts[1]) {
            if (curParts[1] == latestParts[1]) {
              if (curParts[0] == "Spring" || (curParts[0] == "Summer" && latestParts[0] == "Fall")) {
                latest = it;
              }
            }
            else {
              latest = it;
            }
          }
      }
      vector<string> latestParts = parser(latest, " ");
      cout << uInput << " was last offered in " << latestParts[0] << " " << latestParts[1] << endl;
    }
    else{
      if(uInput != "x" && uInput != "X") {
        cout << uInput << " could not be found as far back as the year 2000" << endl;
      }
    }
  } while(uInput != "x" && uInput != "X");
}