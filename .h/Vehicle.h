#pragma once
#include<iostream>
#include<string>

class Vehicle {
public:
	Vehicle();
	Vehicle(std::string make, std::string model, std::string  transmissionType,
			   int manufactoringYear, int passengerCapacity, double ratePerDay);
	~Vehicle();

	void setIdVehicle(int idVehicle);
	void setMake(std::string make);
	void setModel(std::string model);
	void setTransmissionType(std::string transmissionType);
	void setManufactoringYear(int manufactoringYear);
	void setPassengerCapacity(int passengerCapacity);
	void setRatePerDay(double ratePerDay);
	void setStatusVehicle(std::string statusVehicle);

	int getIdVehicle() const;
	std::string getMake() const;
	std::string getModel() const;
	std::string getTransmissionType() const;
	int getManufactoringYear() const;
	int getPassengerCapacity() const;
	double getRatePerDay() const;
	std::string getStatusVehicle() const;

	template <typename T>
	void addVehicle(T storage);

	template <typename T>
	void deleteVehicle(T storage);

	template <typename T>
	static void displayVehicles(T storage);

private:
	int idVehicle;
	std::string make;
	std::string model;
	std::string transmissonType;
	int manufactoringYear;
	int passengerCapacity;
	double ratePerDay;
	std::string statusVehicle;
};