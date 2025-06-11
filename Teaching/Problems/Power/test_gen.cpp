#include "testlib.h"
#include <bits/stdc++.h>>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int sub = opt<int>("sub");
    
    cout<<rnd.next(1,(int)1e9)<<' ';
    if (sub == 1) cout<<rnd.next(1,(long long)1e9)<<' ';
    else cout<<rnd.next(1,(long long)1e18)<<' ';
    cout<<rnd.next(1,(int)1e9)<<endl;
}

