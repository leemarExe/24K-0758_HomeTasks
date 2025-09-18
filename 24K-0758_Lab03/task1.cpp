#include <iostream>
#include <string>
using namespace std;

struct Node {
    string item;
    int price;
    Node* next;
    Node(string i, int p) : item(i), price(p), next(nullptr) {}
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() : head(nullptr) {}

    void insertFront(string item, int price) {
        Node* newNode = new Node(item, price);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(string item, int price) {
        Node* newNode = new Node(item, price);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string target, string item, int price) {
        Node* temp = head;
        while (temp != nullptr && temp->item != target) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        Node* newNode = new Node(item, price);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void search(string target) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->item == target) {
                cout << target << " found! Price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << target << " not found in cart.\n";
    }

    void display() {
        Node* temp = head;
        cout << "\nShopping Cart Items:\n";
        while (temp != nullptr) {
            cout << temp->item << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }

    ~ShoppingCart() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ShoppingCart cart;

    cart.insertEnd("Laptop", 1000);
    cart.insertEnd("Phone", 700);
    cart.insertEnd("Tablet", 400);
    cart.insertEnd("Headphones", 150);

    cart.insertFront("Smartwatch", 200);
    cart.insertEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);
    cart.search("Tablet");
    cart.display();

    return 0;
}
