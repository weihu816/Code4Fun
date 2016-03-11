#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    string str;
    int i;
    cin >> n;
    map<string, int> mymap;
    while (n--) {
        cin >> i;
        if (i == 1) {
            cin >> str >> i;
            if (mymap.find(str) == mymap.end()) {
                mymap[str] = i;
            } else {
                mymap[str] += i;
            }
        } else if (i == 2) {
            cin >> str;
            mymap.erase(str);
        } else if (i == 3) {
            cin >> str;
            cout << (mymap.find(str)!=mymap.end()?mymap[str]:0) << endl;
        }
    }
    return 0;
}