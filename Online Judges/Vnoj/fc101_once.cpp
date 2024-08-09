#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
int a[2*N+5];
map<int,int>mp;
int main() {
    cin>>n;
    for (int i=1;i<=2*n+1;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        if (i->second==1) {
            cout<<i->first;
            return 0;
        }
    }
}
