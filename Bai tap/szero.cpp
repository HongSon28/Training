#include<bits/stdc++.h>
using namespace std;
map<long long,int>mp;
long long a[1000005];
int main() {
    int n;
    cin>>n;
    long long sum=0,res=0,l,h;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        sum+=a[i];
        if (sum==0) {
            if (i>res) {
                res=i;
                l=1;
                h=i;
            }
        } else {
            if (mp[sum]==0) {
                mp[sum]=i;
            } else {
                if (i-mp[sum]>res) {
                    res=i-mp[sum];
                    l=mp[sum]+1;
                    h=i;
                }
            }
        }
    }
    cout<<l<<' '<<h;
}
