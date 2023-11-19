#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
string s[N+5];
pair<int,int>p[N+5];
int cnt(string t) {
    int ans=0;
    for (auto i:t) {
        if (i>='0'&&i<='9') ans++;
    }
    return ans;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        p[i].second=i;
        p[i].first=cnt(s[i]);
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) cout<<s[p[i].second]<<'\n';
}
