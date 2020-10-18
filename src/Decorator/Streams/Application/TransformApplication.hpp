#pragma once

#include "../Input/IInputDataStream.hpp"
#include "../Output/IOutputDataStream.hpp"

class TransformApplication
{
public:
    TransformApplication();

    void run(std::istream & istream, std::ostream & ostream);
private:
};
