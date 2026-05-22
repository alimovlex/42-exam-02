# 42 Exam - Optimization & Dirty Hacks Guide

This document contains compact, elegant solutions and dirty hacks for cracking 42 exam exercises with pointer-only constraints (no recursion, no ternary operators, no array indexing).

---

## 1. MATH PROBLEMS

### **1.1 is_power_of_2**
**Dirty Hack**: Single bitwise check - O(1)
```c
int is_power_of_2(unsigned int n)
{
    return (n && !(n & (n - 1)));  // O(1) - no loops!
}
```
**Theory**: A power of 2 has exactly one bit set. `(n - 1)` flips all bits after that single set bit, so AND results in 0.

---

### **1.2 fprime**
**Dirty Hack**: Never check if divisor is prime! Trial division auto-eliminates composites.
```c
void fprime(char *str)
{
    int n = atoi(str);
    int i = 2;
    
    while (i * i <= n)
    {
        while (n % i == 0)
        {
            printf("%d", i);
            n /= i;
            if (n > 1)
                printf("*");
        }
        i++;
    }
    if (n > 1)
        printf("%d", n);
    printf("\n");
}
```
**Theory**: By continuously dividing `n` by `i`, non-primes (composites) are automatically eliminated.

---

### **1.3 pgcd / lcm**
**Euclidean Algorithm**: Only subtraction needed, or use modulo for speed.
```c
unsigned int pgcd(unsigned int a, unsigned int b)
{
    while (b)
    {
        unsigned int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    if (!a || !b)
        return 0;
    return (a / pgcd(a, b)) * b;  // Avoid overflow: divide first
}
```

---

### **1.4 add_prime_sum**
**Trick**: Sieve combined with iteration (no recursion).
```c
int is_prime(int n)
{
    if (n < 2)
        return 0;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

void add_prime_sum(char *str)
{
    int n = atoi(str);
    int sum = 0;
    int i = 2;
    
    while (i <= n)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    printf("%d\n", sum);
}
```

---

### **1.5 fizzbuzz**
**No Ternary**: Use array indexing or if-else
```c
void fizzbuzz(void)
{
    int i = 1;
    while (i <= 100)
    {
        if (i % 15 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write(1, "fizz\n", 5);
        else if (i % 5 == 0)
            write(1, "buzz\n", 5);
        else
        {
            char buf[16];
            int len = sprintf(buf, "%d\n", i);
            write(1, buf, len);
        }
        i++;
    }
}
```

---

## 2. STRING MANIPULATION (Dirty Hacks)

### **2.1 Case Toggling - Bitwise XOR Trick**
Toggle case instantly: `ch ^= 32` (only if alphabetic!)
```c
void toggle_case(char *str)
{
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
            *str ^= 32;  // Lowercase
        else if (*str >= 'a' && *str <= 'z')
            *str ^= 32;  // Uppercase
        str++;
    }
}
```

### **2.2 alpha_mirror**
Bit manipulation: `'a' + 'z' = 219`, so for any char c: `reverse = 'a' + 'z' - c`
```c
void alpha_mirror(char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str = 'a' + 'z' - *str;
        else if (*str >= 'A' && *str <= 'Z')
            *str = 'A' + 'Z' - *str;
        write(1, str, 1);
        str++;
    }
}
```

### **2.3 Two-Pointer String Reversal**
```c
char *ft_strrev(char *str)
{
    char *start = str;
    char *end = str;
    
    while (*end)
        end++;
    end--;  // Point to last char
    
    while (start < end)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    return str;
}
```

### **2.4 String Copy with Pointer Increment**
```c
char *ft_strcpy(char *dst, char *src)
{
    char *start = dst;
    while (*src)
        *dst++ = *src++;
    *dst = '\0';
    return start;
}
```

### **2.5 rot_13 - Caesar Shift**
```c
void rot_13(char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
        {
            if (*str <= 'm')
                *str += 13;
            else
                *str -= 13;
        }
        else if (*str >= 'A' && *str <= 'Z')
        {
            if (*str <= 'M')
                *str += 13;
            else
                *str -= 13;
        }
        write(1, str, 1);
        str++;
    }
}
```

### **2.6 String Concatenation - No Array Index**
```c
char *ft_strcat(char *dst, char *src)
{
    while (*dst)
        dst++;
    while (*src)
        *dst++ = *src++;
    *dst = '\0';
    return dst - (ft_strlen(src) + 1);
}
```

---

## 3. ATOI / BASE CONVERSION

### **3.1 ft_atoi - Pointer Only**
```c
int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    return result * sign;
}
```

