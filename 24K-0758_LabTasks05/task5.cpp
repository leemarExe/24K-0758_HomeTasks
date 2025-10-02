#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int nestedSum(int n) {
    if (n >= 0 && n <= 9) return n;
    return nestedSum(sumDigits(n));
}

int main() {
    int n;
    cout << "Enter the number: \n";
    cin >> n;
    cout << nestedSum(n) << endl;
    return 0;
}
