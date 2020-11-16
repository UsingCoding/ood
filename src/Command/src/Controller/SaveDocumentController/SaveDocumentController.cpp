#include "SaveDocumentController.hpp"

#include <experimental/filesystem>

void SaveDocumentController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition) 
{
    definition->AddArgument(Common::Console::InputArgument("path"));
}

void SaveDocumentController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output) 
{
    std::experimental::filesystem::path path = input.GetArgument("path").value();

    m_document->Save(path);
}
