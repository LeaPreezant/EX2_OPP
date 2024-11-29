#include "Device.h"
#include <iostream>


std::string Device::getOS() const
{
    return OS;
}

bool Device::isActive() const
{
    return active; // this
}

void Device::activate()
{
    active = true;
} 

void Device::deactivate()
{
    active = false;
}

void Device::init(unsigned int id, DeviceType type, std::string os)
{
    ID = id;
    TYPE = type;
    OS = os;
    active = true; 
}

unsigned int Device::getID() const 
{
    return ID;
}

DeviceType Device::getType() const
{
    return TYPE;
}