//Melissa Coblentz

#pragma once

#include <memory>

using std::shared_ptr;

template <typename Type>
class Node{
public:
	Node(Type e){
		_element = e;
    _next = nullptr;
	}

  static shared_ptr<Node> create(Type e){
  	Node* n = new Node(e);
    shared_ptr<Node> ptr(n);
  	return ptr;
  }

  shared_ptr<Node> getNext(){
    return _next;
  }

  void setNext(shared_ptr<Node> n){
    _next = n;
  }

  Type getData(){
    return _element;
  }  

  void insert(shared_ptr<Node> newSecond){
    shared_ptr<Node> temp = this->getNext();
    temp->setNext(temp);
    this->setNext(newSecond);
    newSecond->setNext(temp);
  }

private:
	Type _element;
  shared_ptr<Node> _next;
};