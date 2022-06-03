#include <iostream>
#include <Contacts.h>
#include <ContactApp.h>
#include <spdlog/spdlog.h>



int main(){
    // spdlog::set_level(spdlog::level::debug);
    MyApp app;
    app.run();
    return 0;
}
