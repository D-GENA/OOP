#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

class Animal {
private:
    int size;
    int height;
    string name;
    bool isMammal;

public:
    Animal() {
        isMammal = true;
        size = 1;
    }

    void speak() {
        cout << "Speaking animal language\n";      
    }

    void move() {
        cout << "Animal on the move\n\n\n";
    }

    void setAttributes(int s, int h, string n, bool m) {
        size = s; height = h; name = n; isMammal = m;
    }

    void displayInfo() {
        cout << "~~Animal Attributes~~";
        cout << "\nName: " << name;
        cout << "\nSize: " << size;
        cout << "\nHeight: " << height;

        if (isMammal == true) {
    cout << "\nType: Mammal";
} 

        else if(isMammal == true) {
    cout << "\nType: Reptile";
}
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~\n";
    }
};

class Reptile : public Animal {
public:
    Reptile() {
        setAttributes(1, 0, "Any Reptile", false);
    }

    void speak() {
        cout << "The reptile snaps.\n";
    }

    void move() {
        cout << "The reptile crawls.\n";
    }

    void setAttributes(int s, int h, string n, bool m) {
        if (m == true) {
            cout << " A reptile cannot be a mammal!";
            Animal::setAttributes(s, h, n, false);
        } else {
            Animal::setAttributes(s, h, n, false);
        }
    }
};

int main() {
    Animal A;
    A.setAttributes(2, 1, "Cow", true);
    A.displayInfo();
    A.speak();
    A.move();


    Reptile R;
    R.setAttributes(2, 1, "Crocodile", false);
    R.displayInfo();
    R.speak();
    R.move();

    return 0;
}