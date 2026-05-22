# 42 Exam 02 - Complete Solutions Guide

## Comprehensive Analysis & Optimization of 55 42-School Exam Exercises

This project contains **elegant, compact solutions** to all 42 exam exercises with strict pointer-only constraints mimicking the actual Moulinette environment.

---

## 📋 Constraints & Philosophies

### **Strict Moulinette-Like Rules**
- ✅ **Pointers Only**: No array indexing `arr[i]` – use pointer arithmetic `*(ptr + i)` or `*ptr++`
- ✅ **Iterative Only**: While loops only – no recursion
- ✅ **No Ternary Operators**: No `condition ? true_val : false_val` – use `if/else`
- ✅ **No Recursion**: All algorithms must be tail-call optimizable to while loops
- ✅ **Efficient**: O(1) and O(N) preferred over O(N²) when possible

---

## 📊 Exercise Breakdown by Category

### **Category 1: Math Problems & Number Theory (6 exercises)**

| Exercise | Algorithm | Dirty Hack | Theory Link |
|----------|-----------|-----------|-------------|
| `is_power_of_2` | Bitwise AND | `(n & (n-1)) == 0` O(1) | [Binary Representation](https://en.wikipedia.org/wiki/Power_of_two#Fast_algorithm_to_check_if_a_number_is_power_of_2) |
| `fprime` | Trial Division | No need to check if `i` is prime | [Prime Factorization](https://en.wikipedia.org/wiki/Trial_division) |
| `pgcd` | Euclidean Algorithm | Use modulo for speed | [GCD Algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm) |
| `lcm` | Formula-based | `LCM = (a*b)/GCD(a,b)` divide first to avoid overflow | [LCM](https://en.wikipedia.org/wiki/Least_common_multiple) |
| `add_prime_sum` | Sieve + Summation | Skip multiples of found primes | [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) |
| `fizzbuzz` | Modulo Check | Use `if/else` instead of ternary | [Modulo Arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic) |

**Key Insights**:
- `is_power_of_2`: A power of 2 has exactly ONE bit set. `(n-1)` flips all bits after that one bit, so `(n & (n-1)) = 0`.
- `fprime`: Continuously dividing by a number automatically eliminates composite factors.
- `pgcd`/`lcm`: Euclidean Algorithm runs in O(log(min(a,b))) – much faster than naive approaches.

**References**:
- [Prime Number Algorithms](https://en.wikipedia.org/wiki/Primality_test)
- [Bitwise Operations](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

---

### **Category 2: Command Line Parsing (4 exercises)**

| Exercise | Task | Depends On | Note |
|----------|------|-----------|------|
| `do_op` | Arithmetic with operator | `atoi` | Character dispatch for `+`, `-`, `*`, `/`, `%` |
| `paramsum` | Count arguments | None | Simple `argc - 1` or iterate argv |
| `print_hex` | Dec to Hex conversion | `atoi` | Recursive digit extraction (OK - minimal) |
| `tab_mult` | Multiplication table | `atoi` | Format output 1-9 times |

**Key Techniques**:
```c
// Operator dispatch pattern
if (*op == '+')
    result = a + b;
else if (*op == '-')
    result = a - b;
// etc.
```

**References**:
- [Base Conversion](https://en.wikipedia.org/wiki/Radix)
- [Command Line Arguments](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)

---

### **Category 3: ATOI - String to Integer (2 exercises)**

| Exercise | Task | Variations | Edge Cases |
|----------|------|-----------|-----------|
| `ft_atoi` | String → Int (base 10) | Handle signs, whitespace | `INT_MIN`, `INT_MAX`, overflow |
| `ft_atoi_base` | String → Int (any base ≤16) | Hex, Oct, Bin support | Invalid base, non-digit chars |

**Algorithm**:
```c
result = result * base + digit_value;
```

**Whitespace Handling**:
```c
// Skip leading whitespace (space, tab, newline, carriage return, form feed, vertical tab)
while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
    str++;
```

**References**:
- [ATOI Implementation](https://man7.org/linux/man-pages/man3/atoi.3.html)
- [ASCII Table](http://www.asciitable.com/)

---

### **Category 4: ITOA - Integer to String (1 exercise)**

| Exercise | Challenge | Hack |
|----------|-----------|------|
| `ft_itoa` | Int → String (base 10) | **INT_MIN overflow** – cast to `long` first! |

**The INT_MIN Problem**:
```c
int n = INT_MIN;  // -2147483648
n = -n;           // OVERFLOW! Can't negate in signed int
```

**Solution**:
```c
long n = (long)nbr;  // Safe in 64-bit long
if (n < 0) {
    is_negative = 1;
    n = -n;
}
```

**Building the String** (reverse order):
```c
while (len > 0) {
    result[--len] = '0' + (n % 10);
    n /= 10;
}
```

**References**:
- [Integer Overflow](https://en.wikipedia.org/wiki/Integer_overflow)
- [Two's Complement](https://en.wikipedia.org/wiki/Two%27s_complement)

---

### **Category 5: Bit Operations (3 exercises)**

| Exercise | Task | Hack | Reference |
|----------|------|------|-----------|
| `swap_bits` | Swap upper/lower nibbles | **ONE LINE**: `((b>>4)\|(b<<4))` | [Bit Manipulation](https://www.geeksforgeeks.org/bit-manipulation-in-c/) |
| `reverse_bits` | Mirror all bits | Shift + build new byte | [Bit Reversal](https://en.wikipedia.org/wiki/Bit-reversal_permutation) |
| `print_bits` | Byte → binary string | No ternary: `'0' + ((b>>i)&1)` | [Binary Representation](https://en.wikipedia.org/wiki/Binary_number) |

**Swap Bits Explained**:
```
Input:  0x45 = 0100 | 0101
         (4)   (5)
           ↓   ↓
Output: 0x54 = 0101 | 0100
           (5)   (4)
Formula: (b >> 4) | (b << 4)
```

**Reverse Bits Explained**:
```
Loop 8 times:
- Extract LSB: b & 1
- Shift result left: result <<= 1
- OR the extracted bit: result |= extracted_bit
- Shift input right: b >>= 1
```

**References**:
- [Bitwise Operators Guide](https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm)
- [Bit Manipulation Tricks](https://en.wikipedia.org/wiki/Bit_manipulation)

---

### **Category 6: String Manipulation (35 exercises!)**

**Subcategories**:

#### A. Basic String Operations (8)
| Exercise | Function | Pointer Trick |
|----------|----------|--------------|
| `ft_strlen` | Count chars | `end - start` |
| `ft_strcpy` | Copy string | `*dst++ = *src++; *dst = '\0'` |
| `ft_strrev` | Reverse in-place | Two-pointer swap: `start++; end--` |
| `ft_strcmp` | Compare | `*s1 - *s2` at first difference |
| `ft_strdup` | Malloc + copy | Loop copy with `malloc` |
| `ft_putstr` | Output | `while(*s) write(1, s++, 1)` |
| `ft_strcspn` | Prefix span | Find first reject char |
| `ft_swap` | Swap integers | `tmp = *a; *a = *b; *b = tmp` |

#### B. Case Manipulation (7)
| Exercise | Task | Hack |
|----------|------|------|
| `rot_13` | Caesar +13 | Check ranges: `a-m` add 13, `n-z` sub 13 |
| `rotone` | Caesar +1 | Handle wrap: `z→a`, `Z→A` |
| `ulstr` | Toggle case | XOR with 32: `ch ^= 32` (only for alpha!) |
| `alpha_mirror` | Mirror alphabet | Formula: `'a'+'z'-ch` |
| `str_capitalizer` | Capitalize words | Track word start (after space/tab) |
| `rstr_capitalizer` | Last char caps | Scan forward, cap last letter only |
| `repeat_alpha` | Repeat by position | `count = ch - 'a' + 1` (or uppercase) |

#### C. Word Processing (4)
| Exercise | Task | Pattern |
|----------|------|---------|
| `first_word` | Extract first | Skip spaces, print until space |
| `last_word` | Extract last | Walk to end, backtrack to space |
| `rev_wstr` | Reverse words | Malloc + copy words in reverse |
| `rostring` | Rotate left | Extract first word, move to end |

#### D. Format & Spacing (4)
| Exercise | Task | Pattern |
|----------|------|---------|
| `epur_str` | 1 space | Skip leading spaces, then 1 between words |
| `expand_str` | 3 spaces | Same, but output 3 spaces |
| `camel_to_snake` | Case convert | Inject `_` before capitals, lowercase all |
| `snake_to_camel` | Case convert | Skip `_`, capitalize next letter |

#### E. Search & Matching (4)
| Exercise | Task | Algorithm |
|----------|------|-----------|
| `hidenp` | Hidden substring | Iterate s1 through s2, keep in order |
| `wdmatch` | Word match | Can we build s1 from s2 in order? |
| `inter` | Intersection | Chars in both, in s1 order, no dupes |
| `union` | Union | Chars in either, in appearance order, no dupes |

#### F. Allocation-Based (8)
| Exercise | Task | Algorithm |
|----------|------|-----------|
| `ft_split` | Split by whitespace | Count words, malloc array, fill |
| `ft_range` | Allocate range | Malloc, fill `start` to `end` |
| `ft_rrange` | Reverse range | Same, but `end` to `start` |
| `sort_int_tab` | Sort array | Bubble sort in-place |
| `max` | Find max | Walk array, track maximum |
| `rev_print` | Print reversed | Walk to end, print backwards |
| `search_and_replace` | Replace char | Scan and swap character |
| `flood_fill` | 2D fill | BFS/DFS from point, no recursion |

**String Hack Compilation**:
```c
// Fastest case toggle (ONLY for [a-zA-Z])
if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    ch ^= 32;

// Mirror alphabet without ternary
if (ch >= 'a' && ch <= 'z')
    ch = 'a' + 'z' - ch;
else if (ch >= 'A' && ch <= 'Z')
    ch = 'A' + 'Z' - ch;

// Pointer iteration + print
while (*s)
    write(1, s++, 1);
```

**References**:
- [String Manipulation in C](https://www.geeksforgeeks.org/string-manipulation-in-c/)
- [ASCII & Character Encoding](http://www.asciitable.com/)
- [Pointer Arithmetic](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)

---

### **Category 7: Linked Lists (4 exercises)**

| Exercise | Task | Key Technique |
|----------|------|----------------|
| `ft_list_size` | Count nodes | `count++; ptr = ptr->next` |
| `ft_list_foreach` | Apply function | `(*f)(ptr->data); ptr = ptr->next` |
| `ft_list_remove_if` | Remove by predicate | **Double pointer** trick: `**begin_list` |
| `sort_list` | Sort by comparator | Bubble sort, swap `.data` fields |

**Double Pointer Trick** (most important for remove_if):
```c
void remove_if(t_list **head, void *ref, int (*cmp)()) {
    while (*head) {
        if ((*cmp)((*head)->data, ref) == 0) {
            t_list *tmp = *head;
            *head = (*head)->next;
            free(tmp);
            // Don't increment *head - check it again
        } else {
            head = &((*head)->next);
        }
    }
}
```

**Why Double Pointer**?
- Allows modifying the pointer itself (`*head = ...`)
- Can remove the head node without extra tracking
- Elegant one-pass deletion

**References**:
- [Linked Lists in C](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
- [Double Pointers](https://www.geeksforgeeks.org/double-pointer-pointer-to-pointer-in-c/)
- [List Algorithms](https://en.wikipedia.org/wiki/Linked_list)

---

## 🧪 Comprehensive Testing

All 55 exercises are tested in `test/comprehensive_tests.cpp` using **Google Test Framework**.

### **Test Coverage**:
- ✅ Basic functionality
- ✅ Edge cases (empty, single element, NULL)
- ✅ Overflow/underflow (INT_MIN, INT_MAX)
- ✅ Boundary conditions
- ✅ String edge cases (empty strings, special chars)
- ✅ Linked list integrity

### **Running Tests**:
```bash
cd /home/alalimov/Test/42-exam-02/build
cmake ..
make
./runExamTests
```

### **Test Organization**:
- `MathFunctionsTest`: All 6 math exercises
- `AtoiFunctionsTest`: Both atoi variants
- `ItoaFunctionsTest`: Integer to string
- `BitFunctionsTest`: All 3 bit ops
- `StringFunctionsTest`: Core string funcs
- `LinkedListTest`: All 4 list operations
- `EdgeCasesTest`: Boundary conditions

---

## 📚 Useful Algorithm References

### **Number Theory**
- [Prime Numbers](https://en.wikipedia.org/wiki/Prime_number)
- [GCD & LCM](https://en.wikipedia.org/wiki/Greatest_common_divisor)
- [Euclidean Algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm)

### **Bit Manipulation**
- [Bitwise Operators](https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm)
- [Bit Tricks](https://github.com/jorenham/bit-manipulation-tricks)
- [Binary Representation](https://en.wikipedia.org/wiki/Binary_number)

### **String Algorithms**
- [KMP Search](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)
- [String Manipulation](https://www.geeksforgeeks.org/string-manipulation-in-c/)
- [Substring Search](https://en.wikipedia.org/wiki/String_searching_algorithm)

### **Data Structures**
- [Linked Lists](https://en.wikipedia.org/wiki/Linked_list)
- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Array Operations](https://www.geeksforgeeks.org/array-data-structure/)

### **C Pointers & Memory**
- [Pointers in C](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)
- [Dynamic Memory Allocation](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-realloc-and-free/)
- [Pointer Arithmetic](https://www.geeksforgeeks.org/pointer-arithmetic-in-c/)

---

## 🎯 Dirty Hacks Summary

### **Best O(1) Hacks**
1. `is_power_of_2`: `(n & (n-1)) == 0`
2. `swap_bits`: `((b >> 4) | (b << 4))`
3. `ulstr` case toggle: `ch ^= 32`

### **Clever Formula Hacks**
4. `alpha_mirror`: `'a' + 'z' - ch`
5. `lcm`: `(a / gcd(a,b)) * b` (divide first!)
6. `print_hex`: Build digit string using `n % 16` and `n /= 16`

### **Smart Loop Patterns**
7. `ft_strlen`: `return end - start`
8. `ft_list_remove_if`: Double pointer `**head` allows removing head
9. `ft_strrev`: Two-pointer swap from ends

### **Gotchas to Avoid**
⚠️ **INT_MIN in ft_itoa**: Use `long` cast
⚠️ **String literals in rot_13**: Only works on writable buffers
⚠️ **Division by zero**: Check denominator in `do_op`
⚠️ **NULL pointers**: Always check before dereferencing

---

## 📁 Project Structure

```
.
├── exam/                          # 55 original solutions
│   ├── is_power_of_2.c
│   ├── fprime.c
│   ├── ft_atoi.c
│   └── ... (52 more)
├── subjects/                      # Original exercise descriptions
│   ├── is_power_of_2/sub.txt
│   ├── fprime/sub.txt
│   └── ... (53 more)
├── test/
│   └── comprehensive_tests.cpp    # Google Test suite (200+ tests)
├── build/                         # CMake build directory
│   └── runExamTests               # Compiled test executable
├── OPTIMIZATION_GUIDE.md          # Detailed hack documentation
├── README.md                      # This file
└── 42_exam_map.drawio             # Visual dependency graph (55 exercises)
```

---

## 🔧 Compilation & Testing

### **Setup**:
```bash
cd /home/alalimov/Test/42-exam-02
mkdir -p build
cd build
cmake ..
make
```

### **Run All Tests**:
```bash
./runExamTests
```

### **Run Specific Test Suite**:
```bash
./runExamTests --gtest_filter=MathFunctionsTest.*
./runExamTests --gtest_filter=StringFunctionsTest.*
```

### **List All Tests**:
```bash
./runExamTests --gtest_list_tests
```

---

## ✨ Key Takeaways

1. **Pointer Arithmetic > Array Indexing**: More elegant, matches 42 style
2. **Bitwise Operations**: Always faster than branching
3. **Precompute When Possible**: GCD calculation before LCM
4. **Pattern Reuse**: Many string exercises use similar "skip whitespace" patterns
5. **Edge Cases Matter**: INT_MIN/MAX, empty strings, NULL pointers break careless code
6. **Avoid Recursion**: Use while loops, even if less elegant
7. **Function Pointers**: Enable generic algorithms (sort_list, ft_list_foreach)

---

## 📖 Citation & References

This guide implements algorithms based on:
- CLRS: *Introduction to Algorithms* (Cormen, Leiserson, Rivest, Stein)
- K&R: *The C Programming Language* (Kernighan & Ritchie)
- Wikipedia: Various algorithm entries
- GeeksforGeeks: C programming tutorials
- Man pages: POSIX standard library documentation

---

## 📝 Notes for 42 Students

- Moulinette will test **edge cases heavily**
- **Norminette compliance**: Clean code, proper function signatures
- **No global variables** (generally avoided in 42)
- **Memory leaks**: Free all malloc'd memory
- **Forbidden functions**: Don't use functions outside the allowed set

---

**Last Updated**: May 22, 2026  
**Status**: Complete with all 55 exercises analyzed, optimized, and tested  
**Test Coverage**: 200+ test cases across 7 categories
