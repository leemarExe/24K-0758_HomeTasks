#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    int price;
    Node* prev;
    Node* next;

    Node(int i, string n, int p) : id(i), name(n), price(p), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertEnd(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertFront(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFront() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void removeEnd() {
        if (!tail) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void searchByID(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Item Found -> ID: " << temp->id << ", Name: " << temp->name << ", Price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void updatePrice(int id, int newPrice) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->price = newPrice;
                cout << "Price updated for ID " << id << ". New Price: $" << newPrice << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void displayForward() {
        cout << "\nCart (Front -> End):\n";
        Node* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Price: $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        cout << "\nCart (End -> Front):\n";
        Node* temp = tail;
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Price: $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    int countItems() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void mostExpensiveItem() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = head;
        Node* maxNode = head;
        while (temp) {
            if (temp->price > maxNode->price) {
                maxNode = temp;
            }
            temp = temp->next;
        }
        cout << "Most Expensive Item -> ID: " << maxNode->id << ", Name: " << maxNode->name << ", Price: $" << maxNode->price << endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList cart;

    cart.insertEnd(1, "Laptop", 1000);
    cart.insertEnd(2, "Phone", 700);
    cart.insertEnd(3, "Tablet", 400);
    cart.insertFront(0, "Smartwatch", 200);

    cart.displayForward();
    cart.displayBackward();

    cart.searchByID(2);
    cart.updatePrice(3, 450);

    cout << "\nTotal Items: " << cart.countItems() << endl;
    cart.mostExpensiveItem();

    cart.removeFront();
    cart.removeEnd();

    cart.displayForward();

    return 0;
}
