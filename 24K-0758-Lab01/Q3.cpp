#include <iostream>
using namespace std;

class Exam {
private:
    float* marks;
    int count;

public:
    Exam(float m[], int c) {
        count = c;
        marks = new float[count];
        for (int i = 0; i < count; i++) {
            marks[i] = m[i];
        }
    }

    ~Exam() {
        delete[] marks;
    }

    void setMark(int index, float value) {
        if (index >= 0 && index < count) {
            marks[index] = value;
        }
    }

    void showMarks() {
        cout << "Marks: ";
        for (int i = 0; i < count; i++) {
            cout << marks[i];
            if (i < count - 1) cout << ", ";
        }
        cout << endl;
    }
};

int main() {
    float marks[] = {45.7, 89.0, 55.8};
    Exam exam1(marks, 3);
    cout << "Exam1 Marks: ";
    exam1.showMarks();

    Exam exam2(exam1);
    cout << "Exam2 Marks (after shallow copy): ";
    exam2.showMarks();

    exam2.setMark(0, 99.9);
    cout << "Exam2 Marks (after change): ";
    exam2.showMarks();

    cout << "Exam1 Marks (after changing Exam2): ";
    exam1.showMarks();

    return 0;
}
