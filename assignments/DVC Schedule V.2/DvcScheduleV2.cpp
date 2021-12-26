//Programmer: Hao Tran
//ID: 1872272
//Mathew: The Interview, Anish: Avengers End Game, Thomas: Avengers 

#include <iostream>
#include <string>
#include <fstream>
#include "DynamicArray.h"
#include "StaticArray.h"
using namespace std;

#include <cstring>

//structs 
struct subject {
  string subjectCode;
  int count;
};

struct termSection {
  string term;
  int numberOfSectionSeen;
  DynamicArray < string > seenSectionNumber;
};

//prototypes
StaticArray < termSection, 100 > alreadySeen;
DynamicArray < string > subjectCount(100);
DynamicArray < string > nonDuplicateClasses;
DynamicArray < subject > subjectCounts;
DynamicArray < subject > sortedCopy;
DynamicArray < subject > bubbleSort(DynamicArray < subject > , int);

int main() {
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 ";
  cout << "File: " << __FILE__ << endl;

  //variables for parsing input file 
  char * token;
  char buf[1000];
  const char *
  const tab = "\t";
  int lines;
  int count = 0;
  int s_count = 0;
  int duplicates = 0;
  int classIndex = 0;
  int subjectIndex = 0;
  int numberOfTerm = 0;

  //open file 
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  //read input file 
  while (fin.good()) {
    lines++;
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());

    if (buf[0] == 0) continue; //skip blank lines 

    if (lines % 1000 == 0) { //load bar every 1000 lines
      cout << ".";
      cout.flush();
    }

    //parsing the line
    const string term(token = strtok(buf, tab));
    const string section((token = strtok(0, tab)) ? token : "");
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue;
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    string classCode = term + section;

    //count lines 
    count++;

    int i = 0;
    int j = 0;
    bool d_check = false;
    for (i = 0; i < numberOfTerm; i++) {
      if (alreadySeen[i].term == term) {
        break;
      }
    }

    if (i == numberOfTerm) {
      alreadySeen[i] = {
        term,
        1
      };
      alreadySeen[i].seenSectionNumber[0] = section;
      numberOfTerm++;
    } else {
      for (int j = 0; j < alreadySeen[i].numberOfSectionSeen; j++) {
        if (alreadySeen[i].seenSectionNumber[j] == section) {
          d_check = true;
          duplicates++;
          break;
        }
      }
      if (j == alreadySeen[i].numberOfSectionSeen) {
        alreadySeen[i].seenSectionNumber[j] = section;
        alreadySeen[i].numberOfSectionSeen++;
      }
    }
    if (d_check) continue;

    //find subject code 
    int s = 0;
    for (s = 0; s < subjectIndex; s++) {
      if (subjectCounts[s].subjectCode == subjectCode) {
        subjectCounts[s].count++;
        break;
      }
    }

    if (s == subjectIndex) {
      subjectCount[subjectIndex++] = {
        subjectCode,
        1
      };
    }
  }
    //count the number of subjects 
    cout << "Finished!" << endl;
    for (int k = 0; k < subjectCounts.capacity(); k++) {
      if (subjectCounts[k].count != 0) {
        s_count++;
      }
    }

    //sort the subjects into new array 
    sortedCopy = bubbleSort(subjectCounts, s_count);
  

  //output 
  cout << "Finished!" << endl; 
  for (int k = 0; k < s_count; k++) {
    if (sortedCopy[k].count != 0) {
      cout << sortedCopy[k].subjectCode << ", " << sortedCopy[k].count << endl;
    }
  }

  cout << "Total duplication: " << duplicates << endl;

}

//function definition
DynamicArray < subject > bubbleSort(DynamicArray < subject > s, int n) {
  bool swap;
  string temp;

  do {
    swap = false;
    for (int i = 1; i < n; i++) {
      if (s[i].subjectCode < s[i - 1].subjectCode) {
        temp = s[i - 1].subjectCode;
        s[i - 1].subjectCode = s[i].subjectCode;
        s[i].subjectCode = temp;
        swap = true;
      }
    }
  } while (swap);

  return s;
}