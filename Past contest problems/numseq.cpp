#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("C:\\Users\\admin\\Desktop\\input.txt");
    ofstream out;
    out.open("C:\\Users\\admin\\Desktop\\output.txt");
    unsigned n;
    inp>>n;
    unsigned a[n+2];
    a[0]=0;
    a[1]=1;
    for (unsigned i=2;i<=n+1;i++) {
        a[i]=(2*a[i-1]-a[i-2]+1);
    }
    unsigned x=pow((a[n+1]-a[n]),2);
    cout<<x;
    out<<x%10;
    inp.close();
    out.close();
}
