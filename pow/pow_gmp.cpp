#include <iostream>
#include <gmp.h>

int main() {
    mpz_t result;
    mpz_init(result);

    mpz_ui_pow_ui(result, 2, 2048);

    char* resultStr = mpz_get_str(NULL, 10, result);
    std::cout << resultStr << std::endl;

    // 释放内存
    mpz_clear(result);
    free(resultStr);

    return 0;
}

