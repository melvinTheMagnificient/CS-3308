//Melissa Coblentz
//Project 5

#pragma once

template <typename Type>
class DynArray {
 public:
  DynArray(){  	
  	_size = 0;
  	_capacity = 4;
  	_dynArray = new Type[_capacity];
  }

  int size(){
  	return _size;
  }

  int capacity(){
  	return _capacity;
  }

  Type get(int element){
  	return 	_dynArray[element];
  }

  void add(Type num){
  	_dynArray[_size]=num;
  	++_size;

  	if(_size>_capacity){  	

  		_capacity = _capacity*2;
  		Type* _tempArray = new Type[_capacity];

  		for(int i = 0; i<=_size;++i){
  			_tempArray[i] = _dynArray[i];
  		}	

  		delete [] _dynArray;
  		
  		_dynArray=new Type[_capacity];

  		for(int i = 0; i <= _size;i++){
  			_dynArray[i] = _tempArray[i];
  		}

  		delete [] _tempArray;
  	}
  }

 private:
 	Type* _dynArray;	
 	int _size;
 	int _capacity;
};