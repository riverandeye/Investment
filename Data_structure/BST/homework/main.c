#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN		128

typedef struct _word_bank_t {
	char **words;
	char *storage;
	int nwords;
} word_bank_t;

typedef struct _bst_t {
	char word[MAX_WORD_LEN];
	int count;
	struct _bst_t *left;
	struct _bst_t *right;
} bst_t;

// function prototypes

bst_t* create_node(char *word){
  bst_t* newnode = (bst_t*)malloc(sizeof(bst_t));
	if( newnode == NULL ) {
		printf("Memory allocation error\n");
		exit(0);		
	}

  strcpy(newnode->word, word);

  newnode->count = 1;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

bst_t* count_words(word_bank_t *word_bank);
bst_t* bst_insert(char *word,bst_t *bst);
bst_t* bst_delete(char *word,bst_t *bst);
bst_t* bst_find(char *word,bst_t *bst);
bst_t* bst_findmin(bst_t *bst);
bst_t* bst_findmax(bst_t *bst);
int bst_maxdepth(bst_t *bst);
int bst_nodenum(bst_t *bst);
int bst_countsum(bst_t *bst);
void bst_print(bst_t *bst, int depth);

word_bank_t* read_text(char *filename)
{
	FILE *fp; // 파일을 읽어들일 파일 포인터 정의
	int filesize, nwords, i, readlen; // filesize, number of words, index 용 i, readlen은 뭔지 모르겠음
	char prev, curr; // char 변수
	char *ptr; // char 포인터
	word_bank_t *word_bank; // word bank 타입 포인터 정의
	
	// create a word bank // 41 ~ 49까지 word bank 메모리 할당 및 초기화에 관련된 내용
	word_bank = (word_bank_t*)malloc(sizeof(word_bank_t));
	if( word_bank == NULL ) {
		printf("Memory allocation error\n");
		exit(0);		
	}
	word_bank->storage = NULL;
	word_bank->words = NULL;
	word_bank->nwords = 0;
	
	// open the file // 텍스트 파일을 열고 읽는다.
	fp = fopen(filename,"r");
	if( fp == NULL ) {
		printf("Fail to open %s\n",filename);
		exit(0);
	}
	
	// check the file size
	fseek(fp, 0, SEEK_END); // fp를 파일의 끝 지점으로 이동시킨다/
	filesize = ftell(fp); // fp의 위치를 구함으로써 파일의 크기를 구한다.
	fseek(fp, 0, SEEK_SET); // fp를 파일의 시작점으로 이동시킨다.
	
	// allocating memory // 위에서 찾은 filesize를 이용하여 wordbank에 저장할 메모리 할당
	word_bank->storage = (char*)malloc(sizeof(char)*(filesize+1));
	if( word_bank->storage == NULL ) {
		printf("Memory allocation error\n");
		exit(0);
	}
	
	// read each word
	nwords = 0; // 글자의 갯수
	ptr = word_bank->storage;
	while( 1 ) {
		if( fscanf(fp,"%s",ptr) != 1 ) break; // fp 위치의 string을 ptr로 복사한다. file이 끝나면 while문을 탈출한다.
		ptr += strlen(ptr)+1; // ptr의 위치를 읽어온 단어 + 1 만큼 이동시킨다 (띄어쓰기)
		nwords++; // 단어의 갯수를 더해준다.
	}
	fclose(fp); // 볼일없으니 닫음.
	
	// allocating the word bank
	word_bank->words = (char**)malloc(sizeof(char*)*(nwords+10)); // 글자의 갯수 + 10만큼 포인터 메모리 할당
	if( word_bank->words == NULL ) {
		printf("Memory allocation error\n");
		exit(0);
	}
	
	// set the location of words
	word_bank->nwords = nwords; // 단어 갯수 할당
	ptr = word_bank->storage; // word bank의 storage에 포인터 지정 ( storage의 첫번째 단어를 가르킴 )
	for( i=0 ; i<nwords ; i++ ) { // 글자의 갯수만큼
		word_bank->words[i] = ptr; // words에 포인터 할당 후
		ptr += strlen(ptr)+1; // 포인터를 다음 단어로 이동한다.
	} // 이렇게 하면 word_bank의 words는 storage에 저장된 단어들의 첫번쨰 위치를 저장하고 있다.
		
	return word_bank;
}

void test1()
{
	bst_t *bst = NULL;
	char word[MAX_WORD_LEN];
	
	printf("[Test 1] Basic Test\n");

	printf("== building an initial tree\n");
	bst = bst_insert("c",bst);
	bst = bst_insert("d",bst);
	bst = bst_insert("e",bst);
	bst = bst_insert("b",bst);
	bst = bst_insert("a",bst);
	bst = bst_insert("d",bst);
	bst = bst_insert("a",bst);
	bst = bst_insert("f",bst);
	bst_print(bst, 0);
	printf("NumNode: %d, SumCnts: %d, MaxDepth: %d\n",
		bst_nodenum(bst), bst_countsum(bst), bst_maxdepth(bst)); 

	printf("== delete d, c, g\n");
	bst = bst_delete("d",bst);
	bst = bst_delete("c",bst);
	bst = bst_delete("g",bst);
	bst_print(bst, 0);
	printf("NumNode: %d, SumCnts: %d, MaxDepth: %d\n",
		bst_nodenum(bst), bst_countsum(bst), bst_maxdepth(bst)); 	

	printf("== insert c and d\n");
	bst = bst_insert("c",bst);
	bst = bst_insert("d",bst);
	bst_print(bst,0);
	printf("NumNode: %d, SumCnts: %d, MaxDepth: %d\n",
		bst_nodenum(bst), bst_countsum(bst), bst_maxdepth(bst)); 	
	
}

void test2()
{
	struct word_count {
		char word[MAX_WORD_LEN];
		int count;
	} wc[50];
	int nwc = 0, i, j;
	FILE *fp;
	word_bank_t *word_bank;
	bst_t *bst;
	int hit, num_nodes, sum_counts;

	printf("[Test 2] Short Text\n");
	
	// read text
	word_bank = read_text("data01_short_text.txt");
	printf("   reading a text and extracting %d words\n",word_bank->nwords);
	
	// read true counts
	fp = fopen("data02_short_text_count.txt","r");
	if( fp == NULL ) {
		printf("Fail to read\n");
		exit(0);
	}
	nwc = 0;
	while( 1 ) {
		if( fscanf(fp,"%s %d",wc[nwc].word,&wc[nwc].count) != 2 ) break;
		nwc++;
	}
	fclose(fp);
	printf("   reading counts for %d unique words\n",nwc);

	// construction
	bst = count_words(word_bank);
	printf("   buding a tree\n");	
	sum_counts = bst_countsum(bst);
	printf("      the sum of counts is %d: %s\n",
		sum_counts,(sum_counts==word_bank->nwords)?"correct":"wrong");
	num_nodes = bst_nodenum(bst);	
	printf("      the number of nodes is %d: %s\n",
		num_nodes,(num_nodes==nwc)?"correct":"wrong");
	printf("      the maximum depth is %d\n",bst_maxdepth(bst));

	// finding
	hit = 0;
	for( i=0 ; i<nwc ; i++ ) {
		bst_t *f = bst_find(wc[i].word,bst);
		if( f != NULL && f->count == wc[i].count ) hit++; 
	}
	printf("      %d correct counts for %d words: %.2f\n",hit,nwc,(float)(hit*100)/nwc);
	
	// printing test
	printf("\n==== Print a Tree ====\n");
	bst_print(bst, 0);
	printf("======================\n\n");
	return;
}

void test3()
{
	struct word_count {
		char word[MAX_WORD_LEN];
		int count;
	} wc[15000];
	int nwc = 0, i, j;
	FILE *fp;
	word_bank_t *word_bank;
	bst_t *bst;
	int hit, num_nodes, sum_counts;

	printf("[Test 3] Long Text\n");

	// read text
	word_bank = read_text("data03_long_text.txt");
	printf("   reading a text and extracting %d words\n",word_bank->nwords);
	
	// read true counts
	fp = fopen("data04_long_text_count.txt","r");
	if( fp == NULL ) {
		printf("Fail to read\n");
		exit(0);
	}
	nwc = 0;
	while( 1 ) {
		if( fscanf(fp,"%s %d",wc[nwc].word,&wc[nwc].count) != 2 ) break;
		nwc++;
	}
	fclose(fp);
	printf("   reading counts for %d unique words\n",nwc);

	// construction
	bst = count_words(word_bank);
	printf("   buding a tree\n");	
	sum_counts = bst_countsum(bst);
	printf("      the sum of counts is %d: %s\n",
		sum_counts,(sum_counts==word_bank->nwords)?"correct":"wrong");
	num_nodes = bst_nodenum(bst);	
	printf("      the number of nodes is %d: %s\n",
		num_nodes,(num_nodes==nwc)?"correct":"wrong");
	printf("      the maximum depth is %d\n",bst_maxdepth(bst));
	
	// finding
	hit = 0;
	for( i=0 ; i<nwc ; i++ ) {
		bst_t *f = bst_find(wc[i].word,bst);
		if( f != NULL && f->count == wc[i].count ) hit++; 
	}
	printf("      %d correct counts for %d words: %.2f\n",hit,nwc,(float)(hit*100)/nwc);
	
	return;
}

void test4()
{
	int i, j;
	char random_word[6];
	bst_t *bst = NULL;
	clock_t t1, t2;
	double elapse, reference;
	int sum_counts, num_nodes;
	
	printf("[Test 4] Random Insertion and Deletion\n");

	srand(0);
	
	// reference time
	t1 = clock();
	for( i=0 ; i<100000 ; i++ ) {
		int *p = (int*)malloc(sizeof(int)*1024);
		for( j=0 ; j<1024 ; j++ ) p[j] = rand();
		free(p);
	}
	t2 = clock();
	reference = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("   The reference time is %.4f sec\n",reference);
	
	// insertion
	random_word[4] = '\0';
	t1 = clock();
	for( i=0 ; i<5000000 ; i++ ) {
		for( j=0 ; j<4 ; j++ ) random_word[j] = 'a'+rand()%26;
		bst = bst_insert(random_word,bst);
	}
	sum_counts = bst_countsum(bst);
	num_nodes = bst_nodenum(bst);
	t2 = clock();
	elapse = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("   The insertion time is %.4f sec (%.4f x ref)\n",
		elapse,elapse/reference);
	printf("      the sum of counts is %d\n",sum_counts);
	printf("      the number of nodes is %d\n",num_nodes);
	printf("      the maximum depth is %d\n",bst_maxdepth(bst));

	// deletion
	random_word[4] = '\0';
	t1 = clock();
	for( i=0 ; i<5000000 ; i++ ) {
		for( j=0 ; j<4 ; j++ ) random_word[j] = 'a'+rand()%26;
		bst = bst_delete(random_word,bst);
	}
	sum_counts = bst_countsum(bst);
	num_nodes = bst_nodenum(bst);
	t2 = clock();
	elapse = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("   The deletion time is %.4f sec (%.4f x ref)\n",
		elapse,elapse/reference);
	printf("      the sum of counts is %d\n",sum_counts);
	printf("      the number of nodes is %d\n",num_nodes);
	printf("      the maximum depth is %d\n",bst_maxdepth(bst));

	return;
}

int main(int argc, char *argv[]) 
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}

