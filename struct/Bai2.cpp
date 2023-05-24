#include<bits/stdc++.h>
using namespace std;
struct dt {
    int a,b,c;
};
int main() {
    int n;
    cin>>n;
    dt td[n];
    for (int i=0;i<n;i++) {
        cin>>td[i].a>>td[i].b>>td[i].c;
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (td[i].a*td[j].b-td[j].a*td[i].b!=0)
                cout<<i+1<<" "<<j+1<<endl;
        }
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            int d=td[i].a*td[j].b-td[j].a*td[i].b;
            int dx=td[i].c*td[j].b-td[j].c*td[i].b;
            int dy=td[i].a*td[j].c-td[j].a*td[i].c;
            if (d==0&&(dx!=0||dy!=0))
                cout<<i+1<<" "<<j+1<<endl;
        }
    }
}
