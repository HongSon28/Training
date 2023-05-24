#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string a;
    int vn=0;
    int ir=0;
    for (int i=0;i<n;i++) {
        cin>>a;
        if (a=="Vietnam")
            vn+=1;
        else
            ir+=1;
    }
    cout<<vn<<" "<<ir;
}
