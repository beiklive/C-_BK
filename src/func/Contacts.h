// Copyright (c) RealCoolEngineer. 2022. All rights reserved.
// Author: beiklive
// Date: 2022-06-02
#ifndef SRC_FUNC_CONTACTS_H_
#define SRC_FUNC_CONTACTS_H_
#include <iostream>
#include <string>
#include <spdlog/spdlog.h>
class contacts{
public:
    struct contact{
        std::string name;
        std::string phone;
        std::string email;
        std::string address;
    };
    
    contacts();
    contacts(std::string name="", std::string phone="", std::string email="", std::string address="");
    ~contacts();


    struct contact GetContact();
    std::string GetInfo();

    void SetName(std::string name);
    void SetPhone(std::string phone);
    void SetEmail(std::string email);
    void SetAddress(std::string address);

private:
    struct contact m_contact;

};



#endif  // SRC_FUNC_CONTACTS_H_
