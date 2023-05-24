#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int i=0;i<t;i++) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sum=0;
        if (s[0]=='0') sum=0;
        else sum=1;
        for (int j=1;j<n;j++) {
            if (s[j]=='0') {
                cout<<'+';
            } else {
                if (sum==1) {
                    cout<<'-';
                    sum--;
                } else {
                    cout<<'+';
                    sum++;
                }
            }
        }
        cout<<endl;
    }
}
