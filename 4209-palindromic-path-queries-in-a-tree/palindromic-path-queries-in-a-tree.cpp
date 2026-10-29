class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy;
    vector<int> head, pos;
    vector<int> seg;
    int timer = 0;

    string s;

    void dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        heavy[u] = -1;

        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];

            if (sz[v] > maxSize) {
                maxSize = sz[v];
                heavy[u] = v;
            }
        }
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;

            decompose(v, v);
        }
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = 1 << (s[getNode(l)] - 'a');
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);

        seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
    }

    vector<int> nodeAtPos;

    int getNode(int p) {
        return nodeAtPos[p];
    }

    void buildArray() {
        nodeAtPos.resize(n);

        for (int u = 0; u < n; u++)
            nodeAtPos[pos[u]] = u;
    }

    void update(int idx, int l, int r, int p, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (p <= mid)
            update(idx * 2, l, mid, p, val);
        else
            update(idx * 2 + 1, mid + 1, r, p, val);

        seg[idx] = seg[idx * 2] ^ seg[idx * 2 + 1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;
        int ans = 0;

        if (ql <= mid)
            ans ^= query(idx * 2, l, mid, ql, qr);

        if (qr > mid)
            ans ^= query(idx * 2 + 1, mid + 1, r, ql, qr);

        return ans;
    }

    int pathQuery(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1,
                          pos[head[u]], pos[u]);

            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }

public:
    vector<bool> palindromePath(int n,
                                vector<vector<int>>& edges,
                                string s,
                                vector<string>& queries) {
        this->n = n;
        this->s = s;

        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        seg.assign(4 * n, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);
        decompose(0, 0);
        buildArray();

        
        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, i,
                   1 << (this->s[nodeAtPos[i]] - 'a'));
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                this->s[u] = c;

                update(1, 0, n - 1, pos[u],
                       1 << (c - 'a'));
            } else {
                int v;
                ss >> v;

                int mask = pathQuery(u, v);

                ans.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};