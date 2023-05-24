#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int cnt1=0,cnt2=0,t;
int a[N+5];
map<int,int>mp;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        if ((i->second)==1) {
            cnt1++;
            t=i->first;
        } else cnt2++;
    }
    if (cnt1==1&&cnt2==1) {
        for (int i=1;i<=n;i++) {
            if (a[i]==t) {
                cout<<i;
                break;
            }
        }
    }
    else if (cnt1==0&&cnt2==1)
        cout<<1;
    else
        cout<<0;
}
