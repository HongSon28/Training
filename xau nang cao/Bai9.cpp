#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dem=0;
    int i=0;
    while (i<n-2) {
        if (s[i]=='x'&&s[i+1]=='x'&&s[i+2]=='x') {
            s.erase(i+2,1);
            n--;
            dem++;
        } else {
            i++;
        }
    }
    cout<<dem;
}
