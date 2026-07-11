#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Query {
    char type;
    int a;
    int b;
};

struct Fenwick {
    int n;
    vector<int> bit;

    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    int sum(int idx) const {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx) {
            s += bit[idx];
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> salary(n);
    for (int i = 0; i < n; ++i) {
        cin >> salary[i];
    }

    vector<Query> queries(q);
    vector<int> values;
    values.reserve(n + q);
    for (int x : salary) {
        values.push_back(x);
    }

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type >> queries[i].a >> queries[i].b;
        if (queries[i].type == '!') {
            values.push_back(queries[i].b);
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    Fenwick fw((int)values.size());

    auto compressedIndex = [&](int x) {
        return (int)(lower_bound(values.begin(), values.end(), x) - values.begin()) + 1;
    };

    auto countLE = [&](int x) {
        int idx = (int)(upper_bound(values.begin(), values.end(), x) - values.begin());
        return fw.sum(idx);
    };

    for (int x : salary) {
        fw.add(compressedIndex(x), 1);
    }

    for (const Query &qq : queries) {
        if (qq.type == '!') {
            int employee = qq.a - 1;
            int newSalary = qq.b;

            fw.add(compressedIndex(salary[employee]), -1);
            salary[employee] = newSalary;
            fw.add(compressedIndex(salary[employee]), 1);
        } else {
            int lo = qq.a;
            int hi = qq.b;
            cout << (countLE(hi) - countLE(lo - 1)) << '\n';
        }
    }

    return 0;
}