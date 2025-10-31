#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] output;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int scores[50] = {
        75, 90, 88, 67, 92, 54, 89, 45, 66, 72,
        81, 99, 35, 60, 50, 78, 84, 40, 32, 27,
        91, 56, 64, 83, 47, 38, 94, 100, 71, 43,
        80, 58, 68, 87, 29, 33, 44, 53, 76, 95,
        48, 61, 70, 52, 62, 73, 85, 34, 46, 55
    };

    int n = 50;

    cout << "Original Scores:\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << "\n\n";

    radixSort(scores, n);

    cout << "Scores Sorted in Ascending Order:\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << "\n\n";

    cout << "Student Ranks (Higher Score = Higher Rank):\n";
     cout << "--------------------------------------------\n";
    for (int i = n - 1, rank = 1; i >= 0; i--, rank++)
        cout << rank << "\t" << scores[i] << endl;

    return 0;
}
