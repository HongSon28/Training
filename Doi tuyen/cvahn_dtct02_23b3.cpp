#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,res=-1;
int a[N+5];
int c[N+5];
vector<int>compress;
int main() {
    freopen("RUSDOLL.INP","r",stdin);
    freopen("RUSDOLL.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        compress.push_back(a[i]);
    }
    sort(compress.begin(),compress.end());
    compress.resize(unique(compress.begin(),compress.end())-compress.begin());
    for (int i=1;i<=n;i++) a[i]=lower_bound(compress.begin(),compress.end(),a[i])-compress.begin()+1;
    for (int k=1;k<=n/2;k++) {
        vector<int>v1,v2;
        bool flag=true;
        for (int i=1;i<=k;i++) c[a[i]]++;
        for (int i=1;i<=n;i++) while (c[i]>0) v1.push_back(i),c[i]--;
        for (int i=k+1;i<=k+k;i++) c[a[i]]++;
        for (int i=1;i<=n;i++) while (c[i]>0) v2.push_back(i),c[i]--;
        for (int i=0;i<v1.size();i++) {
            if (v1[i]>=v2[i]) {
                flag=false;
                break;
            }
        }
        if (flag) res=k;
    }
    cout<<res;
}
/*
10
2 1 4 2 3 2 4 5 2 3
*/
