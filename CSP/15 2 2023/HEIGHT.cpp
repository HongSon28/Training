#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("HEIGHT.INP","r",stdin);
    //freopen("HEIGHT.OUT","w",stdout);
    int q;
    cin>>q;
    while (q--) {
        int n;
        cin>>n;
        int h[n+1],L[n+1],R[n+1],dp1[n+2]={},dp2[n+2]={};
        for (int i=1;i<=n;i++) {
            cin>>h[i];
        }
        deque<int>qmax;
        for (int i=1;i<=n;i++) {
            while (!qmax.empty()&&h[qmax.back()]<h[i]) qmax.pop_back();
            if (qmax.empty()) L[i]=0;
            else L[i]=qmax.back();
            qmax.push_back(i);
        }
        qmax.clear();
        for (int i=n;i>=1;i--) {
            while (!qmax.empty()&&h[qmax.back()]<h[i]) qmax.pop_back();
            if (qmax.empty()) R[i]=n+1;
            else R[i]=qmax.back();
            qmax.push_back(i);
        }
        for (int i=1;i<=n;i++)
            if (h[i]==h[L[i]]) dp1[i]=dp1[L[i]]+1;
        for (int i=n;i>=1;i--)
            if (h[i]==h[R[i]]) dp2[i]=dp2[R[i]]+1;
        for (int i=1;i<=n;i++) {
            cout<<dp1[i]+dp2[i]<<' ';
        }
        cout<<endl;
    }
}
