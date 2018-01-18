#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>


using namespace std;

int main()
{
	char someString[] = "Hello Skunk Works. What are you building?";
	char dataVals[9] = { 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78, 0x89, 0 };
	DWORD newArray = 0;

	printf("Hello World!\n\r");
	printf("Press any key to exit()\n\r");
	getchar(); 

	printf("The length of someString[] is: %d\n\r", sizeof(someString));
	printf("Press any key to continue()\n\r");
	getchar();

	for (int i = 0; i < sizeof(dataVals); i++) {
		printf("dataVals_Hex[%d]: %02X (%d)\n\r", i, (unsigned char)dataVals[i], (unsigned char)dataVals[i], (unsigned char)dataVals[i]);
	}
	printf("Press any key to continue()\n\r");
	getchar();

	// Combine array of values in Hexidecimal!
	newArray = dataVals[0];
	newArray = (newArray << 8) + dataVals[1];
	printf("newArray is: %032X\n\r", newArray);
	printf("Press any key to exit()\n\r");
	getchar();

	for (int j = 0; j < (sizeof(dataVals) - 1); j++) {

	}

	return 0;
}