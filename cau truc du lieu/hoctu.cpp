#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map<string,int> mp;
    for (int i=0;i<n;i++) {
        int type;
        cin>>type;
        if (type==1) {
            string s;
            cin>>s;
            mp[s]++;
        } else {
            string s;
            cin>>s;
            cout<<mp[s]<<endl;
        }
    }
}
