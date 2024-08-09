#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    string res;
    if (a[1]!=b[n]) {
        for (int i=1;i<=n;i++) res+='b';
        for (int i=1;i<=n;i++) res+='a';
    } else if (a[n]!=b[1]) {
        for (int i=1;i<=n;i++) res+='a';
        for (int i=1;i<=n;i++) res+='b';
    } else {
        int t=1;
        res+='a';
        while (a[t]==b[1]||a[t+1]==b[n]) {
            t++;
            res+='a';
        }
        for (int i=1;i<=n;i++) res+='b';
        for (int i=t+1;i<=n;i++) res+='a';
    }
    cout<<res;
}
