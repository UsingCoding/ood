#pragma once

#include "../Document/IDocument.hpp"

class ICommand
{
public:
    virtual void Execute(IDocument & document) = 0;
    virtual void Revert(IDocument & document) = 0;
    virtual void Dispose() = 0;

    virtual ~ICommand() = default;
};

