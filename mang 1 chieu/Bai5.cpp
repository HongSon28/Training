#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    int dem=0;
    cin>>n;
    int a[64];
    while (n!=0) {
        a[dem]=n%16;
        dem+=1;
        n/=16;
    }
    for (int i=dem-1;i>=0;i--)
        if (a[i]==10)
            cout<<"A";
        else if (a[i]==11)
            cout<<"B";
        else if (a[i]==12)
            cout<<"C";
        else if (a[i]==13)
            cout<<"D";
        else if (a[i]==14)
            cout<<"E";
        else if (a[i]==15)
            cout<<"F";
        else
            cout<<a[i];
}
