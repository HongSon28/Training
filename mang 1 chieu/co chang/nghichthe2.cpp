#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,j;
    cin>>n;
    int p[n+1],a[n+1];
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=n;i>0;i--) {
        for(j=n;j>0;j--)
            if(p[j]==0)break;
        a[j]=i;
        for(int k=j;k<=n;k++)
        p[k]--;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}
