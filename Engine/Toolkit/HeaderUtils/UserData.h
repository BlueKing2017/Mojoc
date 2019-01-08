/*
 * Copyright (c) 2012-2019 scott.cgi All Rights Reserved.
 *
 * This code is licensed under the MIT License:
 * https://github.com/scottcgi/Mojoc/blob/master/LICENSE
 *
 * Since : 2017-4-21
 * Update: 2019-1-8
 * Author: scott.cgi
 */

 
#ifndef USER_DATA_H
#define  USER_DATA_H


#include <stddef.h>


typedef union
{
    int   intValue;
    float  floatValue;
    void* ptrValue;
    char* stringValue;
}
UserDataSlot;


typedef struct
{
    UserDataSlot slots[4];
}
UserData;


static inline void AUserData_Init(UserData* userData)
{
    userData->slots[0].ptrValue = NULL;
    userData->slots[1].ptrValue = NULL;
    userData->slots[2].ptrValue = NULL;
    userData->slots[3].ptrValue = NULL;
}


static inline void AUserData_SetSlotInt(UserData* userData, int slotIndex, int value)
{
    userData->slots[slotIndex].intValue = value;
}


static inline void AUserData_SetSlotFloat(UserData* userData, int slotIndex, float value)
{
    userData->slots[slotIndex].floatValue = value;
}


static inline void AUserData_SetSlotPtr(UserData* userData, int slotIndex, void* value)
{
    userData->slots[slotIndex].ptrValue = value;
}


static inline void AUserData_SetSlotString(UserData* userData, int slotIndex, char* value)
{
    userData->slots[slotIndex].stringValue = value;
}


static inline int AUserData_GetSlotInt(UserData* userData, int slotIndex)
{
    return userData->slots[slotIndex].intValue;
}


static inline float AUserData_GetSlotFloat(UserData* userData, int slotIndex)
{
    return userData->slots[slotIndex].floatValue;
}


static inline void* AUserData_GetSlotPtr(UserData* userData, int slotIndex)
{
    return userData->slots[slotIndex].ptrValue;
}


static inline char* AUserData_GetSlotString(UserData* userData, int slotIndex)
{
    return userData->slots[slotIndex].stringValue;
}


#define AUserData_GetSlotPtrWithType(userData, slotIndex, type) \
    ((type) userData->slots[slotIndex].ptrValue)

#endif
