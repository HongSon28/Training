#include<bits/stdc++.h>
using namespace std;
bool checknt(int a) {
    for (int i=2;i<=sqrt(a);i++) {
        if (a%i==0)
            return false;
    }
    return true;
}
int main() {
    int n;
    while(cin>>n) {
        int a[n+1]={};
        int m=2;
        for (int i=2;i<=n;i++) {
            int temp=i;
            int chia=2;
            while (temp>1) {
                if (temp%chia==0) {
                    a[chia]++;
                    temp/=chia;
                } else {
                    chia++;
                }
                m=max(m,chia);
            }
        }
        for (int i=2;i<=m;i++) {
            if (checknt(i)==true) {
                cout<<a[i]<<" ";
            }
        }
    }
}
