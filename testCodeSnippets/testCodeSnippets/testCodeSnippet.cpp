#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>

void swap(char *firstElem, char *secondElem);

using namespace std;

int main()
{
	char someString[] = "Hello Skunk Works. What are you building?";
	char dataVals[9] = { 0xF8, 0x14, 0x45, 0xFE, 0x56, 0x67, 0x78, 0x89, 0 };
	char packetResults[8];
	int newArray = 0x00000000;
	int assembled = 0x00000000;
	int dataResults[2];
	int wrapSize = 4;


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

	// Rearrange buffer array
	for (int i = 0; i < 8; i+=4) {
		swap(dataVals[i + 0], dataVals[i + 3]);
		swap(dataVals[i + 1], dataVals[i + 2]);
	}

	for (int i = 0; i < sizeof(dataVals); i++) {
		printf("dataVals_Hex[%d]: %02X (%d)\n\r", i, (unsigned char)dataVals[i], (unsigned char)dataVals[i], (unsigned char)dataVals[i]);
	}
	printf("Press any key to continue()\n\r");
	getchar();

	// Combine array of values in Hexidecimal!
	for (int j = 0; j < wrapSize; j++) {
		assembled = (assembled << 8)|(unsigned char)dataVals[j];
		printf("assembled after %d:    %08X\n\r", j, assembled);
	}
	printf("assembled array is: %08X\n\r", assembled);
	printf("The decimal equivalent of assembled is: %ld\n\r", assembled);
	printf("Press any key to exit()\n\r");
	getchar();

	// Combine arrays into 32bit DWORD
	for (int x = 0; x < 2; x++) {
		int track = 0;
		for (int k = 0; k < 8; k += 4) {
			for (int m = 0; m < wrapSize; m++) {
				dataResults[track] = (dataResults[track] << 8) | (unsigned char)dataVals[m + k];
			}
			track++;
		}
	}

	/*
	for (int k = 0; k < 2; k++) {
		printf("dataResult[%d]: %08X\n\r", k, dataResults[k]);
	}
	getchar();

	for (int k = 0; k < 2; k++) {
		dataResults[k] = 0;
	}

	track = 0;
	for (int k = 0; k < 8; k += 4) {
		for (int m = 0; m < wrapSize; m++) {
			dataResults[track] = (dataResults[track] << 8) | (unsigned char)dataVals[m + k];
		}
		track++;
	}
	*/


	for (int k = 0; k < 2; k++) {
		printf("dataResult[%d]: %08X\n\r", k, dataResults[k]);
	}
	getchar();
	
	return 0;
}

void swap(char *firstElem, char *secondElem)
{
	char temp = *firstElem;

	*firstElem = *secondElem;
	*secondElem = temp;
}