#pragma once
#include<iostream>
#include<fstream>
class myBase64
{
private:
    /* data */
    std::string m_path;

protected:

public:
    myBase64(/* args */);
    myBase64(const char *pic);
    std::string ReadImage();
    std::string Encode(const char* Data, int DataByte);
    std::string Decode(const char* Data, int DataByte, int& OutByte);
    ~myBase64();
};

