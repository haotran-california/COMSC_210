//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include "StaticArray.h"
using namespace std; 

//function prototypes 
vector<string> parseString(string); 
vector<string> takeInput(); 

//vector prototypes  
vector<string> tokens; 
vector<string> input; 

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl; 

  //initalize objects  
  StaticArray<double, 100> array; 
  StaticArray<int, 100> indexes; 

  //initalize variables
  int num = 0; 
  int index; 
  double value; 
  bool repeat = true; 

  //take input 
  input = takeInput(); 

  //iterate through each string in the vector and parse each string into tokens 
  for(int i = 0; i < input.size(); i++){
    vector<string> tokens; 
    tokens = parseString(input[i]); 
    index = atoi(tokens[0].c_str());
    value = atof(tokens[1].c_str());
    if(index > -1 && index < 100){
      indexes[num] = index; 
      num += 1; 
      array[index] = value;  
    }
  }

  //ouput information and index-value pairs 
  cout << "You have stored this many values: " << num - 1 << endl;
  cout << "The index-value pairs are: " << endl;  
  for(int j = 0; j < num - 1; j++){
    int i = indexes[j]; 
    printf("%i => %.2f\n", i, array[i]); 
  }

  //index lookup event loop 
  while(repeat == true){
    string input = ""; 
    int int_input;  
    cout << "Input an index for me to look up [Q to quit]:"; 
    getline(cin, input);  
    int_input = atoi(input.c_str()); 
    if(input == "Q" || input == "q"){
      repeat = false; 
    }else{
      if(array[int_input] != 0){
        printf("Found it-- the value stored at %i is %.2f\n", int_input, array[int_input]); 
      }else{
        cout << "I didn't find it\n"; 
      }
    }
  }
    
}

vector<string> parseString(string str){
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

vector<string> takeInput(){
  vector<string> results; 
  bool again = true; 
  while(again == true){
    string input = ""; 
    cout << "Input an index and a value [Q to quit]:"; 
    getline(cin, input); 
    results.push_back(input); 
    if(input == "Q" || input == "q"){
      again = false; 
    }
  }

  return results; 
}