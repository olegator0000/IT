#include <iostream>
#include <cmath>

bool is_prime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i <= static_cast<int>(sqrt(number)); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int count_funny_numbers(int l, int m) {
    int funny_count = 0;
    for (int i = l; i <= m; ++i) {
        int divisors_count = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                divisors_count++;
            }
        }
        if (!is_prime(divisors_count)) {
            funny_count++;
        }
    }
    return funny_count;
}

int main() {
    int l, m;
    std::cout << "Введіть діапазон [l, m]: ";
    std::cin >> l >> m;

    if (l > m) {
        std::cout << 'Недійсний діапазон. "l" має бути менше або дорівнювати "m".' << std::endl;
        return 1;  // Exit with an error code
    }

    int result = count_funny_numbers(l, m);

    std::cout << "Кількість кумедних чисел у діапазоні [" << l << ", " << m << "]: " << result << std::endl;

    return 0;
}
