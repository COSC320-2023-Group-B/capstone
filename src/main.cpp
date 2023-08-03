#include <iostream>

#include "../ctlibrary-windows-v1.6.5/caretaker_static.h"
// #include "../ctlibrary-windows-v1.6.5/Win64/libcaretaker_static.lib"

int main(int argc, char const *argv[]) {
    libct_init_data_t init_data = {0};

    init_data.device_class = LIBCT_DEVICE_CLASS_BLE_CARETAKER4;

    libct_app_callbacks_t callbacks = {};

    libct_context_t* context = NULL;

    // int status = libct_init(&context, &init_data, &callbacks);
    // if (LIBCT_FAILED(status)) {
    //     // handle error
    //     std::cout << "Error: status error";
    //     return 1;
    // }

    std::cout << "Did not error!";
    return 0;
}
