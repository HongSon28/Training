#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int n;
int main() {
    cin>>n;
    while (n--) {
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        if (i->second%2==1) {
            cout<<i->first;
            return 0;
        }
    }
}
