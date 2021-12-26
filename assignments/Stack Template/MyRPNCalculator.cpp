//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

#include "Stack.h"

//function prototypes 
vector<string> parseString(string); 
vector<string> takeInput(); 
double calculate(string, double, double); 


int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  Stack<double> stack; 
  Stack<string> temp;
  vector<string>input; 
  vector<string>tokens; 

  input = takeInput(); 
  int i = 0; 
  double operand1; 
  double operand2; 
  string line = ""; 

  for(i = 0; i < input.size(); i++){
    if(input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/" && stack.size() >= 2){
      cout << stack.size() << endl; 
        operand2 = stack.peek(); 
        stack.pop(); 
        operand1 = stack.peek();
        stack.pop();
      cout << stack.size() << endl; 
        cout << operand2 << endl; 
        cout << operand1 << endl; 
        cout << calculate(input[i], operand1, operand2) << endl; 
    }else{
      stack.push(atof(input[i].c_str())); 
    }
  }

  //cout << "RESULT " << stack.peek(); 


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
    cout << "Enter (Q to quit):"; 
    getline(cin, input); 
    results.push_back(input); 
    if(input == "Q" || input == "q" ){
      again = false; 
    }
  }

  return results; 
}

double calculate(string sign, double operand1, double operand2){
  if(sign == "+") return operand1 + operand2; 
  if(sign == "-") return operand1 - operand2; 
  if(sign == "*") return operand1 * operand2;
  if(sign == "/") return operand1 / operand2; 
  return -1; 
} 



