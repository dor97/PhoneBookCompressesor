#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include "struct_client.h"



Short_client* createShortClientArr(int n);
char* searchClientByID(Short_client* arr, int n, char* id);
void cheackAllocation(void* chack);
void compressPhoneNumber(char* phone, unsigned char* compPhone);
void fillArray(Client* clientArr, int size);
void compressId(char* id, unsigned char* compId);
void uncompressPhoneNumber(char* phone, char* compPhone);