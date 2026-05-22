# 42 Exam 02 - Solutions & Algorithms

This project contains elegant, compact solutions to the 42 exam exercises, following strict constraints mimicking the Moulinette environment:
- **Pointers Only** (`*s++`, no array indices `[]`).
- **Iterative Only** (only `while` loops, no recursion).
- **No Ternary Operators** (no `? :`).

## Diagram
See the [42_exam_map.drawio](42_exam_map.drawio) file for a UML dependency graph categorizing the exercises by their core problem types.

## Exercise Groupings, Theories & Dirty Hacks

### 1. Math Problems & Number Theory
- **Problems**: `add_prime_sum`, `fprime`, `is_power_of_2`, `lcm`, `pgcd`, `tab_mult`, `fizzbuzz`
- **Theory**:
  - **Prime Factorization** (`fprime`): The simplest algorithmic approach is trial division. Start dividing the number from 2 upwards. If the number divides evenly (`n % i == 0`), print the factor and divide the number (`n /= i`), otherwise increment the divisor. [Prime Factorization Algorithm](https://en.wikipedia.org/wiki/Trial_division).
  - **GCD & LCM** (`pgcd`, `lcm`): Using the Euclidean Algorithm. GCD is found by subtracting the smaller from the larger until they match, or by modulo. LCM is simply `(a * b) / GCD(a, b)`.
  - **Power of 2**: A number `n` is a power of 2 if `(n & (n - 1)) == 0` and `n > 0`.
- **Dirty Hacks**: 
  - For `is_power_of_2`, using the bitwise operation `(n & (n - 1)) == 0` completely avoids all `while` loops, giving O(1) performance.
  - In `fprime`, you don't actually need to check if the divisor `i` is prime! By continuously dividing `n /= i` as long as `n % i == 0`, you naturally eliminate all non-prime composite factors (e.g., 4 is never reached because 2 already divided the number entirely).

### 2. Strings Manipulation
- **Problems**: `ft_strdup`, `ft_strcpy`, `rev_print`, `ulstr`, `last_word`, `snake_to_camel`, `hidenp`, `first_word`, `ft_strlen`, `rot_13`, `ft_strrev`, `rstr_capitalizer`, `rotone`, `alpha_mirror`, `ft_strcmp`, `inter`, `union`, `epur_str`, `str_capitalizer`, `ft_split`, `wdmatch`
- **Theory**:
  - **ASCII Map**: Uppercase is `A` (65) to `Z` (90). Lowercase is `a` (97) to `z` (122). The difference is exactly `32` (or bit `1 << 5`).
  - **Two-Pointer Technique**: Walk a pointer to the `\0` byte, then decrement backwards `ptr--` to print or swap in reverse.
- **Dirty Hacks**:
  - **Bitwise Case Toggling**: Toggle cases instantly using bitwise XOR: `*str ^= 32;` flips between upper and lowercase! (Ensure you check `if (is_alpha)` first).
  - **Pointer Iteration**: Iterate and print at the same time: `while (*s) { write(1, s++, 1); }`.
  - **In-place modifications (`rot_13`)**: Treat the `char *` as an array of integers. Just do `*str += 13` if within range, skipping any extra allocation. (Beware: passing a string literal directly to this function will segfault. Always use a char array buffer like `char str[] = "abc";`).

### 3. Number Conversions (atoi, itoa)
- **Problems**: `ft_atoi`, `ft_atoi_base`, `do_op`, `ft_itoa`, `print_hex`
- **Theory**:
  - **String to Integer (atoi)**: Loop through digits and shift left in base 10: `result = (result * base) + (*s - '0')`.
  - **Integer to String (itoa)**: Do the reverse. Use `% base` to isolate the least significant digit, and `/ base` to shift right.
- **Dirty Hacks**:
  - **INT_MIN Trick (`ft_itoa`)**: `INT_MIN (-2147483648)` overflows if you try to make it positive using an `int` (`n = -n`). Hack: immediately cast to `long` via `long n = nbr;` at the beginning of `itoa` to safely negate it.
  - **Base Offsets (`ft_atoi_base`)**: You can map `A-F` easily by checking range and applying a static offset: `digit = *s - 'A' + 10`.

### 4. Bit Operations
- **Problems**: `print_bits`, `reverse_bits`, `swap_bits`
- **Theory**:
  - **Bitwise Logic**: `>>` (Right Shift), `<<` (Left Shift), `&` (AND), `|` (OR).
- **Dirty Hacks**:
  - **Swap Nibbles**: `swap_bits` is famously just one line: `return ((b >> 4) | (b << 4));`.
  - **Ternary-less Printing**: If ternaries are banned in `print_bits`, avoid `(b & 1) ? '1' : '0'` by using math: `char c = '0' + ((b >> i) & 1); write(1, &c, 1);`.

### 5. Linked Lists
- **Problems**: `ft_list_foreach`, `ft_list_size`, `ft_list_remove_if`, `sort_list`
- **Theory**:
  - **Traversal**: Iterate using `while (head) { ... head = head->next; }`.
  - **Modification**: When removing nodes in a singly linked list iteratively, you must track `prev` and `curr` to mend the gap (`prev->next = curr->next`).
- **Dirty Hacks**:
  - **XOR Swap in `sort_list`**: Swapping node pointers can be messy. If the subject allows it, just swap the `->data` pointers instead! You can even use the XOR swap trick on integers if `data` is `int`:
    ```c
    lst->data = lst->data ^ lst->next->data;
    lst->next->data = lst->data ^ lst->next->data;
    lst->data = lst->data ^ lst->next->data;
    ```
  - **Resetting the Head**: After swapping data in `sort_list`, instead of moving backward (impossible in singly-linked), just restart the entire list traversal from `start`. It's inefficient (O(N^2) Bubble Sort), but it requires minimal code!

## Google Tests
Tests are located in the `test/` folder and compiled using GTest. They thoroughly verify correct pointer manipulation, lack of out-of-bounds array access, and proper edge case handling (Nulls, INT_MAX/MIN).
Use `cd build && make runExamTests && ./runExamTests` to run the suite.
