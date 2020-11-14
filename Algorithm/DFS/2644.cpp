#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[101], startN, endN, total, num, m, n, dist = 0, result = 0;
vector<int> adj[101];
bool visited[101], printed = false;

void dfs(int a) {
    if(printed) return;
    visited[a] = true;
    
    if (a == endN) {
        printf("%d", dist);
        printed = true;
        return;
    }

    dist++;
    for (int next : adj[a]) {
        if (!visited[next]) {
            dfs(next);
        }
    }

    dist--;
}

int main()
{
    scanf("%d", &total);
    scanf("%d%d", &startN, &endN);
    scanf("%d", &num);

    while (num--) {
        scanf("%d%d", &m, &n);
        adj[m].push_back(n);
        adj[n].push_back(m);
    }

    dfs(startN);
    if (printed == false) printf("-1");
    return 0;
}