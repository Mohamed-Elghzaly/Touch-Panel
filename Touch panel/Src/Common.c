/*
 * Common.c
 *
 *  Created on: Aug 26, 2024
 *      Author: workstation
 */


#include "../Inc/Common.h"

int string_to_intger(char *str)
{
    int Temp=0;
    while(*str >= '0' && *str <='9')
    {
        Temp += (*str - '0');
        str++;
        if(*str >= '0' && *str <='9')
            Temp *=10;
    }
    return Temp;
}
