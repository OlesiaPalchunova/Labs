#include <gtest/gtest.h>

#include <cmath>

#include "BigInt.h"

TEST(Constructor, m_m_val) {
    for (int i = 0; i < 100; ++i) {
        int number = -1 * rand();
        BigInt bigint(number);
        --number;
        --bigint;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, val_m_m) {
    for (int i = 0; i < 100; ++i) {
        int number = -1 * rand();
        BigInt bigint(number);
        number--;
        bigint--;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, p_p_val) {
    for (int i = 0; i < 100; ++i) {
        int number = -1 * std::rand();
        BigInt bigint(number);
        ++number;
        ++bigint;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, val_p_p) {
    for (int i = 0; i < 100; ++i) {
        int number = -1 * rand();
        BigInt bigint(number);
        number++;
        bigint++;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, ex_1) {
    for (int i = 0; i < 100; ++i) {
        int number;
        BigInt bigint;
        int a = rand(), b = rand(), c = rand(), d = rand();
        number = (a + b) * c - d;
        bigint = (a + b) * c - d;;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, ex_2) {
    for (int i = 0; i < 100; ++i) {
        int number;
        BigInt bigint;
        int a = rand() * -1, b = rand() * -1, c = rand() * -1, d = rand() * -1;
        number = (a - b) / c - d * 9;
        bigint = (a - b) / c - d * 9;;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, log_or) {
    for (int i = 0; i < 100; ++i) {
        int number;
        BigInt bigint;
        int a, b;

        a = rand() * -1, b = rand() * -1;
        number = a | b;
        bigint = a | b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand() * -1;
        number = a | b;
        bigint = a | b;
        ASSERT_EQ((int)bigint, number);

        a = rand() * -1, b = rand();
        number = a | b;
        bigint = a | b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand();
        number = a | b;
        bigint = a | b;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, log_and) {
    for (int i = 0; i < 100; ++i) {
        int number;
        BigInt bigint;
        int a, b;

        a = rand() * -1, b = rand() * -1;
        number = a & b;
        bigint = a & b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand() * -1;
        number = a & b;
        bigint = a & b;
        ASSERT_EQ((int)bigint, number);

        a = rand() * -1, b = rand();
        number = a & b;
        bigint = a & b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand();
        number = a & b;
        bigint = a & b;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, log_por) {
    for (int i = 0; i < 100; ++i) {
        int number;
        BigInt bigint;
        int a, b;

        a = rand() * -1, b = rand() * -1;
        number = a ^ b;
        bigint = a ^ b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand() * -1;
        number = a ^ b;
        bigint = a ^ b;
        ASSERT_EQ((int)bigint, number);

        a = rand() * -1, b = rand();
        number = a ^ b;
        bigint = a ^ b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand();
        number = a ^ b;
        bigint = a ^ b;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, rest) {
    for (int i = 0; i < 100; ++i) {
        int number;
        BigInt bigint;
        int a, b;

        a = rand() * -1, b = rand() * -1;
        number = a % b;
        bigint = a % b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand() * -1;
        number = a % b;
        bigint = a % b;
        ASSERT_EQ((int)bigint, number);

        a = rand() * -1, b = rand();
        number = a % b;
        bigint = a % b;
        ASSERT_EQ((int)bigint, number);

        a = rand(), b = rand();
        number = a % b;
        bigint = a % b;
        ASSERT_EQ((int)bigint, number);
    }
}

TEST(Constructor, inv) {
    for (int i = 0; i < 100; ++i) {
        int number = rand();
        BigInt bigint(number);
        ASSERT_EQ((int)~bigint, ~number);
    }
}

TEST(Constructor, less_than_sign){
    for (int i = 0; i < 100; i++){
        int a = rand();
        int number = 60;
        BigInt bigint(number);
        BigInt temp(a);
        if ((number > a && bigint > temp) || (a >= number && temp >= bigint)) ASSERT_EQ(1,1);
        else ASSERT_EQ(1, 0);
    }
}

TEST(Constructor, greater_than_sign){
    for (int i = 0; i < 100; i++){
        int a = rand();
        int number = 60;
        BigInt bigint(number);
        BigInt temp(a);
        if ((number < a && bigint < temp) || (a <= number && temp <= bigint)) ASSERT_EQ(1,1);
        else ASSERT_EQ(1, 0);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
