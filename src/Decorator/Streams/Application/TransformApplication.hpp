#pragma once

#include <memory>
#include <functional>
#include "../Input/IInputDataStream.hpp"
#include "../Output/IOutputDataStream.hpp"

class TransformApplication
{
public:
    TransformApplication(
            const std::function<std::unique_ptr<IInputDataStream>(const std::string &&)> &mInputStreamCreator,
            const std::function<std::unique_ptr<IOutputDataStream>(const std::string &&)> &mOutputStreamCreator);

    void run(std::istream & istream, std::ostream & ostream);
private:
    std::function<std::unique_ptr<IInputDataStream>(const std::string &&)> m_inputStreamCreator;
    std::function<std::unique_ptr<IOutputDataStream>(const std::string &&)> m_outputStreamCreator;
};
