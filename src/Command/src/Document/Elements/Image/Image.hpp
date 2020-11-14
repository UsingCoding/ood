#pragma once

#include "IImage.hpp"

class Image : public IImage
{
public:
    Image(const Path &path, int width, int height);

    Path GetPath() const override;

    int GetWidth() const override;

    int GetHeight() const override;

    void Resize(int width, int height) override;

private:
    Path m_path;
    int m_width;
    int m_height;
};
