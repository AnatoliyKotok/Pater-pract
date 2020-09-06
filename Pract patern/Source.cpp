#include<iostream>
#include"CarStore.h"
using namespace std;

int main() {
	Account account(100'000, "1234");

	CarBilder carBilder;
	Director director(&carBilder);
	Client client(director,&account);
	client.order(123, 40'000, "Skin", "Mercedes");
	Car* car = carBilder.getResult();
	car->print();
	client.pay(40001,"1234");
}