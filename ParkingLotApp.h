#ifndef CLION_PARKINGLOT_H
#define CLION_PARKINGLOT_H
#include <bits/stdc++.h>
using namespace std;

class ParkingLotApp {
    int MAX_SLOTS = 0;
    int currentCars = 0;
private:
    class Car{
    public:
        string registrationNumber;
        int age;
        Car(const string &registrationNumber, const int &age);
    };

     bool isEmpty(){
        if(currentCars==0 && MAX_SLOTS!=0)
            return true;
        else{
            return false;
        }
    }

    bool isFull(){
        if(currentCars==MAX_SLOTS)
            return true;
        else
            return false;
    }

   

public:
    vector<int> slotsAvailable;
    map<int,string> slotToRegistrationNumber;
    map<string,int> registrationNumberToAge;
    map<string,int> carToSlot;
    map<int,vector<int>> ageToSlot;
    map<int,vector<string>> ageToRegistrationNumber;

    //public methods or action
    void createNewParkingLotOfSlots(int lotCount);
    void parkVehicle(string registrationNumber, int age);
    void leaveSlotBySlotNumber(int slotNo);
    void getRegistrationNumbersByDriversAge(int age);
    void getSlotNumbersByDriversAge(int age);
    void getSlotNumberByRegistrationNumber(string registrationNumber);
};


#endif 