#include<bits/stdc++.h>
using namespace std;
struct cay {
    int la;
    int id;
    bool song=true;
};
bool comp(cay a, cay b) {
    if (a.la==b.la)
        return a.id<b.id;
    return a.la<b.la;
}
int main() {
    int n;
    cin>>n;
    cay a[n];
    cay b[n];
    for (int i=0;i<n;i++) {
        cin>>a[i].la;
        a[i].id=i;
        b[i]=a[i];
    }
    sort(a,a+n,comp);
    int day=0;
    for (int i=0;i<n;i++) {
        if (b[a[i].id].song==true) {
            b[a[i].id].song=false;
            b[a[i].id-1].song=false;
            b[a[i].id+1].song=false;
            day++;
        }
    }
    cout<<day;
}
