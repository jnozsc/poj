#include "stdio.h"
#include "string.h"
#include "math.h"
#define ll long long
#define M 503
//poj1505
int a[M], b[M];
int n, m;

int bs(ll x) {
    int i, ans = 0;
    ll k = 0;
    for (i = 0; i < n; i++) {
        if (k + a[i] > x) {
            ans++;
            k = a[i];
        } else
            k += a[i];
    }
    return ans + 1;
}

int main() {
    int i, j, t;
    ll start, end, mid, ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        start = 0;
        end = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            end += a[i];
            if (a[i] > start)
                start = a[i];
        }
        while (start + 1 < end) {
            mid = (start + end) >> 1;
            if (bs(mid) > m)
                start = mid;
            else
                end = mid;
        }
        if (bs(start) <= m)
            ans = start;
        else
            ans = end;
        mid = 0;
        for (i = n - 1, j = m - 1; i >= 0; i--) {
            if (mid + a[i] > ans) {
                b[j] = i + 1;
                mid = a[i];
                j--;
                continue;
            }
            if (i == j)
                break;
            mid += a[i];
        }
        if (i == j) {
            while (i >= 0) {
                b[i] = i;
                i--;
            }
        }
        b[m] = n;
        printf("%d", a[0]);
        for (i = 1; i < b[1]; i++) {
            printf(" %d", a[i]);
        }
        for (i = 1; i < m; i++) {
            printf(" /");
            for (j = b[i]; j < b[i + 1]; j++)
                printf(" %d", a[j]);
        }
        printf("\n");
    }
    return 0;
}
