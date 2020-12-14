#pragma once

#include <memory>
#include "../PictureDraft/PictureDraft.hpp"

class IDesigner
{
public:
    virtual std::unique_ptr<PictureDraft> CreateDraft(std::istream & input) = 0;
    virtual ~IDesigner() = default;
};
