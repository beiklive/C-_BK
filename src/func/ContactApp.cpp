#include "ContactApp.h"

MyApp::MyApp()
{
    spdlog::debug("App Generate ~~");
}

MyApp::~MyApp()
{
    spdlog::debug("App Destroy ~~");
}


bool MyApp::addContact(contacts contact)
{
    if (contact.GetContact().name.empty() || contact.GetContact().phone.empty())
    {
        spdlog::error("necessary contact is empty");
        spdlog::info("please check this contact:\n\
        contact name: {}\n\
        contact phone: {}\n\
        contact email: {}\n\
        contact address: {}\
        ", contact.GetContact().name, contact.GetContact().phone, contact.GetContact().email, contact.GetContact().address);
        return false;
    }
    ContactsList.push_back(contact);
    spdlog::info("add contact [{}] success", contact.GetInfo());
    return true;
}

void MyApp::showContacts(int index)
{
    if (ContactsList.empty())
    {
        spdlog::error("ContactsList is empty");
        return;
    }
    int i = 0;
    spdlog::info("show contacts");
    spdlog::info("No.\tname\t\tphone\t\temail\t\taddress");
    auto f = [](std::string str)->std::string{
        if (str.length() < 8)
        {
            return "\t\t";
        }else if (str.length() < 16)
        {
            return "\t";
        }else
        {
            return "";
        }
    };
    if (index == -1)
    {
        for (auto &contact : ContactsList)
        {
            spdlog::info("{}\t{}{}{}{}{}{}{}",
            i++,
            contact.GetContact().name,
            f(contact.GetContact().name),
            contact.GetContact().phone,
            f(contact.GetContact().phone),
            contact.GetContact().email,
            f(contact.GetContact().email),
            contact.GetContact().address);
        }
    }else{
        spdlog::info("{}\t{}{}{}{}{}{}{}",
        index,
        ContactsList[index].GetContact().name,
        f(ContactsList[index].GetContact().name),
        ContactsList[index].GetContact().phone,
        f(ContactsList[index].GetContact().phone),
        ContactsList[index].GetContact().email,
        f(ContactsList[index].GetContact().email),
        ContactsList[index].GetContact().address);
    }
    
}

bool MyApp::delContact(int index)
{
    if (ContactsList.size() < index){
        spdlog::error("index out of range");
        return false;
    }
    ContactsList.erase(ContactsList.begin() + index);
    spdlog::info("delete contact success");
    return true;
}

contacts *MyApp::getContact(int index)
{
    if (ContactsList.size() < index){
        spdlog::error("index out of range");
        return &ContactsList[0];
    }
    showContacts(index);
    return &ContactsList[index];
}

bool MyApp::changeContact(int index)
{
    if (ContactsList.size() < index){
        spdlog::error("index out of range");
        return false;
    }
    contacts* temp = getContact(index);
    int flag = 1;

    std::string tmp;
    while (flag)
    {
        std::cout << "select the contact you want to change(string or index , 'q' to quit): \n \
        1. name\n \
        2. phone\n \
        3. email\n \
        4. address\n \
        : ";
        std::cin >> tmp;
        
        if (tmp == "1" || tmp == "name")
        {
            std::cout << "input the new name: ";
            std::cin >> tmp;
            temp->SetName(tmp);
            flag = 1;
        }else if (tmp == "2" || tmp == "phone")
        {
            std::cout << "input the new phone: ";
            std::cin >> tmp;
            temp->SetPhone(tmp);
            flag = 1;
        }else if (tmp == "3" || tmp == "email")
        {
            std::cout << "input the new email: ";
            std::cin >> tmp;
            temp->SetEmail(tmp);
            flag = 1;
        }else if (tmp == "4" || tmp == "address")
        {
            std::cout << "input the new address: ";
            std::cin >> tmp;
            temp->SetAddress(tmp);
            flag = 1;
        }else if (tmp == "q")
        {
            flag = 0;
        }else{
            flag = 2;
        }
        switch(flag){
            case 1:
                spdlog::info("change contact success");
                break;
            case 0:
                spdlog::info("quit change contact");
                break;
            case 2:
                spdlog::error("input error");
                break;
        }
    }
    return true;
}

void MyApp::run(){
    int flag = 1;
    while (flag)
    {
        std::cout << "select the function you want to use(index): \n \
        0. quit\n \
        1. add contact\n \
        2. show contacts\n \
        3. delete contact\n \
        4. change contact\n \
        5. save contacts\n \
        6. load contacts\n \
        : ";
        std::cin >> flag;
        switch(flag){
            case 1:
                addHandler();
                break;
            case 2:
                showHandler();
                break;
            case 3:
                delHandler();
                break;
            case 4:
                changeHandler();
                break;
            case 5:
                saveContacts();
                break;
            case 6:
                loadContacts();
                break;
            case 0:
                break;
            default:
                spdlog::error("input error");
                break;
        }
    }
    spdlog::info("see you next time ~~");
}

void MyApp::addHandler(){
    spdlog::info("add contact");
    contacts contact("","","","");
    std::string tmp;
    std::cout << "input the contact name: ";
    std::cin >> tmp;
    contact.SetName(tmp);
    std::cout << "input the contact phone: ";
    std::cin >> tmp;
    contact.SetPhone(tmp);
    std::cout << "input the contact email: ";
    std::cin >> tmp;
    contact.SetEmail(tmp);
    std::cout << "input the contact address: ";
    std::cin >> tmp;
    contact.SetAddress(tmp);
    addContact(contact);
}

void MyApp::showHandler(){
    spdlog::info("show contacts");
    showContacts(-1);
}

void MyApp::delHandler(){
    spdlog::info("delete contact");
    showContacts(-1);
    spdlog::info("input the index of the contact you want to delete: ");
    int index;
    std::cin >> index;
    delContact(index);
}

void MyApp::changeHandler(){
    spdlog::info("change contact");
    showContacts(-1);
    spdlog::info("input the index of the contact you want to change: ");
    int index;
    std::cin >> index;
    changeContact(index);
}

json MyApp::TransListToJson()
{
    json j;
    for (auto &contact : ContactsList)
    {
        json j_contact;
        j_contact["name"] = contact.GetContact().name;
        j_contact["phone"] = contact.GetContact().phone;
        j_contact["email"] = contact.GetContact().email;
        j_contact["address"] = contact.GetContact().address;
        j.push_back(j_contact);
    }
    return j;
}

void MyApp::TransJsonToList(json j)
{
    for (auto &contact : j)
    {
        contacts c(contact["name"], contact["phone"], contact["email"], contact["address"]);
        ContactsList.push_back(c);
    }
}

void MyApp::saveContacts(){
    std::ofstream fout;
    fout.open("contacts.json", std::ios::out | std::ios::trunc);
    auto j = TransListToJson();
    fout << j.dump(4);
    fout.close();
    spdlog::info("save contacts success");
}

void MyApp::loadContacts(){
    std::ifstream fin;
    fin.open("contacts.json", std::ios::in);
    if (!fin.is_open())
    {
        spdlog::error("file open error");
        return;
    }
    json j;
    fin >> j;
    TransJsonToList(j);
    fin.close();
    spdlog::info("load contacts success");
}