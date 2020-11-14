#include "Image.hpp"

Image::Image(const IImage::Path &path, int width, int height) : m_path(path), m_width(width), m_height(height) {}

IImage::Path Image::GetPath() const
{
    return IImage::Path();
}

int Image::GetWidth() const {
    return 0;
}

int Image::GetHeight() const {
    return 0;
}

void Image::Resize(int width, int height)
{

}
