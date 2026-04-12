#include <gtest/gtest.h>
#include <array>
#include <algorithm>
#include <cstdlib>
#include "exam.h"

TEST(ex02, ft_split)
{
    char arr[] = "Hello World together";
    std::array<std::string, 3> checker = {"Hello", "World", "together"};
    std::array<std::string, 3>::iterator itr;
    char** str = ft_split(arr);
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
    char* str = (char*)"Hello world\n";
    ft_putstr(str);
}

TEST(ex02, ft_rev_print)
{
    char* str = (char*)"Hello world";
    ft_rev_print(str);
}

TEST(ex02, ft_ulstr)
{
    char str[] = "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification.";
    char result_str[] = "l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.";
    ft_ulstr(str);
    ASSERT_EQ(strcmp(str, result_str), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
