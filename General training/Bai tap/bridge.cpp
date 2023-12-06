#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int w,n,res;
int c[N];
int main() {
    cin>>w>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    if (c[1]>w) {
        res=0;
    } else if (c[1]+c[2]>w) {
        res=1;
    } else if (c[1]+c[2]+c[3]>w){
        res=2;
    } else if (c[1]+c[2]+c[3]+c[4]>w) {
        res=3;
    } else {
        res=3;
        int sum=c[1]+c[2]+c[3]+c[4];
        for (int i=5;i<=n;i++) {
            if (sum<=w) res++;
            else break;
            sum+=c[i];
            sum-=c[i-4];
        }
        if (sum<=w) res++;
    }
    cout<<res;
}
