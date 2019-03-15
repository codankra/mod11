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
		{
			num[i] = input[i] - '0';
		}
		else{
			printf("Unexpected argument: unable to properly convert input to number!\n");
			return -1;
		}
	}
	int size = sizeof(num)/sizeof(num[0]);
	int rem;

	//Size cases
	if (size == 1) {
		rem = num[0];
	} else if (size == 2){
		rem = num[1] - num[0];
	} else if (size == 3) {
		rem = num[0] +  num[2] - num[1];
	/*
	//If size>3 then take remainder - 1*10^(size of input)
	//or take mod of first 3 digits and then add with mod of other digits
	} else if (size == 4){ // DO num
		rem = 10*num[0] +  num[3] - 10*num[1] - num[2];
	*/
	/*5 digits: a + c + e - d - b */
	/*6 digits:  d + b + f - a - c - e  */
	/*7 digits: 1000*a + 100*c + 10*e + g - 100*b - 10*d - f */
	/*8 digits:  d + b + f + h - a - c - e - g */

	}else{
		fprintf(stderr, 
			"WARNING: invalid size of number: results might be inaccurate!!\n");
	}
	if (neg) {
		rem = -rem;
	}
	while(rem<0){
		rem+=11;
	}
	while(rem>10){
		rem-=11;
	}
	if (!rem){
		printf("%s is divisible by 11!\n", argv[1]);
	} else{
		printf("%s is not divisible by 11. It is congruent (mod 11) to %d! (remainder /11 is %d)\n", argv[1], rem, neg ? 11-rem : rem);
	}
	return 1;
}

