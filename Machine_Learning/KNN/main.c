#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ABS(x)		((x)>0?(x):(-(x)))
#define ElementType Element
#define MIN_ELEMENT 0
#define bool int
#define true 1
#define false 0

typedef struct Element_t {
  float dist;
  float y;
} Element;

struct HeapStruct {
  int Capacity;
  int Size;
  ElementType * Elements;
};

typedef struct HeapStruct *PriorityQueue;

typedef struct _point_t { // point의 번호와 각 점의 좌표를 나타냄
	int num; // 몇번쨰 point인지
	float x1, x2, y; // x1, x2가 점이고, y는 해당 점에 대해서 예측해야할 답이다.
} point_t;

typedef struct _data_t { // 모든 점들의 목록을 points 배열에 넣고, points의 capacity와 현재 point의 갯수인 size를 나타냄.
	int capacity;
	int size;
	point_t *points;
} data_t;

PriorityQueue BuildHeap(int MaxElements); 
bool Insert(float dist, float y, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);

void FatalError(char *input);
bool IsFull(PriorityQueue H);
bool IsEmpty(PriorityQueue H);
void DestroyHeap(PriorityQueue H);

// function prototypes
float knn(point_t *point,data_t *data,int K);

data_t* read_data(const char *filename,int capacity) 
{
	data_t *data;
	FILE *f;
	int n, idx;
	
	data = (data_t*)malloc(sizeof(data_t)); // 일단 해당 struct에 대해 메모리 할당
	if( data == NULL ) {
		printf("Out of memory\n");
		exit(0);
	}
	data->capacity = capacity; // capacity 만큼만 불러오겠다는 뜻
	data->size = 0;
	data->points = (point_t*)malloc(sizeof(point_t) * data->capacity); // capacity 만큼만 point 메모리 할당
	if( data->points == NULL ) {
		printf("Out of memory\n");
		exit(0);
	}

	f = fopen(filename,"r"); // 파일 읽어서 파일 포인터를 f에 지정
	if( f == NULL ) {
		printf("Fail to open a file: %s\n",filename);
		exit(0);
	}
	idx = 0;
	while( idx < data->capacity ) { // fscanf로 데이터 읽어오는 부분, capacity의 수 만큼만 Point를 불러옴.
		n = fscanf(f,"%d %f %f %f",
			&data->points[idx].num, &data->points[idx].x1,
			&data->points[idx].x2, &data->points[idx].y);
		if( n != 4 ) break; // 한 fscanf마다 4개의 field를 불러오니까, 당연히 n이 4가 아니면 잘못된거져. 그래서 4가 아니면 break
    
    // 2번 문제 답
    // 만약 capacity가 파일 내 존재하는 데이터의 갯수보다 크다면, n == EOF 가 될 거라서 이 시점에서 break가 발생할 것이다. 
    // 만약 capacity가 파일 내 존재하는 데이터의 갯수보다 작다면, 위에서부터 capacity 만큼의 갯수가 읽혀질 것이다.
		idx++;
	}
	data->size = idx;
	
	return data;
}

void destroy_data(data_t *data)
{
	if( data ) {
		if( data->points ) free(data->points); // 있으면 free
		free(data); // free
	}
}

void test1()
{
	data_t *data;
	point_t point = {0,0.0,0.0,0.0}; // num, x1, x2, y
	int i, KList[] = {1,5,10};
	float yhat;
	float answers[] = {3.7323,6.9965,5.9280};
	
	printf("[Test 1]\n");
	data = read_data("data_train.txt",10);
	printf("   read %d data\n",data->size);
	for( i=0 ; i<sizeof(KList)/sizeof(int) ; i++ ) {
		yhat = knn(&point,data,KList[i]);
		printf("   KNN( {%5.2f,%5.2f},%2d ) = %.4f : ",point.x1,point.x2,KList[i],yhat);
		if( ABS(yhat-answers[i]) < 0.001 ) printf("correct\n");
		else printf("incorrect\n");
	}
	destroy_data(data);
}

void test2()
{
	printf("[Test 2]\n");	
	printf("   predict y values of test samples using KNN(20)\n");
  printf("\tnum\ty\tyhat\terror\n");
  printf("   ----------------------------------\n");
  
  int i;
  float yhat, mse = 0.0f;
	data_t *train, *test;

	train = read_data("data_train.txt",100000);
	test = read_data("data_test.txt",10);

  for(i = 0 ; i < test->size; i++){
    yhat = knn(&test->points[i], train, 20);
    printf("\t%d\t%.4f\t%.4f\t%.4f\n", test->points[i].num, test->points[i].y, yhat, test->points[i].y - yhat);
    mse += (test->points[i].y - yhat) * (test->points[i].y - yhat);
  }
  mse /= test->size;
  printf("   mse = %.4f\n", mse);
}

