*This project has been created as part of the 42 curriculum by ctrzecik.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf(3)`,
packaged as a static library (`libftprintf.a`).

The goal of the project is to learn how **variadic functions** work in C
(`va_start`, `va_arg`, `va_end`) and to reproduce, for a subset of conversions,
both the output and the return value of the original `printf`.

```c
int	ft_printf(const char *format, ...);
```

### Supported conversions

| Conversion | Argument type    | Output                                         |
|------------|------------------|------------------------------------------------|
| `%c`       | `int` (as char)  | A single character                             |
| `%s`       | `char *`         | A string; `(null)` if the pointer is `NULL`    |
| `%p`       | `void *`         | `0x` + lowercase hex address; `(nil)` if `NULL` |
| `%d` `%i`  | `int`            | Signed decimal                                 |
| `%u`       | `unsigned int`   | Unsigned decimal                               |
| `%x`       | `unsigned int`   | Lowercase hexadecimal                          |
| `%X`       | `unsigned int`   | Uppercase hexadecimal                          |
| `%%`       | —                | A literal `%`                                  |

### Return value

The number of characters printed, or `-1` if a write error occurs or if the
format string is `NULL`.

The `NULL` string and `NULL` pointer outputs (`(null)` and `(nil)`) follow the
behavior of glibc's `printf` on Linux, which is the reference used for testing.

As required by the subject, the output is **not buffered**: every character goes
straight to standard output through `write(2)`.

## Instructions

### Requirements

- A C compiler available as `cc`
- `make` and `ar`

### Building the library

```sh
make        # compiles the sources and creates libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # fclean + all
```

The sources are compiled with `-Wall -Wextra -Werror`, and the library is
created with `ar rcs` at the root of the repository.

### Using it in a program

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s! %d%% done, at %p\n", "42", 100, &count);
	ft_printf("The previous line had %d characters\n", count);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
./demo
```

## Project structure

| File               | Role                                                              |
|--------------------|-------------------------------------------------------------------|
| `ft_printf.h`      | Prototypes of `ft_printf` and the helper functions                |
| `ft_printf.c`      | `ft_printf` (main loop) and `print_type` (conversion dispatcher)  |
| `ft_putchar.c`     | Writes one character                                              |
| `ft_putstr.c`      | Writes a string, or `(null)`                                      |
| `ft_putnbr.c`      | Writes a signed `int` in base 10 (`%d`, `%i`)                     |
| `ft_putunbr.c`     | Writes an `unsigned int` in base 10 (`%u`)                        |
| `ft_putnbr_base.c` | Writes an `unsigned int` in base 16 using a given digit set (`%x`, `%X`) |
| `ft_putptr.c`      | Writes a pointer as `0x` + 64-bit hex, or `(nil)` (`%p`)          |

Every helper returns the number of bytes it wrote, or `-1` if `write` fails.

## Algorithm and data structures

### 1. One pass over the format string

`ft_printf` reads the format string once, from left to right, with an index `i`:

- An ordinary character is written immediately with `ft_putchar`.
- A `%` followed by another character is a conversion. The function hands
  `print_type` a pointer to the `%`, and the index then skips both the `%` and
  the specifier.
- A `%` at the very end of the string is written as a plain character. The
  library never reads past the terminating `'\0'`.

### 2. Dispatching the conversion

`print_type` looks at the character after the `%` and calls the matching
helper, fetching the next argument with `va_arg`.

The type passed to `va_arg` has to be the *promoted* type of the argument.
Inside `...`, a `char` is promoted to `int`, so `%c` reads an `int`. `%u`, `%x`
and `%X` read an `unsigned int`, and `%p` reads a `void *`.

An unknown specifier is printed as it appears (`%` followed by the character).

### 3. Converting numbers to text

Every number is converted with the classic **repeated division** algorithm:

1. Take `n % base` as the next digit, using it as an index into a string of
   digits.
2. Divide `n` by the base, and repeat until `n` reaches 0.
3. The digits come out least-significant first, so they are stored in a small
   array and then written in **reverse order**.

Specific cases:

