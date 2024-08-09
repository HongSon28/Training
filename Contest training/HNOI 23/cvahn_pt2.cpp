#include<bits/stdc++.h>
using namespace std;
long long n,k,t;
long long res;
queue<pair<long long,long long>>q;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>t;
        q.push({t,1});
    }
    while(!q.empty()) {
        pair<long long,long long> temp=q.front();
        q.pop();
        res+=temp.first*temp.second;
        if (temp.first%k==0) q.push({temp.first/k,temp.second*k});
        else break;
    }
    while(!q.empty()) {
        res+=q.front().first*q.front().second;
        q.pop();
    }
    cout<<res;
}
