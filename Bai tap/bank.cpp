#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<pair<int,int>>s;
    int n;
    while (cin>>n) {
        if (n==0) break;
        else if (n==1) {
            int k,p;
            cin>>k>>p;
            s.insert(make_pair(p,k));
        } else if (n==3) {
            if (s.empty()) cout<<0<<endl;
            else {
                cout<<(*s.begin()).second<<endl;
                s.erase(s.begin());
            }
        } else {
            if (s.empty()) cout<<0<<endl;
            else {
                auto it=s.end();
                it--;
                cout<<(*it).second<<endl;
                s.erase(it);
            }
        }
    }
}
