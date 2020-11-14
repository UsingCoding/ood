#pragma once

#include "../IController.hpp"
#include "../../Document/IDocument.hpp"

class UndoController : public IController
{
public:
    UndoController(std::unique_ptr<IDocument> &document) : m_document(document) {}

    void ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void Handle(Common::Console::IInput &input, Common::Console::IOutput &output) override;

private:
    std::unique_ptr<IDocument> & m_document;
};

