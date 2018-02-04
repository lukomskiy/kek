deque <int> q;
q.push_back(s);
vector <int> d(n, 1e9);
d[s] = 0;
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto to : g[v]) {
        if (d[to.F] > d[v] + to.S) {
            d[to.F] = d[v] + to.S;
            if (to.S == 0) q.push_front(to.F);
            else q.push_back(to.F);
        }
    }
}
