#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i=1;i<=5;i++)
        for (int j=1;j<=5;j++) {
            cin>>t;
            if (t==1) {
                cout<<abs(i-3)+abs(j-3);
            }
        }
}
