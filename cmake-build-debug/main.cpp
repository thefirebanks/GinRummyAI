
#include <iostream>
#include "Testing .cpp"
#include "GinState.cpp"

using namespace std;

int main()
{
    try {
        main_program();
    }
    catch (std::runtime_error& error) {
        std::cerr << "ERROR: " << error.what() << std::endl;
        return 1;
    }
}