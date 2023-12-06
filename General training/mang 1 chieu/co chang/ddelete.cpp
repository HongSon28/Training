#include<bits/stdc++.h>
using namespace std;
int main() {
    int sum=0;
    int n;
    cin>>n;
    int odd[n]={};
    int even[n]={};
    int a[n];
    cin>>a[0];
    sum+=a[0];
    if (a[0]%2==0) {
        even[0]=1;
    } else {
        odd[0]=1;
    }
    for (int i=1;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
        if (a[i]%2==0) {
            even[i]=even[i-1]+1;
            odd[i]=odd[i-1];
        } else {
            even[i]=even[i-1];
            odd[i]=odd[i-1]+1;
        }
    }
    int res=0;
    for (int i=0;i<n;i++) {
    }
    if (sum%2==1) {
        for (int i=0;i<n;i++) {
            if (a[i]%2==0) {
                res+=odd[n-1]-odd[i];
            } else {
                res+=even[n-1]-even[i];
            }
        }
    } else {
        for (int i=0;i<n;i++) {
            if (a[i]%2==0) {
                res+=even[n-1]-even[i];
            } else {
                res+=odd[n-1]-odd[i];
            }
        }
    }
    cout<<res;
}
