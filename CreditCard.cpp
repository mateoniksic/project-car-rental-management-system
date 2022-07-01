#include "CreditCard.h"

CreditCard::CreditCard() {
	cardNumber = "uninitialized";
	cvv = "uninitialized";
	expiryDate = "uninitialized";
}

CreditCard::CreditCard(std::string cardNumber, std::string cvv, std::string expiryDate)
	: cardNumber(cardNumber), cvv(cvv), expiryDate(expiryDate) {}

CreditCard::~CreditCard() {}

void CreditCard::setCardNumber(std::string cardNumber) { this->cardNumber = cardNumber; }
void CreditCard::setExpiryDate(std::string expiryDate) { this->expiryDate = expiryDate; }
void CreditCard::setCvv(std::string cvv) { this->cvv = cvv; }

std::string CreditCard::getCardNumber() const { return this->cardNumber; }
std::string CreditCard::getExpiryDate() const { return this->expiryDate; }
std::string CreditCard::getCvv() const { return this->cvv; }