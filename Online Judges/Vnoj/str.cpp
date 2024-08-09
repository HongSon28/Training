#include<bits/stdc++.h>
using namespace std;
string s;
int res;
int main() {
    cin>>s;
    for (auto i:s) {
        if (i!='0'&&i!='1') res++;
    }
    cout<<res;
}
