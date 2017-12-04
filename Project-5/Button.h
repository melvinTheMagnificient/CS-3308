//Melissa Coblentz
//Project 5

#pragma once

#include <string>

using namespace std;

class Button {
public:
	Button();
	Button(string text);

	void setText(string text);
	virtual const string& text() const;

private:
	string _text;
};