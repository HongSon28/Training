#include<bits/stdc++.h>
using namespace std;
bool check(int n) {
    if (n<11)
        return false;
    int comp=n%10;
    n/=10;
    while (n!=0) {
        int temp=n%10;
        if (temp>comp)
            return false;
        comp=temp;
        n/=10;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    int res=0;
    for (int i=0;i<n;i++) {
        if (check(a[i])==true) {
            res++;
        }
    }
    cout<<res;
}
