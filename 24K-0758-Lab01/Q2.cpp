#include <iostream>
using namespace std;

class Box {
private:
    int* volume;

public:
    Box() {
        volume = new int(0);
    }

    Box(int vol) {
        volume = new int(vol);
    }

    Box(const Box& other) {
        volume = new int(*other.volume);
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete volume;
            volume = new int(*other.volume);
        }
        return *this;
    }

    ~Box() {
        delete volume;
    }

    void setVolume(int vol) {
        *volume = vol;
    }

    void displayVolume() const {
        cout << *volume << " cm^3" << endl;
    }
};

int main() {
    Box box1(24);
    cout << "Volume of Box1: ";
    box1.displayVolume();

    Box box2(box1);  
    cout << "Volume of Box2 (Copy of Box1): ";
    box2.displayVolume();

    box2.setVolume(36);
    cout << "Volume of Box2 (after change): ";
    box2.displayVolume();

    cout << "Volume of Box1 (Original remains): ";
    box1.displayVolume();

    Box box3;
    box3 = box1;
    cout << "Volume of Box3 (Assigned from Box1): ";
    box3.displayVolume();

    return 0;
}
