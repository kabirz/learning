#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *reverse(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char tmp = str[i];

		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	return str;
}

static void pow_print(int base, int bit)
{
	int bits = 1;

	if (base >= 10) {
		printf("base %d is too large, should be less than 10\n", base);
		return;
	}

	char *val = calloc(bit, sizeof(char));
	if (!val) {
		perror("calloc:");
		return;
	}
	val[0] = '1';

	for (int i = 0; i < bit; i++) {
		int carr = 0;
		int j = 0;

		for (; val[j] >= '0'; j++) {
			char tmp = (val[j] - '0') * base + carr;
			carr = tmp / 10;
			val[j] = tmp % 10 + '0';
		}

		if (carr > 0) {
			bits++;
			val[j] = carr + '0';
		}
	}
	printf("bits: %d, val: %s\n", bits, reverse(val));
	free(val);
}

int main(int argc, char *argv[])
{
	pow_print(2, 2048);
	return EXIT_SUCCESS;
}
