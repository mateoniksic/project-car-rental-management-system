#include<iostream>
#include<string>
#include<vector>
#include <windows.h>
#include<iomanip>
#include "Customer.h"
#include "Vehicle.h"
#include "Reservation.h"
#include<sqlite_orm/sqlite_orm.h>
using namespace sqlite_orm;

/**
* CUSTOMER CLASS FUNCTIONS
* ----------------------------------------------------------------------
* Functions to create, delete and display customers.
*/
template <typename T>
void Customer::createCustomer(T storage) {
	std::string userInputStr;

	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "CREATING A NEW CUSTOMER" << std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	//Sections
	std::cout << "|_" << std::right << std::setfill(' ') << std::setw(32) << "1. CUSTOMER GENERAL INFORMATION" << std::right << std::setfill(' ') << std::setw(13) << "_ | " << std::endl << std::endl;

	std::cout << " [Input] Customer Name: ";
	std::cin >> this->name;

	std::cout << " [Input] Customer Surname: ";
	std::cin >> this->surname;

	std::cout << " [Input] Date of Birth (format: dd.mm.yyyy.): ";
	std::cin >> this->dateOfBirth;
	std::cout << std::endl;

	std::cout << "|_" << std::right << std::setfill(' ') << std::setw(20) << "2. CUSTOMER ADDRESS" << std::right << std::setfill(' ') << std::setw(25) << "_ | " << std::endl << std::endl;

	std::cout << " [Input] Customer Country: ";
	std::cin >> userInputStr;
	this->address.setCountry(userInputStr);

	std::cout << " [Input] Customer City: ";
	std::cin >> userInputStr;
	this->address.setCity(userInputStr);

	std::cout << " [Input] Customer Postal Code: ";
	std::cin >> userInputStr;
	this->address.setPostalCode(userInputStr);

	std::cout << " [Input] Customer Street (e.g. 55 East 10th Street): ";
	std::cin.ignore(40, '\n');
	std::getline(std::cin, userInputStr);
	this->address.setStreet(userInputStr);
	std::cout << std::endl;

	std::cout << "|_" << std::right << std::setfill(' ') << std::setw(23) << "3. CONTACT INFORMATION" << std::right << std::setfill(' ') << std::setw(22) << "_ | " << std::endl << std::endl;

	std::cout << " [Input] Customer Phone Number (e.g. 0991234567): ";
	std::cin >> this->phoneNumber;

	std::cout << " [Input] Customer Email (e.g. example@example.com): ";
	std::cin >> this->email;
	std::cout << std::endl;

	std::cout << "|_" << std::right << std::setfill(' ') << std::setw(27) << "4. CREDIT CARD INFORMATION" << std::right << std::setfill(' ') << std::setw(18) << "_ | " << std::endl << std::endl;

	std::cout << " [Input] Customer Credit Card Number (16 digits): ";
	std::cin >> userInputStr;
	this->creditCard.setCardNumber(userInputStr);

	std::cout << " [Input] Credit Card Expiry Date (format: mm/yy): ";
	std::cin >> userInputStr;
	this->creditCard.setExpiryDate(userInputStr);
	std::cout << std::endl;

	std::cout << " [Input] Credit Card CVV  (3 digits): ";
	std::cin >> userInputStr;
	this->creditCard.setCvv(userInputStr);


	storage.insert(*this);

	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(34) << "CUSTOMER CREATED SUCESSFULLY!" << std::right << std::setfill(' ') << std::setw(10) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
}

template <typename T>
void Customer::deleteCustomer(T storage) {
	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "DELETE CUSTOMER" << std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	std::cout << " [Input] Customer ID: ";
	std::cin >> this->idCustomer;

	//If user deleted delete reservations
	storage.remove_all<Reservation>(where(c(&Reservation::getIdCustomer) == this->idCustomer));

	storage.remove<Customer>(idCustomer);

	std::cout << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(30) << "CUSTOMER DELETED" << std::right << std::setfill(' ') << std::setw(13) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
} 

