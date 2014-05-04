#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

typedef unsigned char byte;
inline void coreSearchTurbo(byte* haystack, int lenHaystack, byte * elementTosearch, int sizeOfelement, FILE * logger)
{
	int limit = (lenHaystack - sizeOfelement);
	for (int q = 0; q <= limit; q++)	{
		// we check the first and last element of the needle. It should be beneficial for long needles.(..To test)
		if ((haystack[q] == elementTosearch[0]) && (haystack[q + sizeOfelement - 1] == elementTosearch[sizeOfelement - 1]))
		{
			if (memcmp(elementTosearch, &haystack[q], sizeOfelement) == 0)
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
			memcpy(element, &needle[i], threshold);
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


int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("%s\n", "Usage:deepsearch64 filetosearch filesearchpattern threshold");
		printf("%s\n", "After correct insertion please check result.log to inspect search results");
		return 0;
	}
	else
	{
		FILE*	fileLogger = fopen("result.log", "w");
		long  lenHaystack = 0;
		int threshold = atoi(argv[3]);
		long  lenNeedle = 0;
		char * fileNeedle = argv[2];
		byte * needle = GetFileContent(lenNeedle, fileNeedle, fileLogger);
		if (threshold > lenNeedle)
		{
			printf("%s %d\n", "The threshold must be less than or equal to ", lenNeedle);
			delete[] needle;
			return -1;
		}
		char * fileHaystack = argv[1];
		byte * haystack = GetFileContent(lenHaystack, fileHaystack, fileLogger);
		printf("%s %s %s %s\n", "Searching in file", fileHaystack, "of contiguous patterns from file", fileNeedle);
		printf("Threshold: %s\n", argv[3]);
		fprintf(fileLogger, "Threshold: %s\n", argv[3]);
		printf("%s\n", "Please wait....");
		clock_t start, finish;
		start = clock();
		DeepSearchTurbo(haystack, lenHaystack, needle, lenNeedle, threshold, fileLogger);
		finish = clock();
		printf("%s  %.4f ", "Time elapsed in seconds: ", (double)(finish - start) / CLOCKS_PER_SEC);
		printf("%s\n", "");
		fprintf(fileLogger, "%s  %.4f ", "Time elapsed in seconds: ", (double)(finish - start) / CLOCKS_PER_SEC);
		fprintf(fileLogger, "%s\n", "");
		printf("%s\n", "");
		printf("%s\n", "Please inspect results in result.log");
		fclose(fileLogger);
		delete[] haystack; haystack = 0;
		delete[] needle; needle = 0;
		getchar();

	}

	return 0;
}
