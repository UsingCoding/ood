#pragma once

#include "../Input/IInputDataStream.hpp"
#include "../Output/IOutputDataStream.hpp"

class TransformApplication
{
public:
    TransformApplication(IInputDataStream & inputDataStream, IOutputDataStream & outputDataStream)
        : m_inputDataStream(inputDataStream), m_outputDataStream(outputDataStream) {}

    void run(std::istream & istream, std::ostream & ostream);
private:
    IInputDataStream & m_inputDataStream;
    IOutputDataStream & m_outputDataStream;
};
