#include "testlib.h"
#include <bits/stdc++.h>>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int sub = opt<int>("sub");
    int t = opt<int>("t");
    if (sub == 1) cout << 1 << endl << rnd.next(1,1000)<<endl;
    else if (sub == 2) {
        cout<<t<<endl;
        for (int i=1;i<=t;i++) cout<<rnd.next(2,(int)1e6)<<endl;
    } else {
        cout<<t<<endl;
        for (int i=1;i<=t;i++) cout<<rnd.next(2,(int)1e6)<<endl;
    }
}

