#include "ParkingLotApp.h"
#include <bits/stdc++.h>
using namespace std;

ParkingLotApp::Car::Car(const string &regnNo, const int &age) {
    this->registrationNumber = regnNo;
    this->age = age;
}
void ParkingLotApp::createNewParkingLotOfSlots(int lotCount) {
    try {
      //number of parking lots cannot be negative 
        if(lotCount<=0)
            throw lotCount;
        this->MAX_SLOTS = lotCount;
    } catch (int lot) {
        cout<<"Invalid lot count!"<<endl;
         return;
    }

    slotsAvailable.assign(MAX_SLOTS+1,0);
    cout<<"Created parking of "<<lotCount<<" slots"<<endl;
}

void ParkingLotApp::parkVehicle(string regnNo, int age) {
    if (this->MAX_SLOTS <= 0) {
        cout<<"Sorry, parking lot is not created"<<endl;
    } else if (isFull()) {
        cout<<"Sorry, Parking lot is full!"<<endl;
    } else {
      //find a vacant slot and park into it
        int vacantSlot;
        for(int i=1;i<=MAX_SLOTS;i++){
            if(slotsAvailable[i]==0){
                vacantSlot = i;
                break;
            }
        }

        //create mapping of carTOSlot, AgeToSlot, SlotToRegistrationNo.
        slotsAvailable[vacantSlot] = 1;
        carToSlot[regnNo] = vacantSlot;
        ageToSlot[age].push_back(vacantSlot);
        slotToRegistrationNumber[vacantSlot] = regnNo;
        registrationNumberToAge[regnNo] = age;
        ageToRegistrationNumber[age].push_back(regnNo);
        currentCars++;
        cout<<"Car with vehicle registration number \""<<regnNo<<"\" has been parked at slot number "<<vacantSlot<<endl;
    }
}

void ParkingLotApp::leaveSlotBySlotNumber(int slotNo) {
    if (this->MAX_SLOTS <= 0) {
        cout<<"Sorry, parking lot is not created"<<endl;
    }
    else if(isEmpty()) {
        cout<<"Parking lot is empty!"<<endl;
    }
    //if there is a car in that slot, then vacate it, otherwise not
    else if(slotsAvailable[slotNo]==1){
        slotsAvailable[slotNo] = 0;
        string regnNo = slotToRegistrationNumber[slotNo];
        int age = registrationNumberToAge[regnNo];
        //remove mapping of CarToSlot an AgeToSlot when car leave a particular slot.
        carToSlot.erase(regnNo);
        for(auto i = ageToSlot[age].begin(); i != ageToSlot[age].end() ;i++){
            if(*i==slotNo){
                ageToSlot[age].erase(i);
                break;
            }
        }

        //decrease the car count present
        currentCars--;
        slotToRegistrationNumber.erase(slotNo);
        cout<<"Slot number "<<slotNo<<" vacated, the car with vehicle registration number \""<<regnNo<<"\" left the space, the driver of the car was of age "<<age<<endl;
    }
    else{
        cout<<"Slot "<<slotNo<<" already vacant!"<<endl;
    }
}


void ParkingLotApp::getRegistrationNumbersByDriversAge(int age)  {
    if (this->MAX_SLOTS <= 0) {
        cout<<"Sorry, parking lot is not created"<<endl;
    } else if(ageToRegistrationNumber[age].size()>0){
        cout<<"Registration number of cars with driver of age "<<age<<" are: "<<endl;
        int n = ageToRegistrationNumber[age].size();
        int count = 0;
        for(string regnNo: ageToRegistrationNumber[age]){
          if(count == n-1){
            cout<<regnNo<<endl;
          }else{
            cout<<regnNo<<", ";
          }
            count++;
        }
    }
    else {
        cout<<"Registration Number not found!"<<endl;
    }
}

void ParkingLotApp::getSlotNumbersByDriversAge(int age) {
    if (this->MAX_SLOTS <= 0) {
        cout<<"Sorry, parking lot is not created"<<endl;
    } else if (ageToSlot[age].size()>0){
        cout<<"Slots occupied by the driver of age "<<age<<" are: ";
        int n = ageToSlot[age].size();
        int count = 0;
        for(int slot:ageToSlot[age]){
          if(count == n-1){
            cout<<slot<<" ";
          }else{
            cout<<slot<<",";
          }
           count++; 
        }
        cout<<endl;
    } else {
         cout<<"Slot number not found!"<<endl;
    }
}


void ParkingLotApp::getSlotNumberByRegistrationNumber(string regnNo) {
    if (this->MAX_SLOTS <= 0) {
        cout<<"Sorry, parking lot is not created"<<endl<<endl;
    }else if(carToSlot[regnNo]){
        cout<<"Slot number of car with registration number "<<regnNo<<" is ";
        cout<<carToSlot[regnNo]<<endl;
    }
    else {
        cout<<"Slot number not found!"<<endl;
    }
}