/* 
Reason: Shell Sort is more efficient than Bubble Sort for this case because it reduces 
the total number of comparisons and swaps by comparing elements that are far apart 
first, quickly moving heavy luggage toward the end. Bubble Sort, on the other hand, 
only swaps adjacent elements, making it much slower for larger or partially unsorted 
lists. 
*/

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
    int luggage[] = {32, 25, 40, 12, 18, 50, 28};
    int n = sizeof(luggage) / sizeof(luggage[0]);

    cout << "Initial luggage weights: ";
    printArray(luggage, n);
    cout << endl;

    shellSort(luggage, n);

    cout << "\nSorted luggage weights (lightest -> heaviest): ";
    printArray(luggage, n);

    return 0;
}
