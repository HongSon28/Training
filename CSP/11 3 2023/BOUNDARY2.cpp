#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("BOUNDARY.INP","r",stdin);
    //freopen("BOUNDARY.OUT","w",stdout);
    long long n,res=0;
    cin>>n;
    pair<long long,long long>a[n];
    for (int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    long long last;
    if (a[0].first>a[0].second) {
        res=a[0].first;
        last=a[0].second;
    }
    else {
        res=a[0].second;
        last=a[0].first;
    }
    for (int i=1;i<n;i++) {
        long long d1=abs(last-a[i].first)+a[i].second;
        long long d2=abs(last-a[i].second)+a[i].first;
        if (d1>d2) {
            res+=d1;
            last=a[i].first;
        } else {
            res+=d2;
            last=a[i].second;
        }
    }
    cout<<res;
}