bst_t* count_words(word_bank_t *word_bank){
  bst_t * bst = create_node(word_bank->words[0]);
  int i;
  for(i = 1 ; i < word_bank->nwords ; i++)
    bst_insert(word_bank->words[i], bst);
  return bst;
};

bst_t* bst_insert(char *word,bst_t *bst){
  if(bst == NULL){
    bst = create_node(word);
    return bst; 
  }

  bst_t *now = bst;
  int result;

  while(1){
    result = strcmp(word, now->word);
    if(result < 0) {
      if(now->left == NULL){
        now->left = create_node(word);
        break;
      }
      else now = now->left;
    }
    else if(result > 0){
      if(now->right == NULL){
        now->right = create_node(word);
        break;
      }
      else now = now->right;
    }
    else{
      now->count++;
      break;
    }
  }
  return bst;
};

bst_t* bst_deleter(char *word, bst_t *bst){
  bst_t* tmp;

  if(bst == NULL){}
  else if (strcmp(word, bst->word) < 0){
    bst->left = bst_deleter(word, bst->left);
  }
  else if(strcmp(word, bst->word) > 0){
    bst->right = bst_deleter(word, bst->right);
  }else if (bst->left && bst->right ){
    tmp = bst_findmin(bst->right);
    strcpy(bst->word, tmp->word);
    bst->count = tmp->count;
    bst->right = bst_deleter(bst->word, bst->right);
  } else {
    tmp = bst;
    if(bst->left == NULL) bst = bst->right;
    else if (bst->right == NULL) bst = bst->left;
    free(tmp);
  }
  return bst;
}

