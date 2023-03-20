![Social Preview](https://user-images.githubusercontent.com/57192709/226383305-979811e4-2512-4388-b543-a9f861975a42.png)
# What is car rental management system?
Car rental companies need a reliable solution to save time through automation and make it easier for a customer to rent a car. The proposed solution is a car rental system that has options to manage customers, vehicles and reservations.

# How to start the application?
1. **Clone repository**
2. Run .exe file in CarRentalSystemEXE.rar

# Sneak peek
### Main menu
```cpp
===================================
||                               ||
||     CAR RENTAL SYSTEM 2022    ||
||                               ||
===================================
             MAIN MENU
-----------------------------------
||   1 - Manage Customers        ||
||   2 - Manage Vehicles         ||
||   3 - Manage Reservations     ||
||   4 - Show All Databases      ||
||   0 - Exit                    ||
-----------------------------------
[Input] Main Menu Item:
```
### Manage customers
```cpp
|_*****************************************_ |
|_                CUSTOMER LIST            _ |
|_*****************************************_ |
 _______________________________________________________________________________________________________________________________________________________________________________________________________
 | ID  | Name       | Surname    | D.O.B.      | Country    | City       | Postal Code | Street               | Phone No.   | Email                          | CC Number        | CC D.O.E.  | CC CVV  |
 |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 | 1   | Mateo      | Niksic     | 12.08.1997. | Croatia    | Rijeka     | 51000       | Rijeka 5             | 0925887635  | mateo@student.hr               | 9283948593182938 | 12/26      | 199     |
 | 2   | Ivana      | Prepelic   | 18.5.1986.  | Croatia    | Rijeka     | 51216       | Viskovo 3A           | 0918238237  | iprepelic86@hotmail.com        | 8347584938475847 | 03/24      | 283     |
 | 4   | Jhonatan   | Dohenburg  | 01.09.1959. | Germany    | Berlin     | 39998       | Berlin Hills 2       | 18892883823 | jberlin@dohenburh.com          | 9382938483928394 | 08/22      | 847     |
 | 5   | Darko      | Istakovic  | 03.05.2003. | Serbia     | Beograd    | 45928       | Knez Mihailova 13    | 0938443748  | distakovic@google.com          | 5879658742356987 | 07/23      | 087     |
 |_____________________________________________________________________________________________________________________________________________________________________________________________________|

===================================
||                               ||
||     CAR RENTAL SYSTEM 2022    ||
||                               ||
===================================
        CUSTOMERS SUB MENU
-----------------------------------
||   1 - Add Customer            ||
||   2 - Terminate Customer      ||
||   0 - Back to MAIN MENU       ||
-----------------------------------
[Input] Sub Menu Item:
```
### Manage vehicles
```cpp
|_*****************************************_ |
|_                VEHICLES LIST            _ |
|_*****************************************_ |
 __________________________________________________________________________________________________
 | ID  | Model      | Make       | Year  | Passengers  | Transmission  | EUR / Day  | Status      |
 |------------------------------------------------------------------------------------------------|
 | 1   | BMW        | X6         | 2022  | 5           | automatic     | 1750       | reserved    |
 | 2   | AUDI       | RS7        | 2019  | 2           | automatic     | 1499.5     | available   |
 | 3   | PORSCHE    | PANAMERA   | 2012  | 4           | manual        | 450        | available   |
 | 4   | RENAULT    | CLIO       | 2014  | 4           | manual        | 50         | available   |
 | 5   | NISSAN     | JUKE       | 2021  | 4           | automatic     | 800        | available   |
 | 6   | SKODA      | SUPERB     | 2019  | 4           | automatic     | 850        | available   |
 |________________________________________________________________________________________________|

===================================
||                               ||
||     CAR RENTAL SYSTEM 2022    ||
||                               ||
===================================
          VEHICLES SUB MENU
-----------------------------------
||   1 - Add Vehicle              ||
||   2 - Delete Vehicle           ||
||   0 - Back to MAIN MENU        ||
-----------------------------------
[Input] Sub Menu Item:
```
### Manage reservations
```cpp
|_*****************************************_ |
|_            RESERVATIONS LIST            _ |
|_*****************************************_ |
 _____________________________________________________________________________________________________
 | ID  | Customer Name   | Vehicle Model   | Vehicle Make    | Rent Days   | Paid (EUR)   | Status   |
 |---------------------------------------------------------------------------------------------------|
 | 1   | Mateo           | RENAULT         | CLIO            | 10          | 500          | canceled |
 | 2   | Mateo           | BMW             | X6              | 10          | 17500        | active   |
 |___________________________________________________________________________________________________|

===================================
||                               ||
||     CAR RENTAL SYSTEM 2022    ||
||                               ||
===================================
          VEHICLES SUB MENU
-----------------------------------
||   1 - Make a reservation       ||
||   2 - Cancel Reservation       ||
||   0 - Back to MAIN MENU        ||
-----------------------------------
[Input] Sub Menu Item:
```
### Show all databases
```cpp
|_*****************************************_ |
|_                CUSTOMER LIST            _ |
|_*****************************************_ |
 _______________________________________________________________________________________________________________________________________________________________________________________________________
 | ID  | Name       | Surname    | D.O.B.      | Country    | City       | Postal Code | Street               | Phone No.   | Email                          | CC Number        | CC D.O.E.  | CC CVV  |
 |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 | 1   | Mateo      | Niksic     | 12.08.1997. | Croatia    | Rijeka     | 51000       | Rijeka 5             | 0925887635  | mateo@student.hr               | 9283948593182938 | 12/26      | 199     |
 | 2   | Ivana      | Prepelic   | 18.5.1986.  | Croatia    | Rijeka     | 51216       | Viskovo 3A           | 0918238237  | iprepelic86@hotmail.com        | 8347584938475847 | 03/24      | 283     |
 | 4   | Jhonatan   | Dohenburg  | 01.09.1959. | Germany    | Berlin     | 39998       | Berlin Hills 2       | 18892883823 | jberlin@dohenburh.com          | 9382938483928394 | 08/22      | 847     |
 | 5   | Darko      | Istakovic  | 03.05.2003. | Serbia     | Beograd    | 45928       | Knez Mihailova 13    | 0938443748  | distakovic@google.com          | 5879658742356987 | 07/23      | 087     |
 |_____________________________________________________________________________________________________________________________________________________________________________________________________|
|_*****************************************_ |
|_                VEHICLES LIST            _ |
|_*****************************************_ |
 __________________________________________________________________________________________________
 | ID  | Model      | Make       | Year  | Passengers  | Transmission  | EUR / Day  | Status      |
 |------------------------------------------------------------------------------------------------|
 | 1   | BMW        | X6         | 2022  | 5           | automatic     | 1750       | reserved    |
 | 2   | AUDI       | RS7        | 2019  | 2           | automatic     | 1499.5     | available   |
 | 3   | PORSCHE    | PANAMERA   | 2012  | 4           | manual        | 450        | available   |
 | 4   | RENAULT    | CLIO       | 2014  | 4           | manual        | 50         | available   |
 | 5   | NISSAN     | JUKE       | 2021  | 4           | automatic     | 800        | available   |
 | 6   | SKODA      | SUPERB     | 2019  | 4           | automatic     | 850        | available   |
 |________________________________________________________________________________________________|
|_*****************************************_ |
|_            RESERVATIONS LIST            _ |
|_*****************************************_ |
 _____________________________________________________________________________________________________
 | ID  | Customer Name   | Vehicle Model   | Vehicle Make    | Rent Days   | Paid (EUR)   | Status   |
 |---------------------------------------------------------------------------------------------------|
 | 1   | Mateo           | RENAULT         | CLIO            | 10          | 500          | canceled |
 | 2   | Mateo           | BMW             | X6              | 10          | 17500        | active   |
 |___________________________________________________________________________________________________|

Press any key to continue . . .
```
