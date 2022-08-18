#include "Reservation.h"

Reservation::Reservation() {
	idReservation = -1;
	transactionValue = -1;
	rentDays = 0;
	status = "active";
}

Reservation::Reservation(int idCustomer, int idVehicle, int transactionValue, int rentDays)
								  :transactionValue(transactionValue), rentDays(rentDays) {
	idReservation = -1;
	status = "active";
	this->customer.setIdCustomer(idCustomer);
	this->vehicle.setIdVehicle(idVehicle);
}

Reservation::~Reservation() {}

void Reservation::setIdReservation(int idReservation) { this->idReservation = idReservation; }
void Reservation::setIdVehicle(int idVehicle) { this->vehicle.setIdVehicle(idVehicle); }
void Reservation::setIdCustomer(int idCustomer) { this->customer.setIdCustomer(idCustomer); }
void Reservation::setTransactionValue(double transactionValue) { this->transactionValue = transactionValue; }
void Reservation::setRentDays(int rentDays) { this->rentDays = rentDays; }
void Reservation::setStatus(std::string status) { this->status = status; }

int Reservation::getIdReservation() const { return this->idReservation; }
int Reservation::getIdVehicle() const { return this->vehicle.getIdVehicle(); }
int Reservation::getIdCustomer() const { return this->customer.getIdCustomer(); }
double Reservation::getTransactionValue() const { return this->transactionValue; }
int Reservation::getRentDays() const { return this->rentDays; }
std::string Reservation::getStatus() const { return this->status; }