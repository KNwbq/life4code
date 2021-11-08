long long num[666666];

void build(int p,int l,int r)
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)
    {
        t[p].sum=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    t[p].sum=t[2*p].sum+t[2*p+1].sum;
}

void single_change (int p, int x, int z)
{
    if (t[p].l == t[p].r && t[p].l == x) {
        t[p].sum += z; return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (x >= mid + 1) {
        single_change (2 * p + 1, x, z);
    }
    if (x <= mid) {
        single_change (2 * p, x, z);
    }
    t[p].sum = t[2 * p].sum + t[2 * p + 1].sum;
}






const int maxn = 200000+200;
struct node
{
    int l,r,maxx,minn;
}t[maxn<<2];

int num[maxn];

void build (int p, int l, int r)
{
    t[p].l = l; t[p].r = r;
    if (l == r) {
        t[p].maxx = t[p].minn = num[l]; return;
    }
    int mid = (l + r) >> 1;
    build (2 * p, l, mid);
    build (2 * p + 1, mid + 1, r);
    t[p].maxx = max(t[2 * p].maxx, t[2 * p + 1].maxx);
    t[p].minn = min(t[2 * p].minn, t[2 * p + 1].minn);
}
int search_max(int pos,int x,int y)
{
    if(x<=t[pos].l&&y>=t[pos].r)
    {
        return t[pos].maxx;
    }
    int ans=-1;
    int mid=(t[pos].l+t[pos].r)>>1;
    if(x<=mid) ans=max(ans,search_max(pos<<1,x,y));
    if(y>mid) ans=max(ans,search_max(pos<<1|1,x,y));
    return ans;
}
int search_min(int pos,int x,int y)
{
    if(x<=t[pos].l&&y>=t[pos].r)
    {
        return t[pos].minn;
    }
    int ans=10000000+1;
    int mid=(t[pos].l+t[pos].r)>>1;
    if(x<=mid) ans=min(ans,search_min(pos<<1,x,y));
    if(y>mid) ans=min(ans,search_min(pos<<1|1,x,y));
    return ans;
}

int search_max (int p, int x, int y)
{
    if (x <= t[p].l && y >= t[p].r) {
        return t[p].maxx;
    }
    int ans = INT_MIN;
    int mid = (t[p].l + t[p].r) / 2;
    if (x )
}