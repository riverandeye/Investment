#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
 
#define MAX 100002 
using namespace std;
typedef long long ll;

struct Point {
    int x, y;
    int p, q; // p : dx // q : dy
    Point(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};

// 좌하단 좌표 sort
bool comp1(const Point &A, const Point &B) {
    if (A.y != B.y)
        return A.y < B.y;
    return A.x < B.x;
}

// 반시계방향 sort
bool comp(const Point &A, const Point &B) {
    if (1LL * A.q * B.p != 1LL * A.p*B.q)
        return 1LL * A.q * B.p < 1LL * A.p * B.q; // 
 
    if (A.y != B.y)
        return A.y < B.y;
 
    return A.x < B.x;
}


ll ccw(const Point &A, const Point &B, const Point &C) {
    return 1LL * (A.x*B.y + B.x*C.y + C.x*A.y - B.x*A.y - C.x*B.y - A.x*C.y);
}
 
vector<Point> p;
 
int main() {
    int n;
    scanf("%d", &n);
    
    // Point 의 Array
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
 
        p.emplace_back(x, y);
    }
 
    sort(p.begin(), p.end(), comp1); // 이건 그냥 좌하단의 좌표를 p[0]으로 찾기 위함
    
    for (int i = 1; i < n; i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
 
    sort(p.begin() + 1, p.end(), comp); // 각도에 대해 sort
 
    stack<int> s;
 
    s.push(0);
    s.push(1);
 
    int next = 2;
 
    while (next < n) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();
 
            if (ccw(p[first], p[second], p[next]) > 0) {
                s.push(second);
                break;
            }
        }
 
        s.push(next++);
    }
 
    printf("%d", s.size());
    return 0;
}