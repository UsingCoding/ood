#pragma once

#include "../IDocument.hpp"

class IDocumentConverter
{
public:
    virtual std::string Convert(const IDocument & document) = 0;
};
