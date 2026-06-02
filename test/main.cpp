#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include "exam.h"

// --- Existing tests (kept) ----------------------------------------------
// Math tests
TEST(ExamMath, IsPowerOf2) {
    EXPECT_EQ(is_power_of_2(0), 0);
    EXPECT_EQ(is_power_of_2(1), 1);
    EXPECT_EQ(is_power_of_2(2), 1);
    EXPECT_EQ(is_power_of_2(3), 0);
    EXPECT_EQ(is_power_of_2(1024), 1);
    EXPECT_EQ(is_power_of_2(1023), 0);
    EXPECT_EQ(is_power_of_2(2147483648u), 1); // Edge case Max power of 2
}

TEST(ExamMath, Pgcd) {
    EXPECT_EQ(pgcd("14", "77"), 7);
    EXPECT_EQ(pgcd("17", "3"), 1);
    EXPECT_EQ(pgcd("42", "10"), 2);
    EXPECT_EQ(pgcd("42", "12"), 6);
    EXPECT_EQ(pgcd("100", "100"), 100); // Same numbers
}

TEST(ExamMath, Fprime) {
    testing::internal::CaptureStdout();
    fprime((char*)"225225");
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "3*3*5*5*7*11*13\n");

    testing::internal::CaptureStdout();
    fprime((char*)"8333325");
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "3*3*5*5*7*11*13*37\n");
    
    testing::internal::CaptureStdout();
    fprime((char*)"1");
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1");
}

// String tests
TEST(ExamStr, FtStrlen) {
    EXPECT_EQ(ft_strlen((char*)""), 0);
    EXPECT_EQ(ft_strlen((char*)"hello"), 5);
    EXPECT_EQ(ft_strlen((char*)"42"), 2);
}

TEST(ExamStr, FtStrcpy) {
    char dest[100];
    EXPECT_STREQ(ft_strcpy(dest, (char*)"Hello World"), "Hello World");
    EXPECT_STREQ(ft_strcpy(dest, (char*)""), "");
}

TEST(ExamStr, RevPrint) {
    testing::internal::CaptureStdout();
    ft_rev_print((char*)"zaz");
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "zaz\n");
    
    testing::internal::CaptureStdout();
    ft_rev_print((char*)"dub0 a POIL");
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "LIOP a 0bud\n");

    testing::internal::CaptureStdout();
    ft_rev_print((char*)"");
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "\n");
}

TEST(ExamStr, Rot13) {
    char str1[] = "abcqwerty";
    testing::internal::CaptureStdout();
    ft_rot_13(str1);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "nopdjregl\n");

    char str2[] = "My horse is Amazing.";
    testing::internal::CaptureStdout();
    ft_rot_13(str2);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Zl ubefr vf Nznmvat.\n");
}

TEST(ExamStr, FtStrcmp) {
    EXPECT_EQ(ft_strcmp((char*)"abc", (char*)"abc"), 0);
    EXPECT_GT(ft_strcmp((char*)"abcd", (char*)"abc"), 0);
    EXPECT_LT(ft_strcmp((char*)"abc", (char*)"abcd"), 0);
    EXPECT_EQ(ft_strcmp((char*)"", (char*)""), 0);
}

// Conversion tests
TEST(ExamConv, FtAtoi) {
    EXPECT_EQ(ft_atoi((char*)"42"), 42);
    EXPECT_EQ(ft_atoi((char*)"-42"), -42);
    EXPECT_EQ(ft_atoi((char*)"   +42"), 42);
    EXPECT_EQ(ft_atoi((char*)"   -42"), -42);
    EXPECT_EQ(ft_atoi((char*)" \t\n -42ab56"), -42);
}

TEST(ExamConv, FtItoa) {
    char *res;

    res = ft_itoa(42);
    EXPECT_STREQ(res, "42");
    free(res);

    res = ft_itoa(-42);
    EXPECT_STREQ(res, "-42");
    free(res);
    
    res = ft_itoa(-2147483648LL);
    EXPECT_STREQ(res, "-2147483648");
    free(res);

    res = ft_itoa(0);
    EXPECT_STREQ(res, "0");
    free(res);
}

TEST(ExamConv, FtAtoiBase) {
    EXPECT_EQ(ft_atoi_base("12F", 16), 303);
    EXPECT_EQ(ft_atoi_base("-12F", 16), -303);
    EXPECT_EQ(ft_atoi_base("101", 2), 5);
    EXPECT_EQ(ft_atoi_base("42", 10), 42);
    EXPECT_EQ(ft_atoi_base("-FF", 16), -255);
}

