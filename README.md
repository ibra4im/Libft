*This project has been created as part of the 42 curriculum by brancari.*

# Libft

## Description

**Goal:** understand how the standard C functions work by re-coding them, and build a reusable library (`libft.a`) for future 42 projects.

**Overview:** `libft.a` is a static C library made of three parts, all mandatory:

| Part | Content |
|---|---|
| 1 - Libc functions | Re-coded libc functions with the `ft_` prefix: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup` |
| 2 - Additional functions | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| 3 - Linked list | `t_list` structure and `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |

Notes:
- Character classification functions return `1` if the character matches, `0` otherwise.
- `ft_calloc` returns a unique pointer that can be passed to `free()` when `nmemb` or `size` is `0`.
- Prototypes do not use `restrict`, and the code is not compiled with `-std=c99`.
- Helper functions are `static`, there are no global variables, and the library is built with `ar`.

## Instructions

Everything is at the root of the repository. Compilation uses `cc -Wall -Wextra -Werror`.

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all
```

To use the library, include the header and link `libft.a`:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c libft.a
```

## Resources

- `man` pages (`man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, `man 3 calloc`, ...)
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/)
- [42 Norm](https://github.com/42School/norminette)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [`ar` manual](https://man7.org/linux/man-pages/man1/ar.1.html)

**Use of AI:**
- Explaining theory concepts (pointers, memory, linked lists).
- Help in Some edge cases.
- Some Qustions to check my knowldge 
