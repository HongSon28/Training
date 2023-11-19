#include<bits/stdc++.h>
using namespace std;
int n;
string t;
int c1,c2;
int main() {
    cin>>n;
    while (n--) {
        cin>>t;
        if (t[0]=='-') c1++;
        else if (t!="0") c2++;
    }
    cout<<c1<<' '<<c2;
}
