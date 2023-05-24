#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int res=0;
map<int,vector<int>>mp;
vector<vector<int>>v(N+5);
int main() {
    cin>>n;
    while (n--) {
        int id,s;
        cin>>id>>s;
        mp[id].push_back(s);
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        vector<int>t=i->second;
        for (int j=0;j<t.size()-1;j++) {
            if (t[j]!=t[j+1]) res++;
        }
    }
    cout<<res;
}
