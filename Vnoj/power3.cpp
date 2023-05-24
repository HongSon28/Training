#include<bits/stdc++.h>
using namespace std;
bool check(float a) {
    if (a-(int)a==0)
        return true;
    else
        return false;
}
int main() {
    int t;
    cin>>t;
    int kq[t];
    for (int i=0;i<t;i++) {
        long long n;
        cin>>n;
        float a=cbrt(n);
        if (check(a)==true)
            kq[i]=1;
        else
            kq[i]=0;
    }
    for (int i=0;i<t;i++) {
        if (kq[i]==1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}
