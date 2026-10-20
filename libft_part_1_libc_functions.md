# Libft Part 1: Libc Functions — Edge Cases & Defense Questions

---

## 1. Character Classification (`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`)

### High-Critical Defense Questions
1. **Integer Representation & EOF Handling:**
   - Why do character classification functions take an `int` parameter rather than a `char`?
   - What happens when `EOF` (`-1`) is passed as an argument to `ft_isalpha` or `ft_isascii`?
2. **Signed vs. Unsigned Extension:**
   - On architectures where `char` is signed (defaulting to `-128` to `127`), what happens if you pass a negative extended ASCII character like `(char)0x80` (`-128`) without casting it to `unsigned char` first?
3. **Strict Return Value Compliance:**
   - The Libft subject explicitly mandates returning `1` for match and `0` for non-match. Standard `libc` functions return *any non-zero value* for true. Does your implementation strictly return `1` or arbitrary non-zero values?

### Extreme & Edge Case Test Scenarios
* **Negative Values & Extended ASCII:**
  - Pass `c = -1`, `c = -128`, `c = 255`, `c = 128`. Verify no undefined behavior occurs.
* **Boundary Checks:**
  - `ft_isalpha`: Test `c = 'A' - 1` (`@`), `'Z' + 1` (`[`), `'a' - 1` (`` ` ``), `'z' + 1` (`{`).
  - `ft_isdigit`: Test `c = '0' - 1` (`/`), `'9' + 1` (`:`).
  - `ft_isascii`: Test `c = 0` (NUL), `c = 127` (DEL), `c = 128`, `c = -1`.
  - `ft_isprint`: Test `c = 31` (US control char), `c = 32` (Space - printable), `c = 126` (`~` - printable), `c = 127` (DEL - non-printable).

---

## 2. String Length (`ft_strlen`)

### High-Critical Defense Questions
1. **NULL Pointer Behavior:**
   - What occurs if `ft_strlen(NULL)` is called? Is handling NULL expected by standard libc specifications, or is it undefined behavior?
2. **Termination & Huge Buffers:**
   - How does `ft_strlen` handle non-null-terminated memory regions? Why can this lead to Segmentation Faults or reading out of bounds?

### Extreme & Edge Case Test Scenarios
* **Empty String:** Pass `""` (should return `0`).
* **Single Character:** Pass `"a"` (should return `1`).
* **Embedded NUL Byte:** Pass `"Hello\0World"` (should return `5`).
* **Large String:** Pass a dynamically allocated string of size 1,000,000 filled with `'A'` followed by `\0`.

---

## 3. Memory Manipulation (`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`)

### High-Critical Defense Questions
1. **Unsigned Char Casting:**
   - Why must memory operations cast `void *` pointers to `unsigned char *` instead of `char *` or `int *` when performing byte-by-byte copies or comparisons?
2. **Overlapping Memory Boundaries:**
   - What is the difference between `memcpy` and `memmove`? Explain how `memcpy` causes undefined behavior when source and destination overlap, and demonstrate how your `memmove` prevents byte corruption.
3. **Zero-Byte Operations (`n = 0`):**
   - If `n = 0` and `src` or `dst` is `NULL`, should your function crash? What does standard `memcpy(NULL, NULL, 0)` return vs `memcpy(NULL, ptr, 10)`?
4. **`memcmp` Sign Difference:**
   - How does `ft_memcmp` calculate the return value when two bytes differ? Why must the byte comparison be treated as `unsigned char` during subtraction?

### Extreme & Edge Case Test Scenarios
* **Overlapping Memory (`ft_memmove` vs `ft_memcpy`):**
  - **Case A (Dst > Src):** `char str[] = "123456789"; ft_memmove(str + 2, str, 5);` (Result should be `"121234589"`).
  - **Case B (Src > Dst):** `char str[] = "123456789"; ft_memmove(str, str + 2, 5);` (Result should be `"345678789"`).
* **Null Byte Searching (`ft_memchr`):**
  - Search for `\0` within a block of size `n` where `\0` is located midway.
  - Search for byte `0xFF` in a buffer containing binary data.
* **Negative Comparison (`ft_memcmp`):**
  - Compare `\xFE` and `\x01`. If signed `char` is used, `\xFE` becomes `-2`, making `-2 - 1 < 0` (incorrect). With `unsigned char`, `254 - 1 > 0` (correct positive difference).

---

## 4. String Character Search (`ft_strchr`, `ft_strrchr`)

### High-Critical Defense Questions
1. **Searching for NUL Terminator (`\0`):**
   - What should `ft_strchr("hello", '\0')` return? Does it return `NULL` or a pointer to the terminating null byte?
2. **Type Casting of Search Character:**
   - Why does `strchr` accept an `int c` parameter, and how do you handle cases where `c` exceeds `255` (e.g., `c = 1024`)?

### Extreme & Edge Case Test Scenarios
* **Searching for `\0`:**
  - `ft_strchr("abc", '\0')` should return `str + 3`.
  - `ft_strrchr("abc", '\0')` should return `str + 3`.
* **Multiple Occurrences:**
  - `ft_strrchr("hello world", 'o')` must return the pointer to the *second* 'o'.
* **Character Not Present:**
  - `ft_strchr("42 Network", 'z')` must return `NULL`.
* **Empty String Search:**
  - `ft_strchr("", 'a')` -> `NULL`; `ft_strchr("", '\0')` -> pointer to `""`.

---

## 5. String Comparison & Search (`ft_strncmp`, `ft_strnstr`)

### High-Critical Defense Questions
1. **`unsigned char` Casting in Comparison:**
   - Why must `ft_strncmp` compare characters as `unsigned char` rather than `signed char`? Give an explicit ASCII example where signed character subtraction gives the wrong sign.
2. **`ft_strnstr` Parameter Limits:**
   - If `little` is an empty string `""`, what does `ft_strnstr` return?
   - If `len` is smaller than `strlen(little)`, what should `ft_strnstr` return if `little` occurs after `len` bytes?

### Extreme & Edge Case Test Scenarios
* **`ft_strncmp`:**
  - Compare `"test\200"` and `"test\0"`. The result must be strictly positive.
  - Compare `"abc"` and `"abcdef"` with `n = 3` (should return `0`).
  - Compare with `n = 0` (must return `0` regardless of inputs).
* **`ft_strnstr`:**
  - `haystack = "Foo Bar Baz"`, `little = "Bar"`, `len = 4` -> Should return `NULL` (since "Bar" ends at index 6).
  - `haystack = "Foo Bar Baz"`, `little = "Bar"`, `len = 7` -> Should return pointer to `"Bar Baz"`.
  - `haystack = "anything"`, `little = ""`, `len = 0` -> Should return `haystack`.
  - `haystack = ""`, `little = "a"`, `len = 5` -> Should return `NULL`.

---

## 6. String Copy & Concatenation (`ft_strlcpy`, `ft_strlcat`)

### High-Critical Defense Questions
1. **Return Value Mechanics:**
   - What do `strlcpy` and `strlcat` return? Why do they return the length of the string they *tried* to create rather than the number of bytes copied?
2. **Buffer Overflows & `dstsize = 0`:**
   - How does `ft_strlcat` behave if `dstsize` is smaller than `strlen(dst)`? What value does it return, and does it modify `dst`?

### Extreme & Edge Case Test Scenarios
* **`ft_strlcpy`:**
  - `dstsize = 0`: Verify destination is untouched and function returns `strlen(src)`.
  - `dstsize` smaller than `strlen(src) + 1`: Verify truncation and proper `\0` termination.
* **`ft_strlcat`:**
  - `dst` not null-terminated within `dstsize`: If `dst = "hello"`, `dstsize = 3`, `src = "world"`. Function must return `dstsize + strlen(src)` (3 + 5 = 8) without modifying `dst`.
  - Exact buffer sizing: `dst` capacity = 10, `dst = "55555\0"`, `src = "1234"`, `dstsize = 10`. Resulting `dst` must be `"555551234"` (length 9 + NUL = 10 total bytes used).

---

## 7. Character Case Conversion (`ft_toupper`, `ft_tolower`)

### High-Critical Defense Questions
1. **Out-of-Range Arguments:**
   - If an integer value outside the unsigned char range (e.g., `500` or `-50`) is passed, how should `ft_toupper`/`ft_tolower` handle it?

### Extreme & Edge Case Test Scenarios
* Non-alphabetic characters: `c = '1'`, `c = '!'`, `c = '\n'` (must return input unchanged).
* Boundaries: `c = 'a' - 1`, `c = 'z' + 1`, `c = 'A' - 1`, `c = 'Z' + 1`.

---

## 8. Integer Conversion (`ft_atoi`)

### High-Critical Defense Questions
1. **Sign Handling & White Space Parsing:**
   - Which specific characters are considered whitespace in `atoi` according to standard C (`isspace`)? (Hint: `' '`, `\t`, `\n`, `\v`, `\f`, `\r`).
   - How does `ft_atoi` handle multiple signs such as `"--42"` or `"+-42"`?
2. **Integer Overflow & Underflow:**
   - What is the expected behavior when string values exceed `INT_MAX` (`2147483647`) or `INT_MIN` (`-2147483648`)?

### Extreme & Edge Case Test Scenarios
* **Whitespace & Sign combinations:**
  - `"\t\n\v\f\r  +42"` -> `42`
  - `" --42"` -> `0` (stops at second sign)
  - `"+-42"` -> `0`
  - `"   +00001234"` -> `1234`
* **Garbage characters:**
  - `"42abc"` -> `42`
  - `"abc42"` -> `0`
* **Extreme Numeric Limits:**
  - `"2147483647"` -> `2147483647`
  - `"-2147483648"` -> `-2147483648`
  - `"999999999999999999999"` -> Check for overflow safety.

---

## 9. Dynamic Allocation Libc Functions (`ft_calloc`, `ft_strdup`)

### High-Critical Defense Questions
1. **Zero-Byte Allocation in `ft_calloc`:**
   - Subject rule: "If `nmemb` or `size` is 0, then `calloc()` returns a unique pointer value that can be successfully passed to `free()`." How did you implement this?
2. **Integer Overflow during Size Calculation:**
   - In `ft_calloc(nmemb, size)`, if `nmemb * size` exceeds `SIZE_MAX`, what happens? How do you check for multiplication overflow before calling `malloc`?

### Extreme & Edge Case Test Scenarios
* **Zero Allocation:**
  - `ft_calloc(0, 10)` or `ft_calloc(10, 0)` -> Must return a valid non-null pointer (or malloc'd pointer) that does not crash when passed to `free()`.
* **Multiplication Overflow Test:**
  - `ft_calloc(SIZE_MAX / 2, 3)` -> Should detect integer overflow and return `NULL` safely without allocating corrupted memory.
* **`ft_strdup` Empty String:**
  - `ft_strdup("")` -> Allocates 1 byte, stores `\0`, returns valid non-null pointer.