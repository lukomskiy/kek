void dfsb(int v, int pr) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for (int to : g[v]) {
        if (to == pr)  continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfsb(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) bridges.pb({v, to});
        }
    }
}
