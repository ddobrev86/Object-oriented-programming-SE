#include "Gallery.h"

const size_t Gallery::INITITAL_CAPACITY = 8;

void Gallery::free()
{
    for (size_t i = 0; i < size; i++)
        pictures[i] = nullptr;

    delete[] pictures;
    pictures = nullptr;

    size = 0;
    capacity = 0;
}

void Gallery::copyFrom(const Gallery& other)
{
    size = other.size;
    capacity = other.capacity;

    pictures = new Picture * [capacity];

    for (size_t i = 0; i < size; i++)
        pictures[i] = new Picture(*other.pictures[i]);

}

void Gallery::moveFrom(Gallery&& other)
{
    size = other.size;
    capacity = other.capacity;

    pictures = other.pictures;
    other.pictures = nullptr;
}

void Gallery::resize(size_t newCap)
{
    capacity = newCap;
    Picture** temp = new Picture * [newCap];

    for (size_t i = 0; i < size; i++)
    {
        temp[i] = pictures[i];
        pictures[i] = nullptr;
    }

    delete[] pictures;
    pictures = temp;
    temp = nullptr;
}

Gallery::Gallery()
{
    capacity = INITITAL_CAPACITY;
    size = 0;
    pictures = new Picture * [capacity] {nullptr};
}

Gallery::Gallery(const Gallery& other)
{
    copyFrom(other);
}

Gallery& Gallery::operator=(const Gallery& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Gallery::Gallery(Gallery&& other) noexcept
{
    moveFrom(std::move(other));
}

Gallery& Gallery::operator=(Gallery&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

Gallery::~Gallery()
{
    free();
}

void Gallery::addPicture(Picture* pic)
{
    if (size >= capacity)
        resize(capacity * 2);

    pictures[size++] = pic;
}

void Gallery::addPicture(Picture& pic)
{
    addPicture(&pic);
}

void Gallery::removeAt(size_t index)
{
    if (index >= size)
        throw std::invalid_argument("Invalid index");

    std::swap(pictures[index], pictures[size - 1]);
    delete pictures[size - 1];
    pictures[size - 1] = nullptr;
    size--;
}

void Gallery::filterPictureAt(size_t index, PictureFilter filter)
{
    if (index >= size)
        throw std::invalid_argument("Invalid index");

    try
    {
        switch (filter)
        {
            case PictureFilter::GREYSCALE:
                pictures[index]->greyscale();
                break;
            case PictureFilter::MONOCHROME:
                pictures[index]->monochrome();
                break;
            case PictureFilter::NEGATIVE:
                pictures[index]->negative();
                break;
        }
    }
    catch(const std::exception& excp)
    {
        throw excp;
    }
}

void Gallery::filterAll(PictureFilter filter)
{
    try
    {
        switch (filter)
        {
        case PictureFilter::GREYSCALE:
            for (size_t i = 0; i < size; i++)
                pictures[i]->greyscale();

            break;
        case PictureFilter::MONOCHROME:
            for (size_t i = 0; i < size; i++)
                pictures[i]->monochrome();

            break;
        case PictureFilter::NEGATIVE:
            for (size_t i = 0; i < size; i++)
                pictures[i]->negative();

            break;
        }
    }
    catch (const std::exception& excp)
    {
        throw excp;
    }
}

const Picture& Gallery::operator[](size_t index) const
{
    if (index >= size)
        throw std::invalid_argument("Invalid index");

    return *pictures[index];
}

Picture& Gallery::operator[](size_t index)
{
    if (index >= size)
        throw std::invalid_argument("Invalid index");

    return *pictures[index];
}

std::ostream& operator<<(std::ostream& os, const Gallery& obj)
{
    for (size_t i = 0; i < obj.size; i++)
        os << *obj.pictures[i] << '\n';

    return os;
}
