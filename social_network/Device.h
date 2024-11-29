#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType {PHONE, PC, LAPTOP, TABLET};		     //
													     //
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
													     //
/// ///////////////////////////////////////////////////////


class Device
{
private:
	bool active; //Var for active/inactive
	std::string OS;

	bool isActive();
	void activate();
	void deactivate();

public:
	unsigned int ID;
	DeviceType TYPE;

	std::string getOS(DeviceType type)const; 

	void init(unsigned int id, DeviceType type, std::string os);
	int unsigned getID()const;
	DeviceType getType();
};

