#include<bits/stdc++.h>
using namespace std;
int main() {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int t1=abs(x1-x2);
    int t2=abs(y1-y2);
    if ((t1==1&&t2==2)||(t1==2&&t2==1)) cout<<"Yes";
    else cout<<"No";
}
