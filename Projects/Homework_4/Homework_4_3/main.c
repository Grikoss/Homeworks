#include <stdio.h>
#include <stdbool.h>
#include "listTestModule.h"
#include "telephoneDirectory.h"

void main() {
	runModuleTest();
	while (true) {
		int input = 0;
		printf("Enter the mod:\n");
		scanf("%i", &input);
		char name[100] = { 0 };
		char telephone[100] = { 0 };
		switch (input)
		{
		case(1):
			printf("Enter name:\n");
			scanf("%s", name);
			printf("Enter telephone:\n");
			scanf("%s", telephone);
			telephoneDirectory(1, name, telephone);
			break;

		case(2):
			telephoneDirectory(2, NULL, NULL);
			break;

		case(3):
			printf("Enter name:\n");
			scanf("%s", name);
			telephoneDirectory(3, name, NULL);
			break;

		case(4):
			printf("Enter telephone:\n");
			scanf("%s", telephone);
			telephoneDirectory(3, NULL, telephone);
			break;

		case(5): 
			telephoneDirectory(5, NULL, NULL);
			break;

		default:
			telephoneDirectory(0, NULL, NULL);
		}
	}
}