#include<bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>b;
    cin>>a;
    int n=a.length();
    int m=b.length();
    int kq=0;
    int vt[255];
    for (int i=0;i<=n-m;i++) {
        if (a[0]==b[0]) {
            int dem=0;
            for (int j=0;j<m;j++) {
                if (a[i+j]==b[j])
                    dem+=1;
            }
            if (dem==m) {
                vt[kq]=i+1;
                kq+=1;
            }

        }
    }
    cout<<kq<<endl;
    for (int i=0;i<kq;i++) {
        cout<<vt[i]<<" ";
    }
}
