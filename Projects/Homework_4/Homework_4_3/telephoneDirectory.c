#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "telephoneDirectory.h"

typedef struct Contact {
	char name[30];
	char telephone[15];
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

	contact->next = NULL;
	book->head = contact;
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

void addNewContact(TelephoneDirectory* book) {
	Contact* contact = malloc(sizeof(Contact));
	if (contact == NULL) {
		return;
	}

	contact->next = book->head;
	book->head = contact;
	printf("Enter name:\n");
	while (scanf("%c", book->head->name));
	printf("Enter telephone:\n");
	while (scanf("%c", book->head->telephone));
}