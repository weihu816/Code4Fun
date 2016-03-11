#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, a, b;
    cin >> n;
    vector<int> vec;
    while (n--) {
        cin >> a;
        vec.push_back(a);
    }
    cin >> a;
    vec.erase(vec.begin() + a - 1);
    cin >> a >> b;
    vec.erase(vec.begin() + a - 1, vec.begin() + b - 1);
    cout << vec.size() << endl;
    for (int &i : vec ) {
        cout << i << " ";
    }
    return 0;
}