// Bit tests
TEST(ExamBits, SwapBits) {
    EXPECT_EQ(swap_bits(0x41), 0x14); // 'A' 65 -> 20
    EXPECT_EQ(swap_bits(0xF0), 0x0F);
}

TEST(ExamBits, PrintBits) {
    testing::internal::CaptureStdout();
    print_bits(2);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "00000010");
}

TEST(ExamBits, ReverseBits) {
    EXPECT_EQ(reverse_bits(0x01), 0x80); // 1 -> 128
    EXPECT_EQ(reverse_bits(0x02), 0x40); // 2 -> 64
}

// List tests

// Provide full definition since exam.h only forward declares it
struct s_list {
    struct s_list *next;
    void *data;
};

void add_node(t_list **lst, void* data) {
    t_list *node = (t_list*)malloc(sizeof(struct s_list));
    node->data = data;
    node->next = *lst;
    *lst = node;
}

int cmp_ints(int a, int b) {
    return (a <= b) ? 1 : 0; // standard sorting
}

int cmp_void_ints(void *a, void *b) {
    return (a == b) ? 0 : 1;
}

TEST(ExamLists, FtListSize) {
    t_list *head = nullptr;
    EXPECT_EQ(ft_list_size(head), 0);
    
    add_node(&head, (void*)42);
    EXPECT_EQ(ft_list_size(head), 1);
    add_node(&head, (void*)42);
    EXPECT_EQ(ft_list_size(head), 2);
    
    // cleanup
    while (head) {
        t_list *tmp = head;
        head = head->next;
        free(tmp);
    }
}

TEST(ExamLists, FtListRemoveIf) {
    t_list *head = nullptr;
    
    add_node(&head, (void*)10);
    add_node(&head, (void*)20);
    add_node(&head, (void*)10);
    
    EXPECT_EQ(ft_list_size(head), 3);
    
    void* to_remove = (void*)10;
    ft_list_remove_if(&head, to_remove, reinterpret_cast<int(*)()>(cmp_void_ints));
    
    EXPECT_EQ(ft_list_size(head), 1);
    EXPECT_EQ(head->data, (void*)20);
    
    free(head);
}

// --- Appended comprehensive tests (adjusted) -----------------------------

// MathFunctionsTest (expanded power-of-two, pgcd/lcm)
class MathFunctionsTest : public ::testing::Test {};

TEST_F(MathFunctionsTest, IsPowerOf2_Zero) { EXPECT_EQ(is_power_of_2(0), 0); }
TEST_F(MathFunctionsTest, IsPowerOf2_One) { EXPECT_EQ(is_power_of_2(1), 1); }
TEST_F(MathFunctionsTest, IsPowerOf2_Powers) {
    EXPECT_EQ(is_power_of_2(2), 1);
    EXPECT_EQ(is_power_of_2(4), 1);
    EXPECT_EQ(is_power_of_2(8), 1);
    EXPECT_EQ(is_power_of_2(16), 1);
    EXPECT_EQ(is_power_of_2(32), 1);
    EXPECT_EQ(is_power_of_2(64), 1);
    EXPECT_EQ(is_power_of_2(128), 1);
    EXPECT_EQ(is_power_of_2(256), 1);
    EXPECT_EQ(is_power_of_2(512), 1);
    EXPECT_EQ(is_power_of_2(1024), 1);
}
TEST_F(MathFunctionsTest, IsPowerOf2_NonPowers) {
    EXPECT_EQ(is_power_of_2(3), 0);
    EXPECT_EQ(is_power_of_2(5), 0);
    EXPECT_EQ(is_power_of_2(6), 0);
    EXPECT_EQ(is_power_of_2(7), 0);
    EXPECT_EQ(is_power_of_2(9), 0);
    EXPECT_EQ(is_power_of_2(10), 0);
    EXPECT_EQ(is_power_of_2(15), 0);
    EXPECT_EQ(is_power_of_2(100), 0);
}

