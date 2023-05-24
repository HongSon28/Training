#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int kq[1000];
    for (int i=0;i<t;i++) {
        string a,b;
        cin>>a>>b;
        int n=a.length();
        int m=b.length();
        if (m<n) {
            kq[i]=0;
        } else if (m==n) {
            if (a==b) {
                kq[i]=1;
            } else {
                kq[i]=0;
            }
        } else {
            char temp=a[0];
            while (m!=0) {
                while (a[0]==b[0]) {
                    temp=a[0];
                    a.erase(0,1);
                    b.erase(0,1);
                    n--;
                    m--;
                }
                if (a[0]!=b[0]) {
                    if (b[0]==temp) {
                        b.erase(0,1);
                        m--;
                    } else {
                        kq[i]=0;
                        break;
                    }
                }
                if (n==0&&m==0)
                    kq[i]=1;
            }
        }
    }
    for (int i=0;i<t;i++) {
        if (kq[i]==0) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
}
