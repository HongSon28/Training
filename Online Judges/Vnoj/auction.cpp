#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int a[N+2];
long long res,sum;
int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int temp;
        cin>>temp;
        a[temp]++;
    }
    for (int i=N-1;i>=1;i--) a[i]+=a[i+1];
    for (int i=1;i<=N;i++) {
        long long temp=i*min(a[i],n);
        if (temp>sum) {
            sum=temp;
            res=i;
        }
    }
    cout<<res<<' '<<sum;
}
