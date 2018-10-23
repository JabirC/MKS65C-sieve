#include "sieve.h"

int sieve(int targetPrime){
  if(targetPrime == 1)return 2;
  int size;
  double targetlog = log(targetPrime);
  if (targetPrime > 5000) size = (int)(0.575 * targetPrime * targetlog);
  else size = (int)(.65 * targetPrime * targetlog) + 10 ;
  char * arr =  calloc(size, sizeof(char)) ;
  int index = 0;
  int num = 3;
  while(num < ceil(sqrt(size))){
    if(!arr[index]){
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
    if(!arr[index])counter++;
    if(counter == targetPrime){
      return num;
    }
    num+=2;
  }
}
