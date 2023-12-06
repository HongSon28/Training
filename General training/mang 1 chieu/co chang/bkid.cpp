#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,p;
    cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   p=0;
   for(int i=1;i<n;i++){
        if(a[i]>a[p]) {
            cout<<i+1<<endl;
        } else {
            cout<<p+1<<endl;
            p=i;
        }
    }
}
