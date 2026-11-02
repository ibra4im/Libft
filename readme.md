*This project has been created as part of the 42 curriculum by brancari.*

# Libft

> Your very first own library

## Description

**Libft** is a C static library (`libft.a`) that gathers general-purpose functions reimplemented from the standard C library (libc), plus additional utility functions and a small set of linked-list helpers.

**Goal:** understand how the standard functions really work by rewriting them from scratch, and build a reusable toolbox for all future C projects of the 42 curriculum.

**Overview:** the library is split in three parts, **all mandatory**:

1. **Part 1 – Libc functions**: re-coded versions of classic libc functions, prefixed with `ft_`.
2. **Part 2 – Additional functions**: string, number and file-descriptor helpers that are not in libc or exist in a different form.
3. **Part 3 – Linked list**: a `t_list` structure and the functions to manipulate it.

### Constraints followed

- Written in C, respecting the Norm.
- Compiled with `cc -Wall -Wextra -Werror`.
- No global variables.
- Helper functions are declared `static`.
- Library built with `ar` (no `libtool`).
- No memory leaks, no unexpected crashes (except undefined behavior).
- All files at the root of the repository.

## Instructions

### Compilation

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all
```

The Makefile provides the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`, and does not relink unnecessarily.

### Usage

Include the header in your code:

```c
#include "libft.h"
```

Then compile your program against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

### Example

```c
#include "libft.h"

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello 42 world", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

## Library content

### Part 1 – Libc functions

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

Notes:
- Character classification functions return `1` if the character matches the class, `0` otherwise.
- `ft_calloc` returns a unique pointer that can be passed to `free()` when `nmemb` or `size` is `0`.
- `ft_calloc` and `ft_strdup` rely on `malloc`.
- Prototypes do not use the `restrict` qualifier, and the code is not compiled with `-std=c99`.

### Part 2 – Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Returns a substring of `s` starting at `start`, with a maximum length `len`. |
| `ft_strjoin` | Returns a new string resulting from the concatenation of `s1` and `s2`. |
| `ft_strtrim` | Returns a copy of `s1` with characters from `set` removed at the beginning and the end. |
| `ft_split` | Splits a string using a delimiter character; returns a NULL-terminated array of strings. |
| `ft_itoa` | Converts an integer to a string (negative numbers handled). |
| `ft_strmapi` | Applies `f(index, char)` to each character and returns a new string with the results. |
| `ft_striteri` | Applies `f(index, &char)` to each character of a string, in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3 – Linked list (mandatory)

Structure declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node with the given content; `next` is set to `NULL`. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the number of nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees a node's content with `del`, then frees the node (not the next one). |
| `ft_lstclear` | Deletes and frees a node and all its successors, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies `f` to the content of each node. |
| `ft_lstmap` | Creates a new list by applying `f` to each node's content; uses `del` to clean up on failure. |

## Project structure

```
.
├── Makefile
├── README.md
├── libft.h
└── ft_*.c
```

## Technical choices

- Helper functions needed to split complex functions are `static` to restrict their scope to their file.
- Every function that allocates memory returns `NULL` on allocation failure and frees anything already allocated (e.g. `ft_split`, `ft_lstmap`).
- Functions follow the behavior described in the corresponding `man` pages.

## Resources

### References

- `man` pages: `man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, `man 3 calloc`, etc.
- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/)
- [42 Norm](https://github.com/42School/norminette)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [`ar` manual](https://man7.org/linux/man-pages/man1/ar.1.html)

### Use of AI

AI was used for the following tasks :

Explaining reasons of practices in libc.

Explaining linked list padding and alignement.

Explaining memory layout and how each part functions.

Suggesting edge cases.

