#include "CUBEParser.h"

int main() {
	char title[100];
	int32_t size;
	double* data = NULL;
	//if you don't need the title pass NULL as argument
	int32_t result = CUBEParser("test.cube", title, &size, &data);

	switch (result) {
	case -1: printf("Size error - not a CUBE file\n"); break;
	case -2: printf("Error - no data lut\n"); break;
	case -3: printf("Error - input file not found\n"); break;
	case 0:
		printf("Everything fine\n");
		printf("Title: %s\n", title);
		printf("Size: %d\n\n", size);
		for (uint32_t idx = 0; idx < pow(size, 3) * 3; idx += 3) printf("%.9f %.9f %.9f\n", data[idx], data[idx + 1], data[idx + 2]);
		free(data);
		break;
	}

}

