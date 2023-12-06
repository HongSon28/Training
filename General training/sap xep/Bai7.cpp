#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
   return a > b;
}
int main() {
    int n,k,tong=0;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        tong+=a[i];
    }
    sort(a,a+n,comp);
    int vt=0, tonggiam=0;
    while(n>=k) {
        tonggiam+=a[vt+k-1];
        vt+=k;
        n-=k;
    }
    cout<<tong-tonggiam;
}
