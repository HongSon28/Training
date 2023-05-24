#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n,sum=0;
    cin>>n;
    long long a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    long long res=0;
    for (int i=0;i<n-1;i++) {
        if (a[i]<sum) {
            res+=sum-a[i];
            a[i+1]-=sum-a[i];
        } else if (a[i]>sum) {
            res+=a[i]-sum;
            a[i+1]+=a[i]-sum;
        }
        //cout<<res<<endl;
    }
    cout<<res;
}
