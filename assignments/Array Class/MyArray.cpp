//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std; 

//class declaration
class Array{
  int values[100]; 
  int dummy = 0; 

  public: 
    Array(); 
    int capacity( ) const; 
    int operator[ ](int) const; //getter 
    int& operator[ ](int); //setter 
};

//function prototypes 
vector<string> parseString(string); 
vector<string> tokens; 
vector<string> takeInput(); 
void indexLookUp(); 

int main(){
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  

  //initalize objects and variables 
  Array array;
  Array indexes; 
  int num = 0; 
  int index, value; 
  bool repeat = true; 

  //store all user input inside a vector of strings 
  vector<string>input; 
  input = takeInput(); //user index and value input event loop 

  //iterate through each string in the vector and parse each string into tokens 
  for(int i = 0; i < input.size(); i++){
    vector<string> tokens; 
    tokens = parseString(input[i]); 
    index = atoi(tokens[0].c_str());
    value = atoi(tokens[1].c_str());
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
    printf("%i => %i\n", i, array[i]); 
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
        printf("Found it-- the value stored at %i is %i\n", int_input, array[int_input]); 
      }else{
        cout << "I didn't find it\n"; 
      }
    }
  }
    
}

Array::Array(){
  for(int i = 0; i < 100; i++){
    values[i] = 0; 
  }
}

int Array::capacity() const {
    return 100; 
}

int Array:: operator[] (int index) const{
  if(index < 0 || index > 100){
    return 0; 
  }

  return values[index]; 
}

int& Array:: operator[] (int index){
  if(index < 0 || index >= 100){
    return dummy;  
  }

  return values[index]; //mutable reference 
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