template <typename T>
static void Customer::displayCustomers(T storage) {
	auto rows = storage.select(
		columns(&Customer::getIdCustomer, &Customer::getName, &Customer::getSurname,
			        &Customer::getDateOfBirth, &Customer::getCountry, &Customer::getCity, 
					&Customer::getPostalCode, &Customer::getStreet, &Customer::getPhoneNumber, 
					&Customer::getEmail, &Customer::getCreditCardNumber, 
					&Customer::getCreditCardExpiryDate, &Customer::getCreditCardCvv));

	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "CUSTOMER LIST" 
				<< std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	std::cout << std::setfill('_') << std::setw(199) << std::left << " _" << "_" << std::endl
				<<" | " << std::setfill(' ') << std::setw(3) << std::left << "ID"
				 << " | " << std::setw(10) << "Name"
				 << " | " << std::setw(10) << "Surname"
				 << " | " << std::setw(11) << "D.O.B."
				 << " | " << std::setw(10) << "Country"
				 << " | " << std::setw(10) << "City"
				 << " | " << std::setw(11) << "Postal Code"
				 << " | " << std::setw(20) << "Street"
				 << " | " << std::setw(11) << "Phone No."
				 << " | " << std::setw(30) << "Email"
				 << " | " << std::setw(16) << "CC Number"
				 << " | " << std::setw(10) << "CC D.O.E."
				 << " | " << std::setw(7) << "CC CVV"
				 << " | " << std::endl
				 << std::setfill('-') << std::setw(199) << std::left << " |" << "|" << std::endl;
	for (auto& row : rows) {
		std::cout << " | " << std::setfill(' ') << std::setw(3) << std::left << std::get<0>(row)
					<< " | " << std::setw(10) << std::get<1>(row)
					<< " | " << std::setw(10) << std::get<2>(row)
					<< " | " << std::setw(11) << std::get<3>(row)
					<< " | " << std::setw(10) << std::get<4>(row)
					<< " | " << std::setw(10) << std::get<5>(row)
					<< " | " << std::setw(11) << std::get<6>(row)
					<< " | " << std::setw(20) << std::get<7>(row)
					<< " | " << std::setw(11) << std::get<8>(row)
					<< " | " << std::setw(30) << std::get<9>(row)
					<< " | " << std::setw(16) << std::get<10>(row)
					<< " | " << std::setw(10) << std::get<11>(row)
					<< " | " << std::setw(7) << std::get<12>(row)
					<< " | " << std::endl;
	}
	std::cout << std::setfill('_') << std::setw(199) << std::left << " |" << "|" << std::endl;
}

