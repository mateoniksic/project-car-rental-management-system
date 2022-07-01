#pragma once
#include<iostream>
#include<string>

class Address {
public:
	Address();
	Address(std::string street, std::string postalCode, std::string city, std::string country);
	~Address();

	void setStreet(std::string street);
	void setPostalCode(std::string postalCode);
	void setCity(std::string city);
	void setCountry(std::string country);

	std::string getStreet() const;
	std::string getPostalCode() const;
	std::string getCity() const;
	std::string getCountry() const;

private:
	std::string street;
	std::string postalCode;
	std::string city;
	std::string country;
};