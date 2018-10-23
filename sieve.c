#include "sieve.h"

int sieve(int targetPrime){
  int size;
  double targetlog = log(targetPrime);
  if (targetPrime > 5000) size = (int)(1.15 * targetPrime * targetlog);
  else size = (int)(1.3 * targetPrime * targetlog) + 10 ;
  int * arr =  calloc(size, sizeof(int)) ;
  int index = 2;
  while(index < size){
    if(arr[index]==0){
        int innerind;
        for(innerind = 2* index; innerind < size; innerind += index){
          arr[innerind] = 1;
        }
    }
        index++;
  }
  int counter =0;
  for(index = 2; index < size; index++){
    if(arr[index] == 0)counter++;
    if(counter == targetPrime){
      return index;
    }
  }
}
