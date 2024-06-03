#include <bits/stdc++.h>
using namespace std;
long long n;
long long a,b;
long long l=a,r=1e9,kq=0;
bool check(long long m){
    long long sum=((m-1)*b+2*a)*m/2;
    if(sum<=n)
        return true;
    return false;
}
int main(){
    cin>>n;
    cin>>a>>b;
    while(l<=r){
        long long m=(l+r)/2;
        if(check(m)){
           l=m+1;
           kq=m;
        }
        else
            r=m-1;
    }
    long long sum=((kq-1)*b+2*a)*kq/2;
    if(sum<n) kq++;
    cout<<kq;
}