- **Signed numbers (`%d`, `%i`):** the `int` is copied into a `long` before it
  is negated. `-INT_MIN` does not fit in an `int`, but it fits in a `long`, so
  `-2147483648` is printed correctly. The `-` sign is written first, then the
  absolute value.
- **Hexadecimal (`%x`, `%X`):** the same function handles both. The caller
  passes either `"0123456789abcdef"` or `"0123456789ABCDEF"` as the digit set.
- **Pointers (`%p`):** the address is cast to `unsigned long`, which holds all
  64 bits, and printed in hex after the `0x` prefix.
- **Zero:** handled explicitly, so that `0` prints one digit instead of nothing.

### 4. Counting characters and detecting errors

`len` (a `size_t`) holds the running total of bytes written, and `save_len`
holds the total from the previous step.

When a helper fails it returns `-1`, and adding `-1` to the total leaves
`len == save_len - 1`. `ft_printf` checks for exactly that condition after every
step and returns `-1` straight away, which is what `printf` does on an output
error. A `NULL` format string also returns `-1`, as glibc does.

### Data structures used

| Structure                     | Where                            | Purpose                          |
|-------------------------------|----------------------------------|----------------------------------|
| `va_list`                     | `ft_printf`, `print_type`        | Cursor over the variadic arguments |
| `char buf[11]`                | `ft_putnbr`, `ft_putunbr`        | Up to 10 decimal digits of a 32-bit integer |
| `char buf[8]`                 | `ft_putnbr_base`                 | Up to 8 hex digits of a 32-bit integer |
| `char buf[16]`                | `ft_putptr`                      | Up to 16 hex digits of a 64-bit address |

There are no structs, no linked lists and no heap allocation.

### Why this design

- **No struct for the format specification.** The mandatory part has no flags,
  width or precision, so the single character after `%` defines the whole
  conversion. A struct holding the parsed specification would add complexity
  without any benefit here.
- **Fixed-size stack buffers instead of `malloc`.** The largest possible number
  of digits is known at compile time from the width of each type. Using stack
  buffers means nothing has to be freed, so memory cannot leak, and there is
  no allocation-failure case to handle.
- **Direct, unbuffered `write`.** The subject forbids reproducing printf's
  buffer management. Writing straight away also keeps the output in the right
  order when other code writes to the same file descriptor.
- **One small function per conversion.** Each helper lives in its own file,
  fits the Norm's limits (25 lines per function, 5 functions per file) and can
  be tested on its own. Adding a conversion only takes a new helper and one
  extra branch in `print_type`.
- **Complexity.** Time is O(n + d), where n is the length of the format string
  and d is the total number of characters printed by the conversions. Extra
  memory is O(1).
- **Trade-off.** Each character costs one `write` system call. This is simple
  and meets the subject's rules, but it is slower than the real `printf` for
  very large outputs.

## Testing

On Linux x86_64, the library was compared against glibc's `printf`:

- Hand-written edge cases: `INT_MIN`, `UINT_MAX`, `%c` with `'\0'`, `NULL`
  strings and pointers, `%%`, and calls with many arguments.
- Tens of thousands of randomly generated format strings, comparing the output
  byte by byte together with the return value.
- Checks with `norminette`, `valgrind`, AddressSanitizer and
  UndefinedBehaviorSanitizer, all without errors.

## Resources

### References

- [`printf(3)` — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`stdarg(3)` — Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [cppreference — `printf`, `fprintf`, …](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
- [GNU C Library manual — Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [42 Norminette](https://github.com/42School/norminette)

### Use of AI

AI (Claude) was used as a **reviewer and tester**. It did not write the
implementation. It was used for:

- **Compliance review:** checking the project against the subject's mandatory
  requirements (Makefile rules, no relinking, allowed functions, header name and
  prototype) and running `norminette`.
- **Testing:** writing throwaway test programs that are not part of the
  repository. These compared `ft_printf` with `printf` on fixed edge cases and
  on random format strings, and ran the library under `valgrind`,
  AddressSanitizer and UndefinedBehaviorSanitizer.
- **Finding issues:** it pointed out problems that I then fixed myself, such as
  a function longer than 25 lines, missing 42 headers, a crash on a `NULL`
  format and an out-of-bounds read when the format ends with `%`.
- **Documentation:** helping draft this README.
