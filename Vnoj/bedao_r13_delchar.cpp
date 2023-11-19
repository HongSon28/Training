#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long res;
long long cnt=1;
int main() {
    cin>>n>>s;
    s=' '+s;
    for (int i=1;i<n;i++) {
        if (s[i]==s[i+1]) cnt++;
        else {
            res+=cnt*(cnt-1)/2;
            cnt=1;
        }
        //cout<<s[i]<<' '<<s[i+1]<<' '<<cnt<<endl;
    }
    res+=cnt*(cnt-1)/2;
    cout<<res;
}
