#include <iostream>
#include <string>


static void pow_print(int base, int bit)
{
	if (base >= 10) {
		std::cerr << "base " << base << " is too large, should be less than 10" << std::endl;
		return;
	}
	std::string val = "1";

	for (int i = 0; i < bit; i++) {
		int carr = 0;

		for (int j = val.size() - 1; j >= 0; j--) {
			char tmp = (val[j] - '0') * base + carr;
			carr = tmp / 10;
			val[j] = tmp % 10 + '0';
		}

		if (carr > 0) {
			val = std::to_string(carr) + val;
		}
	}
	std::cout << val << std::endl;
}

int main(int argc, char *argv[])
{
	pow_print(2, 8);
	pow_print(2, 2048);
	pow_print(8, 2048);
	return EXIT_SUCCESS;
}
