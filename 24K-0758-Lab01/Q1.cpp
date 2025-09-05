#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authors;  
    int count;       

public:

    ResearchPaper(const string names[], int n) {
        count = n;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = names[i];
        }
    }

    ResearchPaper(const ResearchPaper& other) {
        count = other.count;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = other.authors[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this == &other){
            return *this;
            delete[] authors;
        } 

        count = other.count;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = other.authors[i];
        }

        return *this;
    }

    ~ResearchPaper() {
        delete[] authors;
    }

    void showAuthors() const {
        cout << "Authors: ";
        for (int i = 0; i < count; i++) {
            cout << authors[i];
            if (i < count - 1) cout << ", ";
        }
        cout << endl;
    }
};

int main() {
    string authors1[] = {"Alice", "Bob", "Charlie"};
    ResearchPaper paper1(authors1, 3);

    cout << "Paper1: ";
    paper1.showAuthors();

    ResearchPaper paper2 = paper1;
    cout << "Paper2 (copy of Paper1): ";
    paper2.showAuthors();

    string authors2[] = {"David", "Emma"};
    ResearchPaper paper3(authors2, 2);
    cout << "Paper3 before assignment: ";
    paper3.showAuthors();

    paper3 = paper1;
    cout << "Paper3 after assignment (copy of Paper1): ";
    paper3.showAuthors();

    return 0;
}
