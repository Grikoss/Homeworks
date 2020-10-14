#pragma once

#include<stdio.h>

typedef struct StringValue {
	char* string[100];
	struct StringValue* next;
} StringValue;