#include <iostream>
#include <string>
using namespace std;

struct Ticket {
    int ticketID;
    string customerName;
    string rideName;
    Ticket* next;
};

Ticket* head = nullptr;

void issueTicketEnd(int id, string name, string ride) {
    Ticket* newTicket = new Ticket{id, name, ride, nullptr};
    if (head == nullptr) {
        head = newTicket;
        head->next = head;
        return;
    }
    Ticket* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newTicket;
    newTicket->next = head;
}

void issuePriorityTicketFront(int id, string name, string ride) {
    Ticket* newTicket = new Ticket{id, name, ride, nullptr};
    if (head == nullptr) {
        head = newTicket;
        head->next = head;
        return;
    }
    Ticket* temp = head;
    while (temp->next != head) temp = temp->next;
    newTicket->next = head;
    temp->next = newTicket;
    head = newTicket;
}

void cancelFirstTicket() {
    if (head == nullptr) {
        cout << "No tickets to cancel.\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
        cout << "First ticket cancelled. List is now empty.\n";
        return;
    }
    Ticket* temp = head;
    Ticket* last = head;
    while (last->next != head) last = last->next;
    head = head->next;
    last->next = head;
    delete temp;
    cout << "First ticket cancelled successfully.\n";
}

void cancelTicketByID(int id) {
    if (head == nullptr) {
        cout << "No tickets to cancel.\n";
        return;
    }
    Ticket* curr = head;
    Ticket* prev = nullptr;
    do {
        if (curr->ticketID == id) {
            if (curr == head) {
                cancelFirstTicket();
                return;
            }
            prev->next = curr->next;
            delete curr;
            cout << "Ticket " << id << " cancelled successfully.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    cout << "Ticket with ID " << id << " not found.\n";
}

void searchTicketByID(int id) {
    if (head == nullptr) {
        cout << "No tickets booked.\n";
        return;
    }
    Ticket* temp = head;
    do {
        if (temp->ticketID == id) {
            cout << "Ticket Found:\n";
            cout << "ID: " << temp->ticketID << ", Customer: " << temp->customerName << ", Ride: " << temp->rideName << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Ticket with ID " << id << " not found.\n";
}

void displayTickets() {
    if (head == nullptr) {
        cout << "No tickets booked.\n";
        return;
    }
    Ticket* temp = head;
    cout << "Tickets in Circular Order:\n";
    do {
        cout << "ID: " << temp->ticketID << ", Customer: " << temp->customerName << ", Ride: " << temp->rideName << endl;
        temp = temp->next;
    } while (temp != head);
}

void countTickets() {
    if (head == nullptr) {
        cout << "Total Tickets: 0\n";
        return;
    }
    int count = 0;
    Ticket* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    cout << "Total Tickets: " << count << endl;
}

void findNextTicket(int id) {
    if (head == nullptr) {
        cout << "No tickets booked.\n";
        return;
    }
    Ticket* temp = head;
    do {
        if (temp->ticketID == id) {
            cout << "Next Ticket after ID " << id << ":\n";
            cout << "ID: " << temp->next->ticketID << ", Customer: " << temp->next->customerName << ", Ride: " << temp->next->rideName << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Ticket with ID " << id << " not found.\n";
}

int main() {
    issueTicketEnd(101, "Ali", "Roller Coaster");
    issueTicketEnd(102, "Sara", "Ferris Wheel");
    issuePriorityTicketFront(100, "VIP Ahmed", "Haunted House");

    displayTickets();
    countTickets();

    searchTicketByID(102);
    findNextTicket(101);

    cancelTicketByID(102);
    displayTickets();

    cancelFirstTicket();
    displayTickets();

    return 0;
}
