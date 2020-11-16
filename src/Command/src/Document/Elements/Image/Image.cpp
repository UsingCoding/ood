#include "Image.hpp"

Image::Image(const IImage::Path &path, int width, int height) : m_path(path), m_width(width), m_height(height) {}

IImage::Path Image::GetPath() const
{
    return m_path;
}

int Image::GetWidth() const
{
    return m_width;
}

int Image::GetHeight() const
{
    return m_height;
}

void Image::Resize(int width, int height)
{
    m_width = width;
    m_height = height;
}
