/*Shell Sort is better here because it moves items long distances early (with large gaps),
dramatically reducing the number of small shifts that Insertion Sort would do when elements are far from their final positions. 
Now the full explanation and the step-by-step Shell Sort on your data.*/
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = arr[i];
            int j = i;
            while(j >= gap && arr[j - gap] > key){
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }

        cout << "After gap = " << gap << ": ";
        printArray(arr, n);
    }
}

int main() {
    int books[] = {205, 102, 310, 450, 120, 90};
    int n = sizeof(books) / sizeof(books[0]);

    cout << "Initial array: ";
    printArray(books, n);

    shellSort(books, n);

    cout << "\nSorted array: ";
    printArray(books, n);

    return 0;
}
