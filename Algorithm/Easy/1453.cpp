#include <stdio.h>
void pc_bang()
{
  int N;
  scanf("%d", &N);
  int i, j;
  int arr[101] = {0};
  int seat_num;
  int bye_cnt = 0;
  for (i = 0; i < N; i++)
  {
    scanf("%d", &seat_num);
    if (arr[seat_num] == 1)
      bye_cnt++;
    arr[seat_num] = 1;
  }
  printf("%d", bye_cnt);
}
int main()
{
  pc_bang();
}