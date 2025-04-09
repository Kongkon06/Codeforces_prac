#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaterandomnum(int n){
  srand(time(NULL));
  return rand()%n;

}
int main()
{
  printf("hi my name is kongkon bora %d\n",rand()%100);
  return 0;
}