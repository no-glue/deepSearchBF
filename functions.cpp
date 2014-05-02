#include <stdio.h>
#include <tchar.h>
#include "functions.h"
#include <memory.h>

typedef unsigned char byte;

byte * GetFileContent(long &fileLength, char * fileName)
{
	FILE *fp = 0;
	byte * bufByte = 0;
	fp = fopen(fileName, "r+b");
	int ret = fseek(fp, 0, SEEK_END);
	fileLength = ftell(fp);
	rewind(fp);
	bufByte = new byte[fileLength];
	memset(bufByte, 0, fileLength); // we zero the buffer content
	fread(bufByte, 1, fileLength, fp);
	fclose(fp);
	fp = NULL;
	return bufByte;
}
void DeepSearchTurbo(byte * haystack, int lenHaystack, byte * needle, int lenNeedle, int threshold)
{
    byte * element = new byte[lenNeedle];
	memset(element, 0, lenNeedle);
	do
	{
		for (int i = 0; i <= (lenNeedle - threshold); i++)
		{			
			for (int j = 0; j < threshold; j++)
			{				
				element[j] = needle[i + j];
			}
			printf("Offset of needle: %d\n",  i);			
			coreSearchTurbo(haystack, lenHaystack, element, threshold);
			int y = 0;
		}
		threshold++;
	}
	while (threshold < (lenNeedle + 1));
	printf("%s\n", "");
	printf("%s\n", "*****************  Search terminated  **************************");
	delete[] element;
}
inline void coreSearchTurbo(byte* haystack, int lenHaystack, byte * elementTosearch, int sizeOfelement)
{	
	int limit = (lenHaystack - sizeOfelement);
	for (int q = 0; q <= limit; q++)	{
		if (haystack[q] == elementTosearch[0])
		{
			int ret = memcmp(&haystack[q], elementTosearch, sizeOfelement);
			if (ret == 0)
			{
				printf("Element of Size %d found at position %d\n", sizeOfelement, q);
				printf("%s\n", "");
				q += sizeOfelement;
			}
		}
	}
}