#include "UndoController.hpp"

void UndoController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{

}

void UndoController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    if (!m_document->CanUndo())
    {
        *output << "Can`t undo" << std::endl;
        return;
    }

    m_document->Undo();
}
