#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
};

void display(Student s[], int n) {
    cout << "\nRank\tName\tScore\n";
    cout << "------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << s[i].name << "\t" << s[i].score << "\n";
    }
}

void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].score < s[j + 1].score) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 5;

    Student s[5] = {
        {"Rahul", 95},
        {"Priya", 90},
        {"Amit", 85},
        {"Sneha", 80},
        {"Rohan", 75}
    };

    cout << "Original Ranking:";
    display(s, n);

    // update score
    string name;
    int newScore;

    cout << "\nEnter student name to update: ";
    cin >> name;
    cout << "Enter new score: ";
    cin >> newScore;

    for (int i = 0; i < n; i++) {
        if (s[i].name == name) {
            s[i].score = newScore;
            cout << "Score updated!\n";
            break;
        }
    }

    // sort again using bubble sort
    bubbleSort(s, n);

    cout << "\nUpdated Ranking:";
    display(s, n);

    return 0;
}