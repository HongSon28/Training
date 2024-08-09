#include<bits/stdc++.h>
using namespace std;
int main() {
    char a[4][4];
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            cin>>a[i][j];
    for (int i=0;i<=2;i++) {
        for (int j=0;j<=2;j++) {
            int cnt1=0,cnt2=0;
            if (a[i][j]=='.') cnt1++;
            else cnt2++;
            if (a[i+1][j]=='.') cnt1++;
            else cnt2++;
            if (a[i][j+1]=='.') cnt1++;
            else cnt2++;
            if (a[i+1][j+1]=='.') cnt1++;
            else cnt2++;
            if (cnt1>=3||cnt2>=3) {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}

