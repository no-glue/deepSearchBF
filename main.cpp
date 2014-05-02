#include <stdio.h>
#include <tchar.h>
#include "functions.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	if (argc != 4)
	{
		printf("%s\n", "Usage: filetosearch filesearchpattern threshold");
		printf("%s\n", "After correct insertion please check result.log to inspect search results");
		return 0;
	}
	else
	{
		// Read haistack content file
		FILE*	fileLogger = fopen("result.log", "w");
		long  lenHaystack = 0;;
		char * fileHaystack = argv[1];
		byte * haystack = GetFileContent(lenHaystack, fileHaystack, fileLogger);
		// Read needle content file
		long  lenNeedle = 0;
		char * fileNeedle = argv[2];
		byte * needle = GetFileContent(lenNeedle, fileNeedle, fileLogger);
		// Setting Threshold
		int threshold = atoi(argv[3]);
		printf("%s %s %s %s\n","Searching in file", fileHaystack, "of contiguous patterns from file", fileNeedle);
		printf("Threshold: %s\n", argv[3]);
		printf("%s\n", "Please wait....");
		// Performing deep search
		clock_t start, finish;
		start = clock();		
		DeepSearchTurbo(haystack, lenHaystack, needle, lenNeedle, threshold, fileLogger);
		finish = clock();
		printf("%s  %.4f ", "Time elapsed in seconds: ", (double)(finish - start) / CLOCKS_PER_SEC);
		printf("%s\n", "");
		fprintf(fileLogger, "%s  %.4f ", "Time elapsed in seconds: ", (double)(finish - start) / CLOCKS_PER_SEC);
		fprintf(fileLogger, "%s\n", "");
		printf("%s\n", "");
		printf("%s\n","Please inspect results in result.log");
		fclose(fileLogger);
		delete[] haystack; haystack = 0;
		delete[] needle; needle = 0;
		getchar();
	}

	return 0;


	
	
}







