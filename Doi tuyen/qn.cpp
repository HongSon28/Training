#include<bits/stdc++.h>
using namespace std;
int n,x,pos;
vector<int>v;
void prep() {
    v.push_back(0);
    v.push_back(1);
    for (int i=1;i<n;i++) {
        for (int j=v.size()-1;j>=0;j--) v.push_back(v[j]+(1<<i));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x;
    prep();
    for (int i=0;i<v.size();i++) {
        if (v[i]==x) {
            pos=i;
            break;
        }
    }
    for (int i=pos-1;i>=0;i--) cout<<v[i]<<'\n';
    for (int i=(1<<n)-1;i>pos;i--) cout<<v[i]<<'\n';
}
