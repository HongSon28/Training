#include<bits/stdc++.h>
using namespace std;
bool solve(int n) {
    int sum=0;
    for (int i=1;i*i<n;i++) {
        if (n%i==0) {
            sum+=i;
            sum+=n/i;
        }
    }
    int temp=sqrt(n);
    if (temp*temp==n)
        sum+=temp;
    sum-=n;
    if (sum==n)
        return true;
    return false;
}
int sum(int n) {
    int res=0;
    while (n!=0) {
        res+=n%10;
        n/=10;
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    int res=0;
    for (int i=0;i<n;i++){
        int temp=sum(a[i]);
        if (solve(temp)==true) {
            res++;
        }
    }
    cout<<res;
}
