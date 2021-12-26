//Programmer: Hao Tran
//ID: 1872272

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <queue> 
using namespace std; 

template <typename K, typename V, int CAP>
class HashTable{
  struct Node
  {
    K key;
    V value;
  };

  list<Node> data[CAP]; //chaining  
  int(*hashCode)(const K&); // ptr to hashCode function 
  int siz;
  Node dummy;

public:
  HashTable(int(*)(const K&)=0); // =0 for default contructor 
  double loadFactor() const {return 1.0 * size / CAP;}
  V operator[](const K&) const; // getter
  V& operator[](const K&); // setter
  bool containsKey(const K&) const; // getter
  void deleteKey(const K&); // setter
  queue<K> keys() const;
  int size() const {return siz;}
  void clear();
};

template <typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[](const K& key) const{
  int index = hashCode(key) % CAP; //index within CAP
  typename list<Node>::const_iterator it; 
  for( it = data[index].begin(); it != data[index].end(); it++){
    return it->value; 
  }
  return V(); 
}

template <typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K& key) const{
  int index = hashCode(key) % CAP; //index within CAP
  typename list<Node>::const_iterator it; 
  for( it = data[index].begin(); it != data[index].end(); it++){
    return true; 
  }
  return false; 
}

template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K& key){
  int index = hashCode(key) % CAP; //index within CAP
  typename list<Node>::iterator it; 
  for( it = data[index].begin(); it != data[index].end(); it++){
    break; 
  }
  if(it != data[index].end()){
    data[index].erase(it); 
    siz --; 
  } 
}

template <typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[](const K& key){
  int index = hashCode(key) % CAP; //index within CAP
  typename list<Node>::iterator it; 
  for( it = data[index].begin(); it != data[index].end(); it++){
    return it->value; 
  }
  Node temp = {key, V()}; 
  data[index].push_back(temp); 
  siz++; 
  return.data[index].back().value; 
}

template <typename K, typename V, int CAP>
queue<K> HashTable<K, V, CAP>::keys() const{
  queue<K> key_queue;
  typename list<Node>::const_iterator it;
  for(int i = 0; i < CAP; i++){
    for (it = data[i].begin(); it != data[i].end(); ++it) {
      key_queue.push(it->key);
    }
  }
  return key_queue;
}

template <typename K, typename V, int CAP> 
void HashTable<K, V, CAP>::clear(){
  for(int i = 0; i < siz; i++) {
      data[i].clear();
  }
  siz = 0; 
}

#endif