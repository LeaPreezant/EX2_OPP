#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H
#include <string>
#include "ProfileList.h"

class SocialNetwork
{
	std::string NETWORKNAME;
	int MINAGE;
	ProfileList* Profiles;

public:
	void init(std::string networkName, int minAge);
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices() const;

	void clear();

};

#endif