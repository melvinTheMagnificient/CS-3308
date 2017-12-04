// Melissa Coblentz
// Project 4

#include "./interaction.h"
#include "./Person.h"
#include "./Customer.h"
#include "./Employee.h"
#include "./Manager.h"
#include "./Server.h"
#include "./Cook.h"
#include "./Restaurant.h"

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void runInteraction(){

	vector<Person*> people;
	Restaurant* r = new Restaurant();

	people.push_back(new Manager("Joe"));
	people.push_back(new Cook("Jane"));
	people.push_back(new Server("Sally"));
	people.push_back(new Customer("Frank"));
	
	bool dontQuit = true;
	while(dontQuit){
		char action;
		cout<<""<<endl
		<<"Main menu:"<<endl
		<<"------------------------"<<endl
		<<"p = print people"<<endl
		<<"a = add person"<<endl
		<<"r = pay"<<endl
		<<"s = speak"<<endl
		<<"q = quit"<<endl
		<<"Action: ";

		cin>>action;
		cout<<""<<endl;


		if(action == 'p'){
			people = PrintPeople(people);
		} else if(action == 'a'){
			people = AddPerson(people);
		} else if(action == 'r'){
			people = Pay(people, r);
		} else if(action == 's'){
			people = Speak(people);
		} else if(action == 'q'){
			dontQuit = false;
		} else{
			cout<<"";
		}
	}	
}

vector<Person*> PrintPeople(vector<Person*> v){
	cout<<""<<endl
	<<"People:"<<endl
	<<"------------------------"<<endl;

	if(v.capacity()>0){
		int count = 0;
		for(Person* p:v){
			cout<<count<<": "<<p->getName()<<" is a "<<p->getRole()<<endl;
			++count;
		}
	}	
	return v;
}

vector<Person*> AddPerson(vector<Person*> v){
	string name;
	char role;

	cout<<"name: ";
	cin>>name;
	cout<<"	m = manager"<<endl
	<<"	c = cook"<<endl
	<<"	f = server"<<endl
	<<"	u = customer"<<endl
	<<"role: ";
	cin>>role;

	if(role == 'm'){
		v.push_back(new Manager(name));
	} else if(role == 'c'){
		v.push_back(new Cook(name));
	} else if(role == 'f'){
		v.push_back(new Server(name));
	} else if(role == 'u'){
		v.push_back(new Customer(name));
	} else{
		cout<<"Command not recognized"<<endl;
	}

	return v;
}

vector<Person*> Pay(vector<Person*> v, Restaurant* transactionWith){
	int element;
	int amount;
	PrintPeople(v);

	cout<<"Pay which person? (0-"<<v.capacity()-1<<") ";
	cin>>element;
	cout<<"How much? ";
	cin>>amount;

	if(v[element]->getRole() == "Customer"){
		v[element]->pay(amount, transactionWith);
	} else if(transactionWith->getCashOnHand()-amount>=0){
		v[element]->pay(amount, transactionWith);
	} else{
		cout<<"The restaurant does not currently have the means to pay this employee"<<endl;
	}	

	cout<<"The restaurant now has "<<transactionWith->getCashOnHand()
	<<" cash on hand"<<endl;
	return v;
}

vector<Person*> Speak(vector<Person*> v){
	int element;
	PrintPeople(v);

	cout<<"Which person should speak? (0-"<<v.capacity()-1<<") ";
	cin>>element;
	cout<<v[element]->getName()<<" says: "<<v[element]->speak()<<""<<endl;
	return v;
}

void Quit(){

}