#include <gtest/gtest.h>
#include <array>
#include <algorithm>
#include <cstdlib>
#include "exam.h"

int g_argc;
char** g_argv;

TEST(ex02, ft_split)
{
    std::array<std::string, 3> checker = {"Hello", "World", "Programmer"};
    std::array<std::string, 3>::iterator itr;
    char** str = ft_split(*++g_argv);
    char** start = str;
    int i = 0;

    for (itr = checker.begin(), i = 0; itr != checker.end() && i < 3; ++itr, ++i)
        ASSERT_EQ(str[i], *itr);

    while(*str)
    {
        //std::cout << *str << std::endl;
        free(*str);
        str++;
    }
    free(start);

}

TEST(ex02, ft_putstr)
{
    ft_putstr(*g_argv);
    std::cout << std::endl;
}

TEST(ex02, ft_rev_print)
{
    std::string str = "remmargorP dlroW olleH";
    //char* ptr = const_cast<char*>(str.c_str());
    ft_rev_print(str.data());
}

TEST(ex02, ft_ulstr)
{
    ft_ulstr(*g_argv);
    std::string str = "hELLO wORLD pROGRAMMER";
    ASSERT_STREQ(*g_argv, str.data());
}

TEST(ex02, ft_rot_13)
{
    ft_rot_13(*g_argv);
    std::string str = "uRYYB jBEYQ cEBTENZZRE";
    ASSERT_STREQ(*g_argv, str.data());
}

TEST(ex02, ft_first_word)
{
    ft_first_word(*g_argv);
}

TEST(ex02, ft_rotone)
{
    ft_rotone(*g_argv);
    std::string str = "vSZZC kCFZR dFCUFOAASF";
    ASSERT_STREQ(*g_argv, str.data());
}

TEST(ex02, ft_strcpy)
{
    std::string str;
    //char* ptr = const_cast<char*>(str.c_str());
    //ft_strcpy((char*)str.c_str(), *g_argv);
    ft_strcpy(str.data(), *g_argv);
    ASSERT_STREQ(str.c_str(), *g_argv);
}

TEST(ex02, ft_strlen)
{
    ASSERT_EQ(22, ft_strlen(*g_argv));
}

TEST(ex02, ft_swap)
{
    int a = 42, b = 21;
    ft_swap(&a, &b);
    ASSERT_EQ(b, 42);
    ASSERT_EQ(a, 21);
}

TEST(ex02, ft_wdmatch)
{
    std::string str_one = "faya", str_two = "fgvvfdxcacpolhyghbreda";
    ft_wdmatch(str_one.data(), str_two.data());
}

TEST(ex02, ft_strrev)
{
    std::string str = *g_argv;
    std::reverse(str.begin(), str.end());
    ft_strrev(*g_argv);
    ASSERT_EQ(str, *g_argv);
}

TEST(ex02, ft_strdup)
{
    std::string str = ft_strdup(*g_argv);
    ASSERT_STREQ(str.data(), *g_argv);
}

TEST(ex02, ft_strcmp)
{
    std::string str_one = "abc", str_two = "dfg", str_dup = "abc";
    ASSERT_EQ(0, ft_strcmp(str_one.data(), str_dup.data()));
    ASSERT_EQ(strcmp(str_one.data(), str_two.data()), ft_strcmp(str_one.data(), str_two.data()));
}

TEST(ex02, ft_alpha_mirror)
{
    ft_alpha_mirror(*g_argv);
}

TEST(ex02, max)
{
    std::array<int, 4> array_one = {25, 100, 125, 500};
    int array_two[] = {25, 100, 125, 500};
    int max_one = max(array_one.data(), array_one.size());
    int max_two = max(array_two, 4);
    std::cout << max_one << "=" << max_two << std::endl;
    ASSERT_EQ(max_one, max_two);
}

TEST(ex02, ft_atoi)
{
    ASSERT_EQ(atoi("-2025"), ft_atoi("-2025"));
    ASSERT_EQ(atoi("2025"), ft_atoi("2025"));
}

TEST(ex02, is_power_of_2)
{
    ASSERT_EQ(1, is_power_of_2(1024));
    ASSERT_EQ(0, is_power_of_2(9));
}

TEST(ex02, camel_snake)
{
    char str[] = "hello_world";
    snake_to_camel(str);
    char string[] = "helloWorld";
    camel_to_snake(string);
}

int main(int argc, char **argv)
{
    g_argc = argc;
    g_argv = argv;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
