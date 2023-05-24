#include<bits/stdc++.h>
using namespace std;
int nt[30000];
bool checknt (int a) {
    for (int i=2;i<=sqrt(a);i++) {
        if (a%i==0)
            return false;
    }
    return true;
}
bool check(int a) {
    if (a%2==0) {
        if (a==30)
            return true;
        else
            return false;
    } else {
        for (int i=1;i<cbrt(a)+1;i++) {
            if (nt[i]*nt[i+1]*nt[i+2]==a)
                return true;
            else if (nt[i]*nt[i+1]*nt[i+2]>a)
                return false;
        }
    }
    return false;
}
int tim(int n) {
    for (int i=n;i>=30;i--) {
        if (check(i)==true) {
            return i;
        }
    }
}
int main() {
    int t;
    cin>>t;
    int n[t];
    int mx=0;
    for (int i=0;i<t;i++) {
        cin>>n[i];
        mx=max(mx,n[i]);
    }
    int demnt=0;
    bool a[30000];
    for (int i=2;i<mx;i++) {
        a[i]=true;
    }
    for (int i=2;i<mx;i++) {
        if (checknt(a[i])==true) {
            for (int j=i*2;j<mx;j+=i) {
                a[j]=false;
            }
        }
    }
    for (int i=2;i<mx;i++) {
        if (a[i]==true) {
            nt[demnt]=i;
            demnt++;
        }
    }
    int kq[t];
    for (int i=0;i<t;i++) {
        if (n[i]<30) {
            kq[i]=-1;
        } else {
            kq[i]=tim(n[i]);
        }

    }
    for (int i=0;i<t;i++) {
        cout<<kq[i]<<endl;
    }
}
