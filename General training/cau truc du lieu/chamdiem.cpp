#include<bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin>>q;
    map <string,int> mp;
    for (int i=0;i<q;i++) {
        int type;
        cin>>type;
        if (type==1) {
            string name;
            int temp;
            cin>>name>>temp;
            mp[name]+=temp;
        } else if (type==2) {
            string name;
            cin>>name;
            mp[name]=0;
        } else {
            string name;
            cin>>name;
            cout<<mp[name]<<endl;
        }
    }
}
