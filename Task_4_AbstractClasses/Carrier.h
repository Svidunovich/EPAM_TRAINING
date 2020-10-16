#pragma once
#include <iostream>
#include <bits/stdc++.h>

class Carrier{
	public:
		virtual void setName(std::string name) = 0;
		virtual void getName() = 0;
};

class Passenger : public Carrier{
	public:
		Passenger(int passengers)
			:_passengers(passengers)
		{
		}
		Passenger(){

		}
		void setName(std::string name) override { _name = name; }
		virtual void getName() override {
			std::cout << "Name: " << _name << std::endl;
		}
    	virtual void setPassengers(int passengers) = 0;
		virtual int getPassengers() = 0;
		virtual void setCost(int cost) = 0; 
		virtual void getSumCost() = 0;
		~Passenger(){
			_passengers;
		}
	protected:
		std::string _name;
		int _passengers;
		int _cost;
};


class Cargo : public Carrier{
	public:
		Cargo(int passengers)
			:_passengers(passengers)
		{
		}
		Cargo(){

		}
		void setName(std::string name) override { _name = name; }
		void  getName() override {
			std::cout << "Name: " << _name << std::endl;
		}
		virtual void setPassengers(int passengers) = 0;
		virtual void setCost(int cost) = 0; 
		virtual void getSumCost() = 0;
		virtual int getPassengers() = 0;
		~Cargo(){
			_passengers;
		}
	protected:
		int _cost;
		std::string _name;
		int _passengers;
};

class Bus : public Cargo{
	public:
		Bus(int passengers) : Cargo(passengers)
		{
			_name = "";
		}

		void setPassengers(int passengers) override {
			_passengers = passengers;
		}
		int getPassengers() override {
			return _passengers;
		}	
		void setCost(int cost) override {
			_cost = cost;
		}
		void getSumCost(){
			std::cout << "Full cost: " <<  _cost * _passengers << std::endl;
		}

};

class Plane : public Cargo{
	public:
		Plane(int passengers) : Cargo(passengers)
		{
			_name = "";
		}

		void setPassengers(int passengers) override {
			_passengers = passengers;
		}
		int getPassengers() override {
			return _passengers;
		}	
		void setCost(int cost) override {
			_cost = cost;
		}
		void getSumCost(){
			std::cout << "Full cost: " <<  _cost * _passengers << std::endl;
		}

};

class Train : public Passenger{
	public:
		Train(int passengers) : Passenger(passengers)
		{
			_name = "";
		}

		void setPassengers(int passengers) override {
			_passengers = passengers;
		}
		int getPassengers() override {
			return _passengers;
		}	
		void setCost(int cost) override {
			_cost = cost;
		}
		void getSumCost(){
			std::cout << "Full cost: " <<  _cost * _passengers << std::endl;
		}
};

class Car : public Passenger{
	public:
		Car(int passengers) : Passenger(passengers)
		{
			_name = "";
		}

		void setPassengers(int passengers) override {
			_passengers = passengers;
		}
		int getPassengers() override {
			return _passengers;
		}	
		void setCost(int cost) override {
			_cost = cost;
		}
		void getSumCost(){
			std::cout << "Full cost: " <<  _cost * _passengers << std::endl;
		}

};






