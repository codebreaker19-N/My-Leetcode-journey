
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<vector<int>> path(26);

        // First DFS: Find new parents using original tree
        vector<pair<int, bool>> st;
        st.push_back({0, false});

        while (!st.empty()) {
            auto [u, exit] = st.back();
            st.pop_back();

            int c = s[u] - 'a';

            if (exit) {
                path[c].pop_back();
                continue;
            }

            if (!path[c].empty()) {
                newParent[u] = path[c].back();
            } else {
                newParent[u] = parent[u];
            }

            path[c].push_back(u);

            st.push_back({u, true});

            for (int i = adj[u].size() - 1; i >= 0; i--) {
                st.push_back({adj[u][i], false});
            }
        }

        // Build the final tree
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Second DFS: Calculate subtree sizes
        vector<int> order;
        st.clear();
        st.push_back({0, false});

        while (!st.empty()) {
            int u = st.back().first;
            st.pop_back();

            order.push_back(u);

            for (int v : newAdj[u]) {
                st.push_back({v, false});
            }
        }

        vector<int> ans(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};