/**
* VEHICLE CLASS FUNCTIONS
* ----------------------------------------------------------------------
* Functions to add, delete and display vehicles.
*/
template <typename T>
void Vehicle::addVehicle(T storage) {
	std::string userInputStr;

	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "ADDING A NEW VEHICLE" << std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	// Sections
	std::cout << "|_" << std::right << std::setfill(' ') << std::setw(32) << "1. VEHICLE GENERAL INFORMATION" << std::right << std::setfill(' ') << std::setw(13) << "_ | " << std::endl << std::endl;

	std::cout << " [Input] Vehicle Model: ";
	std::cin >> this->model;

	std::cout << " [Input] Vehicle Make: ";
	std::cin.ignore(40, '\n');
	std::getline(std::cin, userInputStr);
	this->make = userInputStr;

	std::cout << " [Input] Vehicle Manufactoring Year (e.g. 2022): ";
	std::cin >> this->manufactoringYear;
	std::cout << std::endl;

	std::cout << "|_" << std::right << std::setfill(' ') << std::setw(32) << "1. VEHICLE ADDITIONAL INFORMATION" << std::right << std::setfill(' ') << std::setw(13) << "_ | " << std::endl << std::endl;

	userInputStr = "\0";
	while (userInputStr != "1" && userInputStr != "2") {
		std::cout << " Vehicle Transmission Types: " << std::endl;
		std::cout << " [1] - Manual transmisson" << std::endl;
		std::cout << " [2] - Automatic transmisson" << std::endl;
		std::cout << " [Input] Vehicle Transmission Type: ";
		std::cin >> userInputStr;
		if (userInputStr == "1") {
			this->transmissonType = "manual";
			break;
		}
		else if (userInputStr == "2") {
			this->transmissonType = "automatic";
			break;
		}
		std::cout << " [Error] Please, select the right type of transmission. " << std::endl << std::endl;
	}
	std::cout << std::endl;

	std::cout << " [Input] Vehicle Passenger Capacity (e.g. 4): ";
	std::cin >> this->passengerCapacity;
	std::cout << std::endl;

	std::cout << " [Input] Vehicle Daily Rate in EUR (e.g. 100): ";
	std::cin >> this->ratePerDay;
	std::cout << std::endl;

	storage.insert(*this);

	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(34) << "VEHICLE ADDED SUCESSFULLY!" << std::right << std::setfill(' ') << std::setw(10) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
}

template <typename T>
void Vehicle::deleteVehicle(T storage) {
	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "DELETE VEHICLE" << std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	std::cout << " [Input] Vehicle ID: ";
	std::cin >> this->idVehicle;

	//If vehicle deleted delete reservations
	storage.remove_all<Reservation>(where(c(&Reservation::getIdVehicle) == this->idVehicle));

	storage.remove<Vehicle>(idVehicle);

	std::cout << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(30) << "VEHICLE DELETED" << std::right << std::setfill(' ') << std::setw(13) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
}

template <typename T>
static void Vehicle::displayVehicles(T storage) {
	auto rows = storage.select(
		columns(&Vehicle::getIdVehicle, &Vehicle::getModel, &Vehicle::getMake,
					&Vehicle::getManufactoringYear, &Vehicle::getPassengerCapacity, &Vehicle::getTransmissionType,
					&Vehicle::getRatePerDay, &Vehicle::getStatusVehicle));

	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "VEHICLES LIST"
		<< std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	std::cout << std::setfill('_') << std::setw(98) << std::left << " _" << "_" << std::endl
		<< " | " << std::setfill(' ') << std::setw(3) << std::left << "ID"
		<< " | " << std::setw(10) << "Model"
		<< " | " << std::setw(10) << "Make"
		<< " | " << std::setw(5) << "Year"
		<< " | " << std::setw(11) << "Passengers"
		<< " | " << std::setw(13) << "Transmission"
		<< " | " << std::setw(10) << "EUR / Day"
		<< " | " << std::setw(11) << "Status"
		<< " | " << std::endl
		<< std::setfill('-') << std::setw(98) << std::left << " |" << "|" << std::endl;
	for (auto& row : rows) {
		std::cout << " | " << std::setfill(' ') << std::setw(3) << std::left << std::get<0>(row)
			<< " | " << std::setw(10) << std::get<1>(row)
			<< " | " << std::setw(10) << std::get<2>(row)
			<< " | " << std::setw(5) << std::get<3>(row)
			<< " | " << std::setw(11) << std::get<4>(row)
			<< " | " << std::setw(13) << std::get<5>(row)
			<< " | " << std::setw(10) << std::get<6>(row)
			<< " | " << std::setw(11) << std::get<7>(row)
			<< " | " << std::endl;
	}
	std::cout << std::setfill('_') << std::setw(98) << std::left << " |" << "|" << std::endl;
}

