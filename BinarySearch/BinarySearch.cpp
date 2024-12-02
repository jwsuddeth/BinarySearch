// BinarySearch.cpp 

#include <iostream>

void mergeSort(int data[], int size);
int binarySearch(int data[], int start, int stop);
void swap(int& x, int& y);
void printArray(int data[], int size);


int main()
{
    int data[] = { 3, 8, 9, 2, 4, 7, 1 };
    mergeSort(data, sizeof(data) / sizeof(1));
    printArray(data, sizeof(data) / sizeof(1));

    int searchValue;
    std::cout << "Enter search value: ";
    std::cin >> searchValue;
    

    int position = binarySearch(data, searchValue, sizeof(data) / sizeof(1) - 1);
    if (position > -1)
    {
        std::cout << "The value " << searchValue << " was found at position " << position << std::endl;
    }
    else
    {
        std::cout << "The value " << searchValue << " was not found" << std::endl;
    }
}

int binarySearch(int data[], int value, int size)
{
    int first = 0, last = size - 1;
    bool found = false;
    int position = -1;

    while (!found && first <= last)
    {
        int middle = (first + last) / 2;
        if (data[middle] == value)
        {
            position = middle;
            found = true;
        }
        else if (data[middle] > value)
        {
            last = middle - 1;
        }
        else 
        {
            first = middle + 1;
        }
    }

    return position;
}


void mergeSort(int data[], int size)
{
    int startScan;
    int index;
    int minIndex;
    int minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = data[startScan];

        for (int index = startScan + 1; index < size; index++)
        {
            if (data[index] < minValue)
            {
                minValue = data[index];
                minIndex = index;
            }
        }

        swap(data[minIndex], data[startScan]);
    }
}

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void printArray(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << std::endl;
}
