#include <bits/stdc++.h>
using namespace std;
int n,cnt;
int trai[1000000],gai[1000000];
multiset<int>mam;
multiset<int>mduong;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>trai[i];
        if(trai[i]>0)
            mduong.insert(trai[i]);
        else
            mam.insert(abs(trai[i]));
    }
    for(int i=1;i<=n;i++){
        cin>>gai[i];
        if(gai[i]<0) {
            if(!mduong.empty()){
                if(mduong.lower_bound(abs(gai[i]))!=mduong.begin()){
                    mduong.erase(--mduong.lower_bound(abs(gai[i])));
                    cnt++;
                }
            }
        } else{
           if(!mam.empty()) {
                if(mam.upper_bound(gai[i])!=mam.end()){
                    mam.erase(mam.upper_bound(gai[i]));
                    cnt++;
                }
           }
        }
    }
    cout<<cnt;
}
