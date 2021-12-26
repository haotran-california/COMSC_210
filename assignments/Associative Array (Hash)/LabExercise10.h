//Programmer: Hao Tran
//ID: 1872272
//array implementation of associative array 
//excited to read Dune because of the upcoming movie 

#ifndef AssociativeArray_H
#define AssociativeArray_H

#include <queue>
using namespace std;

template <typename K, typename V>
class AssociativeArray{
  struct Node
  {
    K key;
    V value;
    bool inUse; 
  };

  Node* values; 
  int siz; 
  int cap; 
  void capacity(int); 

public:
  AssociativeArray(int = 2);
  AssociativeArray(const AssociativeArray<K, V> &); 
  AssociativeArray<K, V>& operator=(const AssociativeArray<K, V> &); 
  ~AssociativeArray(); 
  V operator[](const K&) const; 
  V& operator[](const K&); 
  bool containsKey(const K&) const; 
  void deleteKey(const K&); 
  queue<K> keys() const;
  int size() const; 
  void clear(); 
};

template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const{
  for(int i = 0; i < cap; i++){
    if(values[i].key == key && values[i].inUse){
        return values[i].value; 
    }
  }
  return V(); 
}

template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const{
  for(int i = 0; i < cap; i++){
    if(values[i].key == key && values[i].inUse){
        return true; 
    }
  }
  return false; 
}

template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key){
  for(int i = 0; i < cap; i++){
    if(values[i].key == key && values[i].inUse){
        values[i].inUse = false;  
    }
  }
}

template <typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key){
  int unusedIndex = cap; 
  for(int i = 0; i < cap; i++){
    if(values[i].inUse == true){
      if(values[i].key == key){
        return values[i].value; 
        }
    }else if(unusedIndex == cap){
      unusedIndex = i; 
    }
  }
  if(unusedIndex == cap) capacity(cap * 2); 
  values[unusedIndex].key = key; 
  values[unusedIndex].inUsed = true; siz++
  return values[unusedIndex].value; 
}

template <typename K, typename V>
queue<K> AssociativeArray<K, V>::keys() const{
  queue<K> keyQueue; 
  for(int i = 0; i < cap; i++){
    if(values[i].inUse){
      keyQueue.push(values[i].key; 
    }
  }
  return keyQueue; 
}

template <typename K, typename V>
void AssociativeArray<K, V>::clear(){
  for(int i = 0; i < cap; i++){
    values[i].inUse = false; 
  }
  int siz = 0; 
}

#endif

