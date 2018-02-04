stack <pii> mn1, mn2;

int getmn() {
    ll res = 0;
    if (mn1.empty() || mn2.empty()) {
        if (mn1.empty()) res = mn2.top().S;
        else res = mn1.top().S;
    } else res = min(mn1.top().S, mn2.top().S);
    return res;
}

void addmn(int x) {
    int cur = 0;
    if (mn1.empty()) cur = x;
    else cur = min(x, mn1.top().S);
    mn1.push({x, cur});
}

void delmn() {
    if (mn2.empty()) {
        while (!mn1.empty()) {
            int cur = mn1.top().F;
            mn1.pop();
            int mn = 0;
            if (mn2.empty()) mn = cur;
            else mn = min(cur, mn2.top().S);
            mn2.push({cur, mn});
        }
    }
    mn2.pop();
}

