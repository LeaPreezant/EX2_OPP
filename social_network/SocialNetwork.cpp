#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	NETWORKNAME = networkName;
	MINAGE = minAge;
}

std::string SocialNetwork::getNetworkName() const
{
	return NETWORKNAME;
}

int SocialNetwork::getMinAge() const
{
	return MINAGE;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < MINAGE)
		return false;

	Profiles->add(profile_to_add);
	return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
	std::string res = "";
	ProfileNode* curr = Profiles->get_first();
	while (curr != nullptr)
	{
		DeviceNode* current = curr->get_data().getOwner().getDevices().get_first();
		while (current != nullptr)
		{
			Device dev = current->get_data();
			if (dev.getOS() == WINDOWS7 || dev.getOS() == WINDOWS10 || dev.getOS() == WINDOWS11)
			{
				if (res != "")
				{
					res += ", ";
				}
				res += "[" + std::to_string(dev.getID()) + ", " + dev.getOS() + "]";
			}
			current = current->get_next();
		}
		curr = curr->get_next();
	}

	return res;

}

void SocialNetwork::clear()
{
	Profiles->clear();  // Clear all profiles from the ProfileList
	delete Profiles;    // Delete the ProfileList object
	Profiles = nullptr; // Set pointer to nullptr to avoid dangling pointer

	NETWORKNAME.clear();    // Clear the network name
	MINAGE = 0;             // Reset minimum age to a default value
}