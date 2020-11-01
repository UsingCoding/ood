#include <iostream>
#include "App/App.hpp"

int main()
{
    std::cout << "Should we use new API (y)?";
    std::string userInput;
    if (getline(std::cin, userInput) && (userInput == "y" || userInput == "Y"))
    {
        app::PaintPictureOnModernGraphicsRenderer();
    }
    else
    {
        app::PaintPictureOnCanvas();
    }

    return 0;
}