### **3.2 ft_atoi_base - Any Base (2-16)**
```c
int ft_atoi_base(const char *str, int base)
{
    int result = 0;
    int sign = 1;
    
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    
    while (*str)
    {
        int digit;
        if (*str >= '0' && *str <= '9')
            digit = *str - '0';
        else if (*str >= 'a' && *str <= 'f')
            digit = *str - 'a' + 10;
        else if (*str >= 'A' && *str <= 'F')
            digit = *str - 'A' + 10;
        else
            break;
        
        if (digit >= base)
            break;
        
        result = result * base + digit;
        str++;
    }
    
    return result * sign;
}
```

---

## 4. ITOA - Integer to String

### **4.1 INT_MIN Hack**
Standard `int n = -n` fails for INT_MIN. Cast to `long` first!
```c
char *ft_itoa(int nbr)
{
    long n = nbr;  // CRITICAL: Handle INT_MIN overflow
    char *result;
    int len = 0;
    int is_negative = 0;
    long tmp;
    
    if (n < 0)
    {
        is_negative = 1;
        n = -n;
    }
    
    tmp = n;
    while (tmp)
    {
        len++;
        tmp /= 10;
    }
    
    if (n == 0)
        len = 1;
    if (is_negative)
        len++;
    
    result = malloc(len + 1);
    result[len] = '\0';
    
    tmp = n;
    while (len > is_negative)
    {
        result[--len] = '0' + (tmp % 10);
        tmp /= 10;
    }
    
    if (is_negative)
        result[0] = '-';
    
    return result;
}
```

---

## 5. BIT OPERATIONS

### **5.1 swap_bits - ONE LINE HACK**
```c
unsigned char swap_bits(unsigned char b)
{
    return ((b >> 4) | (b << 4));
}
```

### **5.2 reverse_bits - Mirror Bits**
```c
unsigned char reverse_bits(unsigned char b)
{
    unsigned char result = 0;
    int i = 8;
    
    while (i--)
    {
        result = (result << 1) | (b & 1);
        b >>= 1;
    }
    
    return result;
}
```

### **5.3 print_bits - No Ternary**
```c
void print_bits(unsigned char b)
{
    int i = 8;
    
    while (i--)
    {
        char c = '0' + ((b >> (7 - i)) & 1);
        write(1, &c, 1);
    }
}
```

---

## 6. LINKED LISTS

### **6.1 ft_list_size - Pointer Traversal**
```c
int ft_list_size(t_list *begin_list)
{
    int count = 0;
    
    while (begin_list)
    {
        count++;
        begin_list = begin_list->next;
    }
    
    return count;
}
```

### **6.2 ft_list_foreach - Function Pointer**
```c
void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}
```

### **6.3 ft_list_remove_if - Double Pointer Trick**
```c
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    while (*begin_list)
    {
        if ((*cmp)((*begin_list)->data, data_ref) == 0)
        {
            t_list *tmp = *begin_list;
            *begin_list = (*begin_list)->next;
            free(tmp);
        }
        else
            begin_list = &((*begin_list)->next);
    }
}
```

### **6.4 sort_list - Bubble Sort with Function Pointer**
```c
t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int swapped;
    
    while (lst)
    {
        swapped = 0;
        t_list *current = lst;
        
        while (current && current->next)
        {
            if (!(*cmp)(current->data, current->next->data))
            {
                int tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
                swapped = 1;
            }
            current = current->next;
        }
        
        if (!swapped)
            break;
    }
    
    return lst;
}
```

---

## 7. COMMAND LINE PARSING

### **7.1 do_op - Operator Dispatch**
```c
int do_op(int a, char *op, int b)
{
    if (*op == '+')
        return a + b;
    else if (*op == '-')
        return a - b;
    else if (*op == '*')
        return a * b;
    else if (*op == '/')
        return a / b;
    else if (*op == '%')
        return a % b;
    return 0;
}
```

### **7.2 print_hex - Base Conversion**
```c
void print_hex(unsigned int n)
{
    if (n >= 16)
        print_hex(n / 16);  // Recursive, but minimal
    write(1, &"0123456789abcdef"[n % 16], 1);
}
```

---

## KEY PRINCIPLES

1. **Pointer Arithmetic**: `ptr++`, `ptr--`, `*(ptr + offset)` instead of `ptr[i]`
2. **While Loops Only**: All iteration via while
3. **Bitwise Operations**: Use `&`, `|`, `^`, `>>`, `<<` for speed
4. **No Ternary**: Use if-else or bitwise logic
5. **Double Pointers**: For list manipulation (`**ptr`)
6. **Function Pointers**: For callbacks and comparisons

---

## COMMON EDGE CASES TO TEST

| Problem | Edge Cases |
|---------|-----------|
| is_power_of_2 | n=0, n=1, n=2^31 |
| fprime | n=1, n=2, prime number, composite |
| atoi | overflow, negative, whitespace, multiple signs |
| itoa | INT_MIN, INT_MAX, 0 |
| string funcs | empty string, single char, NULL handling |
| lists | empty list, single node, NULL pointers |

