#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>>added,deleted;
string s;
int k,u,v;
int main() {
    while (cin>>s) {
        if (s=="END") return 0;
        if (s=="NEW") {
            cin>>k;

        } else if (s=="ADD") {
            cin>>u>>v;
            added.insert({u,v});
            deleted.erase({u,v});
        } else if (s=="DEL") {
            cin>>u>>v;
            added.erase({u,v});

        } else if (s=="ANY") {

        }
    }
}
