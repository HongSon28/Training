#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,res=0;
    cin>>n;
    vector<int>v;
    map<int,bool>mp;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        mp[temp]=false;
        v.push_back(temp);
    }
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        mp[temp]=true;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int i=0;
    while (i<v.size()-1) {
        if (mp[v[i]]!=mp[v[i+1]]) {
            res++;
            i+=2;
        } else {
            i++;
        }
    }
    cout<<res;
}
