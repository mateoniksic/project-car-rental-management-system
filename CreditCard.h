#pragma once
#include<iostream>
#include<string>

class CreditCard {
public:
	CreditCard();
	CreditCard(std::string cardNumber, std::string cvv, std::string expiryDate);
	~CreditCard();

	void setCardNumber(std::string cardNumber);
	void setExpiryDate(std::string expiryDate);
	void setCvv(std::string cvv);

	std::string getCardNumber() const;
	std::string getExpiryDate() const;
	std::string getCvv() const;

private:
	std::string cardNumber;
	std::string expiryDate;
	std::string cvv;
};