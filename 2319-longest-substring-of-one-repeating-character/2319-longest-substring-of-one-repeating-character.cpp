class segTree {
public:
    vector<tuple<int, char, int, char, int>> seg;
    int n;
    segTree(int size) {
        n = size;
        seg.resize(4 * n);
    }

    void build(string &s, int i, int l, int r) {
        if (l == r) {
            seg[i] = {1, s[l], 1, s[r], 1};
            return;
        }
        int mid = (l + r) / 2;
        build(s, 2 * i + 1, l, mid);
        build(s, 2 * i + 2, mid + 1, r);

        char rcls = get<3>(seg[2 * i + 1]);
        int rfls = get<4>(seg[2 * i + 1]);
        char lcls = get<1>(seg[2 * i + 1]);
        int lfls = get<2>(seg[2 * i + 1]);
        int llen = get<0>(seg[2 * i + 1]);

        char lcrs = get<1>(seg[2 * i + 2]);
        int lfrs = get<2>(seg[2 * i + 2]);
        char rcrs = get<3>(seg[2 * i + 2]);
        int rfrs = get<4>(seg[2 * i + 2]);
        int rlen = get<0>(seg[2 * i + 2]);

        int ml = max(llen, rlen);
        if (rcls == lcrs) {
            ml = max(ml, rfls + lfrs);
        }
        int prelen = lfls;
        if (lfls == (mid - l + 1) && lcls == lcrs) {
            prelen += lfrs;
        }
        int sufflen = rfrs;
        if (rfrs == (r - mid) && rcls == rcrs) {
            sufflen += rfls;
        }
        seg[i] = {ml, lcls, prelen, rcrs, sufflen};
    }

    void update(int idx, int i, int l, int r, char ch) {
        if (l == r) {
            seg[i] = {1, ch, 1, ch, 1};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(idx, 2 * i + 1, l, mid, ch);
        } else {
            update(idx, 2 * i + 2, mid + 1, r, ch);
        }

        char rcls = get<3>(seg[2 * i + 1]);
        int rfls = get<4>(seg[2 * i + 1]);
        char lcls = get<1>(seg[2 * i + 1]);
        int lfls = get<2>(seg[2 * i + 1]);
        int llen = get<0>(seg[2 * i + 1]);

        char lcrs = get<1>(seg[2 * i + 2]);
        int lfrs = get<2>(seg[2 * i + 2]);
        char rcrs = get<3>(seg[2 * i + 2]);
        int rfrs = get<4>(seg[2 * i + 2]);
        int rlen = get<0>(seg[2 * i + 2]);

        int ml = max(llen, rlen);
        if (rcls == lcrs) {
            ml = max(ml, rfls + lfrs);
        }
        int prelen = lfls;
        if (lfls == (mid - l + 1) && lcls == lcrs) {
            prelen += lfrs;
        }
        int sufflen = rfrs;
        if (rfrs == (r - mid) && rcls == rcrs) {
            sufflen += rfls;
        }
        seg[i] = {ml, lcls, prelen, rcrs, sufflen};
    }

    int query() {
        return get<0>(seg[0]);
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        segTree sg(n);
        sg.build(s, 0, 0, n - 1);
        vector<int> ans(queryCharacters.length());
        for (int i = 0; i < queryCharacters.length(); i++) {
            char ch = queryCharacters[i];
            int idx = queryIndices[i];
            sg.update(idx, 0, 0, n - 1, ch);
            ans[i] = sg.query();
        }
        return ans;
    }
};