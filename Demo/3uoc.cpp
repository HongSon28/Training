#include<bits/stdc++.h>
using namespace std;
bool check(long long a) {
    for (long long i=2;i<=sqrt(a);i++) {
        if (a%i==0)
            return false;
    }
    return true;
}
int main() {
    long long n;
    cin>>n;
    long long a[n];
    for (long long i=0;i<n;i++)
        cin>>a[i];
    for (long long i=0;i<n;i++) {
        long long temp=sqrt(a[i]);
        if (temp*temp==a[i]) {
            if (check(temp)==false||a[i]==1)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}

