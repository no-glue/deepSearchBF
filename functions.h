#include <stdio.h>
#include <tchar.h>
typedef unsigned char byte;
byte * GetFileContent(long &fileLength, char * fileName);
void DeepSearchTurbo(byte * haystack, int lenHaystack, byte * needle, int lenNeedle, int threshold);
void coreSearchTurbo(byte* haystack, int lenHaystack, byte * elementTosearch, int sizeOfelement);






