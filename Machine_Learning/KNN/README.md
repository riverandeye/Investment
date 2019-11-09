# KNN

> K-Nearest-Neighbor 알고리즘 에 대해 다룹니다.



설명은 [여기]( https://www.analyticsvidhya.com/blog/2018/08/k-nearest-neighbor-introduction-regression-python/ )에 정말 잘 되어있다.

KNN은 classification과 regression 두 영역에 모두 사용되는 알고리즘이다. 새로운 값을 예측할 때, 현재 Data Point가 어떻게 배치되어있느냐에 따라 값을 예측한다.



현재 구성한 코드는 regression training에 대한 코드이다.

```c
float knn(point_t *point, data_t *data, int K){

  int i;
  float ret = 0.0f;
  ElementType temp;
  PriorityQueue Heap = BuildHeap(data->size);
  
  for(i = 0 ; i < data->size ; i ++){
    Insert(getDist(point, &data->points[i]), data->points[i].y, Heap);
  }

  for(i = 1 ; i <= K ; i++){
    temp = DeleteMin(Heap);
    ret += temp.y;
  }
  ret /= K;

  DestroyHeap(Heap);
  return ret;
};

```

여기서는 K값을 Train 시키는 것은 생략했는데, 어짜피 뭐 만들어진 knn 값에 대해서 평균 내고, 각 K값에 대해 비교해서 적절한 K값을 찾으면 되기 때문에, 큰 문제는 안된다.

입력한 데이터 포인트에 대해서 현재 주어진 데이터들과의 거리를 구하여 heap 자료구조로 정렬하고, 가장 거리가 짧은 K개의 node에 대한 y값의 평균을 결과로 regression 하는 것이다.