void test3()
{
	printf("[Test 3]\n");
  printf("\tK\tMSE_Train\tMSE_Test\n");
  printf("\t--------------------------------\n");
  
	int K, i, j, KList[] = {1, 5, 10, 20, 50, 100, 200, 1000, 2000};
	data_t *train, *test;
  float mse_train, mse_test, trainyhat, testyhat;

	train = read_data("data_train.txt",10000);
	test = read_data("data_test.txt",10000);

  for(j = 0 ; j < 9 ; j++){
    mse_train = 0.0f;
    mse_test = 0.0f;
    K = KList[j];
    for(i = 0 ; i < 10000 ; i++){
      trainyhat = knn(&train->points[i], train, K);
      testyhat = knn(&test->points[i], train, K);

      trainyhat -= train->points[i].y;
      testyhat -= test->points[i].y;

      mse_train += trainyhat * trainyhat;
      mse_test += testyhat * testyhat;
    }
    mse_train /= 10000;
    mse_test /= 10000;
    printf("\t%d\t%.4f\t\t%.4f\n", K, mse_train, mse_test);
  }
}

void test4()
{
	data_t *train, *test;
	point_t *sample;
	float yhat, error, rss = 0.0;
	int i, j;	
	clock_t t1, t2;
	double elapse, reference;

	printf("[Test 4]\n");

	// reference time
	t1 = clock();
	for( i=0 ; i<100000 ; i++ ) {
		float *p = (float*)malloc(sizeof(float)*1024);
		for( j=0 ; j<1024 ; j++ ) {
			p[j] = ((float)rand())/((float)rand());
		}
		free(p);
	}
	t2 = clock();
	reference = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("   The reference time is %.4f sec\n",reference);	

	train = read_data("data_train.txt",100000);
	test = read_data("data_test.txt",10000);

	printf("   predict %d tests using KNN(100) with %d trains\n",
		test->size,train->size);
	t1 = clock();
	rss = 0;
	for( i=0 ; i<test->size ; i++ ) {
		sample = test->points+i;
		yhat = knn(sample,train,100);
		error = sample->y - yhat;
		rss += error*error;
	}
	printf("   mse = %.4f\n",rss/test->size);
	t2 = clock();
	elapse = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("   The prediction time is %.4f sec (%.4f x ref)\n",
		elapse,elapse/reference);
		
	destroy_data(train);
	destroy_data(test);
}

int main(int argc, char *argv[]) 
{
	// test1();
	// test2();
	test3();
	// test4();
			
	return 0;
}

float getDist(point_t *p1, point_t *p2){
  return sqrtf( (p1->x1 - p2->x1) * (p1->x1 - p2->x1)  + (p1->x2 - p2->x2) * (p1->x2 - p2->x2) ) ;
}

float knn(point_t *point,data_t *data, int K){

  int i;
  float ret = 0.0f;
  ElementType temp;
  PriorityQueue Heap = BuildHeap(data->size);
  
  for(i = 0 ; i < data->size ; i ++){
    Insert(getDist(point, &data->points[i]), data->points[i].y, Heap);
    // printf("%f ", getDist(point, &data->points[i]));
  }
  // printf("\n");

  for(i = 1 ; i <= K ; i++){
    temp = DeleteMin(Heap);
    // printf("%f ", temp);
    ret += temp.y;
  }
  // printf("\n");
  
  ret /= K;

  DestroyHeap(Heap);
  return ret;
};


PriorityQueue BuildHeap(int MaxElements){
  PriorityQueue H;

  H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
  if(H == NULL) FatalError("Out of Memory");
  H->Elements = (ElementType *)malloc(sizeof(ElementType) *(MaxElements*1));
  if(!H->Elements) FatalError("Out of Memory");

  H->Capacity = MaxElements;
  H->Size = 0;
  H->Elements[0].dist = MIN_ELEMENT;

  return H;
}

bool Insert(float dist, float y, PriorityQueue H){
  int i;

  if(IsFull(H)){
    FatalError("Priority Queue is Full");
    return false;
  }

  H->Size++;
  for(i = H->Size ; H->Elements[i / 2].dist > dist ; i /= 2){
    H->Elements[i] = H->Elements[i/2];
  }
  H->Elements[i].dist = dist;
  H->Elements[i].y = y;
  return true;
};

ElementType DeleteMin(PriorityQueue H){
  int i, Child;

  float Lastdist, Lasty;
  ElementType MinElement;

  if(IsEmpty(H)){
    FatalError("Priority Queue is Empty");
    return H->Elements[0];
  }

  MinElement = H->Elements[1];
  Lastdist = H->Elements[H->Size].dist;
  Lasty = H->Elements[H->Size].y;
  H->Size--;

  for(i = 1 ; i * 2 <= H ->Size; i = Child){
    Child = i * 2;

    if(Child == H->Size){}
    else if(H->Elements[Child+1].dist < H->Elements[Child].dist){Child++;}

    if(Lastdist > H->Elements[Child].dist){
      H->Elements[i].dist = H->Elements[Child].dist;
      H->Elements[i].y = H->Elements[Child].y;
    }
    else break;
  }
  H->Elements[i].dist = Lastdist;
  H->Elements[i].y = Lasty;
  return MinElement;
};

bool IsFull(PriorityQueue H){
  if(H->Capacity == H->Size) return true;
  else return false;
};

bool IsEmpty(PriorityQueue H){
  if(H->Size == 0) return true;
  else return false;
};

void DestroyHeap(PriorityQueue H){
  free(H->Elements);
  free(H);
};

void FatalError(char *input){
  printf("%s\n", input);
  exit(-1);
};

// 5. ABS 는 매크로임. 함수는 아님. 