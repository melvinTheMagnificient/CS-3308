//Melissa Coblentz
//Project 5

#include "./RadioButton.h"
#include "./Button.h"

#include <string>


RadioButton::RadioButton():Button(){
	_rbText = "Choice " + Button::text();
}

RadioButton::RadioButton(string text):Button(text){
	_rbText = "Choice " + Button::text();
}

const string& RadioButton::text() const{
	return _rbText;
}