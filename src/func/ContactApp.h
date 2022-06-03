#ifndef __MyApp_H__
#define __MyApp_H__
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <fstream>

#include "Contacts.h"
using nlohmann::json;


class MyApp{;
public:
    MyApp();
    ~MyApp();

// 元功能： 增删改查
    void showContacts(int index = -1);
    bool addContact(contacts contact);
    bool delContact(int index);
    contacts *getContact(int index);
    bool changeContact(int index);
    json TransListToJson();
    void TransJsonToList(json j);

// 系统功能：
    void run(); //整体启动
    void addHandler();
    void delHandler();
    void changeHandler();
    void showHandler();

// 文件功能：
    void saveContacts();
    void loadContacts();


private:
    std::vector<contacts> ContactsList;

    int m_max_count{999};
    int m_per_page{8};
};















#endif