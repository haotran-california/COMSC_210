//Programmer: Hao Tran
//ID: 1872272

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include <cmath>
#include <cstdlib>

#include "DynamicArray.h"
#include "Queue.h"

struct Customer{
  char ID; 
  int arrivalT;
  int endT;
};

int getRandomNumberOfArrivals(double);
char genID(char&);

int main()
{
  //programer identification 
  cout << "Programmer: Hao Tran ";
  cout << "ID: 1872272 "; 
  cout << "File: " << __FILE__ << endl;

  srand(time(0));
  rand();

  int numServers = 0;
  double avgArrivalRate = 0.0;
  int waitMaxLength = 0;
  int minServTime = 0;
  int maxServTime = 0;
  int clockStopTime = 0;
  char curAlpha = 'A';
  
  ifstream fin;
  fin.open("simulation.txt");
  
  fin >> numServers;
  fin >> avgArrivalRate;
  fin >> waitMaxLength;
  fin >> minServTime;
  fin >> maxServTime;
  fin >> clockStopTime;
  cout << "number of servers:     " << numServers << endl;
  cout << "customer arrival rate: " << avgArrivalRate << " per minute, for " << clockStopTime << " minutes" << endl;
  cout << "maximum queue length:  " << waitMaxLength << endl;
  cout << "minimum service time:  " << minServTime << " minutes" << endl;
  cout << "maximum service time:  " << maxServTime << " minutes" << endl;
  
  Queue<Customer> customerQ;
  DynamicArray<Customer> nowServing;
  DynamicArray<bool> serversStatus;
  
  for(int time = 0; ;time++){
    // handle all services scheduled to complete at this clock time
    for(int i = 0; i < numServers; i++)
    {
      if (serversStatus[i])
      {
        if(nowServing[i].endT == time)
        {
          serversStatus[i] = false;
        }
      }
    }
    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    if(time < clockStopTime){
      int numArrive = getRandomNumberOfArrivals(avgArrivalRate);
      for(int i = 0; i < numArrive; i++)
      {
        if(customerQ.size() < waitMaxLength)
        {
          Customer c;
          c.ID = genID(curAlpha);
          c.arrivalT = time; 
          customerQ.push(c);
        }
      }
    }
    //for idle servers, move customer from wait queue and begin
    for(int i = 0; i < numServers; i++){
      if(!serversStatus[i] && !customerQ.empty())
      {
        nowServing[i] = customerQ.front();
        customerQ.pop();
        nowServing[i].endT = time + minServTime + rand() % (maxServTime - minServTime + 1);
        serversStatus[i] = true;
      }
    }
    //Find next end of service event
    int nextEOS = nowServing[0].endT;
    int numIdle = 0;
    for(int i = 0; i < numServers; i++){
      if(!serversStatus[i])
      {
        numIdle++;
      }
      else
      {
        if(nextEOS > nowServing[i].endT)
          nextEOS = nowServing[i].endT;
      }
    }
    //output the summary
    if(numIdle == numServers)
      cout << "\nTime: " << time << ", no scheduled end-of-service events at this time\n";
    else
      cout << "\nTime: " << time << ", next end-of-service event at " << nextEOS << " minutes\n";
    cout << "---------------------------" << endl;
    cout << "server now serving wait queue" << endl;
    cout << "------ ----------- ----------" << endl;
    for(int i = 0; i < numServers; i++){
      string show = " ";
      if(serversStatus[i])
      {
        show = nowServing[i].ID;
      }
      cout << setw(2) << i << setw(10) << show;
      if(i == 0)
      {
        Queue<Customer> tempQ = customerQ;
        cout << setw(10);
        while(!tempQ.empty())
        {
          cout << tempQ.front().ID;
          tempQ.pop();
        }
      }
      cout << endl;
    }
    if(numIdle == numServers && time >= clockStopTime){
      cout << "--------------------------";
      cout << "\nDone!\n\n";
      break;
    }
    do{
      cout << "--------------------------";
      cout << "\nPress ENTER to continue...";
    }while (cin.get() != '\n');
  }
}

int getRandomNumberOfArrivals(double averageArrivalRate){
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
  return arrivals;
}
  
char genID(char& curAlpha){
  if(curAlpha == 'Z')
  {
    curAlpha = 'A';
    return 'Z';
  }
  return curAlpha++;
}