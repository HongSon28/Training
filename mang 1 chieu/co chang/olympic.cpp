#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int gold[n+1],silver[n+1],bronze[n+1];
    gold[0]=0,silver[0]=0,bronze[0]=0;
    for (int i=1;i<=n;i++) {
        if (a[i-1]==1) {
            gold[i]=gold[i-1]+1;
            silver[i]=silver[i-1];
            bronze[i]=bronze[i-1];
        } else if (a[i-1]==2) {
            gold[i]=gold[i-1];
            silver[i]=silver[i-1]+1;
            bronze[i]=bronze[i-1];
        } else {
            gold[i]=gold[i-1];
            silver[i]=silver[i-1];
            bronze[i]=bronze[i-1]+1;
        }
    }
    for (int i=0;i<m;i++) {
        int l,r;
        cin>>l>>r;
        cout<<gold[r]-gold[l-1]<<" "<<silver[r]-silver[l-1]<<" "<<bronze[r]-bronze[l-1]<<endl;
    }
}
