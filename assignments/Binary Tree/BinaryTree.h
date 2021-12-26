//Programmer: Hao Tran
//ID: 1872272

#ifndef BinaryTree_H
#define BinaryTree_H

#include <queue>
using namespace std;

template <typename K, typename V>
class BinarySearchTree{

  struct Node{
  K key; 
  V value; 
  Node *left; 
  Node *right 
  }

Node* rootNode; 
int siz; 
void Keys(const Node*, queue<K> &) const; 
void clear(Node*); 
void copyTree(Node*, const Node*); 

public: 
BinarySearchTree(){rootNode = 0; siz = 0;}
BinarySearchTree(const BinarySearchTree&); 
BinarySearchTree<K, V>& operator=(const BinarySearchTree<K, V>&); 
~BinarySearchTree(); 

int size() {return siz;}
V operator[ ] (const K&) const; 
V& operator[ ] (const K&); 
bool containsKey(const K&) const; 
void deleteKey(const K&); 
queue<K> Keys() const; 
void clear(); 

};

//getter s
template <typename K, typename V>
V BinarySearchTree<K, V>::operator[](const K& key) const{
  Node* p = rootNode; 
  while(p){
    if(p->key == key) return p->value; 
    else if(p-> key > key) p = p->left; 
    else p = p->right; 
  }
  return false; 
}

template <typename K, typename V>
V BinarySearchTree<K, V>::operator[](const K& key) const{
  Node* p = rootNode; 
  while(p){
    if(p->key == key) return p->value; 
    else if (p-> key > key) p = p-> left; 
    else p = p->right; 
  }
  return V(); 
}

template <typename K, typename V>
V& BinarySearchTree<K, V>::operator[](const K& key){
  Node* p = rootNode; 
  Node* prev = 0; 

  while(p){
    if(p->key == key) return p->value; 
    prev = p; 
    if (p->key > key) p = p-> left; 
    else p = p->right; 
  }

  return V(); 
}

template <typename K, typename V>
V& BinarySearchTree<K, V>::operator[](const K& key){
  Node* p = rootNode; 
  Node* prev = 0; 

  while(p){
    if(p->key == key) return p->value; 
    prev = p; 
    if (p->key > key) p = p-> left; 
    else p = p->right; 

    //add the new node 
    Node* temp = new Node{key, V()}; siz++; 
    //add as root node 
    if(prev == 0){
      rootNode = temp; 
    }else{
      if(prev == 0) prev->right = temp; 
      else prev->left = temp; 
    }
  }
  return temp->value; 
}

template <typename K, typename V>
void BinarySearchTree<K, V>::deleteKey(const K& key){
  Node* p = rootNode; 
  Node* prev = 0; 

  while(p){
    if(p->key == key) break; //found it 
    prev = p; 
    if(p->key < key) p = p->right; 
    else p = p->left; 
  }

  if(!p) return; //case 1: not found 

  if(p->left == 0){
    if(p->right == 0){
      if(prev == 0) rootNode = 0; 
      if(prev->left == p) prev->left = 0; 
      else prev->right = 0; 

      delete p; 
      siz --; 
      return; 
    }
  }
}

#endif