#include "A2DConverter.h"

bool getActualChargeOrDischargeCurrentVaule_10A2D(int*sensorData,int * currentInAmps)
{
    float currentValue = 0.0;
    int CurrentRoundedValue = 0;
    
    if((*sensorData < 1024)&&(*sensorData >=0))
    {
        currentValue = (30  *( *sensorData / 1023));
        CurrentRoundedValue = round(currentValue);
        *currentInAmps = abs(CurrentRoundedValue - 1023);
        return 1;
    }
    else
    {
        return 0;
    }
}

bool  getActualCurrentvalue_12A2D(int*sensorData,int * currentInAmps)
{
    if((*sensorData < 4095) &&(*sensorData >=0))
    {
        *currentInAmps = round(10  * (*sensorData / 4094));
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int ConvertToCurrentRange(int bitInput ,int*sensorData)
{
    
    bool isvalueInRange = 0;
    int currentValue = 0;
    if(bitInput == 10)
    {
        isvalueInRange =getActualChargeOrDischargeCurrentVaule_10A2D(sensorData,&currentValue); 
        
        
    }
    else 
    {
        //(bitInput == 12)
        isvalueInRange = getActualCurrentvalue_12A2D(sensorData,&currentValue);
    }

    if( isvalueInRange == 1)
    {
        return currentValue;
    }
    else
    {
        return -1;
    }
}
int getA2DInRangeValue(int* sensorData,int inputBit ,int startRange, int endRange)
{
    int RangeValue = sizeof(sensorData);
    int currentValue[RangeValue] ={0};
    int noOfValueInRange= 0;
    
    
    for(int i = 0; i< RangeValue ; i++)
    {
        currentValue[i] = ConvertToCurrentRange(inputBit ,sensorData[i]);
    }
    
    noOfValueInRange = getNoOfRValuesInRange(currentValue,startRange ,endRange);
    return noOfValueInRange;
}
