#include<bits/stdc++.h>
using namespace std;
vector<long long>val;
bool check(long long x) {
    long long y=x*x;
    int c[10]={};
    string s1=to_string(x),s2=to_string(y);
    for (auto i:s1) c[i-'0']++;
    for (auto i:s2) c[i-'0']++;
    for (int i=0;i<=9;i++) if (c[i]>2) return false;
    return true;
}
void prep() {
    for (long long i=1;i<=10000000;i++) if (check(i)) val.push_back(i);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();
    int t;
    cin>>t;
    while (t--) {
        long long n;
        cin>>n;
        auto it=lower_bound(val.begin(),val.end(),n);
        if (it==val.end()) cout<<-1<<'\n';
        else cout<<*it<<'\n';
    }
}
