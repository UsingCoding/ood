#include "Designer.hpp"
#include <string>
#include <iostream>
#include <vector>

const std::string Designer::STOP_KEY_WORD = "Stop";

std::unique_ptr<PictureDraft> Designer::CreateDraft(std::istream &input)
{
    auto shapes = std::make_unique<std::vector<std::unique_ptr<Shape>>>();

    std::string line;
    while (getline(input, line))
    {
        if (line == STOP_KEY_WORD)
        {
            break;
        }

        try
        {
            shapes->push_back(m_factory.CreateShape(line));
        }
        catch (const std::invalid_argument & e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return std::make_unique<PictureDraft>(std::move(shapes));
}
