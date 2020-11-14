#include "RedoController.hpp"

void RedoController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{

}

void RedoController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    if (!m_document->CanRedo())
    {
        *output << "Can`t redo" << std::endl;
        return;
    }

    m_document->Redo();
}
