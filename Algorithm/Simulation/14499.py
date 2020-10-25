from copy import copy
N,M,x,y,K=list(map(int, input().split()))
MAP = [[0 for i in range(M)] for k in range(N)]
for i in range(N):
    data = list(map(int, input().split()))
    for j in range(M):
        MAP[i][j] = data[j]
commands=list(map(int,input().split()))
status=[0,0,0,0,0,0] #1,2,3,4,5,6 번째 면에 쓰여있는 값
curpos=[x,y]

def cc(s,c):
    if c==1 :
        s[0],s[2],s[3],s[5] = s[3],s[0],s[5],s[2]
    elif c==2:
        s[0],s[2],s[3],s[5] = s[2],s[5],s[0],s[3]
    elif c==3 :
        s[0],s[1],s[4],s[5] = s[4],s[0],s[5],s[1]
    elif c==4 :
        s[0],s[1],s[4],s[5] = s[1],s[5],s[0],s[4]
    return s

def isok(pos,c,N,M):

    x,y = pos
    ok=list()
    if y != M-1 :
        ok.append(1)
    if y != 0 :
        ok.append(2)
    if x != 0 :
        ok.append(3)
    if x != N-1 :
        ok.append(4)
    if c in ok :
        if c == 1 :
            return x,y+1
        elif c == 2 :
            return x,y-1
        elif c == 3 :
            return x-1,y
        elif c == 4 :
            return x+1,y
    else :
        return False

for c in commands :
    res = isok(curpos,c,N,M)
    if res :
        curpos = res
        status = cc(status,c)
        if MAP[curpos[0]][curpos[1]] == 0 :
            MAP[curpos[0]][curpos[1]] = status[5]
        else :
            status[5] = MAP[curpos[0]][curpos[1]]
            MAP[curpos[0]][curpos[1]] = 0
        print(status[0])
    else :
        continue