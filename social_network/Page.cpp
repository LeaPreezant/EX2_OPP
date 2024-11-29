#include "Page.h"

void Page::init()
{
	POST = "";
	STATUS = "";
}

std::string Page::getPosts() const
{
	return POST;
}

std::string Page::getStatus() const
{
	return STATUS;
}

void Page::clearPage()
{
	POST.clear();
}

void Page::setStatus(std::string status)
{
	STATUS = status;
}

void Page::addLineToPosts(std::string new_line)
{
	POST += new_line + "\n";
}

