
# CUBE File Parser
CUBE File Parser, tiny, fast and easy, header only, written in C

Copy the header CUBEParser.h in your project and include it  

**Basic usage:**

1) Buffer as argument --> set 0 as mode  
Buffer will be modified internally, remember to free it
```c++
#include "CUBEParser.h"

char title[100] = { 0 };  //in case we won't find the title it will be ""
int32_t size;
double* data = NULL;

//if you don't need the title pass NULL as argument
char* buffer = get_file_contents_("test.cube");
int32_t result = CUBEParser(buffer, 0, title, &size, &data);
free(buffer);
	
```
2) Path to the file as argument --> set 1 as mode  
Memory will be allocated to read the file and free internally after
```c++
int32_t result = CUBEParser("test.cube", 1, title, &size, &data);
```

**Result could be -1, -2, -3 or 0**

```c++
switch (result) {
  case -1: printf("Error - no data lut\n"); break;
  case -2: printf("Size error - not a CUBE file\n"); break;
  case -3: printf("Error - input file not found\n"); break;
  case 0:
    printf("Everything fine\n");
    printf("Title: %s\n", title);
    printf("Size: %d\n\n", size);
    free(data);
    break;
}
```

  
**C++**  

If you are in C++ and you have a string to pass as argument you should copy it in a char array.
You might avoid to copy it using mystring.data() or &mystring[0], but be careful about contigous memory allocation, null terminator and sizes...





