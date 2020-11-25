#ifdef WIN32

#include <windows.h>

#else
#include <dlfcn.h>
#endif

#include <cstdio>
#include "mylib.h"

using namespace std;

// https://stackoverflow.com/questions/53530566/loading-dll-in-windows-c-for-cross-platform-design


int main() {
    void *handle;
    void (*f)();
    char *error;

    handle = dlopen("mylib_dll.dll", RTLD_LAZY);
    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    f = dlsym(handle, "hello");
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }

    f();
    dlclose(handle);
    return 0;
}
