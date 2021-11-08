#include<bits/stdc++.h>
using namespace std;

typedef complex<double> cp;
typedef long long ll;
const int maxn = 5e6;
const double pi = acos(-1);
ll rev[maxn], ans[maxn], cnt1 = 0, cnt2 = 0, cnt = 1, bits = 0;
char s1[maxn], s2[maxn];

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

struct node{
    double x, y ;
    node (double xx = 0, double yy = 0){
        x = xx, y = yy ;
    }
}F1[maxn], F2[maxn] ;
node operator * (node J, node Q){
    return node(J.x * Q.x - J.y * Q.y , J.x * Q.y + J.y * Q.x);
}
node operator + (node J, node Q){
    return node(J.x + Q.x , J.y + Q.y);
}
node operator - (node J, node Q){
    return node(J.x - Q.x , J.y - Q.y );
}

void fft(node* a, ll inv) {
    for (ll i = 0; i < cnt; ++i) 
        if (rev[i] > i) swap(a[i], a[rev[i]]);  
    for (ll mid = 1; mid < cnt; mid *= 2) {
        node wn(cos(pi/mid), inv*sin(pi/mid));
        for (ll i = 0; i < cnt; i += 2*mid) {
            node x(1, 0);
            for (ll j = 0; j < mid; ++j) {
                node f0 = a[i+j], f1 = x*a[i+j+mid];
                a[i+j] = f0 + f1, a[i+j+mid] = f0 - f1;
                x = x*wn;
            }
        }
    }
    if (inv == -1) for (ll i = 0; i < cnt; ++i) a[i].x = (ll)(a[i].x/cnt+0.5);
}

int main() {
    // freopen("D:\\code\\VSCODE\\DataTest\\data.in.txt", "r", stdin);
    // freopen("D:\\code\\VSCODE\\DataTest\\data.out.txt", "w", stdout);
    memset(ans, 0, sizeof(ans));
    memset(ans, 0, sizeof(ans));
    scanf("%s%s", s1, s2);
    cnt1 = strlen(s1);
    cnt2 = strlen(s2);
    for (ll i = 0; i < cnt1; ++i)
        F1[cnt1-i-1].x = (ll)s1[i]-48;
    for (ll i = 0; i < cnt2; ++i)
        F2[cnt2-i-1].x = (ll)s2[i]-48;

    while (cnt <= (cnt1+cnt2)) { cnt <<= 1; ++bits; }
    for (ll i = 0; i < cnt; ++i)
        rev[i] = ((rev[i>>1]>>1) | ((1&i)<<(bits-1)));
    fft(F1, 1);
    fft(F2, 1);
    for (ll i = 0; i < cnt; ++i)
        F1[i] = F1[i]*F2[i];
    fft(F1, -1);
    for (ll i = 0; i < cnt; ++i) {
        ans[i] += F1[i].x;
        if (ans[i] >= 10) {
            ans[i+1] = ans[i] / 10;
            ans[i] = ans[i] % 10;
            cnt += (i == cnt-1);
        }
    }
    while (cnt > 0 && !ans[cnt-1]) --cnt;
    for (ll i = cnt-1; i >= 0; --i)
        print(ans[i]);
    return 0;
}
