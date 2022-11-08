#include <inttypes.h>
#include <stdio.h>

uint64_t intpow(uint64_t b, int e) {
	uint64_t res;
	for (res = 1;; b *= b) {
		if (e & 1)
			res *= b;
		e >>= 1;
		if (!e) break;
	}

	return res;
}

int main()
{
	uint64_t mult10[20];

	mult10[0] = 1;
	for (int i = 1; i <= 19; i++)
		mult10[i] = 10ull * mult10[i - 1];


	int count = 3;
	for (int n = 1; n < 19; n++) {
		uint64_t thres = mult10[n - 1];
		for (uint64_t i = 1; i < 10; i++) {
			uint64_t p = intpow(i, n);
			if (p >= thres)
				count++;
		}
	}

	printf("%d\n", count);


	return 0;
}
