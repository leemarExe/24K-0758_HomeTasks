#include <iostream>
#include <iomanip>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void printArray(int arr[], int n, int pass) {
    cout << "After pass " << pass << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countSort(int arr[], int n, int exp, int pass) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    printArray(arr, n, pass);
    delete[] output;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    int pass = 1;
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp, pass++);
}

int main() {
    int products[20] = {
        12345, 98765, 10234, 56473, 29384, 
        47593, 83746, 18273, 91823, 74829,
        62384, 23456, 11223, 99213, 78541,
        67234, 39812, 54987, 34567, 82910
    };

    int n = 20;

    cout << "Before Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << products[i] << " ";
    cout << "\n\n";

    radixSort(products, n);

    cout << "\nAfter Complete Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << products[i] << " ";
    cout << endl;

    return 0;
}
