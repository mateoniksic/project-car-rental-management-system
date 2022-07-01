#pragma once
#include<iostream>
#include<string>
#include<string.h>

#include "Address.h"
#include "CreditCard.h"

class Customer {
public:
	Customer();
	Customer(std::string name, std::string surname, std::string dateOfBirth, 
		std::string street, std::string postalCode, std::string city, std::string country,
		std::string phoneNumber, std::string email,
		std::string cardNumber, std::string cvv, std::string ccDate);
	~Customer();

	void setIdCustomer(int idCustomer);
	void setName(std::string name);
	void setSurname(std::string surname);
	void setPhoneNumber(std::string phoneNumber);
	void setEmail(std::string email);
	void setDateOfBirth(std::string dateOfBirth);

	int getIdCustomer() const;
	std::string getName() const;
	std::string getSurname() const;
	std::string getPhoneNumber() const;
	std::string getEmail() const;
	std::string getDateOfBirth() const;
	
	void setCreditCardNumber(std::string cardNumber);
	void setCreditCardCvv(std::string cvv);
	void setCreditCardExpiryDate(std::string expiryDate);

	std::string getCreditCardNumber() const;
	std::string getCreditCardCvv() const;
	std::string getCreditCardExpiryDate() const;

	void setStreet(std::string street);
	void setPostalCode(std::string postalCode);
	void setCity(std::string city);
	void setCountry(std::string country);

	std::string getStreet() const;
	std::string getPostalCode() const;
	std::string getCity() const;
	std::string getCountry() const;

	template <typename T>
	void createCustomer(T storage);

	template <typename T>
	void deleteCustomer(T storage);

	template <typename T>
	static void displayCustomers(T storage);

private:
	int idCustomer;
	std::string name;
	std::string surname;
	std::string dateOfBirth;
	std::string phoneNumber;
	std::string email;
	Address address;
	CreditCard creditCard;
};