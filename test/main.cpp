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
}

TEST(ex02, ft_rev_print)
{
    std::string str = "remmargorP dlroW olleH";
    char* ptr = const_cast<char*>(str.c_str());
    ft_rev_print(ptr);
}

TEST(ex02, ft_ulstr)
{
    ft_ulstr(*g_argv);
    std::string str = "hELLO wORLD pROGRAMMER";
    ASSERT_STREQ(*g_argv, str.c_str());
}

TEST(ex02, ft_rot_13)
{
    ft_rot_13(*g_argv);
    std::string str = "uRYYB jBEYQ cEBTENZZRE";
    ASSERT_STREQ(*g_argv, str.c_str());
}

TEST(ex02, ft_first_word)
{
    ft_first_word(*g_argv);
}

TEST(ex02, ft_rotone)
{
    ft_rotone(*g_argv);
    std::string str = "vSZZC kCFZR dFCUFOAASF";
    ASSERT_STREQ(*g_argv, str.c_str());
}

TEST(ex02, ft_strcpy)
{
    std::string str;
    char* ptr = const_cast<char*>(str.c_str());
    //ft_strcpy((char*)str.c_str(), *g_argv);
    ft_strcpy(ptr, *g_argv);
    ASSERT_STREQ(str.c_str(), *g_argv);
}

int main(int argc, char **argv)
{
    g_argc = argc;
    g_argv = argv;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
