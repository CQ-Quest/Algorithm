# 建树
    struct Segment
    {
        int l, r;
        int v;
    } tr[maxn * 4];
    int m, n;
    int w[maxn];
    void build(int u, int l, int r)
    {
        tr[u] = {l, r, w[r]};
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
# 区间更新
    void pushup(int u)
    {
        tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
    }
    
    lazy标记作加法
    void pushdown(int u){
      auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
      if(root.add){
        left.add+=root.add,left.sum+=(ll)(left.r-left.l+1)*root.add;
        right.add+=root.add,right.sum+=(ll)(right.r-right.l+1)*root.add;
        root.add=0;
      }
    }
# 查询
    int query(int u, int l, int r)
    {
        if (tr[u].l >= l && tr[u].r <= r)
            return tr[u].v;
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid)
            v = max(v, query(u << 1, l, r));
        if (r > mid)
            v = max(v, query(u << 1 | 1, l, r));
        return v;
    }
# 修改
    void modify(int u, int x, int v)
    {
        if (tr[u].l == tr[u].r)
            tr[u].v = v;
        else
        {
            int mid = (tr[u].l + tr[u].r) >> 1;
            if (x <= mid)
                modify(u << 1, x, v);
            else
                modify(u << 1 | 1, x, v);
            pushup(u);
        }
    }
