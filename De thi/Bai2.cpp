#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp;
    inp.open("C:\\Users\\admin\\Desktop\\input.txt");
    ofstream out;
    out.open("C:\\Users\\admin\\Desktop\\output.txt");
    int n;
    inp>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        inp>>a[i];
    }
    sort(a,a+n);
    out<<a[n-1]*a[n-2]*a[n-3];
    inp.close();
    out.close();
}

