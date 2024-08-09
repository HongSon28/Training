#include<bits/stdc++.h>
using namespace std;
vector<int>nt;
void sang(int n) {
    bool p[n+1];
    memset(p,true,sizeof(p));
    p[0]=false;
    p[1]=false;
    for (int i=2;i<=n;i++) {
        if (p[i]==true) {
            for (int j=i*2;j<=n;j+=i) p[j]=false;
        }
    }
    for (int i=2;i<=n;i++) {
        if (p[i]==true) nt.push_back(i);
    }
}
int main(){
    int n;
    cin>>n;
    sang(n);
    int res=0;
    for (int i=0;i<nt.size()-1;i++) {
        for (int j=i+1;j<nt.size();j++) {
            if (nt[i]*nt[j]<=n)
                res=max(res,nt[i]*nt[j]);
        }
    }
    cout<<res;
}
