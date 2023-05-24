#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int calc (int a,int b,int c, int d) {
    return (c-a)*(c-a)+(d-b)*(d-b);
}
int fi(int a1,int a2, int b1, int b2) {
    int lo=-N,hi=N;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        //cout<<lo<<' '<<hi<<' '<<mid<<endl;
        if (a1<=mid&&a2>=mid&&b1<=mid&&b2>=mid) {
            return mid;
        } else if (mid<a1||mid<b1) lo=mid+1;
        else hi=mid-1;
    }
    return -N;
}
int main() {
    freopen("COVERED.INP","r",stdin);
    freopen("COVERED.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if (fi(y1,y2,y3,y4)!=-N) {
            int t=fi(y1,y2,y3,y4);
            cout<<calc(x2,t,x3,t)<<endl;
        } else {
            cout<<min({calc(x1,y1,x3,y3),calc(x1,y1,x4,y4),calc(x2,y2,x3,y3),calc(x2,y2,x4,y4)})<<endl;
        }
    }
}
