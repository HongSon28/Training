#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map<pair<string,string>, int> mp1;
    int res=0;
    for (int i=0;i<n;i++) {
        string a,b;
        cin>>a>>b;
        a=a.substr(0,2);
        if (a!=b){
            res+=mp1[make_pair(b,a)];
        }
        mp1[make_pair(a,b)]++;
    }
    cout<<res;
}
