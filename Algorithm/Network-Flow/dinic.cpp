#include <bits/stdc++.h>
using namespace std;

int INF = 2147483647;

struct Edge {
   int to, r;
   Edge* ori;
   Edge* rev;
   Edge(int T, int R){
      to = T, r = R;
   }
};

vector<Edge *> v[1000];
void addedge(int f, int t, int r) // from to ryoungryang
{
   Edge* ori = new Edge(t, r);
   Edge* rev = new Edge(f, 0);
   ori->rev = rev;
   rev->rev = ori;
   v[f].push_back(ori);
   v[t].push_back(rev);
}

int S = 'A', T = 'Z';
int level[503],work[503];
bool bfs() { // 레벨 설정
   memset(level, -1, sizeof(level));
   level[S] = 0;
   queue<int> q;
   q.push(S);
   while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto& nn : v[x]) {
         int next = nn->to;
         if (level[next] == -1 && nn->r > 0) {
            level[next] = level[x] + 1;
            q.push(next);
         }
      }
   }
   return level[T] != -1;
}
int dfs(int N, int des, int flow) { // 경로 찾아가기
   if (N == des) return flow;
   for (int &i = work[N]; i<v[N].size(); i++) {
      int next = v[N][i]->to;
      if (level[next] == level[N] + 1 && v[N][i]->r > 0) {
         int df = dfs(next, des, min(v[N][i]->r, flow));
         if (df > 0) {
            v[N][i]->r -= df;
            v[N][i]->rev->r += df;
            return df;
         }
      }
   }
   return 0;
}

int match(){
   int res = 0;
   while (bfs())
   {
      memset(work,0,sizeof(work));
      while (1)
      {
         int f = dfs(S, T, INF);
         if (f == 0)break;
         res += f;
      }
   }
   return res;
}

int main(){
  // s -> source A 넣고
  // t -> sink Z 넣고
  int n;

  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    char a,b;
    int c;

    scanf(" %c %c %d", &a, &b, &c);
    addedge(a,b,c);
    addedge(b,a,c);
  }

  int r = match();  
  cout << r;
}