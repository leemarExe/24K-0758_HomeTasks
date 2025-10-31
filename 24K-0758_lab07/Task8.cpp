#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    int totalPrice;
};

int partition(Order arr[], int low, int high) {
    int pivot = arr[high].totalPrice;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].totalPrice < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Order arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of orders: ";
    cin >> n;
    Order* orders = new Order[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Order " << i + 1 << ":\n";
        cout << "Order ID: ";
        cin >> orders[i].orderID;
        cout << "Customer Name: ";
        cin >> orders[i].customerName;
        cout << "Total Price: ";
        cin >> orders[i].totalPrice;
    }

    quickSort(orders, 0, n - 1);

    cout << "\nSorted Orders by Total Price (Ascending):\n";
    cout << "---------------------------------------------\n";
    cout << "Order ID\tCustomer Name\tTotal Price\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < n; i++)
        cout << orders[i].orderID << "\t\t" << orders[i].customerName << "\t\t" << orders[i].totalPrice << endl;

    delete[] orders;
    return 0;
}
