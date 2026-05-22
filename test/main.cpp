#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "exam.h"

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
