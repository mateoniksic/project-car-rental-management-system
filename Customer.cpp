#include "Customer.h"

Customer::Customer() {
	idCustomer = -1;
	name = "uninitialized";
	surname = "uninitialized";
	phoneNumber = "uninitialized";
	email = "uninitialized";
}

Customer::Customer(std::string name, std::string surname, std::string dateOfBirth, std::string phoneNumber, std::string email, std::string street, std::string postalCode, std::string city, std::string country, std::string cardNumber, std::string cvv, std::string ccDate)
							: name(name), surname(surname),  dateOfBirth(dateOfBirth),  phoneNumber(phoneNumber), email(email),  address(street, postalCode, city, country ),  creditCard(cardNumber, cvv, ccDate) {
	idCustomer = -1;
}

Customer::~Customer() {}

void Customer::setIdCustomer(int idCustomer) { this->idCustomer = idCustomer; }
void Customer::setName(std::string name) { this->name = name; }
void Customer::setSurname(std::string surname) { this->surname = surname; }
void Customer::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Customer::setEmail(std::string email) { this->email = email; }
void Customer::setDateOfBirth(std::string dateOfBirth) { this->dateOfBirth = dateOfBirth; }

int Customer::getIdCustomer() const { return this->idCustomer; }
std::string Customer::getName() const { return this->name; }
std::string Customer::getSurname() const { return this->surname; }
std::string Customer::getPhoneNumber() const { return this->phoneNumber; }
std::string Customer::getEmail() const { return this->email; }
std::string Customer::getDateOfBirth() const { return dateOfBirth; }

void Customer::setCreditCardNumber(std::string cardNumber) { this->creditCard.setCardNumber(cardNumber); }
void Customer::setCreditCardCvv(std::string cvv) { this->creditCard.setCvv(cvv); }
void Customer::setCreditCardExpiryDate(std::string expiryDate) { this->creditCard.setExpiryDate(expiryDate); }

std::string Customer::getCreditCardNumber() const { return this->creditCard.getCardNumber(); }
std::string Customer::getCreditCardCvv() const { return this->creditCard.getCvv(); }
std::string Customer::getCreditCardExpiryDate() const { return this->creditCard.getExpiryDate(); }

void Customer::setStreet(std::string street) { this->address.setStreet(street); }
void Customer::setPostalCode(std::string postalCode) { this->address.setPostalCode(postalCode); }
void Customer::setCity(std::string city) { this->address.setCity(city); }
void Customer::setCountry(std::string country) { this->address.setCountry(country); }

std::string Customer::getStreet() const { return this->address.getStreet(); }
std::string Customer::getPostalCode() const { return this->address.getPostalCode(); }
std::string Customer::getCity() const { return this->address.getCity(); }
std::string Customer::getCountry() const { return this->address.getCountry(); }