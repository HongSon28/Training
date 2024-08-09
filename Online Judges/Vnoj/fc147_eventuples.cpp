#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,q;
int a[N+5];
long long odd[N+5],even[N+5];
int main(){
    cin>>n>>q;
    odd[0]=0,even[0]=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        odd[i]=odd[i-1];
        even[i]=even[i-1];
        if (a[i]%2==1) odd[i]++;
        else even[i]++;
    }
    while (q--) {
        int l,r;
        cin>>l>>r;
        long long n_odd=odd[r]-odd[l-1];
        long long n_even=even[r]-even[l-1];
        long long res=n_even*n_odd*(n_odd-1)/2+n_even*(n_even-1)*(n_even-2)/6;
        cout<<res<<endl;
    }
}
