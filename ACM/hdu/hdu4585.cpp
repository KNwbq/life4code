#include<stdio.h>
#include<iterator>
#include<map>
#include<cmath>
#include<iostream>
using namespace std;

int main() {
    int n, id, g, ans;
    while (cin >> n) {
        if (n == 0) return 0;
        map<int, int> monks;
        map<int, int>::iterator it, it1, it2;
        monks[1000000000] = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &id, &g);
            monks[g] = id;
            it = monks.find(g);
            if (it == monks.begin()) ans = (++it)->second;
            else {
                it1 = it; it2 = ++it; --it1;
                if (g-it1->first <= it2->first-g) ans = it1->second;
                else ans = it2->second;
            }
            printf("%d %d\n", id, ans);
        }

    }
    return 0;
} 