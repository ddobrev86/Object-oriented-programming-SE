#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable : 4996)

namespace constants
{
    //задача 2
    const size_t MAX_NUMBER_COUNT = 20;
    const char EVEN_FILE[] = "even.txt";
    const char ODD_FILE[] = "odd.txt";

    //задача 3
    const size_t MAX_VECTOR_COUNT = 50;
    const size_t BUFF_SIZE = 1024;
}

//задача 1
void transferNumbersFromFiles(const char* inputFile, const char* outputFile)
{
    if (!inputFile || !outputFile)
    {
        std::cout << "Error";
        return;
    }
    int firstNum, secondNum;

    std::ifstream ifs(inputFile);
    if (!ifs.is_open())
    {
        std::cout << "Error";
        return;
    }

    ifs >> firstNum >> secondNum;
    ifs.close();


    std::ofstream ofs(outputFile);
    if (!ofs.is_open())
    {
        std::cout << "Error";
        return;
    }

    ofs << firstNum + secondNum << " " << firstNum * secondNum;
    ofs.close();
}

//задача 2
bool isEven(const int num)
{
    return (num % 2 == 0);
}

void splitEvenAndOddNumbers(const char* fileName)
{
    if (!fileName)
    {
        std::cout << "Error";
        return;
    }

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        std::cout << "Error";
        return;
    }

    std::ofstream even(constants::EVEN_FILE);
    std::ofstream odd(constants::ODD_FILE);

    if (!even.is_open() || !odd.is_open())
    {
        std::cout << "Error";
        return;
    }

    size_t numberCounter = 0;
    int currentNum;

    while (!inputFile.eof())
    {
        inputFile >> currentNum;
        numberCounter++;

        if(isEven(currentNum))
        { 
            even << currentNum << " ";
        }
        else 
        {
            odd << currentNum << " ";
        }

        if (numberCounter >= constants::MAX_NUMBER_COUNT)
        {
            break;
        }
    }

    inputFile.close();
    even.close();
    odd.close();
}

//задача 3
namespace VectorOperations
{
    struct Vector
    {
        int x;
        int y;
        int z;
    };

    struct VectorSpace
    {
        Vector vectors[constants::MAX_VECTOR_COUNT];
        size_t currentVectorCount;
    };

    Vector makeVector(int x, int y, int z)
    {
        return { x, y, z };
    }

    void addToVectorSpace(VectorSpace& vectorSpace, const Vector& vector)
    {
        if (vectorSpace.currentVectorCount >= constants::MAX_VECTOR_COUNT)
        {
            std::cout << "Cannot add a new vector";
            return;
        }

        vectorSpace.vectors[vectorSpace.currentVectorCount] = vector;
        vectorSpace.currentVectorCount++;
    }

    void serializeVector(std::ofstream& ofs, const Vector& vector)
    {
        ofs << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
    }

    void findNumberPositionsInLine(const char buff[], size_t numberPositions[])
    {
        size_t firstPtr = 0;
        size_t secondPtr = 0;

        numberPositions[0] = 1;
        size_t end = strlen(buff);

        for(size_t current = 1; current < end; )
    }

    Vector deserializeVector(std::ifstream& ifs)
    {
        size_t currentPos = ifs.tellg();

        int x, y, z;
        char buff[constants::BUFF_SIZE];
        ifs.getline(buff, constants::BUFF_SIZE);

        size_t numberPositions[6];

        ifs >> x >> y >> z;
        std::cout << x << " " << y << " " << z;
        //ifs.close();

        ifs.seekg(currentPos);
        return makeVector(x, y, z);
    }
}

int main()
{
    std::ifstream ifs("input.txt");
    VectorOperations::deserializeVector(ifs);

    return 0;
}
