#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    set <int> a;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        a.insert(temp);
    }
    int m;
    cin>>m;
    int res=0;
    for (int i=0;i<m;i++) {
        int temp;
        cin>>temp;
        if (a.count(temp)==1)
            res++;
    }
    cout<<res;
}
