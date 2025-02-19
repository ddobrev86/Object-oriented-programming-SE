#include <iostream>

int squareNum(int num)
{
    return num * num;
}

void squareArray(int* arr, size_t size)
{
    if (!arr)
    {
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] *= arr[i];
    }
}

void addTwoArray(int* arr, size_t size)
{
    if (!arr)
    {
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] += 2;
    }
}

void arrayOperation(int* arr, size_t size, int (*f)(int num))
{
    if (!arr || !f)
    {
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = f(arr[i]);
    }
}

void printArray(const int* arr, size_t size)
{
    if (!arr)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

int main()
{
    int arr[5] = { 1,2,3,4,5 };

    arrayOperation(arr, 5, squareNum);

    printArray(arr, 5);

    arrayOperation(arr, 5, [](int num) -> int {return num + 2; });

    printArray(arr, 5);

    return 0;
}
