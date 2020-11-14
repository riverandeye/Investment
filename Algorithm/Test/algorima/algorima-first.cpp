#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > visited;
vector<vector<int> > original;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y)
{
  visited[x][y] = true;

  int max_depth = 0;
  for (int i = 0; i < 4; i++)
  {
    int newx = x + dx[i];
    int newy = y + dy[i];

    if(newx < 0 || newy < 0 || newx >= original.size() || newy >= original[0].size()) continue;

    if (!visited[newx][newy] && (original[x][y]) == original[newx][newy])
    {
      int now = dfs(newx, newy);

      if (max_depth < now)
      {
        max_depth = now;
      }
    }
  }

  visited[x][y] = false;
  return max_depth + 1;
}

int solution(vector<vector<int> > board)
{
  original = board;

  int answer = 0;
  for (int i = 0; i < board.size(); i++)
  {
    visited.push_back(vector<int>());
    for (int j = 0; j < board[i].size(); j++)
      visited[i].push_back(0);
  }

  int max_dfs = 0;
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[i].size(); j++)
    {
      int now = dfs(i, j);

      if (max_dfs < now)
      {
        max_dfs = now;
      }
    }
  }

  if (max_dfs == 1)
  {
    return -1;
  }

  answer = max_dfs;

  return answer;
}

vector<vector<int> > a;

int main(){
  vector<vector<int> > b;
  b.push_back(vector<int>());
  b.push_back(vector<int>());
  b.push_back(vector<int>());
  b.push_back(vector<int>());

  b[0].push_back(3);
  b[0].push_back(2);
  b[0].push_back(3);
  b[0].push_back(2);

  b[1].push_back(2);
  b[1].push_back(1);
  b[1].push_back(1);
  b[1].push_back(2);

  b[2].push_back(1);
  b[2].push_back(1);
  b[2].push_back(2);
  b[2].push_back(1);

  b[3].push_back(4);
  b[3].push_back(1);
  b[3].push_back(1);
  b[3].push_back(1);

  cout << solution(b);
}
