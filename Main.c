#include <stdio.h>
#include "main.h"

int getNoOfRValuesInRange(int* array_p,int startRange ,int endRange)
{
  int arrayLength =0;
  int valueInRange =0;
  arrayLength = sizeof(array_p);
  for(int i=0; i< arrayLength ;i++)
  {
       if(true == checkInRange(array_p,startRange,endRange))
       {
         valueInRange ++;
       }
       else
       {
         
       }
  }
  printf("\n%d-%d,%d",startRange,endRange,valueInRange);
  return valueInRange;
}

bool checkInRange(int* array_p,int startRange ,int endRange)
{
  if((array_p[i] >= startRange) && (array_p[i] <= endRange))
  {
    return true;
  }
  else
  {
    return false;
  }
}
        
