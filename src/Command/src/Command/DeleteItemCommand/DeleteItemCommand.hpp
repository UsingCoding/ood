#pragma once

#include "../ICommand.hpp"

class DeleteItemCommand : public ICommand
{
public:
    DeleteItemCommand(const DocumentItem &item, size_t position);

    void Execute(IDocument &document) override;

    void Revert(IDocument &document) override;

    void Dispose() override;

private:
    DocumentItem m_item;
    size_t m_position;
};
