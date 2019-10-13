#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define NULL_ELEMENT '\0'

// function prototypes you need to implement

void FetalError(char* msg){
  printf("%s", msg);
  exit(0);
}

typedef int ElementType;
struct StackRecord;
typedef struct StackRecord *Stack;

struct StackRecord {
  int Capacity;
  int TopOfStack;
  ElementType *Array;
};

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

int in2post(char *infix,char *postfix);
int postcalc(char *postfix);

Stack CreateStack(int MaxElements){
  Stack S;
  if(MaxElements <= 0) return NULL;
  S = (Stack)malloc(sizeof(struct StackRecord));
  if(S == NULL) FetalError("Out of Memory");
  S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
  if(S->Array == NULL) FetalError("Out of Memory");
  S->Capacity = MaxElements;
  MakeEmpty(S);
  return S;
}

void DisposeStack(Stack S){
  if(S){
    free(S->Array);
    free(S);
  }
}

int IsEmpty(Stack S){
  return (S->TopOfStack == -1);
}

int IsFull(Stack S){
  return (S->TopOfStack == S->Capacity);
}

void MakeEmpty(Stack S){
  S->TopOfStack = -1;
}

void Push(ElementType X, Stack S){
  if(IsFull(S)) FetalError("Full Stack\n");
  else S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S){
  if(!IsEmpty(S)) return S->Array[S->TopOfStack];
  FetalError("Empty Stack");
  return NULL_ELEMENT;
}

void Pop(Stack S){
  if(IsEmpty(S)) FetalError("Empty Stack");
  else S->TopOfStack--;
}

ElementType TopAndPop(Stack S){
  if(!IsEmpty(S)) return S->Array[S->TopOfStack--];
  FetalError("Empty Stack");
  return NULL_ELEMENT;
}

void test1()
{
   int i, v;
   char eq[][128] = {
      "1234+*5678+*-9*++",
      "1234+*+5678+*-9*+",
      "1234+*+5678+*-9*",
      "234+*+5678+*-9*+",
      "1234+*+678+*-9*+"
   };

   printf("[Test1: postfix expression validity check]\n");   
   for( i=0 ; i<5 ; i++ ) {
      v = postcalc(eq[i]);
      if( v == 0 ) {
         printf("   %s is not valid\n",eq[i]);
      } else if( v == -750 ) {
         printf("   %s is valid and correctly calcualted: %d\n",eq[i],v);
      } else {
         printf("   %s is valid but not correctly calcualted: %d\n",eq[i],v);         
      }
   }
}

void test2()
{
   FILE *fp;
   int n, linenum, answer;
   char postfix[2048];
   int v, total, score;
   
   printf("[Test2: postfix expression calculation]\n");
   fp = fopen("data_test2.txt","r");
   if( fp == NULL ) {
      printf("Fail to open the file\n");
      return;
   }
   total = score = 0;
   while( 1 ) {
      n = fscanf(fp,"%d %s %d",&linenum, postfix, &answer);
      if( n != 3 ) break;
      v = postcalc(postfix);
      if( v == answer ) score++;
      total++;
   }

   printf("   %d correct answers for %d expressions: %.2f\n",score,total,((float)score/total)*100);
   
   fclose(fp);   
}

void test3()
{
   char eq[][128] = {
      "1+2*3+(4*5+6)*7",
      "1+2*3+((4*5+6)*7)",
      "(1+2*3)+(4*5+6)*7",
      "(((1)+(2*3))+((4*5+6)*7))",
      "1+2*3+((4*5+6)*7",
      "1+2*3+(4*5+6)*7)",
      "1++2*3+((4*5+6)*7)",
      "1+2*3+((4*5+6)*7+)",
      "1+2*3+((4*5+6)*7)+",
      "1+2*3+(9(4*5+6)*7)",
      "1+2*3+((4*5+6)*7)9"
   };
   char postfix[1024];
   int i, r;
   
   printf("[Test3: infix to postfix conversion]\n");
   for( i=0 ; i<11 ; i++ ) {
      r = in2post(eq[i],postfix);
      if( r == 0 ) {
         printf("   %s is not valid\n",eq[i]);
      } else {
         printf("   %s --> %s\n",eq[i],postfix);
      }
   }
}

void test4()
{
   FILE *fp;
   int n, linenum, answer;
   char infix[2048], postfix[2048];
   int v, r;
   int total, score;
   
   printf("[Test4: infix expression calculation]\n");
   fp = fopen("data_test4.txt","r");
   if( fp == NULL ) {
      printf("Fail to open the file\n");
      return;
   }
   total = score = 0;
   while( 1 ) {
      n = fscanf(fp,"%d %s %d",&linenum,infix,&answer);
      if( n != 3 ) break;
      in2post(infix,postfix);
      v = postcalc(postfix);
      if( v == answer ) score++;
      total++;
   }
   printf("   %d correct answers for %d expressions: %.2f\n",score,total,((float)score/total)*100);
   
   fclose(fp);
}

