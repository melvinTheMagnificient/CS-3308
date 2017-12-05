//Melissa Coblentz

#pragma once

template <typename Type>
class SmartPtr{
public:
	SmartPtr(){
		_ref = NULL;
		_numReferences = NULL;
	}

	SmartPtr(Type* ref){
		_ref = ref;
		_numReferences = new int(1);
	}

	SmartPtr(const Type& c){
		copy(c);
		_numReferences++;
	}

	~SmartPtr(){
		_numReferences--;
		if(_numReferences == 0){
			delete _ref;
			delete _numReferences;
		}
	}

	Type* get(){
		return _ref;
	}

	SmartPtr& operator=(const SmartPtr& r) {
    	return copy(r);
  	}

	Type* operator->(){
		return _ref;
	}

	Type& operator*(){
		return *_ref;
	}

private:
	Type* _ref;
	int* _numReferences;

	SmartPtr& copy(SmartPtr& c){
		this->_ref = c._ref;
		this->_numReferences = c._numReferences;
		this->_numReferences++;
		return *this;
	}
};