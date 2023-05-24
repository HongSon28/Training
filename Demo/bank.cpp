#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
           if(s[j]=='U') cout<<"D";
           else if(s[j]=='D') cout<<"U";
           else cout<<s[j];
        }
        cout<<endl;
    }
    return 0;
}
