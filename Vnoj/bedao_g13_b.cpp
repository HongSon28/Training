#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5];
long long inf=1e16;
long long res=inf;
long long sum;
long long minleft[N+5],minright[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    long long temp=0;
    minleft[0]=inf;
    for (int i=1;i<=n;i++) {
        temp+=a[i];
        if (temp>0) temp=0;
        minleft[i]=min(minleft[i-1],temp);
    }
    temp=0;
    minright[n+1]=inf;
    for (int i=n;i>=1;i--) {
        temp+=a[i];
        if (temp>0) temp=0;
        minright[i]=min(minright[i+1],temp);
    }
    for (int i=1;i<n;i++) {
        res=min(res,minleft[i]+minright[i+1]);
    }
    cout<<sum-res*2;
}
