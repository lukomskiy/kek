while (1) {
    int f = 0;
    for (int i = 0; i < q; i++) check[i].clear();
    for (int i = 0; i < n; i++) {
        if (l[i] != r[i]) {
            check[(l[i] + r[i]) / 2].pb(i);
            f = 1;
        }
    }
    if (f == 0) break;
    for (int i = 0; i < q; i++) {
        for (auto ch : check[i]) {
            if (can(ch)) {
                r[ch] = i;
            } else l[ch] = i + 1;
        }
    }
}
