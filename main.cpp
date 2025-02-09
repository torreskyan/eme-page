#include <iostream>
#include <limits>

using namespace std;

void mergeAndSort(double arr1[], int size1, double arr2[], int size2, double merged[]) {
    int mergedSize = size1 + size2;
    
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
    
    
    for (int i = 0; i < mergedSize - 1; i++) {
        for (int j = 0; j < mergedSize - i - 1; j++) {
            if (merged[j] < merged[j + 1]) { 
                swap(merged[j], merged[j + 1]);
            }
        }
    }
}

bool getValidInput(double & num) {
    while (!(cin >> num)) {
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input." <<endl;
        cout << "Please Enter a Number: ";
    }
    return true;
}

int main() {
    double arr1[10], arr2[10], merged[20];
    int size1, size2;
    
    cout << "Enter the number of elements for the first array (max 10): ";
    while (!(cin >> size1) || size1 > 10 || size1 < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid size. Please enter a number between 1 and 10: ";
    }
    
    cout << "Enter elements for first array: ";
    for (int i = 0; i < size1; i++) {
        cout << "Element " << i + 1 << ": ";
        getValidInput(arr1[i]);
    }
    
    cout << "Enter the number of elements for the second array (max 10): ";
    while (!(cin >> size2) || size2 > 10 || size2 < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid size. Please enter a number between 1 and 10: ";
    }
    
    cout << "Enter elements for second array: ";
    for (int i = 0; i < size2; i++) {
        cout << "Element " << i + 1 << ": ";
        getValidInput(arr2[i]);
    }
    
    mergeAndSort(arr1, size1, arr2, size2, merged);
    
    cout << "Merged array in descending order: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    
    return 0;
}
