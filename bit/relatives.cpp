#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int t;
long long a[1025];
long long res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>t;
        int temp=0;
        while (t>0) {
            temp|=(1<<t%10);
            t/=10;
        }
        a[temp]++;
    }
    for (int i=0;i<=(1<<10);i++) {
        res+=a[i]*(a[i]-1)/2;
        for (int j=i+1;j<=(1<<10);j++) {
            if (i&j) res+=a[i]*a[j];
        }
    }
    cout<<res;
}
