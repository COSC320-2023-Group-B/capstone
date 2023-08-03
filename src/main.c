#include <stdio.h>

#include "./ctlibrary-windows-v1.6.5/caretaker_dynamic.h"

typedef int (LIBCTAPI* LP_LIBCT_INIT)(libct_context_t**,libct_init_data_t*, libct_app_callbacks_t*);
typedef void (LIBCTAPI* LP_LIBCT_DEINIT)(libct_context_t*);


void LIBCTAPI on_device_discovered(libct_context_t* context, libct_device_t* device) {
    const char* address = libct_device_get_address(device);
    const char* name = libct_device_get_name(device);
    // do something
    
    printf("on_device_discovered called!");
}

int main() {
    HINSTANCE hDLL;                   // Handle to DLL
    libct_context_t* context;         // libcaretaker context
    LP_LIBCT_INIT LibctInit;     // initialization function pointer  
    LP_LIBCT_DEINIT LibctDeinit; // de-initialization function pointer

    // Setup to connect to a Caretaker 4 device
    libct_init_data_t initData = {0}; 
    initData.device_class = LIBCT_DEVICE_CLASS_BLE_CARETAKER4;

    // Setup your application callbacks. (Only one is illustrated here but add more as needed.)
    libct_app_callbacks_t appCallbacks = {0};
    appCallbacks.on_device_discovered = on_device_discovered;

    printf("loading library\n");
    // might not be working because LoadLibrary expects WORD16 const or something
    hDLL = LoadLibrary("./ctlibrary-windows-v1.6.5/Win64/libcaretaker_dynamic.dll");

    if (hDLL != NULL) {
        printf("loaded library successfully!!!!!!\n");

        LibctInit = (LP_LIBCT_INIT)GetProcAddress(hDLL, "libct_init");
        if (!LibctInit) {  
            // handle the error  
            FreeLibrary(hDLL);
            return 69;
        }
        LibctDeinit = (LP_LIBCT_DEINIT)GetProcAddress(hDLL, "libct_deinit");
        if (!LibctDeinit) {
            // handle the error
            FreeLibrary(hDLL);
            return 420;  
        }
        // Initialize the library
        context = NULL;
        int status = LibctInit(&context, &initData, &appCallbacks);
        if ( LIBCT_FAILED(status) ) {
            // handle the error  
            FreeLibrary(hDLL);         
            return 69420;
        }
        // Add your application code to connect and monitor data

        // Exit when done
        LibctDeinit(context);
        FreeLibrary(hDLL);
    } else {
        printf("hDLL is Null\n");
    }

    printf("Did not error!");
    return 0;
}
