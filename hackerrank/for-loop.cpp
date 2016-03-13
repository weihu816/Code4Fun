#include <iostream>
#include <cstdio>
using namespace std;

void printNum(int i) {
    if (i <= 0 || i > 9) return;
    if (i == 1) {
        cout << "one";
    } else if (i == 2) {
        cout << "two";
    } else if (i == 3) {
        cout << "three";
    } else if (i == 4) {
        cout << "four";
    } else if (i == 5) {
        cout << "five";
    } else if (i == 6) {
        cout << "six";
    } else if (i == 7) {
        cout << "seven";
    } else if (i == 8) {
        cout << "eight";
    } else {
        cout << "nine";
    }
    cout << endl;
}

void printOddEven(int i) {
    if (i <= 9) return;
    if (i % 2 == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }
}
int main() {
    // Complete the code.
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        printNum(i);
        printOddEven(i);
    }
}
