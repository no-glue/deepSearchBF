#include <stdio.h>
#include <tchar.h>
#include "functions.h"
#include <time.h>

int main(int argc, char* argv[])
{

	/*if (argc != 4)
	{
		printf("%s\n", "Usage: filetosearch filesearchpattern threshold");
		printf("%s\n", "After correct insertion please check result.log to inspect search results");
		return 0;
	}
	else
	{		
		printf("%s\n", argv[1]);
		printf("%s\n", argv[2]);
		printf("%s\n", argv[3]);
	}

	return 0;*/


	// Read haistack content file
	long  lenHaystack = 0;;
	char * fileHaystack = "Haystack.bin";
	byte * haystack = GetFileContent(lenHaystack, fileHaystack);	
	// Read needle content file
	long  lenNeedle = 0;
	char * fileNeedle = "needle.bin";
	byte * needle = GetFileContent(lenNeedle, fileNeedle);
	// Setting Threshold
	int threshold = 950;
	// Performing deep search
	clock_t start, finish;
	start = clock();
	DeepSearchTurbo(haystack, lenHaystack, needle, lenNeedle, threshold);
	finish = clock();
	printf("%s  %f ", "Time elapsed in seconds: ", (double)(finish - start) / CLOCKS_PER_SEC);
	printf("%s\n", "");	
	delete[] haystack; haystack = 0;
	delete[] needle; needle = 0;




	

	// your code here

	


	getchar();
	return 0;
}







