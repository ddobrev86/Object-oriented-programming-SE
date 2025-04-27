#include "PrintableDoubleArray.h"

PrintableDoubleArray::PrintableDoubleArray() : DoubleArray(){}
PrintableDoubleArray::PrintableDoubleArray(const double* numbers, const size_t size) : DoubleArray(numbers, size){}

std::ostream& operator<<(std::ostream& os, const PrintableDoubleArray& obj)
{
    for (size_t i = 0; i < obj.size; i++)
        os << obj.numbers[i] << " ";

    return os;
}

std::istream& operator>>(std::istream& is, PrintableDoubleArray& obj)
{
    size_t numbersToInsert;
    is >> numbersToInsert;

    double* temp = new double[numbersToInsert];
    for (size_t i = 0; i < numbersToInsert; i++)
        is >> temp[i];

    obj = PrintableDoubleArray(temp, numbersToInsert);

    return is;
}
