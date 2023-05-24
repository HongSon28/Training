#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    pair<int,int>a[n+1];
    map<pair<int,int>,int>mp;
    mp[make_pair(0,0)]=1;
    for (int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    for (int i=1;i<=n;i++) {
        vector<pair<pair<int,int>,int>>v;
        for (auto j=mp.begin();j!=mp.end();j++) {
            pair<int,int>t1=j->first;
            pair<int,int>t2=make_pair(t1.first+a[i].first,t1.second+a[i].second);
            v.push_back(make_pair(t2,j->second));
        }
        for (int j=0;j<v.size();j++) {
            mp[v[j].first]+=v[j].second;
        }
        //for (auto j=mp.begin();j!=mp.end();j++) cout<<(j->first).first<<' '<<(j->first).second<<' '<<j->second<<endl;
        //cout<<endl;
    }
    int u,v;
    cin>>u>>v;
    cout<<mp[make_pair(u,v)];
}
