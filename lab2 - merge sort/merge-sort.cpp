#include <iostream>
#include <string>

bool compareStrings(const std::string& left, const std::string& right);
void printStrings(std::string strings[], int stringsQuantity);
void mergeArrays(std::string leftArray[], std::string rightArray[], int leftSize, int rightSize);
void mergeSort(std::string strings[], int size);


int main() {
    int stringsQuantity = 0;

    std::cin >> stringsQuantity;

    std::string* strings = new std::string[stringsQuantity];

    for (int index = 0; index < stringsQuantity; index++) {
        std::cin >> strings[index];
    }

    mergeSort(strings, stringsQuantity);

    std::cerr << "\n\n-------------------------\n\n";
    printStrings(strings, stringsQuantity);

    delete[] strings;

    return 0;
}


void printStrings(std::string strings[], int stringsQuantity) {
    for (int index = 0; index < stringsQuantity; index++) {
        std::cout << strings[index] << "\n";
    }
}


bool compareStrings(const std::string& left, const std::string& right) {
    int leftLength = left.length();
    int rightLength = right.length();
    
    if (leftLength > rightLength) {
        return true;
    }

    if (leftLength < rightLength) {
                return false;
        }

    for (int index = 0; index < leftLength; index++) {
        if (left[index] > right[index]) {
            return true;
        }
        else if (left[index] < right[index]) {
            return false;
        }
    }

    return true;
}


void mergeArrays(std::string leftArray[], std::string rightArray[], int leftSize, int rightSize) {
    int stringsArraySize = leftSize + rightSize;
    std::string* strings = new std::string[stringsArraySize];

    int leftArrayIndex = 0;
    int rightArrayIndex = 0;
    int stringsArrayIndex = 0;

    while (leftArrayIndex < leftSize and rightArrayIndex < rightSize) {
        bool isLeftGreaterThanRigth = compareStrings(leftArray[leftArrayIndex], rightArray[rightArrayIndex]);
        
        if (isLeftGreaterThanRigth) {
            strings[stringsArrayIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }
        else {
            strings[stringsArrayIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        }

        stringsArrayIndex++;
    }

    while (leftArrayIndex < leftSize) {
        strings[stringsArrayIndex] = leftArray[leftArrayIndex];
        leftArrayIndex++;
        stringsArrayIndex++;
    }

    while (rightArrayIndex < rightSize) {
        strings[stringsArrayIndex] = rightArray[rightArrayIndex];
        rightArrayIndex++;
        stringsArrayIndex++;
    }

    for (int index = 0; index < stringsArraySize; index++) {
        leftArray[index] = strings[index];
    }

    delete[] strings;
}


void mergeSort(std::string strings[], int size) {
    if (size < 2) {
        return;
    }

    int middleIndex = size / 2;
    int leftSize = middleIndex;
    int rightSize = size - middleIndex;

    std::string* leftArray = &strings[0];
    std::string* rightArray = &strings[middleIndex];

    mergeSort(leftArray, leftSize);
    mergeSort(rightArray, rightSize);

    mergeArrays(leftArray, rightArray, leftSize, rightSize);
}