#include "User.h"

void User::init(unsigned int id, const std::string& username, unsigned int age)
{
	ID = id;
	USERNAME = username;
	AGE = age;
	DEVICES = new DevicesList();
	DEVICES->init();
}

void User::clear() // Clears all linked list of devices
{
	DEVICES->clear();
	delete DEVICES;
	DEVICES = nullptr;
}

unsigned int User::getID() const 
{
	return ID;
}

std::string User::getUserName() const 
{
	return USERNAME;
}

unsigned int User::getAge() const 
{
	return AGE;
}

DevicesList& User::getDevices()
{
	return *DEVICES;
}

void User::addDevice(const Device& newDevice) 
{
	DEVICES->add(newDevice); // from DeviceList
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode* cur = DEVICES->get_first();
	while (cur != nullptr) 
	{ 
		if (!cur->get_data().isActive())  // if not active
		{  
			return false;
		}
		cur = cur->get_next(); 
	}
	return true;
}