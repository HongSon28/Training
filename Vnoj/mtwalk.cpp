#include<bits/stdc++.h>
using namespace std;
int n;
int mx=INT_MIN;
int mn=INT_MAX;
int a[101][101];
struct td{
    int x,y,mn,mx;
};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool check(int m) {

}
int main() {
    cin>>n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
            mx=max(mx,a[i][j]);
            mn=min(mn,a[i][j]);
        }
    }
    int lo=0,hi=mx-mn;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (check(mid)==true) {
            lo=mid;
        } else {
            hi=mid-1;
        }
    }
}
