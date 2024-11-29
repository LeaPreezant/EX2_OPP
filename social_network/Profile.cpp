#include "Profile.h"
#include <algorithm>

void Profile::init(const User& owner)
{
	USER = owner;
	this->PAGE = new Page();
	this->PAGE->init();
	this->USERLIST = new UserList();
	this->USERLIST->init();
}

void Profile::clear()
{
	USERLIST->clear();
	delete PAGE;
	delete USERLIST;
}

User Profile::getOwner() const
{
	return USER;
}

void Profile::setStatus(const std::string& new_status)
{
	PAGE->setStatus(new_status);
}

void Profile::addPostToProfilePage(const std::string& post)
{
	PAGE->addLineToPosts(post);
}

void  Profile::addFriend(const User& friend_to_add)
{
	USERLIST->add(friend_to_add);
}

std::string Profile::getPage() const
{
	std::string allPage = "Status: " + PAGE->getStatus() + "\n" + "*******************" + "\n" + "*******************" + "\n" + PAGE->getPosts();
	return allPage;
}

std::string Profile::getFriends() const
{
	UserNode* cur = USERLIST->get_first();
	std::string allNames;

	while (cur != nullptr)
	{
		allNames += cur->get_data().getUserName() + ",";
		cur = cur->get_next();
	}
	allNames.pop_back();
	return allNames;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	if (USERLIST->get_first() == nullptr) return "";
	std::string stringOfFriends;
	std::string currentFriend;
	bool first = true;
	UserNode* cur = USERLIST->get_first();
	while (cur != nullptr)
	{
		currentFriend = cur->get_data().getUserName();
		if (USER.getUserName().length() == currentFriend.length())
		{
			if (!first) stringOfFriends += ",";
			stringOfFriends += currentFriend;
			first = false;
		}
		cur = cur->get_next();
	}
	return stringOfFriends;
}


///////////////////////////////////
void Profile::changeWordInStatus(const std::string& word_to_replace, const std::string& replacement)
{
	std::string current_status = PAGE->getStatus();
	size_t pos = 0;

	while ((pos = current_status.find(word_to_replace, pos)) != std::string::npos)
	{
		current_status.replace(pos, word_to_replace.length(), replacement);
		pos += replacement.length(); // Move past the replacement
	}

	PAGE->setStatus(current_status);
}


void Profile::changeAllWordsInStatus(const std::string& replacement)
{
	std::string current_status = PAGE->getStatus();
	std::string new_status;

	int word_count = std::count_if(current_status.begin(), current_status.end(),
		[](char c) { return std::isspace(c); }) + 1;

	for (int i = 0; i < word_count; ++i)
	{
		if (i > 0)
			new_status += " "; 

		new_status += replacement;
	}
	PAGE->setStatus(new_status);
}
/////////////////////////////////