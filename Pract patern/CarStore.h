#pragma once
#include<iostream>
#include<string>
#include"Car.h"
using namespace std;
//Used billder and Proxy
__interface ICreate {
	void reset();
	void setComplet(double engen, double price, const string& salon);
	void setMark(const string& mark);
};
__interface IPay {

	void pay(double sum,const string &pin);
};
class Car;
class CarBilder :public ICreate {
	Car* car=nullptr;
public:
	void reset()override {
		car = new Car;
	}
	void setComplet(double engen, double price, const string& salon) {
		car->setComplet(engen, price, salon);
	}
	void setMark(const string& mark) {
		car->setMark(mark);
	}
	Car* getResult() {
		return car;
	}
};
class ManualBillder :public ICreate {
	string manual;
public:
	void reset()override {
		manual = "Start of buillding";
	}
	void setComplet(double engen, double price, const string& salon)override {
		manual.append("Complectation:\n  " + std::to_string(engen) + "\n  " + std::to_string(price) + "\n  " + salon + "\n");
	}
	void setMark(const string& mark)override {
		manual.append("Mark->" + mark + "\n");
	}
	string getResult()const {
		return manual;
	}
};
class Director {
	ICreate* billder = nullptr;
public:
	Director(ICreate* billder) :billder(billder) {

	}
	void changeBillder(ICreate* billder) {
		this->billder = billder;
	}
	void make(double engen,double price,const string&salon,const string&mark) {
		if (billder == nullptr)
			throw exception("Billder not exists");
		billder->reset();
		billder->setComplet(engen, price, salon);
		billder->setMark(mark);

	}
};

class Account :public IPay {
	string pin;
	double cash;
	
public:
	Account(double cash,const string& pin) :pin(pin), cash(cash) {

	}
	void pay(double sum,const string&pin) {
		if (sum <= cash && pin == this->pin) {
			cash -= sum;
			cout << "You took off->" << sum << endl;
			cout << "Remainder->" << cash << endl;
		}
		else {
			cout << "Incorect info" << endl;
		}
	}

};
class Client :public IPay {
	Director director;
	Account* account;
	double price;
public:
	Client(Director director, Account* account) :director(director), account(account) {}
	void order(double engen, double price, const string& salon, const string& mark) {
		this->price = price;
		director.make(engen, price, salon, mark);
		
	}
	void pay(double sum,const string& pin) {
		if (sum == this->price) {
			account->pay(sum, pin);
		}
		else {
			cout << "Incorect info" << endl;
		}
	}
	
};