#include<bits/stdc++.h>
using namespace std;
string s;
string x;
int main() {
    cin>>s;
    sort(s.begin(),s.end(),greater<char>());
    for (auto i:s)
        if (i>='a'&&i<='z') x+=i;
        else cout<<i;
    cout<<x;
}
