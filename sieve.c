#include "sieve.h"

int sieve(int targetPrime){
  if(targetPrime == 1)return 2;
  int size;
  double targetlog = log(targetPrime);
  if (targetPrime > 5000) size = (int)(1.15 * targetPrime * targetlog);
  else size = (int)(1.3 * targetPrime * targetlog) + 10 ;
  size /=2;
  int * arr =  calloc(size, sizeof(int)) ;
  int index = 0;
  int num = 3;
  while(num < ceil(sqrt(size))){
    if(arr[index]==0){
        int innerind;
        for(innerind = index + num; innerind < size; innerind += num){
          arr[innerind] = 1;
        }
    }
        index++;
        num+=2;
  }
  int counter =1;
  num = 3;
  for(index = 0; index < size; index++){
    if(arr[index] == 0)counter++;
    if(counter == targetPrime){
      return num;
    }
    num+=2;
  }
}
