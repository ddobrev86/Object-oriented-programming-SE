#include "ArrayReader.h"
#include <cstring>
#include <stdexcept>
#pragma warning(disable:4996)

void ArrayReader::free()
{
    delete[] inputFile;
    delete[] outputFile;
    delete[] arr;

    inputFile = nullptr;
    outputFile = nullptr;
    arr = nullptr;
}

void ArrayReader::copyFrom(const ArrayReader& other)
{
    inputFile = new char[strlen(other.inputFile) + 1];
    strcpy(inputFile, other.inputFile);

    outputFile = new char[strlen(other.outputFile) + 1];
    strcpy(outputFile, other.outputFile);

    size = other.size;
    arr = new int[size];

    for (size_t i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

void ArrayReader::moveFrom(ArrayReader&& other)
{
    inputFile = other.inputFile;
    other.inputFile = nullptr;
    
    outputFile = other.outputFile;
    other.outputFile = nullptr;

    arr = other.arr;
    other.arr = nullptr;
    size = other.size;
}

ArrayReader::ArrayReader(const char* inputFile, const char* outputFile)
{
    if (!inputFile || !outputFile)
        throw std::invalid_argument("Invalid file name");

    this->inputFile = new char[strlen(inputFile) + 1];
    strcpy(this->inputFile, inputFile);

    this->outputFile = new char[strlen(outputFile) + 1];
    strcpy(this->outputFile, outputFile);

    arr = nullptr;
    size = 0;
}

ArrayReader::ArrayReader(const ArrayReader& other)
{
    copyFrom(other);
}

ArrayReader& ArrayReader::operator=(const ArrayReader& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

ArrayReader::ArrayReader(ArrayReader&& other) noexcept
{
    moveFrom(std::move(other));
}

ArrayReader& ArrayReader::operator=(ArrayReader&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

ArrayReader::~ArrayReader()
{
    free();
}

void ArrayReader::sort()
{
    for (size_t first = 0; first < size - 1; first++)
    {
        size_t minIndex = first;

        for (size_t second = first; second < size; second++)
        {
            if (arr[minIndex] > arr[second])
                minIndex = second;
        }

        if (minIndex != first)
            std::swap(arr[minIndex], arr[first]);
    }
}