bst_t* bst_delete(char *word,bst_t *bst){
  if(bst == NULL) return NULL;
  
  bst_t *temp;
  temp = bst_deleter(word, bst);
  return bst;
};

bst_t* bst_find(char *word,bst_t *bst){
  if(bst == NULL) return NULL;

  int result = strcmp(word, bst->word);
  if(result < 0) return bst_find(word, bst->left);
  else if (result > 0 ) return bst_find(word, bst->right);
  else return bst;
};

bst_t* bst_findmin(bst_t *bst){
  if(bst == NULL) return NULL;
  if(bst->left != NULL) return bst_findmin(bst->left);
  else return bst;
};

bst_t* bst_findmax(bst_t *bst){
  if(bst == NULL) return NULL;
  if(bst->right != NULL) return bst_findmax(bst->right);
  else return bst;
};

int bst_maxdepth(bst_t *bst){
  if(bst==NULL) return 0;

  int ret = 1;
  int leftdepth = bst_maxdepth(bst->left);
  int rightdepth = bst_maxdepth(bst->right);
  ret += (leftdepth > rightdepth) ? leftdepth : rightdepth;

  return ret;
};

int bst_nodenum(bst_t *bst){
  if(bst == NULL) return 0;

  int ret = 1;
  if(bst->left != NULL) ret += bst_nodenum(bst->left);
  if(bst->right != NULL) ret += bst_nodenum(bst->right);
  return ret;
};
int bst_countsum(bst_t *bst){
  if(bst == NULL) return 0;

  int ret = bst->count;
  if(bst->left != NULL) ret += bst_countsum(bst->left);
  if(bst->right != NULL) ret += bst_countsum(bst->right);
  return ret;
};

void bst_print(bst_t *bst, int depth){
  if(bst == NULL) return;
  int i;
  for(i = 0 ; i < depth ; i++) printf(" ");
  printf("%s (%d)\n", bst->word, bst->count);
  bst_print(bst->left, depth + 1);
  bst_print(bst->right, depth + 1);
};