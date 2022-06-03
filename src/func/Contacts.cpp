#include "Contacts.h"

contacts::contacts()
{
    spdlog::debug("contacts Generate ~~");
}

contacts::~contacts()
{
    spdlog::debug("contacts Destroy ~~");
}

contacts::contacts(std::string name, std::string phone, std::string email, std::string address)
{
    if (name.length() >= 16)
    {
        m_contact.name = name.substr(0, 16);
    }else{
        m_contact.name = name;
    }
    if (phone.length() >= 16)
    {
        m_contact.phone = phone.substr(0, 16);
    }else{
        m_contact.phone = phone;
    }
    if (email.length() >= 16)
    {
        m_contact.email = email.substr(0, 16);
    }else{
        m_contact.email = email;
    }
    m_contact.address = address;
}

struct contacts::contact contacts::GetContact()
{
    return m_contact;
}


std::string contacts::GetInfo()
{
    return "name: " + m_contact.name + ", " +
           "phone: " + m_contact.phone + ", " +
           "email: " + m_contact.email + ", " +
           "address: " + m_contact.address;
}

void contacts::SetName(std::string name)
{
    if (name.length() >= 16)
    {
        m_contact.name = name.substr(0, 16);
    }else{
        m_contact.name = name;
    }
}

void contacts::SetPhone(std::string phone)
{
    if (phone.length() >= 16)
    {
        m_contact.phone = phone.substr(0, 16);
    }else{
        m_contact.phone = phone;
    }
}

void contacts::SetEmail(std::string email)
{
    if (email.length() >= 16)
    {
        m_contact.email = email.substr(0, 16);
    }else{
        m_contact.email = email;
    }
}

void contacts::SetAddress(std::string address)
{
    m_contact.address = address;
}