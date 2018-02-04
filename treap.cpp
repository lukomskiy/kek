struct treap {
    int key, pr, sz;
    treap *l;
    treap *r;
    treap () {}
    treap(int x) {
        pr = rand();
        key = x;
        sz = 1;
        l = r = NULL;
    }
};

int calc(treap* t) {
    if (t == NULL) return 0;
    t -> sz = 1;
    if (t -> l) t -> sz += (t -> l -> sz);
    if (t -> r) t -> sz += (t -> r -> sz);
    return t -> sz;
}
void merge(treap* l, treap* r, treap* &t) {
    if (l == NULL) {
        t = r;
        return;
    }
    if (r == NULL) {
        t = l;
        return;
    }
    if (l -> pr > r -> pr) {
        t = l;
        merge(l -> r, r, t -> r);
    } else {
        t = r;
        merge(l, r -> l, t -> l);
    }
    calc(t);
}
void split(treap *t, treap* &l, treap* &r, int k) {
    if (t == NULL) {
        l = NULL;
        r = NULL;
        return;
    }
    if (calc(t -> l) + 1 <= k) {
        l = t;
        split(t -> r, l -> r, r, k - (calc(t -> l)) - 1);
    } else {
        r = t;
        split(t -> l, l, r -> l, k);
    }
    calc(l);
    calc(r);
}

void out(treap *t) {
    if (t == NULL) return;
    out(t -> l);
    cout << t -> key << " ";
    out(t -> r);
}
