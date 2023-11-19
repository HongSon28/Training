#include<bits/stdc++.h>
using namespace std;
bool used[10];
string s;
int main() {
    cin>>s;
    for (auto i:s) {
        if ((i=='2'||i=='3'||i=='5'||i=='7')&&(!used[i-'0'])) {
            cout<<i<<' ';
            used[i-'0']=true;
        }
    }
}
