#include "Picture.h"

void Picture::free()
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] canvas[i];
        canvas[i] = nullptr;
    }

    delete[] canvas;
    canvas = nullptr;
}

void Picture::copyFrom(const Picture& other)
{
    size = other.size;
    filter = other.filter;

    canvas = new Pixel * [size];
    for (size_t i = 0; i < size; i++)
        canvas[i] = new Pixel[size];

    for (size_t r = 0; r < size; r++)
    {
        for (size_t c = 0; c < size; c++)
            canvas[r][c] = other.canvas[r][c];
    }
}

void Picture::moveFrom(Picture&& other)
{
    size = other.size;
    filter = other.filter;

    canvas = other.canvas;
    other.canvas = nullptr;
}

Picture::Picture(size_t size)
{
    this->size = size;
    filter = PictureFilter::NORMAL;

    canvas = new Pixel * [size];
    for (size_t i = 0; i < size; i++)
        canvas[i] = new Pixel[size];

}

Picture::Picture(size_t size, const Pixel** canvas, PictureFilter filter)
{
    this->size = size;
    this->filter = filter;

    this->canvas = new Pixel * [size];
    for (size_t i = 0; i < size; i++)
        canvas[i] = new Pixel[size];

    for (size_t r = 0; r < size; r++)
    {
        for (size_t c = 0; c < size; c++)
            this->canvas[r][c] = canvas[r][c];
    }
}

Picture::Picture(const Picture& other)
{
    copyFrom(other);
}

Picture& Picture::operator=(const Picture& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Picture::Picture(Picture&& other) noexcept
{
    moveFrom(std::move(other));
}

Picture& Picture::operator=(Picture&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

Picture::~Picture()
{
    free();
}

void Picture::changePixel(size_t xPos, size_t yPos, 
    size_t r, size_t g, size_t b)
{
    canvas[xPos][yPos].setRed(r);
    canvas[xPos][yPos].setGreen(g);
    canvas[xPos][yPos].setBlue(b);
}

void Picture::greyscale()
{
    if (filter == PictureFilter::GREYSCALE || filter == PictureFilter::MONOCHROME)
        throw std::logic_error("Only color pictures can be greyscaled");

    for (size_t row = 0; row < size; row++)
    {
        for (size_t col = 0; col < size; col++)
        {
            uint8_t grey = 0.299 * canvas[row][col].getRed()
                + 0.587 * canvas[row][col].getGreen()
                + 0.114 * canvas[row][col].getBlue();

            canvas[row][col].setRed(grey);
            canvas[row][col].setBlue(grey);
            canvas[row][col].setGreen(grey);
        }
    }

    filter = PictureFilter::GREYSCALE;
}

void Picture::monochrome()
{
    if (filter == PictureFilter::MONOCHROME)
        throw std::logic_error("Cannot monochrome a monochrome picture");

    for (size_t row = 0; row < size; row++)
    {
        for (size_t col = 0; col < size; col++)
        {
            uint8_t grey = 0.299 * canvas[row][col].getRed()
                + 0.587 * canvas[row][col].getGreen()
                + 0.114 * canvas[row][col].getBlue();

            if (grey < 128)
            {
                canvas[row][col].setRed(0);
                canvas[row][col].setBlue(0);
                canvas[row][col].setGreen(0);
            }
            else
            {
                canvas[row][col].setRed(255);
                canvas[row][col].setBlue(255);
                canvas[row][col].setGreen(255);
            }
        }
    }

    filter = PictureFilter::MONOCHROME;
}

void Picture::negative()
{
    for (size_t row = 0; row < size; row++)
    {
        for (size_t col = 0; col < size; col++)
        {
            uint8_t red = canvas[row][col].getRed();
            uint8_t green = canvas[row][col].getGreen();
            uint8_t blue = canvas[row][col].getBlue();

            canvas[row][col].setRed(255 - red);
            canvas[row][col].setBlue(255 - blue);
            canvas[row][col].setGreen(255 - green);
        }
    }

    filter = PictureFilter::NEGATIVE;
}

std::ostream& operator<<(std::ostream& os, const Picture& obj)
{
    for (size_t row = 0; row < obj.size; row++)
    {
        for (size_t col = 0; col < obj.size; col++)
        {
            os << obj.canvas[row][col] << '\t';
        }

        os << '\n';
    }

    return os;
}
