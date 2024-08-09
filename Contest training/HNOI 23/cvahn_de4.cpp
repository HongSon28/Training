#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt1,cnt2;
long long res;
int main() {
    cin>>s;
    for (auto i:s) {
        if (i=='a'||i=='e'||i=='i'||i=='o'||i=='u') cnt1++;
        else res+=cnt1;
    }
    for (auto i:s) {
        if (i=='a'||i=='e'||i=='i'||i=='o'||i=='u') res+=cnt2;
        else cnt2++;
    }
    cout<<res;
}
