#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,p,s;
    cin>>n>>p>>s;
    set <string> name;
    map <string,int> test,point;
    for (int i=0;i<n;i++) {
        string t;
        cin>>t;
        name.insert(t);
        point[t]=0;
    }
    for (int i=0;i<p;i++) {
        string temp;
        cin>>temp;
        cin>>test[temp];
    }
    for (int i=0;i<s;i++) {
        string m,p,k;
        cin>>m>>p>>k;
        if (name.count(m)==1) {
            if (k=="AC") {
                point[m]+=test[p];
            }
        }
    }
    for (auto i=point.begin();i!=point.end();i++) {
        cout<<i->first<<" "<<i->second<<endl;
    }
}
