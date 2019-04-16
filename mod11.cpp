#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 2) { 
		fprintf(stderr, 
			"Wrong number of command-line arguments:\nUsage: Expecting a single number\n");
		return -1;
	}
	char* input = argv[1];
	int neg = 0;
	if (input[0] == '-') {
		input = &input[1];
		neg = 1;
	}
	if (strlen(input) == 0) {
		fprintf(stderr, 
			"Invalid argument:\nUsage: Expecting a number\n");
		return -1;
	}
	int num[strlen(input)];
	for (int i = 0; i < strlen(input); ++i){
		if (input[i] - '0' >=0 && input[i] - '0'<10)
			num[i] = input[i] - '0';
		else{
			printf("Unexpected argument: unable to properly convert input to number!\n");
			return -1;
		}
	}
	int size = strlen(input);
	int rem = 0;
	for (int i = 0; i < size; ++i)
		rem = num[i] - rem;
	if (neg) //only if # started with -
		rem = -rem;
	while(rem<0) //eg. -1 -=- 10
		rem+=11;
	while(rem>10) //eg. 12 -=- 1
		rem-=11;
	if (!rem)
		printf("%s is divisible by 11!\n", argv[1]);
	else 
		printf("%s is not divisible by 11. It is congruent (mod 11) to %d! (remainder /11 is %d)\n", argv[1], rem, neg ? 11-rem : rem);
	return 1;
}

