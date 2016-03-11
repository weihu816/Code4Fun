#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, val;
    cin >> n;
    vector<int> v;
    while (n--) {
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}