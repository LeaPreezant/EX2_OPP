#ifndef PROFILE_H
#define PROFILE_H
#include <string>
#include "DeviceList.h"
#include "Device.h"
#include "User.h"
#include "Page.h"
#include "UserList.h"

class Profile
{
private:
    User USER;
    Page* PAGE;
    UserList* USERLIST;

public:
    void init(const User& owner);
    void clear();
    User getOwner() const;
    void setStatus(const std::string& new_status); //setStatus
    void addPostToProfilePage(const std::string& post);
    void addFriend(const User& friend_to_add);
    std::string getPage() const;
    std::string getFriends() const;
    std::string getFriendsWithSameNameLength() const;
    //////////////////
    void changeWordInStatus(const std::string& word_to_replace, const std::string& replacement);
    void changeAllWordsInStatus(const std::string& replacement);
    //////////////////
};

#endif