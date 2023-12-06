#include<bits/stdc++.h>
using namespace std;
struct shop {
    int num,price,index,buy;
};
bool comp(shop a, shop b) {
    if (a.price==b.price)
        return a.index>b.index;
    return a.price<b.price;
}
bool comp2(shop a, shop b) {
    return a.index<b.index;
}
int main() {
    ifstream inp("buy.inp");
    ofstream out("buy.out");
    int m,n;
    inp>>m>>n;
    shop a[n];
    for (int i=0;i<n;i++) {
        inp>>a[i].num>>a[i].price;
        a[i].index=i;
        a[i].buy=0;
    }
    sort(a,a+n,comp);
    int money=0;
    for (int i=0;i<n;i++) {
        if (m>a[i].num) {
            m-=a[i].num;
            money+=a[i].price*a[i].num;
            a[i].buy=a[i].num;
        } else {
            money+=a[i].price*m;
            a[i].buy=m;
            break;
        }
    }
    sort(a,a+n,comp2);
    out<<m<<" "<<money<<endl;
    for (int i=0;i<n;i++)
        out<<a[i].buy<<endl;
}
