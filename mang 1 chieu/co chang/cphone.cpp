#include<bits/stdc++.h>
using namespace std;
struct ts {
    int index;
    int vote;
};
bool comp(ts a, ts b) {
    if (a.vote==b.vote)
        return a.index<b.index;
    return a.vote>b.vote;
}
int main() {
    int n;
    cin>>n;
    ts a[100001];
    for (int i=1;i<=100001;i++) {
        a[i].vote=0;
        a[i].index=i;
    }
    for (int i=1;i<=n;i++) {
        int temp;
        cin>>temp;
        a[temp].vote++;
    }
    sort(a+1,a+100001,comp);
    cout<<a[1].index<<endl;
    for (int i=2;i<=n;i++) {
        if (a[i].vote==a[i-1].vote) {
            cout<<a[i].index<<endl;
        } else {
            return 0;
        }
    }
}