TEST_F(MathFunctionsTest, PGCD_Basic) {
    EXPECT_EQ(pgcd("42", "10"), 2);
    EXPECT_EQ(pgcd("42", "12"), 6);
    EXPECT_EQ(pgcd("14", "77"), 7);
}
TEST_F(MathFunctionsTest, PGCD_Same) {
    EXPECT_EQ(pgcd("10", "10"), 10);
    EXPECT_EQ(pgcd("1", "1"), 1);
}
TEST_F(MathFunctionsTest, PGCD_One) {
    EXPECT_EQ(pgcd("17", "3"), 1);
    EXPECT_EQ(pgcd("100", "99"), 1);
}
TEST_F(MathFunctionsTest, PGCD_Coprime) {
    EXPECT_EQ(pgcd("7", "11"), 1);
    EXPECT_EQ(pgcd("13", "17"), 1);
}
/*
TEST_F(MathFunctionsTest, LCM_Basic) {
    EXPECT_EQ(lcm(4, 6), 12);
    EXPECT_EQ(lcm(3, 5), 15);
}

TEST_F(MathFunctionsTest, LCM_Same) {
    EXPECT_EQ(lcm(5, 5), 5);
    EXPECT_EQ(lcm(10, 10), 10);
}
TEST_F(MathFunctionsTest, LCM_Zero) {
    EXPECT_EQ(lcm(0, 5), 0);
    EXPECT_EQ(lcm(5, 0), 0);
    EXPECT_EQ(lcm(0, 0), 0);
}
*/
// StringFunctionsTest (expanded)
class StringFunctionsTest : public ::testing::Test {};

TEST_F(StringFunctionsTest, FtStrlen_Empty) { char str[] = ""; EXPECT_EQ(ft_strlen(str), 0); }
TEST_F(StringFunctionsTest, FtStrlen_Single) { char str[] = "a"; EXPECT_EQ(ft_strlen(str), 1); }
TEST_F(StringFunctionsTest, FtStrlen_Multiple) { char str[] = "hello"; EXPECT_EQ(ft_strlen(str), 5); }
TEST_F(StringFunctionsTest, FtStrlen_Long) { char str[] = "The quick brown fox jumps over the lazy dog"; EXPECT_EQ(ft_strlen(str), 43); }
TEST_F(StringFunctionsTest, FtStrlen_WithSpaces) { char str[] = "hello world test"; EXPECT_EQ(ft_strlen(str), 16); }

TEST_F(StringFunctionsTest, FtStrcpy_Empty) { char dst[10]; char src[] = ""; ft_strcpy(dst, src); EXPECT_STREQ(dst, ""); }
TEST_F(StringFunctionsTest, FtStrcpy_Single) { char dst[10]; char src[] = "a"; ft_strcpy(dst, src); EXPECT_STREQ(dst, "a"); }
TEST_F(StringFunctionsTest, FtStrcpy_Multiple) { char dst[20]; char src[] = "hello"; ft_strcpy(dst, src); EXPECT_STREQ(dst, "hello"); }
TEST_F(StringFunctionsTest, FtStrcpy_WithSpaces) { char dst[30]; char src[] = "hello world"; ft_strcpy(dst, src); EXPECT_STREQ(dst, "hello world"); }

TEST_F(StringFunctionsTest, FtStrcmp_Equal) { EXPECT_EQ(ft_strcmp((char*)"hello", (char*)"hello"), 0); }
TEST_F(StringFunctionsTest, FtStrcmp_Different) { EXPECT_LT(ft_strcmp((char*)"abc", (char*)"abd"), 0); EXPECT_GT(ft_strcmp((char*)"abd", (char*)"abc"), 0); }
TEST_F(StringFunctionsTest, FtStrcmp_Empty) { EXPECT_EQ(ft_strcmp((char*)"", (char*)""), 0); }
TEST_F(StringFunctionsTest, FtStrcmp_LongerVsShorter) { EXPECT_LT(ft_strcmp((char*)"abc", (char*)"abcd"), 0); EXPECT_GT(ft_strcmp((char*)"abcd", (char*)"abc"), 0); }

TEST_F(StringFunctionsTest, FtStrrev_Empty) { char str[] = ""; ft_strrev(str); EXPECT_STREQ(str, ""); }
TEST_F(StringFunctionsTest, FtStrrev_Single) { char str[] = "a"; ft_strrev(str); EXPECT_STREQ(str, "a"); }
TEST_F(StringFunctionsTest, FtStrrev_Palindrome) { char str[] = "racecar"; ft_strrev(str); EXPECT_STREQ(str, "racecar"); }
TEST_F(StringFunctionsTest, FtStrrev_Normal) { char str[] = "hello"; ft_strrev(str); EXPECT_STREQ(str, "olleh"); }
TEST_F(StringFunctionsTest, FtStrrev_WithSpaces) { char str[] = "abc def"; ft_strrev(str); EXPECT_STREQ(str, "fed cba"); }

