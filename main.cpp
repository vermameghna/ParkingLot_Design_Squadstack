#include "ParkingLotApp.h"
#include <bits/stdc++.h>
using namespace std;

int main() {

    //refer to the input.txt file for input in read only mode
    freopen("input.txt","r",stdin);

    //refer to the ouput.txt file for output in write mode
    freopen("output.txt","w",stdout);

    
    string command;
    ParkingLotApp parkingLotApp;

    //while entering input to input.txt file
    while(cin>>command){
      //Create new parking lots by number of slots
        if(command=="Create_parking_lot"){
            int numsLot;
            cin>>numsLot;
            parkingLotApp.createNewParkingLotOfSlots(numsLot);
        }
        else if(command=="Park"){
          //Park a vehilce by registration number and driver age
            string registrationNumber;
            string driverAgeString;
            int driverAge;
            cin>>registrationNumber>>driverAgeString>>driverAge;
            parkingLotApp.parkVehicle(registrationNumber,driverAge);
        }
        else if(command=="Slot_numbers_for_driver_of_age"){
          //return all slot numbers which has driverAge given
            int driverAge;
            cin>>driverAge;
            parkingLotApp.getSlotNumbersByDriversAge(driverAge);
        }
        else if(command=="Slot_number_for_car_with_number"){
          //return slot number by Vehicle's registration number
            string registrationNumber;
            cin>>registrationNumber;
            parkingLotApp.getSlotNumberByRegistrationNumber(registrationNumber);
        }
        else if(command=="Leave"){
          //Leave a slot by slot number
            int slotNumber;
            cin>>slotNumber;
            parkingLotApp.leaveSlotBySlotNumber(slotNumber);
        }
        else if(command=="Vehicle_registration_number_for_driver_of_age"){
          //Get all parked vehicle registration number of cars parked by the driver of age given
            int driverAge;
            cin>>driverAge;
            parkingLotApp.getRegistrationNumbersByDriversAge(driverAge);
        }
    }
   
    return 0;
}