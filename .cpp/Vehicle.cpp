#include "Vehicle.h"

Vehicle::Vehicle() {
	idVehicle = -1;
	make = "uninitialized";
	model = "uninitialized";
	manufactoringYear = -1;
	passengerCapacity = -1;
	transmissonType = "uninitialized";
	ratePerDay = -1;
	statusVehicle = "available";
}

Vehicle::Vehicle(std::string make, std::string model, std::string  transmissionType, int manufactoringYear, int passengerCapacity, double ratePerDay)
					: make(make), model(model), transmissonType(transmissonType), manufactoringYear(manufactoringYear), passengerCapacity(passengerCapacity), ratePerDay(ratePerDay) {
	idVehicle = -1;
	statusVehicle = "available";
}

Vehicle::~Vehicle() {}

void Vehicle::setIdVehicle(int idVehicle) { this->idVehicle = idVehicle; }
void Vehicle::setMake(std::string make) { this->make = make; }
void Vehicle::setModel(std::string model) { this->model = model; }
void Vehicle::setTransmissionType(std::string transmissionType) { this->transmissonType = transmissionType; }
void Vehicle::setManufactoringYear(int manufactoringYear) { this->manufactoringYear = manufactoringYear; }
void Vehicle::setPassengerCapacity(int passengerCapacity) { this->passengerCapacity = passengerCapacity; }
void Vehicle::setRatePerDay(double ratePerDay) { this->ratePerDay = ratePerDay; }
void Vehicle::setStatusVehicle(std::string statusVehicle) { this->statusVehicle = statusVehicle; }

int Vehicle::getIdVehicle() const { return this->idVehicle; }
std::string Vehicle::getMake() const { return this->make; }
std::string Vehicle::getModel() const { return this->model; }
std::string Vehicle::getTransmissionType() const { return this->transmissonType; }
int Vehicle::getManufactoringYear() const { return this->manufactoringYear; }
int Vehicle::getPassengerCapacity() const { return this->passengerCapacity; }
double Vehicle::getRatePerDay() const { return this->ratePerDay; }
std::string Vehicle::getStatusVehicle() const { return this->statusVehicle; }