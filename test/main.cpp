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
    char* str = (char*)"remmargorP dlroW olleH";
    ft_rev_print(str);
}

TEST(ex02, ft_ulstr)
{
    ft_ulstr(*g_argv);
}

TEST(ex02, ft_rot_13)
{
    ft_rot_13(*g_argv);
}

int main(int argc, char **argv)
{
    g_argc = argc;
    g_argv = argv;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
