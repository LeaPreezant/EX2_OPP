#ifndef USER_H
#define USER_H
#include <string>
#include "DeviceList.h"
#include "Device.h"

class User
{
private:
    unsigned int ID;
    std::string USERNAME;
    unsigned int AGE;
    DevicesList DEVICES;

public:
    void init(unsigned int id, const std::string& username, unsigned int age); //Initialize a new object
    void clear(); //Clearing memory
    unsigned int getID() const; //Return the user's ID
    std::string getUserName() const; //Return username
    unsigned int getAge() const; //Return age

    DevicesList& getDevices();
    void addDevice(const Device& newDevice);
    bool checkIfDevicesAreOn() const;

};



#endif

