#include <stdio.h>
#include <stdlib.h>

// Copied from my .cpp template
#define FOR(i, j, k) for(int i=j;i<k;i++)
#define FORN(i, j, k) for(int i=j;i<=k;i++)
#define REP(i, j) FOR(i, 0, j)
#define ll long long

typedef struct _vector {
    int size;
    int max;
    ll *get;
} vector;

typedef struct _vertex {
    vector e, a;
} vertex;

void eb(vector *A, ll v) {
    if (A->size==A->max) {
        if (A->max) {
            A->get = (ll*) realloc(A->get, sizeof(ll)*A->size*2);
            A->max <<=1;
        } else {
            A->get = (ll*) malloc(sizeof(ll));
            A->max++;
        }
    }
    A->get[A->size++] = v;
}

vector *createVector(int size) {
    vector *v = (vector*) malloc(sizeof(vector));
    v->size = 0, v->max = size, v->get = (ll*) malloc(sizeof(ll)*size);
    return v;
}

void addEdge(vertex *v, ll val) {
    eb(&v->e, val);
    eb(&v->a, 0);
}

ll a, b, c, n;

int dfs(ll v, ll p, ll num, vertex *adj, ll *vis) {
    if (vis[v]==num) return 0;
    printf("DFS %lld: %lld\n", num, v);
    if (v == n+1) return 1;
    vis[v] = num;
    vertex *c = adj+v;
    int s = c->e.size;
    // printf("size: %d\n", s);
    for (int i=0;i<s;i++) {
        if (c->a.get[i]) continue;
        if ((c->a.get[i] = dfs(c->e.get[i], v, num, adj, vis))) {
            if (p>=0) addEdge(adj+v, p);
            printf("Found %lld!\n", v);
            return 1;
        }
    }
    return 0;
}

void printAdj(vertex *adj, int size) {
    REP(i, size) {
        printf("%d: ", i);
        REP(j, adj[i].a.size)
            printf("%lld%s ", adj[i].e.get[j], adj[i].a.get[j]?"*":"");
        printf("\n");
    }
}

int main() {
    scanf("%lld%lld%lld", &b, &a, &c);
    n = a+b+c;
    vertex *adj = (vertex*) calloc(n+2, sizeof(vertex));
    FORN(i, 1, a) {
        printf("Adding edge from %d to %d\n", 0, i);
        addEdge(adj, i);
    }
    FORN(i, a+b+1, n) {
        printf("Adding edge from %d to %d\n", i, (int) n+1);
        addEdge(adj+i, n+1);       
    }
    FORN(i, 1+a, b+a) {
        ll x, y, z;
        scanf("%lld%lld", &x, &y);
        REP(j, x) {
            scanf("%lld", &z);
            printf("Adding p-s edge from %d to %d\n", (int) z, i);
            addEdge(adj+z, i);
        }
        REP(j, y) {
            scanf("%lld", &z);
            printf("Adding s-m edge from %d to %d\n", i, (int) (z+a+b));
            addEdge(adj+i, z+a+b);
        }
    }
    printAdj(adj, n+2);

    ll ans = 0, c=1;
    ll *vis = (ll*) calloc(n+2, sizeof(ll));
    while (dfs(0, -1, c++, adj, vis)) {
        ans++;
        printAdj(adj, n+2);
    }
    printf("%lld\n", ans);
}
