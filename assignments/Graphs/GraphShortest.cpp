//Programmer: Hao Tran
//ID: 1872272

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
  string name;

  bool isVisited;
  list<pair<int, double> > neighbors;
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over neighbors
// TO DO -- write this function

  //initalize the database 
  for(int i = 0; i < database.size(); i++){
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }
  queue<int> toDo;
  database[iStart].isVisited = true;
  toDo.push(iStart);

  //search database 
  while(!toDo.empty()){
    int popIndex = toDo.front();
    toDo.pop();
    for (pair<int, double> &neb : database[popIndex].neighbors){
      if(database[neb.first].isVisited){
        continue;
      }
      database[neb.first].cost = database[popIndex].cost + 1;
      database[neb.first].prev = popIndex;
      toDo.push(neb.first);
      database[neb.first].isVisited = true;
      if(neb.first == iEnd){
        while(!toDo.empty()){
          toDo.pop();
        }
        break;
      }
    }
  }
  result.second = database[iEnd].cost;
  int nextIndex = iEnd;
  while(nextIndex != iStart){
    result.first.push(nextIndex);
    nextIndex = database[nextIndex].prev;
  }
  result.first.push(iStart);
  return result;
}

int main()
{
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;  
  
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  vector<Node> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    // add nodes for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
      database.push_back(fromNode);
    }
    iFromNode = i; 

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = {toCity};
      database.push_back(toNode);
    }
    iToNode = i; 

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
    database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    cout << "Route";
    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    for (; !result.first.empty(); result.first.pop())
      cout << '-' << database[result.first.top()].name;
    cout << "Total edges: " << result.second;  
    cout << endl;
  }
}
