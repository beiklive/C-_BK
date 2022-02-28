#include<iostream>
#include"myBase64.hpp"

int main(){
    myBase64 img("test.jpg");
    std::cout << img.ReadImage() << std::endl;
}