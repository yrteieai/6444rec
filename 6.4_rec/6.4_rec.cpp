#include <iostream>
#include <cmath> 

using namespace std;

int CountZeros(double* arr, int size, int index = 0) {
    if (index == size) return 0;
    return (arr[index] == 0 ? 1 : 0) + CountZeros(arr, size, index + 1);
}

int FindMinIndex(double* arr, int size, int index = 0, int minIndex = 0) {
    if (index == size) return minIndex;
    if (arr[index] < arr[minIndex]) minIndex = index;
    return FindMinIndex(arr, size, index + 1, minIndex);
}

double SumAfterMin(double* arr, int size, int minIndex, int index = 0) {
    if (index <= minIndex) return SumAfterMin(arr, size, minIndex, index + 1);
    if (index == size) return 0;
    return arr[index] + SumAfterMin(arr, size, minIndex, index + 1);
}

void RecursiveBubbleSort(double* oddArr, int size, int pass = 0) {
    if (pass == size - 1) return;
    for (int i = 0; i < size - pass - 1; i++) {
        if (fabs(oddArr[i]) > fabs(oddArr[i + 1])) {
            swap(oddArr[i], oddArr[i + 1]);
        }
    }
    RecursiveBubbleSort(oddArr, size, pass + 1);
}

void CollectOddElements(double* arr, double* oddArr, int size, int& oddCount, int index = 0) {
    if (index == size) return;
    if (static_cast<int>(arr[index]) % 2 != 0 && floor(arr[index]) == arr[index]) {
        oddArr[oddCount++] = arr[index];
    }
    CollectOddElements(arr, oddArr, size, oddCount, index + 1);
}

void SortOddElements(double* arr, int size, int index = 0) {
    if (index == size) return;

    int oddCount = 0;
    double* oddArr = new double[size];

    CollectOddElements(arr, oddArr, size, oddCount);

    RecursiveBubbleSort(oddArr, oddCount);

    for (int i = 0, j = 0; i < size && j < oddCount; i++) {
        if (static_cast<int>(arr[i]) % 2 != 0 && floor(arr[i]) == arr[i]) {
            arr[i] = oddArr[j++];
        }
    }

    delete[] oddArr; 
    SortOddElements(arr, size, index + 1);
}

void PrintArray(double* arr, int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << arr[index] << (index < size - 1 ? ", " : "");
    PrintArray(arr, size, index + 1);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    double* arr = new double[n];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Initial array: ";
    PrintArray(arr, n);

    // 1.1. Підрахунок кількості елементів, рівних нулю
    int zeroCount = CountZeros(arr, n);
    cout << "Number of zero elements: " << zeroCount << endl;

    // 1.2. Сума елементів після мінімального елемента
    int minIndex = FindMinIndex(arr, n);
    double sumAfterMin = SumAfterMin(arr, n, minIndex);
    cout << "Sum of elements after minimum: " << sumAfterMin << endl;

    // 2. Впорядкування непарних елементів за зростанням модулів
    SortOddElements(arr, n);

    cout << "Modified array: ";
    PrintArray(arr, n);

    delete[] arr;

    return 0;
}
