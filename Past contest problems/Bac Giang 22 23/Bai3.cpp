#include<bits/stdc++.h>
using namespace std;
map<long long,long long>mp;
long long sum=0,res=0;
long long n,k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    mp[0]++;
    for (int i=0;i<n;i++) {
        long long temp;
        cin>>temp;
        sum+=temp;
        long long rem;
        if (sum<0) {
            rem=(sum%k+k)%k;
        } else {
            rem=sum%k;
        }
        mp[rem]++;
        //cout<<rem<<endl;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        //cout<<i->first<<' '<<i->second<<endl;
        long long t=i->second;
        res+=t*(t-1)/2;
    }
    cout<<res;
}
