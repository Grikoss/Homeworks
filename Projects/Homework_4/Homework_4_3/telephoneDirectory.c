#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "telephoneDirectory.h"

typedef struct Contact {
	char* name;
	char* telephone;
	struct Contact* next;
} Contact;

typedef struct TelephoneDirectory {
	Contact* head;
} TelephoneDirectory;

TelephoneDirectory* createTelephoneDirectory(void) {
	Contact* contact = malloc(sizeof(contact));
	if (contact == NULL) {
		return NULL;
	}

	TelephoneDirectory* book = malloc(sizeof(TelephoneDirectory));
	if (book == NULL) {
		return NULL;
	}

	contact->name = NULL;
	contact->telephone = NULL;
	contact->next = NULL;
	book->head = contact;

	FILE* file = fopen("Telephone Directory.txt", "r");
	if (file == NULL) {
		return book;
	}

	return book;
}

bool isEnd(TelephoneDirectory* book) {
	return book->head->next == NULL;
}

void deleteTelephoneDirectory(TelephoneDirectory* book) {
	while (!isEnd(book)) {
		Contact* oldHead = book->head;
		book->head = book->head->next;
		free(oldHead);
	}

	free(book->head);
	free(book);
}

void addNewContact(TelephoneDirectory* book, char* name, char* telepone) {
	Contact* contact = malloc(sizeof(Contact));
	if (contact == NULL) {
		return;
	}

	contact->name = name;
	contact->telephone = telepone;
	contact->next = book->head;
	book->head = contact;
}

void exitFromProgram(void) {
	printf("Program left chat");
	exit(0);
}

void printTelephoneDirectory(TelephoneDirectory* book) {
	if (isEnd(book)) {
		printf("Telephone Directory is empty\n");
		return;
	}

	for (TelephoneDirectory* i = book; !isEnd(i); i->head = i->head->next) {
		printf("Name: %s\n", i->head->name);
		printf("Telephone: %s:\n", i->head->telephone);
		printf("\n");
	}
}

char* searchByName(TelephoneDirectory* book, char* input) {
	if (isEnd(book)) {
		printf("Telephone Directory is empty\n");
		return;
	}
	
	for (TelephoneDirectory* i = book; !isEnd(i); i->head = i->head->next) {
		if (strcmp(input, i->head->name) == 0) {
			return i->head->telephone;
		}
	}

	return NULL;
}

char* searchByTelephone(TelephoneDirectory* book, char* input) {
	if (isEnd(book)) {
		printf("Telephone Directory is empty\n");
		return;
	}

	for (TelephoneDirectory* i = book; !isEnd(i); i->head = i->head->next) {
		if (strcmp(input, i->head->telephone) == 0) {
			return i->head->name;
		}
	}

	return NULL;
}

void teleponeDirectory(void) {


}