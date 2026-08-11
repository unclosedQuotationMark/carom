#include "controls/app.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

int main()
try
{
    carom::controls::App app;
    app.run();
    return EXIT_SUCCESS;
}
catch (const std::exception& e)
{
    std::cerr << "Fatal Error: " << e.what() << '\n';
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Unknown Fatal Error!\n";
    return EXIT_FAILURE;
}
