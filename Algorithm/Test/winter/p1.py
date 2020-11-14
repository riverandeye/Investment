from random import randint
Map = [[]]
Mapx = 0
Mapy = 0 

dx = [0,0,1,-1]
dy = [1,-1,0,0]
    
def dfs(x,y,cur):
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    
    if(Map[x][y] == -1): return
    Map[x][y] = -1
    
    for i in range(4):
        newx = x + dx[i]
        newy = y + dy[i]
        
        if(newx >= Mapx or newy >= Mapy or newx < 0 or newy < 0): continue
        if(Map[newx][newy] != cur) : continue
        dfs(newx, newy, cur)

def solution(v):
    global Map, Mapx, Mapy
    
    Map = v
    Mapx = len(v)
    Mapy = len(v[0])
    
    if Mapx == 0 or Mapy == 0 : return [0,0,0]

    answer = [0, 0, 0]
    
    for i in range(Mapx) : 
        for j in range(Mapy) :
            if(Map[i][j] == -1) : continue
            if(Map[i][j] > 2): continue
            answer[Map[i][j]] += 1
            dfs(i,j,Map[i][j])
    
    return answer

def solution(v):
    global Map, Mapx, Mapy

    Map = v
    Mapx = len(v)
    Mapy = len(v[0])

    answer = [0, 0, 0]
    
    for i in range(Mapx) : 
        for j in range(Mapy) :
            if(Map[i][j] == -1) : continue
            answer[Map[i][j]] += 1
            dfs(i,j,Map[i][j])
    
    return answer

def main():
  for i in range(1,100):
    for j in range(1,100) : 
        print(i * 100 + j, end=" ")
        print(solution([[randint(2,2) for _ in range(100)] for _ in range(100)]))

main()
