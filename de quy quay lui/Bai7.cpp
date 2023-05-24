#include<bits/stdc++.h>
using namespace std;
int n;
char a[21];
int cnt1=0,cnt2=0;
char c[2]={'(',')'};
bool check(int i) {
    if (i==0) {
        if (cnt1<n)
            return true;
        return false;
    } else {
        if (cnt1<=cnt2) {
            return false;
        } else {
            if (cnt2<n)
                return true;
            return false;
        }
    }
}
void xuat() {
    for (int i=1;i<=2*n;i++)
        cout<<a[i];
    cout<<endl;
}
void dequy(int k) {
    for (int i=0;i<2;i++) {
        if (check(i)==true) {
            a[k]=c[i];
            if (i==0)
                cnt1++;
            else
                cnt2++;
            if (k==2*n) {
                xuat();
            } else {
                dequy(k+1);
            }
            if (i==0)
                cnt1--;
            else
                cnt2--;
        }
    }
}
int main() {
    cin>>n;
    dequy(1);
}