int main(int argc, const char *argv[]) 
{
   test1();
   test2();
   test3();
   test4();
   
   return 0;
}

/*
 * infix: string of an infix expression
 * postfix: character array where the converted 
            postfix expression will be stored.
            assume that enough storage is prepared.
         the postfix expression should be a string.
 * return value: 1 if sucessful, 0 if fails
 */

int isNumber(char a){
  return (a-'0'<= 9 && a-'0' >=0) ? true : false;
}

int isOperator(char a){
  return (a == '+' || a == '-' || a == '*') ? true : false;
}

int isParentheses(char a){
  return (a == '(' || a == ')') ? true : false;
}

int in2post(char *infix,char *postfix)
{
  Stack OperatorStack = CreateStack(2048);
  ElementType word, tmp;

  int leftParenthesesNumber = 0;
  int infixidx = 0, postfixidx = 0;
  int wasOperator = false; // 이전 값이 Operator 인가
  int wasNumber = false; // 이전 값이 Number 인가
  int wasRightParenthesis = false;

  while((word = infix[infixidx]) != '\0'){
    if(isNumber(word)){
      if(wasRightParenthesis) return 0;
      wasRightParenthesis = false;
      wasNumber = true;
      wasOperator = false;
      postfix[postfixidx] = word;
      postfixidx++;
    }
    else if(isOperator(word)){
      if(wasOperator) return 0;
      wasOperator = true;
      wasNumber = false;
      wasRightParenthesis = false;
      if(word == '*'){
        if(!IsEmpty(OperatorStack) && Top(OperatorStack) == '*'){
          postfix[postfixidx] = word;
          postfixidx++;
        }
        else Push(word, OperatorStack);
      }
      else if(word == '+' || word == '-'){
        if(!IsEmpty(OperatorStack) && isOperator(Top(OperatorStack))){
          while(!IsEmpty(OperatorStack) && isOperator(Top(OperatorStack))){
            postfix[postfixidx] = TopAndPop(OperatorStack);
            postfixidx++;
          }
          Push(word, OperatorStack);
        }
        else Push(word, OperatorStack);
      }
    }
    else if(isParentheses(word)){
      if(word == '('){
        if(wasNumber) return 0;
        wasRightParenthesis = false;
        Push(word, OperatorStack);
        leftParenthesesNumber++;
      }
      else if (word == ')'){
        if(wasOperator) return 0;
        if(leftParenthesesNumber == 0) return 0; // wrong data
        wasRightParenthesis = true;
        while(!IsEmpty(OperatorStack) && (tmp = TopAndPop(OperatorStack)) != '('){
          postfix[postfixidx] = tmp;
          postfixidx++;
        }
        leftParenthesesNumber--;
      }
      wasNumber = false;
      wasOperator = false;
    }
    else{
      printf("Something went wrong because this word is not included in any type : %c\n", word);
      FetalError("Error in in2post");
    }
    infixidx++;
  }

  while(!IsEmpty(OperatorStack) && (tmp = TopAndPop(OperatorStack)) != '('){
    postfix[postfixidx] = tmp;
    postfixidx++;
  }

  if(wasOperator) return 0;
  if(leftParenthesesNumber != 0) return 0;

  postfix[postfixidx] = '\0';
  DisposeStack(OperatorStack);
  return 1;
}

/*
 * postfix: string of a postfix expression
 * return value: calculated value, 0 if fails
 */

int postcalc(char *postfix)
{
  Stack NumberStack = CreateStack(2048);
  ElementType word, tmp;
  int idx = 0;
  int pop1,pop2;

  while((word = postfix[idx]) != '\0'){
    if(isNumber(word)) Push(word - '0', NumberStack);
    else{
      if(NumberStack->TopOfStack < 1) return 0; // Stack에 값이 2개 미만일때
      pop1 = TopAndPop(NumberStack);
      pop2 = TopAndPop(NumberStack);
      if(word == '*') Push(pop1 * pop2, NumberStack);
      else if(word == '+') Push(pop1 + pop2, NumberStack);
      else if(word == '-') Push(pop2 - pop1, NumberStack);
      else FetalError("Wrong Operator");
    }
    idx++;
  }

  if(NumberStack->TopOfStack != 0) return 0;
  ElementType result = TopAndPop(NumberStack);
  DisposeStack(NumberStack);
   return result;
}