/**
* RESERVATION CLASS FUNCTIONS
* ----------------------------------------------------------------------
* Functions to make, cancel and display reservation.
*/
template <typename T>
void Reservation::makeReservation(T storage) {
	std::string userInputStr;
	int userInputNum;

	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "MAKE A RESERVATION" << std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << std::endl;

	std::cout << " [Input] Customer ID: ";
	std::cin >> userInputNum;
	this->customer.setIdCustomer(userInputNum);

	std::cout << " [Input] Vehicle ID: ";
	std::cin >> userInputNum;

	auto vehicle = storage.get<Vehicle>(userInputNum);
	this->vehicle = vehicle;

	//Change vehicle status
	Vehicle tmpVehicle;
	tmpVehicle = vehicle;
	tmpVehicle.setStatusVehicle("reserved");
	storage.replace(tmpVehicle);
	
	std::cout << " [Input] Days For Rent (e.g. 14) : ";
	std::cin >> rentDays;
	std::cout << std::endl;

	this->setTransactionValue(this->vehicle.getRatePerDay() * rentDays);
	storage.insert(*this);

	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(30) << "RESERVATION COMPLETED" << std::right << std::setfill(' ') << std::setw(13) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
}

template <typename T>
void Reservation::cancelReservation(T storage) {
	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "CANCEL RESERVATION" << std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	int userInputNum;
	std::cout << " [Input] Reservation ID: ";
	std::cin >> userInputNum;
	
	auto reservation = storage.get<Reservation>(userInputNum);

	*this = reservation;
	this->status = "canceled";

	//Change vehicle status
	auto vehicle = storage.get<Vehicle>(this->vehicle.getIdVehicle());
	Vehicle tmpVehicle;
	tmpVehicle = vehicle;
	tmpVehicle.setStatusVehicle("available");
	storage.replace(tmpVehicle);

	storage.update(*this);

	std::cout << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(30) << "RESERVATION CANCELED" << std::right << std::setfill(' ') << std::setw(13) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
}

template <typename T>
static void Reservation::displayReservations(T storage) {
	auto rows = storage.select(
		columns(&Reservation::getIdReservation, &Customer::getName, &Vehicle::getModel,
					&Vehicle::getMake, &Reservation::getRentDays, &Reservation::getTransactionValue, &Reservation::getStatus),
		natural_join<Customer>(),
		natural_join<Vehicle>(),
		where(c(&Customer::getIdCustomer) == &Reservation::getIdCustomer and c(&Vehicle::getIdVehicle) == &Reservation::getIdVehicle)
	);

	//Entry explanation
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;
	std::cout << "|_ " << std::right << std::setfill(' ') << std::setw(28) << "RESERVATIONS LIST"
				<< std::right << std::setfill(' ') << std::setw(16) << "_ | " << std::endl;
	std::cout << "|_" << std::right << std::setfill('*') << std::setw(45) << "_ | " << std::endl;

	std::cout << std::setfill('_') << std::setw(101) << std::left << " _" << "_" << std::endl
		<< " | " << std::setfill(' ') << std::setw(3) << std::left << "ID"
		<< " | " << std::setw(15) << "Customer Name"
		<< " | " << std::setw(15) << "Vehicle Model"
		<< " | " << std::setw(15) << "Vehicle Make"
		<< " | " << std::setw(11) << "Rent Days"
		<< " | " << std::setw(12) << "Paid (EUR)"
		<< " | " << std::setw(8) << "Status"
		<< " | " << std::endl
		<< std::setfill('-') << std::setw(101) << std::left << " |" << "|" << std::endl;

	for (auto& row : rows) {
		
		std::cout << " | " << std::setfill(' ') << std::setw(3) << std::left << std::get<0>(row)
			<< " | " << std::setw(15) << std::get<1>(row)
			<< " | " << std::setw(15) << std::get<2>(row)
			<< " | " << std::setw(15) << std::get<3>(row)
			<< " | " << std::setw(11) << std::get<4>(row)
			<< " | " << std::setw(12) << std::get<5>(row)
			<< " | " << std::setw(8) << std::get<6>(row)
			<< " | " << std::endl;
	}
	std::cout << std::setfill('_') << std::setw(101) << std::left << " |" << "|" << std::endl;
}

