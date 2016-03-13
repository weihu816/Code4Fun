#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;


class Box {
    int l, b, h;
    public:
    Box() : l(0), b(0), h(0) {
        BoxesCreated++;
    }
    
    Box(Box& B) {
        l = B.getLength();
        b = B.getBreadth();
        h = B.getHeight();
        BoxesCreated++;
    }
    
    Box(int l, int b, int h) : l(l), b(b), h(h) {
        BoxesCreated++;
    }
    
    ~Box() {
        BoxesDestroyed++;
    }
    
    int getLength() {
        return l;
    }
    
    int getBreadth() {
        return b;
    }
    
    int getHeight() {
        return h;
    }
    
    long long CalculateVolume() {
        return (long long) l * b * h;
    }
    
    bool operator<(Box &B) {
        if (l != B.getLength()) return l < B.getLength();
        if (b != B.getBreadth()) return b < B.getBreadth();
        return h < B.getHeight();
    }
};

ostream& operator<<(ostream& out, Box b) {
    out << b.getLength() << " " << b.getBreadth() << " " << b.getHeight();
    return out;
}


void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
