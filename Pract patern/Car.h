#pragma once
#include<iostream>
using namespace std;

struct CompletSet {
	double engen;
	double price;
	string salon;
};
struct CarMark {
	string mark;
};
class Car {
	CompletSet car;
	CarMark carMark;
public:
	void setComplet(double engen, double price, const string& salon) {
		car.engen = engen;
		car.price = price;
		car.salon = salon;
	}
	void setMark(const string& mark) {
		carMark.mark = mark;
	}
	void print() {
		cout << "Mark->" << carMark.mark << endl;
		cout << "Engen->" << car.engen << endl;
		cout << "Price->" << car.price << endl;
		cout << "Salon->" << car.salon << endl;
	}
};