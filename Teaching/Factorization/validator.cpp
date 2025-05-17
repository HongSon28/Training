#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, (int)1e6, "T");
    inf.readEoln();
    for (int t=1;t<=T;t++) {
        int n = inf.readInt(2, (int)1e8, "n");
        if (t!=T) inf.readEoln();
    }
    if (T!=1) inf.readEoln();
    inf.readEof();
}
