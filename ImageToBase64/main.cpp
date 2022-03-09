#include<iostream>
#include"myBase64.h"

int main(){
    myBase64 img("test.jpg");
    std::cout << img.ReadImage() << std::endl;
}
