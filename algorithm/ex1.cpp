/*
EX1
*/

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<time.h>
#include<random>
#include<chrono>
#include<cstring>
#define LL long long
using namespace std;
const int maxn = 100000;
int arry_buff[maxn];


void bubble(int* arry, int maxn) {
    for (int i = 0; i < maxn-1; ++i)
        for (int j = 0; j < maxn-1-i; ++j) 
            if (arry[j] > arry[j+1]) swap(arry[j], arry[j+1]);
}

void select(int* arry, int maxn) {
    for (int i = 0; i < maxn-1; ++i) {
        int temp, minn = 100;
        for (int j = i; j < maxn; ++j) {
            if (arry[j] < minn) {
                temp = j; minn = arry[j];
            }
        }
        if (temp != i) swap(arry[i], arry[temp]);
    }
}

void insert(int* arry, int maxn) {
    for (int i = 0; i < maxn; ++i) {
        int j = i;
        while (j > 0 && arry[j] < arry[j-1]) 
            { swap(arry[j], arry[j-1]); --j; }
    }
}

void shell(int gap, int* arry, int maxn) {
    for (int x = gap; x > 0; x /= 2) {
        for (int y = 0; y < x; ++y) {
            for (int i = y; i < maxn; i += x) {
                int j = i;
                while (j >= x && arry[j] < arry[j-x]) 
                    { swap(arry[j], arry[j-x]); j -= x; }
            }
        }
    }
}

void heap(int* arry, int maxn) {
    priority_queue<int> heap;
    for (int i = 0; i < maxn; ++i)
        heap.push(arry[i]);
    int cnt = 0;
    while (!heap.empty()) { arry[cnt++] = heap.top(); heap.pop(); }
}

void quick(int*arry, int l, int r) {
    if (r <= l) return;
    int ll = l, rr = r;
    int mid = (l+r)/2;
    int pivot = arry[mid];
    swap(arry[mid], arry[r]); --l;
    do {
        while (arry[++l] < pivot);
        while (r > 0 && arry[--r] > pivot);
        swap(arry[l], arry[r]);
    }while (r > l);
    swap(arry[r], arry[l]);
    swap(arry[l], arry[rr]);
    quick(arry, ll, r);
    quick(arry, l+1, rr);
}

void mergesort_(int* arry, int l, int r) {
    if (l == r) return;
    int mid = (l+r)/2, i1 = l, i2 = mid+1;
    mergesort_(arry, l, mid); mergesort_(arry, mid+1, r);
    for (int i = l; i <= r; ++i) arry_buff[i] = arry[i];
    for (int curr = l; curr <= r; ++curr) {
        if (i1 == mid+1) arry[curr] = arry_buff[i2++];
        else if (i2 == r+1) arry[curr] = arry_buff[i1++];
        else if (arry_buff[i1] < arry_buff[i2]) arry[curr] = arry_buff[i1++];
        else arry[curr] = arry_buff[i2++];
    }
    return;
}
 

void bin(int* arry) {
    int B[1000], cnt = 0;
    for (int i = 0; i < 1000; ++i) B[i] = 0;
    for (int i = 0; i < maxn; ++i) 
        ++B[arry[i]+10];
    for (int i = 0; i < 1000; ++i) {
        while (B[i] > 0) {
            arry[cnt++] = i-10;
            --B[i];
        }
    }
}

void radix(int* arry, int base, int digit) {
    int* b = new int[base];
    int* c = new int[base];
    for (int z = 0, cbase = 1; z < digit; ++z, cbase*= base) {
        for (int i = 0; i < base; ++i) b[i] = 0;
        for (int i = 0; i < maxn; ++i) ++b[(arry[i]/cbase)%base];
        for (int i = 1; i < base; ++i) b[i] = b[i]+b[i-1];
        for (int i = maxn-1; i >= 0; --i) c[--b[(arry[i]/cbase)%base]] = arry[i];
        for (int i = 0; i < maxn; ++i) arry[i] = c[i];
    }
}

void init(int* A, int* B, int maxn) {
    for (int i = 0; i < maxn; ++i)
        B[i] = A[i];
}

int main() {
    clock_t start, finish;
    double Time[10][1000];
    memset(Time, 0, sizeof(Time));
    int times = 0;
    char* A[4] = {"heap", "select", "insert", "quick"};
    for (int i = 100; i < 100001; i += 1000) {
        int arry[maxn], buff[maxn];
        for (int j = 0; j < i; ++j)
            arry[j] = rand()%1000;

        for (int j = 0; j < 5; ++j) {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            shuffle(arry, arry+i, std::default_random_engine(seed));

            init(arry, buff, i);
            start = clock();
            heap(arry, i);
            finish = clock();
            Time[0][times] += (double)(finish-start)/CLOCKS_PER_SEC;

            init(arry, buff, i);
            start = clock();
            select(arry, i);
            finish = clock();
            Time[1][times] += (double)(finish-start)/CLOCKS_PER_SEC;

            init(arry, buff, i);
            start = clock();
            insert(arry, i);
            finish = clock();
            Time[2][times] += (double)(finish-start)/CLOCKS_PER_SEC;

            init(arry, buff, i);
            start = clock();
            quick(arry, 0, i-1);
            finish = clock();
            Time[3][times] += (double)(finish-start)/CLOCKS_PER_SEC;

            ++times;
        }
    }
     for (int i = 0; i < 4; ++i) {
            cout << A[i] << ':';
            for (int j = 0; j < times; ++j)
                cout << Time[i][j]/5 << ' ';
            cout << '\n';
        }
    return 0;
}



