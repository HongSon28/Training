#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    pair<string,int> p[n];
    int h[201]={};
    int repeat[201]={};
    int mx=INT_MIN,mn=INT_MAX,r=1;
    for (int i=0;i<n;i++) {
        int n,m;
        cin>>p[i].first;
        cin>>n>>m;
        p[i].second=n+m;
        mx=max(mx,p[i].second);
        mn=min(mn,p[i].second);
        repeat[p[i].second]++;
    }
    while (mx>=mn) {
        if (repeat[mx]>0) {
            h[mx]=r;
            r+=repeat[mx];
        }
        mx--;
    }
    for (int i=0;i<n;i++)
        cout<<p[i].first<<' '<<h[p[i].second]<<endl;
}