template <typename T>
void manageCustomers(T storage) {
	Customer customer;
	int menuItem;

	do {
		std::cout << std::endl;
		customer.displayCustomers(storage);
		std::cout << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "||     CAR RENTAL SYSTEM 2022    ||" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "        CUSTOMERS SUB MENU                                   " << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "||   1 - Add Customer            ||" << std::endl;
		std::cout << "||   2 - Terminate Customer      ||" << std::endl;
		std::cout << "||   0 - Back to MAIN MENU       ||" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "[Input] Sub Menu Item: ";
		std::cin >> menuItem;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << std::endl << std::endl;

		switch (menuItem) {
		case 1:
			customer.createCustomer(storage);
			break;
		case 2:
			customer.deleteCustomer(storage);
			break;
		default:
			continue;
		}
		std::system("cls");
	} while (menuItem != 0);
}

template <typename T>
void manageVehicles(T storage) {
	Vehicle vehicle;
	int menuItem;
	do {
		std::cout << std::endl;
		vehicle.displayVehicles(storage);
		std::cout << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "||     CAR RENTAL SYSTEM 2022    ||" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "          VEHICLES SUB MENU                                   " << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "||   1 - Add Vehicle              ||" << std::endl;
		std::cout << "||   2 - Delete Vehicle           ||" << std::endl;
		std::cout << "||   0 - Back to MAIN MENU        ||" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "[Input] Sub Menu Item: ";
		std::cin >> menuItem;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << std::endl << std::endl;

		switch (menuItem) {
		case 1:
			vehicle.addVehicle(storage);
			break;
		case 2:
			vehicle.deleteVehicle(storage);
			break;
		default:
			continue;
		}
		std::system("cls");
	} while (menuItem != 0);
}

template <typename T>
void manageReservations(T storage) {
	Customer customer;
	Vehicle vehicle;
	Reservation reservation;
	int menuItem;
	do {
		std::cout << std::endl;
		reservation.displayReservations(storage);
		std::cout << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "||     CAR RENTAL SYSTEM 2022    ||" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "          VEHICLES SUB MENU                                   " << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "||   1 - Make a reservation       ||" << std::endl;
		std::cout << "||   2 - Cancel Reservation       ||" << std::endl;
		std::cout << "||   0 - Back to MAIN MENU        ||" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "[Input] Sub Menu Item: ";
		std::cin >> menuItem;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << std::endl << std::endl;

		switch (menuItem) {
		case 1:
			std::cout << std::endl << std::endl;
			customer.displayCustomers(storage);
			std::cout << std::endl << std::endl;
			vehicle.displayVehicles(storage);
			std::cout << std::endl << std::endl;
			reservation.makeReservation(storage);
			break;
		case 2:
			reservation.cancelReservation(storage);
			break;
		default:
			continue;
		}
		std::system("cls");
	} while (menuItem != 0);
}

template <typename T>
void showAllLists(T storage) {
	Customer customer;
	Vehicle vehicle;
	Reservation reservation;

	std::cout << std::endl;
	customer.displayCustomers(storage);
	vehicle.displayVehicles(storage);
	reservation.displayReservations(storage);
	
	std::cout << std::endl;
	std::system("pause");
}

