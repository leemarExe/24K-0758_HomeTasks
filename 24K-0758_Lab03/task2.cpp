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

    void addToTail(string item, int price) {
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

    void deleteFromFront() {
        if (head == nullptr) {
            cout << "Cart is empty, nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByName(string target) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->item == target) {
                cout << "Item: " << temp->item << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << target << " not found in cart.\n";
    }

    void searchByPosition(int pos) {
        Node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            if (index == pos) {
                cout << "At position " << pos << ": " << temp->item << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "No item found at position " << pos << endl;
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

    cart.addToTail("Laptop", 1000);
    cart.addToTail("Phone", 700);
    cart.addToTail("Tablet", 400);
    cart.addToTail("Headphones", 150);

    cout << "Initial cart:"; 
    cart.display();

    cart.deleteFromFront();
    cout << "\nAfter deleting from front:"; 
    cart.display();

    cart.searchByName("Tablet");
    cart.searchByPosition(2);

    return 0;
}
