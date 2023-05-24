#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t;
int n,k,m;
int w[N];
int main() {
    freopen("FISHPOOL.INP","r",stdin);
    freopen("FISHPOOL.OUT","w",stdout);
    cin>>t;
    while (t--) {
        cin>>n>>k>>m;
        for (int i=0;i<n;i++) {
            cin>>w[i];
        }
        sort(w,w+n);
        w[n]=1e9;
        if (k==m) {
            cout<<0<<endl;
        }
        else if (k<w[0]) {
            cout<<-1<<endl;
        } else {
            int cnt=0,i=0;
            while (true) {
                if (k>=m) break;
                if (k>=w[i+1]) i++;
                else {
                    int nx=min(m-k,w[i+1]-k);
                    if (nx%w[i]==0) {
                        nx=nx/w[i];
                    }
                    else {
                        nx=nx/w[i]+1;
                    }
                    k+=nx*w[i];
                    cnt+=nx;
                    //cout<<cnt<<' ';
                }
            }
            cout<<cnt<<endl;
        }
    }
}
