#include<iostream>
using namespace std;



class Player{
    public:
    int rating;
    Player* next;
    Player(int rat) : rating(rat){
        next = nullptr;
    }
};

class PriorityQueue{
    Player* root;

    public:
    PriorityQueue(){
        root = nullptr;
    }

    void insert(int rating){
        Player* newPlayer = new Player(rating);

        if(!root || newPlayer->rating > root->rating){
            newPlayer->next = root;
            root = newPlayer;
            return;
        }
        Player* curr = root;
        while(curr->next && curr->next->rating >= newPlayer->rating){
            curr = curr->next;
        }
        Player* temp = curr->next;
        curr->next = newPlayer;
        newPlayer->next = temp;
    }

    void remove(){
        if(!root){
            return;
        }

        Player* temp = root;
        root = root->next;
        delete temp;
    }

    void display() {
        Player* curr = root;
        while (curr) {
            cout << curr->rating << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};



int main(){

    PriorityQueue pq;

    pq.insert(1500);
    pq.insert(1200);
    pq.insert(1800);
    pq.insert(1600);
    pq.display();
    
    pq.insert(1700);
    pq.display();
    
    pq.remove();
    pq.display();

    return 0;
    
}