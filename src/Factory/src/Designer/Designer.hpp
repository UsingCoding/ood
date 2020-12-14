#pragma once

#include "IDesigner.hpp"
#include "../Factory/IShapeFactory.hpp"

class Designer : public IDesigner
{
public:
    Designer(IShapeFactory &factory) : m_factory(factory) {}

    std::unique_ptr<PictureDraft> CreateDraft(std::istream &input) override;

private:
    IShapeFactory & m_factory;

    static const std::string STOP_KEY_WORD;
};
