#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    int salary;
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Employee employees[12] = {
        {"raza", 10, 84000},
        {"kinza", 323, 80000},
        {"sana", 211, 63000},
        {"ali", 191, 56000},
        {"zahib", 345, 54000},
        {"zohaib", 477, 49000},
        {"yasir", 156, 47000},
        {"moiz", 122, 39000},
        {"ahba", 121, 32000},
        {"laila", 990, 28000},
        {"hama", 100, 24000},
        {"saba", 123, 12000}
    };

    int n = 12;

    mergeSort(employees, 0, n - 1);

    cout << "Employees Sorted by Salary (Descending):\n";
    cout << "------------------------------------------\n";
    cout << "Name\tID\tSalary\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << employees[i].name << "\t" << employees[i].id << "\t" << employees[i].salary << endl;
    }

    cout << "\nTop 3 Highest Paid Employees:\n";
    cout << "------------------------------------------\n";
    cout << "Rank\tName\tID\tSalary\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "\t" << employees[i].name << "\t" << employees[i].id << "\t" << employees[i].salary << endl;
    }

    return 0;
}