template <typename T>
void initializeApp(T storage) {
	SetConsoleTitleA("Car Rental System");

	int menuItem;
	do {
		std::cout << "===================================" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "||     CAR RENTAL SYSTEM 2022    ||" << std::endl;
		std::cout << "||                               ||" << std::endl;
		std::cout << "===================================" << std::endl;
		std::cout << "             MAIN MENU                                   " << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "||   1 - Manage Customers        ||" << std::endl;
		std::cout << "||   2 - Manage Vehicles         ||" << std::endl;
		std::cout << "||   3 - Manage Reservations     ||" << std::endl;
		std::cout << "||   4 - Show All Databases      ||" << std::endl;
		std::cout << "||   0 - Exit                    ||" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "[Input] Main Menu Item: ";
		std::cin >> menuItem;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << std::endl << std::endl;

		switch (menuItem) {
		case 1: 
			std::system("cls");
			manageCustomers(storage);
			break;
		case 2: 
			std::system("cls");
			manageVehicles(storage);
			break;
		case 3:
			std::system("cls");
			manageReservations(storage);
			break;
		case 4:
			std::system("cls");
			showAllLists(storage);
			break;
		default:
			continue;
		}
		std::system("cls");
	} while (menuItem !=  0);

}

int main() {
	/**
	* SQLITE ORM WRAPPER STORAGE (DATABASE)
	* ----------------------------------------------------------------------
	* Create tables and columns. If a column is edited,
	* the whole table will be dropped.
	*/
	auto storage = make_storage("storage",
		make_table("Customer",
			make_column("idCustomer", &Customer::setIdCustomer,	&Customer::getIdCustomer,	autoincrement(),	primary_key()),
			make_column("name",	&Customer::setName,	&Customer::getName),
			make_column("surname",	&Customer::setSurname, &Customer::getSurname),
			make_column("dateOfBirth", &Customer::setDateOfBirth, &Customer::getDateOfBirth),
			make_column("country",	&Customer::setCountry,	&Customer::getCountry),
			make_column("city", 	&Customer::setCity, 	&Customer::getCity),
			make_column("postalCode",	&Customer::setPostalCode,	&Customer::getPostalCode),
			make_column("street", &Customer::setStreet,	&Customer::getStreet),
			make_column("phoneNumber",	&Customer::setPhoneNumber, &Customer::getPhoneNumber),
			make_column("email",	&Customer::setEmail, &Customer::getEmail),
			make_column("cardNumber", &Customer::setCreditCardNumber, &Customer::getCreditCardNumber),
			make_column("cardExpiryDate", &Customer::setCreditCardExpiryDate,	&Customer::getCreditCardExpiryDate),
			make_column("cardCvv",	&Customer::setCreditCardCvv, &Customer::getCreditCardCvv)
		), make_table(	"Vehicle",
			make_column("idVehicle",	&Vehicle::setIdVehicle, &Vehicle::getIdVehicle,	autoincrement(),	primary_key()),
			make_column("model", &Vehicle::setModel,	&Vehicle::getModel),
			make_column("make",	&Vehicle::setMake, &Vehicle::getMake),
			make_column("manufactoringYear", &Vehicle::setManufactoringYear,	&Vehicle::getManufactoringYear),
			make_column("transmissionType",	&Vehicle::setTransmissionType,	&Vehicle::getTransmissionType),
			make_column("passengerCapacity", &Vehicle::setPassengerCapacity,	&Vehicle::getPassengerCapacity),
			make_column("ratePerDay",	&Vehicle::setRatePerDay, 	&Vehicle::getRatePerDay),
			make_column("statusVehicle", &Vehicle::setStatusVehicle, &Vehicle::getStatusVehicle)
		), make_table(	"Reservation",
			make_column("idReservation", &Reservation::setIdReservation, &Reservation::getIdReservation,	autoincrement(), primary_key()),
			make_column("idCustomer", &Reservation::setIdCustomer, &Reservation::getIdCustomer),
			make_column("idVehicle", &Reservation::setIdVehicle, &Reservation::getIdVehicle),
			make_column("transactionValue", &Reservation::setTransactionValue, &Reservation::getTransactionValue),
			make_column("rentDays", &Reservation::setRentDays, &Reservation::getRentDays),
			make_column("statusReservation", &Reservation::setStatus, &Reservation::getStatus)));
	storage.sync_schema();

	/**
	* START APPLICATION
	*/
	initializeApp(storage);

	return 0;
}