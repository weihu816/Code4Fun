#include <iostream>
#include <deque> 
using namespace std;
void printKMax(int arr[], int n, int k){
   //Write your code here.
    if (k > n) return;
    deque<int> q;
    int i = 0;
    while (i < k) {
        while (!q.empty() && arr[i] > arr[q.back()]) q.pop_back();
        q.push_back(i);
        i++;
    }
    
    while (i < n) {
        cout << arr[q.front()] << " ";
        if (i - q.front() >= k) q.pop_front();
        while (!q.empty() && arr[i] > arr[q.back()]) q.pop_back();
        q.push_back(i);
        i++;
    }
    cout << arr[q.front()] << endl;
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}