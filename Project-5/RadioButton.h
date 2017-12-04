//Melissa Coblentz
//Project 5

#pragma once

#include "./Button.h"

#include <iostream>
#include <string>

using namespace std;

class RadioButton : public Button {
public:
	RadioButton();
	RadioButton(string text);

	const string& text() const;

private:
	string _rbText;
};