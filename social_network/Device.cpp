#include "Device.h"
#include <iostream>


std::string getOS(DeviceType type)
{
    switch (type) 
    {
    case PHONE:
        return ANDROID;
    case PC:
        return WINDOWS10;
    case LAPTOP:
        return MacOS;
    case TABLET:
        return IOS;
    default:
        return "Unknown OS";
    }
}

bool Device::isActive()
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

DeviceType Device::getType()
{
    return TYPE;
}