TEST_F(StringFunctionsTest, FtSwap_Integers) { int a = 5; int b = 10; ft_swap(&a, &b); EXPECT_EQ(a, 10); EXPECT_EQ(b, 5); }
TEST_F(StringFunctionsTest, FtSwap_Negative) { int a = -5; int b = 10; ft_swap(&a, &b); EXPECT_EQ(a, 10); EXPECT_EQ(b, -5); }
TEST_F(StringFunctionsTest, FtSwap_Same) { int a = 5; int b = 5; ft_swap(&a, &b); EXPECT_EQ(a, 5); EXPECT_EQ(b, 5); }
TEST_F(StringFunctionsTest, FtSwap_Zero) { int a = 0; int b = 10; ft_swap(&a, &b); EXPECT_EQ(a, 10); EXPECT_EQ(b, 0); }

// Atoi Functions
class AtoiFunctionsTest : public ::testing::Test {};

TEST_F(AtoiFunctionsTest, FtAtoi_Zero) { EXPECT_EQ(ft_atoi("0"), 0); }
TEST_F(AtoiFunctionsTest, FtAtoi_Positive) { EXPECT_EQ(ft_atoi("123"), 123); EXPECT_EQ(ft_atoi("42"), 42); EXPECT_EQ(ft_atoi("999"), 999); }
TEST_F(AtoiFunctionsTest, FtAtoi_Negative) { EXPECT_EQ(ft_atoi("-123"), -123); EXPECT_EQ(ft_atoi("-42"), -42); }
TEST_F(AtoiFunctionsTest, FtAtoi_Leading_Whitespace) { EXPECT_EQ(ft_atoi("   123"), 123); EXPECT_EQ(ft_atoi("\t\t42"), 42); EXPECT_EQ(ft_atoi("\n\r 100"), 100); }
TEST_F(AtoiFunctionsTest, FtAtoi_Sign) { EXPECT_EQ(ft_atoi("+123"), 123); EXPECT_EQ(ft_atoi("-456"), -456); }
TEST_F(AtoiFunctionsTest, FtAtoi_NonDigits) { EXPECT_EQ(ft_atoi("123abc"), 123); EXPECT_EQ(ft_atoi("42xyz"), 42); }
TEST_F(AtoiFunctionsTest, FtAtoi_Empty) { EXPECT_EQ(ft_atoi(""), 0); }
TEST_F(AtoiFunctionsTest, FtAtoi_NoDigits) { EXPECT_EQ(ft_atoi("abc"), 0); EXPECT_EQ(ft_atoi("   "), 0); }
TEST_F(AtoiFunctionsTest, FtAtoi_Large) { EXPECT_EQ(ft_atoi("2147483647"), INT_MAX); }
TEST_F(AtoiFunctionsTest, FtAtoiBase_Binary) { EXPECT_EQ(ft_atoi_base("1010", 2), 10); EXPECT_EQ(ft_atoi_base("11111111", 2), 255); }
TEST_F(AtoiFunctionsTest, FtAtoiBase_Octal) { EXPECT_EQ(ft_atoi_base("12", 8), 10); EXPECT_EQ(ft_atoi_base("377", 8), 255); }
TEST_F(AtoiFunctionsTest, FtAtoiBase_Hex) { EXPECT_EQ(ft_atoi_base("10", 16), 16); EXPECT_EQ(ft_atoi_base("ff", 16), 255); EXPECT_EQ(ft_atoi_base("FF", 16), 255); EXPECT_EQ(ft_atoi_base("dead", 16), 0xDEAD); }
TEST_F(AtoiFunctionsTest, FtAtoiBase_Decimal) { EXPECT_EQ(ft_atoi_base("123", 10), 123); }

