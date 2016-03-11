#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, a;
    vector<int> v;
    cin >> n;
    while (n--) {
        cin >> a;
        v.push_back(a);
    }
    cin >> n;
    while (n--) {
        cin >> a;
        auto iter = lower_bound(v.begin(), v.end(), a);
        cout << (*iter==a?"Yes ":"No ") << (distance(v.begin(), iter) + 1) << endl;
    }
    return 0;
}