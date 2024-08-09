#include<bits/stdc++.h>
using namespace std;
int n,x,k;
int res;
int change;
multiset<int>s;
int main() {
    cin>>n>>x;
    while (n--) {
        char type;
        cin>>type>>k;
        if (type=='I') {
            s.insert(k-change);
            res++;
        }
        else if (type=='A') change+=k;
        else if (type=='S') change-=k;
        else {
            if (s.size()<k) cout<<-1<<'\n';
            //else cout<<*(s.begin()+k-1)<<'\n';
        }
        auto it=s.lower_bound(x-change);
        if (it==s.begin()) continue;
        it--;
        s.erase(s.begin(),it);
        cout<<s.size()<<' '<<*it<<endl;
    }
    cout<<res-s.size();
}
