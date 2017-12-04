//Melissa Coblentz
//Project 5

#include "./Button.h"

#include<string>

Button::Button(){
	Button::setText("");
}

Button::Button(string text){
	Button::setText(text);
}

void Button::setText(string text){
	_text = text;
}

const string& Button::text() const{
	return _text;
}