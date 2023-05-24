#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int kq[t];
    for (int i=0;i<t;i++) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int dem=0;
        int luu=0;
        for (int j=0;j<n;j++) {
            if (s[j]=='(')
                dem++;
            else
                dem--;
            if (dem<0) {
                int temp=abs(dem);
                luu=max(luu,temp);
            }
        }
        kq[i]=luu;
    }
    for (int i=0;i<t;i++)
        cout<<kq[i]<<endl;
}
