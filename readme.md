*This project has been created as part of the 42 curriculum by brancari.*

# Libft

## Description
Libft is your very first own library project in the 42 curriculum. It involves coding a C library (`libft.a`) that includes numerous general-purpose functions for your future C programs.

## Instructions

- The project must be written in C and comply with the Norm.
- All source files must be placed at the root of the repository.
- Compile the library using the provided Makefile with the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re` using `cc` and flags `-Wall`, `-Wextra`, and `-Werror`.
- Include the `bonus` rule in your Makefile to compile bonus files.

## Detailed Library Description

### Part 1: Libc Functions

Re-implementations of standard C library functions with the `ft_` prefix ;

- **Character classification:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **Memory operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`'
- **String operations:** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`'
- **Conversions:** `ft_atoi`, `ft_toupper`, `ft_tolower`;

### Part 2: Additional Functions

Functions not included in standard libc or existing in a different form :

- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri` 
- File descriptor output: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Part 3: Linked List

Functions using the `t_list` structure (`content` and `next`)

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Resources

- **References:** Standard man pages, GNU C Library manual, and BSD string libraries
- **AI Usage:** AI tools were referenced to understand fundamental concepts, edge cases (such as `calloc` behavior with zero-sized inputs and `memmove` overlapping safety), and documentation navigation. All core coding and problem-solving were carried out independently to build strong foundational reasoning
