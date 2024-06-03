#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxN = 100000;
const long long turtle = static_cast<long long>(1e18) + 1;

struct Racer {
    int a, b, c, xid1, xid2;
};

struct Line {
    int x1, x2, d;
    long long y1, y2;
};

struct Node {
    Line line;
    int L, H;
};

Racer r[maxN + 1];
int xarr[maxN + 1];
Node tree[4 * maxN + 1];
int leaf[maxN + 1];
int nx, n, k;
long long res;

void Sort(int L, int H) {
    if (L >= H) return;
    int i = L + rand() % (H - L + 1),j;
    swap(r[i], r[L]);
    i = L, j = H;
    Racer pivot = r[L];
    while (i < j) {
        while (r[j].a > pivot.a && i < j) j--;
        if (i < j) {
            r[i] = r[j];
            i++;
        }
        while (r[i].a < pivot.a && i < j) i++;
        if (i < j) {
            r[j] = r[i];
            j--;
        }
    }
    r[i] = pivot;
    Sort(L, i - 1);
    Sort(i + 1, H);
}

void Enter() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> r[i].a >> r[i].b >> r[i].c;
    }
    Sort(1, n);
}

void MakeLine(Line& res, int a, int b, int c, long long start) {
    res.x1 = a;
    res.x2 = b;
    res.d = c;
    res.y1 = start;
    res.y2 = static_cast<long long>(b - a) * c + start;
}

long long Time(const Line& l, int x) {
    return static_cast<long long>(x - l.x1) * l.d + l.y1;
}

void Build(int node, int low, int high) {
    tree[node].L = low;
    tree[node].H = high;
    MakeLine(tree[node].line, xarr[low], xarr[high], 0, turtle);
    if (low == high) {
        leaf[low] = node;
    } else {
        int middle = (low + high) / 2;
        Build(node * 2, low, middle);
        Build(node * 2 + 1, middle + 1, high);
    }
}

int Search(int xv) {
    int low = 1, high = nx;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (xarr[middle] <= xv) low = middle + 1;
        else high = middle - 1;
    }
    return high;
}

void Init() {
    nx = 0;
    int old = -1;
    for (int i = 1; i <= n; i++) {
        if (r[i].a != old) {
            old = r[i].a;
            nx++;
            xarr[nx] = old;
        }
        r[i].xid1 = nx;
    }
    for (int i = 1; i <= n; i++) {
        r[i].xid2 = Search(r[i].b);
    }
    Build(1, 1, nx);
}

void PartialLine(Line& newline, const Line& line, int x1, int x2) {
    newline.x1 = x1;
    newline.x2 = x2;
    newline.d = line.d;
    newline.y1 = Time(line, x1);
    newline.y2 = Time(line, x2);
}

void Swap(Line& l1, Line& l2) {
    Line temp = l1;
    l1 = l2;
    l2 = temp;
}

void UpdateNode(int node, Line& aline) {
    if (tree[node].line.y1 <= aline.y1 && tree[node].line.y2 <= aline.y2) return;
    if (tree[node].line.y1 >= aline.y1 && tree[node].line.y2 >= aline.y2) {
        tree[node].line = aline;
        return;
    }
    if (tree[node].line.y1 < aline.y1) Swap(tree[node].line, aline);
    int M = (tree[node].L + tree[node].H) / 2;
    if (aline.x1 <= xarr[M]) {
        if (tree[node * 2].line.y2 > aline.y2) UpdateNode(node * 2, aline);
        else PartialLine(aline, tree[node * 2].line, aline.x1, xarr[M]);
    }
    if (aline.x2 >= xarr[M + 1]) {
        if (tree[node * 2 + 1].line.y2 > aline.y2) UpdateNode(node * 2 + 1, aline);
        else PartialLine(aline, tree[node * 2 + 1].line, xarr[M + 1], aline.x2);
    }
}

void InsertToTree(int node, int xv) {
    if (tree[node].L == tree[node].H) {
        UpdateNode(node, r[tree[node].L].line);
        return;
    }
    int M = (tree[node].L + tree[node].H) / 2;
    if (xv <= xarr[M]) InsertToTree(node * 2, xv);
    else InsertToTree(node * 2 + 1, xv);
    UpdateNode(node, r[tree[node].L].line);
}

long long Query(int node, int xq) {
    if (tree[node].L == tree[node].H) return Time(tree[node].line, xq);
    int M = (tree[node].L + tree[node].H) / 2;
    if (xq <= xarr[M]) return min(Time(tree[node].line, xq), Query(node * 2, xq));
    else return min(Time(tree[node].line, xq), Query(node * 2 + 1, xq));
}

void Solve() {
    for (int i = 1; i <= n; i++) {
        r[i].line.y1 = turtle;
        r[i].line.y2 = turtle;
    }
    res = turtle;
    for (int i = 1; i <= n; i++) {
        int d = r[i].xid2;
        long long t = Query(1, d) + static_cast<long long>(r[i].c);
        if (t < res) res = t;
        InsertToTree(1, r[i].xid1);
    }
}

void WriteOutput() {
    cout << res << endl;
}

int main() {
    Enter();
    Init();
    Solve();
    WriteOutput();
    return 0;
}