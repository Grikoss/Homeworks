#pragma once

#include <stdlib.h>
#include<stdbool.h>
#include "telephoneDirectory.h"

typedef struct Contact {
	char name[30];
	char telephone[15];
	struct Contact* next;
} Contact;

typedef struct TelephoneDirectory {
	Contact* head;
} TelephoneDirectory;

TelephoneDirectory* createTelephoneDirectory(void){
	Contact* contact = malloc(sizeof(contact));
	if (contact == NULL) {
		return NULL;
	}

	TelephoneDirectory* book = malloc(sizeof(TelephoneDirectory));
	if (book == NULL) {
		return NULL;
	}

	contact->next = NULL;
	book->head = contact;
}

bool isEnd(TelephoneDirectory* book){
	return book->head->next == NULL;
}

