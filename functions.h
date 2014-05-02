#include <stdio.h>
#include <tchar.h>
typedef unsigned char byte;
byte * GetFileContent(long &fileLength, char * fileName, FILE * logger);
void DeepSearchTurbo(byte * haystack, int lenHaystack, byte * needle, int lenNeedle, int threshold, FILE * logger);
void coreSearchTurbo(byte* haystack, int lenHaystack, byte * elementTosearch, int sizeOfelement, FILE * logger);






