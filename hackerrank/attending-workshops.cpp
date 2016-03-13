#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
class Workshops {
    public:
    int start_time, duration, end_time;
    Workshops() {}
    Workshops(int s, int d) : start_time(s), duration(d), end_time(s+d) {}
};

class Available_Workshops {
    public:
    int n;
    Workshops * workshops;
    Available_Workshops(int num) : n(num) {
        workshops = new Workshops[num];
    }
    ~Available_Workshops() {
        free(workshops);
    }
};

Available_Workshops* initialize (int start_time[], int duration[], int n) {
    Available_Workshops* aws = new Available_Workshops(n);
    for (int i = 0; i < n; i++) {
        aws->workshops[i].start_time = start_time[i];
        aws->workshops[i].duration = duration[i];
        aws->workshops[i].end_time = start_time[i] + duration[i];
    }
    return aws;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int ans = 1;
    sort(ptr->workshops, ptr->workshops + ptr->n, 
         [](Workshops const & a, Workshops const & b) -> bool
          { return a.end_time < b.end_time; });
    if (ptr->n == 1) return ans;
    int end = ptr->workshops[0].end_time;
    for (int i = 1; i < ptr->n; i++) {
        if (ptr->workshops[i].start_time >= end) {
            ans++;
            end = max(end, ptr->workshops[i].end_time);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int start_time[n],duration[n];
    for(int i=0;i<n;i++)
    {
        cin>>start_time[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>duration[i];
    }
    
    Available_Workshops * ptr;
    ptr=initialize(start_time,duration,n);
    cout<<CalculateMaxWorkshops(ptr)<<endl;
    return 0;
}

