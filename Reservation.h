#pragma once
#include<iostream>
#include<string>
#include "Vehicle.h"
#include "Customer.h"

class Reservation {
public:
	Reservation();
	Reservation(int idCustomer, int idVehicle, int transactionValue, int rentDays);
	~Reservation();

	void setIdReservation(int idReservation);
	void setIdVehicle(int idVehicle);
	void setIdCustomer(int idCustomer);
	void setTransactionValue(double transactionValue);
	void setRentDays(int rentDays);
	void setStatus(std::string status);

	int getIdReservation() const;
	int getIdVehicle() const;
	int getIdCustomer() const;
	double getTransactionValue() const;
	int getRentDays() const;
	std::string getStatus() const;

	template <typename T>
	void makeReservation(T storage);

	template <typename T>
	void cancelReservation(T storage);

	template <typename T>
	static void displayReservations(T storage);

private:
	int idReservation;
	double transactionValue;
	int rentDays;
	std::string status;
	Vehicle vehicle;
	Customer customer;
};

