class Solution {
public:
    struct Node {
        char left, right;
        int pre, suf, best, len;
    };

    vector<Node> st;

    Node merge(Node a, Node b){
        Node c;

        c.left = a.left;
        c.right = b.right;
        c.len = a.len + b.len;

        c.pre = a.pre;
        c.suf = b.suf;
        c.best = max(a.best, b.best);

        if (a.right == b.left){
            c.best = max(c.best, a.suf + b.pre);

            if (a.pre == a.len)
                c.pre = a.len + b.pre;

            if (b.suf == b.len)
                c.suf = b.len + a.suf;
        }

        return c;
    }

    void build(string &s, int p, int l, int r){
        if (l == r) {
            st[p] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }

        int m = (l + r) / 2;

        build(s, p * 2, l, m);
        build(s, p * 2 + 1, m + 1, r);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    void update(string &s, int p, int l, int r, int idx){
        if (l == r) {
            st[p] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(s, p * 2, l, m, idx);
        else
            update(s, p * 2 + 1, m + 1, r, idx);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices){

        int n = s.size();

        st.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++){
            int idx = queryIndices[i];
            s[idx] = queryCharacters[i];
            update(s, 1, 0, n - 1, idx);
            ans.push_back(st[1].best);
        }

        return ans;
    }
};