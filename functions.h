#include <stdio.h>
#include <tchar.h>
#include <memory.h>

typedef unsigned char byte;
inline void coreSearchTurbo(byte* haystack, int lenHaystack, byte * elementTosearch, int sizeOfelement, FILE * logger)
{
	int limit = (lenHaystack - sizeOfelement);
	for (int q = 0; q <= limit; q++)	{
		if (haystack[q] == elementTosearch[0])
		{
			if (memcmp(&haystack[q], elementTosearch, sizeOfelement) == 0)
			{
				fprintf(logger, "Element of Size %d found at position %d\n", sizeOfelement, q);
				q += sizeOfelement;
			}
		}
	}

}
inline byte * GetFileContent(long &fileLength, char * fileName, FILE * logger)
{
	fprintf(logger, "%s\n", "Reading File......");
	FILE *fp = 0;
	byte * bufByte = 0;
	fp = fopen(fileName, "r+b");
	int ret = fseek(fp, 0, SEEK_END);
	fileLength = ftell(fp);
	rewind(fp);
	bufByte = new byte[fileLength];
	memset(bufByte, 0, fileLength);
	fread(bufByte, 1, fileLength, fp);
	fclose(fp);
	fp = NULL;
	return bufByte;



}
inline void DeepSearchTurbo(byte * haystack, int lenHaystack, byte * needle, int lenNeedle, int threshold, FILE * logger)
{
	byte * element = new byte[lenNeedle];
	int maxValue = lenNeedle + 1;
	memset(element, 0, lenNeedle);
	do
	{
		int limit = (lenNeedle - threshold);
		for (int i = 0; i <= limit; i++)
		{
			for (int j = 0; j < threshold; j++)
			{
				element[j] = needle[i + j];
			}
			fprintf(logger, "Offset of needle: %d\n", i);
			coreSearchTurbo(haystack, lenHaystack, element, threshold, logger);
		}
		threshold++;
	} while (threshold < (maxValue));
	printf("%s\n", "");
	printf("%s\n", "*****************  Search terminated  **************************");
	fprintf(logger, "%s\n", "");
	fprintf(logger, "%s\n", "*****************  Search terminated  **************************");
	delete[] element;
}







