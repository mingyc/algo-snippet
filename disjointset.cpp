#include <vector>
#include <numeric>
using namespace std;

class DisjointSet{
public:
    DisjointSet(const int &n) {
        id.resize(n);
        iota(id.begin(), id.end(), 0);
        sz.resize(n, 1);
    }
    void unite(const int &p, const int &q) {
        const int pi = root(p);
        const int qi = root(q);
        if (sz[pi] < sz[qi]) {
            id[pi] = qi;
            sz[qi] += sz[pi];
        } else {
            id[qi] = pi;
            sz[pi] += sz[qi];
        }
    }
    bool same(const int &p, const int &q) {
        return root(p) == root(q);
    }
private:
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    vector<int> id;
    vector<int> sz;
};
