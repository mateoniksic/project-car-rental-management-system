#include "Address.h"

Address::Address() {
	street = "uninitialized";
	postalCode = "uninitialized";
	country = "uninitialized";
}

Address::Address(std::string street, std::string postalCode, std::string city, std::string country) 
	: street(street), postalCode(postalCode), city(city), country(country) {}

Address::~Address() {}

void Address::setStreet(std::string street) { this->street = street; }
void Address::setPostalCode(std::string postalCode) { this->postalCode = postalCode; }
void Address::setCity(std::string city) { this->city = city; }
void Address::setCountry(std::string country) { this->country = country; }

std::string Address::getStreet() const { return this->street; }
std::string Address::getPostalCode() const { return this->postalCode; }
std::string Address::getCity() const { return this->city; }
std::string Address::getCountry() const { return this->country; }