#ifndef PAGE_H
#define PAGE_H
#include <string>
#include "DeviceList.h"
#include "Device.h"

class Page
{
private:
    std::string POST;
    std::string STATUS;

public:
    void init();
    std::string getPosts() const;
    std::string getStatus() const;
    void clearPage();
    void setStatus(std::string status);
    void addLineToPosts(std::string new_line);
};

#endif