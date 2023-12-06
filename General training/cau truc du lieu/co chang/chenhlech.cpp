#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    pair<int,int>p[n];
    int c[1001]={};
    for (int i=0;i<n;i++) {
        cin>>p[i].first>>p[i].second;
        int temp=abs(p[i].first-p[i].second);
        c[temp]++;
    }
    int a=0,res=0;
    for (int i=0;i<=1000;i++) {
        if (c[i]>a) {
            res=i;
            a=c[i];
        }
    }
    cout<<res<<endl;
    for (int i=0;i<n;i++) {
        int temp=abs(p[i].first-p[i].second);
        if (temp==res) {
            cout<<p[i].first<<' '<<p[i].second<<endl;
        }
    }
}
