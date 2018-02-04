bool dfs(int v) {
    if (us[v] == cur) return 0;
    us[v] = cur;
    for (int to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            mt[v] = to;
            return 1;
        }
    }
    for (int to : g[v]) {
        if (us[to] != cur && dfs(mt[to])) {
            mt[to] = v;
            mt[v] = to;
            return 1;
        }
    }
    return 0;
}

bool run = 1;
while (run) {
    run = 0;
    cur++;
    for (int i = 0; i < k; i++) {
        if (mt[i] == -1 && dfs(i)) {
            run = 1;
        }
    }
}