// Itoa Functions
class ItoaFunctionsTest : public ::testing::Test {};
TEST_F(ItoaFunctionsTest, FtItoa_Zero) { char *result = ft_itoa(0); EXPECT_STREQ(result, "0"); free(result); }
TEST_F(ItoaFunctionsTest, FtItoa_Positive) { char *result = ft_itoa(123); EXPECT_STREQ(result, "123"); free(result); result = ft_itoa(42); EXPECT_STREQ(result, "42"); free(result); }
TEST_F(ItoaFunctionsTest, FtItoa_Negative) { char *result = ft_itoa(-123); EXPECT_STREQ(result, "-123"); free(result); }
TEST_F(ItoaFunctionsTest, FtItoa_IntMax) { char *result = ft_itoa(INT_MAX); EXPECT_STREQ(result, "2147483647"); free(result); }
TEST_F(ItoaFunctionsTest, FtItoa_IntMin) { char *result = ft_itoa(INT_MIN); EXPECT_STREQ(result, "-2147483648"); free(result); }
TEST_F(ItoaFunctionsTest, FtItoa_Single_Digit) { char *result = ft_itoa(5); EXPECT_STREQ(result, "5"); free(result); }
TEST_F(ItoaFunctionsTest, FtItoa_Negative_Single) { char *result = ft_itoa(-9); EXPECT_STREQ(result, "-9"); free(result); }

// Bit Functions
class BitFunctionsTest : public ::testing::Test {};
TEST_F(BitFunctionsTest, SwapBits_Zero) { EXPECT_EQ(swap_bits(0x00), 0x00); }
TEST_F(BitFunctionsTest, SwapBits_FF) { EXPECT_EQ(swap_bits(0xFF), 0xFF); }
TEST_F(BitFunctionsTest, SwapBits_0F) { EXPECT_EQ(swap_bits(0x0F), 0xF0); }
TEST_F(BitFunctionsTest, SwapBits_F0) { EXPECT_EQ(swap_bits(0xF0), 0x0F); }
TEST_F(BitFunctionsTest, SwapBits_45) { EXPECT_EQ(swap_bits(0x45), 0x54); }
TEST_F(BitFunctionsTest, ReverseBits_Zero) { EXPECT_EQ(reverse_bits(0x00), 0x00); }
TEST_F(BitFunctionsTest, ReverseBits_FF) { EXPECT_EQ(reverse_bits(0xFF), 0xFF); }
TEST_F(BitFunctionsTest, ReverseBits_01) { EXPECT_EQ(reverse_bits(0x01), 0x80); }
TEST_F(BitFunctionsTest, ReverseBits_80) { EXPECT_EQ(reverse_bits(0x80), 0x01); }
TEST_F(BitFunctionsTest, ReverseBits_26) { EXPECT_EQ(reverse_bits(0x26), 0x64); }

// Linked list helpers and tests from comprehensive
// reuse existing `t_list` / `struct s_list` defined above
static void print_data(void *data) {
    if (data)
        std::cout << *(int*)data << " ";
}

class LinkedListTest : public ::testing::Test {};

TEST_F(LinkedListTest, FtListSize_Empty) { EXPECT_EQ(ft_list_size(NULL), 0); }
TEST_F(LinkedListTest, FtListSize_Single) { t_list node1 = {NULL, NULL}; EXPECT_EQ(ft_list_size(&node1), 1); }
TEST_F(LinkedListTest, FtListSize_Multiple) { t_list node3 = {NULL, NULL}; t_list node2 = {&node3, NULL}; t_list node1 = {&node2, NULL}; EXPECT_EQ(ft_list_size(&node1), 3); }
TEST_F(LinkedListTest, FtListSize_Five) { t_list node5 = {NULL, NULL}; t_list node4 = {&node5, NULL}; t_list node3 = {&node4, NULL}; t_list node2 = {&node3, NULL}; t_list node1 = {&node2, NULL}; EXPECT_EQ(ft_list_size(&node1), 5); }
TEST_F(LinkedListTest, FtListForeach_Empty) { ft_list_foreach(NULL, print_data); }
TEST_F(LinkedListTest, FtListForeach_Single) { int data = 42; t_list node = {NULL, &data}; ft_list_foreach(&node, print_data); }

// Edge cases
class EdgeCasesTest : public ::testing::Test {};
TEST_F(EdgeCasesTest, IsPowerOf2_Large) { EXPECT_EQ(is_power_of_2(1 << 30), 1); EXPECT_EQ(is_power_of_2((1U << 31)), 1); }
TEST_F(EdgeCasesTest, Atoi_Overflow) { int result = ft_atoi("9999999999999999"); EXPECT_NE(result, 0); }
TEST_F(EdgeCasesTest, StringFuncs_Nullbyte) { char str[] = "hello\0world"; EXPECT_EQ(ft_strlen(str), 5); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
