#include<bits/stdc++.h>
using namespace std;
int n,s;
int res;
int main() {
    cin>>n>>s;
    for (int a=0;a<=n;a++) {
        for (int b=0;b<=n;b++) {
            int c=s-a-b;
            if (c>=0&&c<=n) res++;
        }
    }
    cout<<res;
}
