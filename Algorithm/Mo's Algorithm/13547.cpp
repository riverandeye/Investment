#include <bits/stdc++.h>

using namespace std;

int res,sz;

int a[100001], cnt[1000002], ans[100001];
struct query {
  int l,r,i;
} Q[100001];
void add(int x){
  cnt[x]++;
  if(cnt[x]==1)res++;
}
void del(int x){
  cnt[x]--;
  if(cnt[x]==0)res--;
}
int main(){
  int n,q;
  scanf("%d", &n);
  sz = sqrt(n);
  for(int i=0;i<n;i++)scanf("%d",a+i);
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    l--,r--;
    Q[i]={l,r,i};
  }
  sort(Q, Q+q, [&](query q1, query q2){
    int l1=q1.l, r1=q1.r, l2=q2.l, r2=q2.r;
    if(l1/sz != l2/sz) return l1/sz < l2/sz; // 다른 버킷일땐 버킷의 위치대로 결정
    return r1<r2; // 같은 버킷일땐 r에 대해서 정렬
  });
  int L=0;
  int R=0;

  add(a[0]);
  for(int i=0;i<q;i++){
    int l=Q[i].l, r=Q[i].r;
    while(R<r){
      add(a[++R]);
    }
    while(L>l){
      add(a[--L]);
    }
    while(R>r){
      del(a[R--]);
    }
    while(L<l){
      del(a[L++]);
    }
    ans[Q[i].i]=res;
  }

  for(int i=0;i<q;i++)printf("%d\n", ans[i]);
}