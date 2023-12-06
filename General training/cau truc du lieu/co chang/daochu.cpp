#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    pair<string, string> p[n];
    for (int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    for (int i=0;i<n;i++)
        cout<<p[i].second<<' '<<p[i].first<<endl;
}
