#include<bits/stdc++.h>
using namespace std;
int main() {
    short x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    short ax=abs(x1-x2);
    short bx=abs(y1-y2);
    cout<<ax*bx;
}
