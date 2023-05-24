#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("KHACNHAU.inp","r",stdin);
    freopen("KHACNHAU.out","w",stdout);
    int n,cnt=1;
    vector <int> p;
    while(cin>>n){
        p.push_back(n);
    }
    sort(p.begin(),p.end());
    for(int i=1;i<p.size();i++)
        if(p[i]!=p[i-1]) cnt++;
    cout<<cnt;
}
