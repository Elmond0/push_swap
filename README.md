# <img align="middle" height="115" src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/push_swape.png" alt="push_swap badge"/> <picture><source media="(prefers-color-scheme: dark)" srcset="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=58A6FF&vCenter=true&width=400&height=80&lines=push_swap"><source media="(prefers-color-scheme: light)" srcset="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=0366D6&vCenter=true&width=400&height=80&lines=push_swap"><img align="middle" src="https://readme-typing-svg.demolab.com/?font=Fira+Code&weight=600&size=55&pause=1000&color=0366D6&vCenter=true&width=400&height=80&lines=push_swap" alt="push_swap"/></picture>

[![Common Core](https://img.shields.io/badge/-Common%20Core-24292e?style=flat&logo=data:image/svg%2Bxml;base64,PHN2ZyByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAzNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+NDI8L3RpdGxlPjxkZXNjPkxvZ28gNDIgY29uIHBhZGRpbmcgaW5mZXJpb3JlOiBHaXRIdWIgcmltdW92ZSBnbGkgYXR0cmlidXRpIHN0eWxlIGRhbCBtYXJrZG93biwgcXVpbmRpIGlsIG1hcmdpbmUgY2hlIGFsbGluZWEgbCdpY29uYSBhbCB0ZXN0byBkZWwgdGl0b2xvIGUnIGluY29ycG9yYXRvIG5lbCB2aWV3Qm94LiBJbCBnbGlmbyBvY2N1cGEgeSAzLjU3NC0yMC40MjYgZSBzb3R0byByZXN0YW5vIDEzLjU3NCB1bml0YScgdnVvdGU6IHJlc28gYSA0MnB4IGNvbiBhbGlnbj1taWRkbGUsIGlsIGdsaWZvIHN0YSB+MnB4IHNvcHJhIGxhIGJhc2VsaW5lIGRlbCB0aXRvbG8uIFBlciBhbHphcmxvIGFuY29yYSBzZXJ2b25vICsxIHVuaXRhJyBkaSB2aWV3Qm94IG9nbmkgKzEuMnB4IGRpIGhlaWdodCAoY2lyY2EgKzAuNnB4IGRpIHNvbGxldmFtZW50bywgYSBwYXJpdGEnIGRpIGRpbWVuc2lvbmUgZGVsIGdsaWZvKS48L2Rlc2M+PHN0eWxlPnBhdGh7ZmlsbDojMDAwMDAwfSBAbWVkaWEgKHByZWZlcnMtY29sb3Itc2NoZW1lOmRhcmspe3BhdGh7ZmlsbDojRkZGRkZGfX08L3N0eWxlPjxwYXRoIGQ9Ik0xOS41ODEgMTYuODUxSDI0di00LjQzOVpNMjQgMy41NzRoLTQuNDE5djQuNDJsLTQuNDE5IDQuNDE4djQuNDRoNC40MTl2LTQuNDRMMjQgNy45OTNabS00LjQxOSAwaC00LjQxOXY0LjQyem0tNi4zMjQgOC44MzhINC40MTlsOC44MzgtOC44MzhIOC44MzhMMCAxMi40MTJ2My41OTVoOC44Mzh2NC40MTloNC40MTl6Ii8+PC9zdmc+Cg==)](https://profile.intra.42.fr/users/elmondo)
![Language](https://img.shields.io/badge/language-C-blue)
![Norm](https://img.shields.io/badge/Norminette-passing-brightgreen)


> Sort a stack of integers using only two stacks and a tiny set of operations — and do it in as few moves as possible.

---

## 📖 Project Description

`push_swap` is a 42 School algorithm project. The program receives a list of integers, loads them into **stack A** and prints, on the standard output, the **shortest sequence of instructions** it can find to sort them in ascending order (smallest number on top), using a second, initially empty, **stack B**.

The project is about choosing the right algorithm for the right input size:

- **Data structures** — both stacks are singly linked lists (`t_list` from my `libft`); every operation is a pointer manipulation, with no array shifting.
- **Input normalisation** — each number is replaced by its **rank** (`0 … n-1`), so the sorting code never deals with negatives or huge values.
- **Algorithm design** — a dedicated solution for 2, 3 and 4–5 numbers, and a **chunk-based algorithm** for bigger inputs.
- **Complexity under constraints** — the output is judged by the *number of operations*, not by speed.
- **Robust parsing** — wrong input must print `Error` on `stderr`, never crash and never leak.

The whole codebase follows the **42 Norminette** and compiles with `-Wall -Wextra -Werror`.

---

## 🧰 Allowed Operations

| Op | Description |
|:--:|-------------|
| `sa` / `sb` / `ss` | **swap** the first two elements of A / B / both |
| `pa` | **push** the top of B onto A |
| `pb` | **push** the top of A onto B |
| `ra` / `rb` / `rr` | **rotate** A / B / both: the first element becomes the last |
| `rra` / `rrb` / `rrr` | **reverse rotate** A / B / both: the last element becomes the first |

Each instruction is printed on its own line.

---

## 🧠 The Algorithm

| Input size | Strategy |
|:----------:|----------|
| already sorted / 1 number | prints nothing |
| 2 | `sa` if needed |
| 3 | hard-coded case analysis (at most 2 moves) |
| 4 – 5 | push the two smallest values to B, sort the remaining 2–3 in A, push back |
| 6 + | **chunk sort** |

### Chunk sort (6+ numbers)

1. **Normalise** — every value becomes its rank in the sorted order (`0 … n-1`).
2. **Push to B in chunks** — the size of a chunk depends on `n` (`n/8` up to 150 numbers, `n/14` above). Looking at the top of A, with `pushed` elements already moved:
   - value `<= pushed` → `pb` then `rb` (small values go to the bottom of B),
   - value `<= pushed + chunk` → `pb`,
   - otherwise `ra` to look at the next element.
3. **Bring everything back** — until B is empty, find the **largest** value in B, rotate B in the *shortest* direction (`rb` or `rrb`) and `pa`. Since the maximum always arrives first, A ends up sorted in ascending order.

### Performance

Measured on 100 random runs per size, verified with the provided `checker_linux`:

| Numbers | Average | Worst seen | Typical 42 target |
|:-------:|:-------:|:----------:|:-----------------:|
| 3 | 1 | 2 | ≤ 3 |
| 5 | 7 | 10 | ≤ 12 |
| 100 | ~580 | 626 | < 700 |
| 500 | ~5090 | 5230 | < 5500 |

---

## ⚙️ Compilation & Usage

### Requirements

A C compiler and `make`:

```bash
# Ubuntu
sudo apt install build-essential

# Arch
sudo pacman -S base-devel
```

### Step 1 — Build

```bash
make        # builds libft (with ft_printf and get_next_line) and push_swap
make clean  # removes all .o object files
make fclean # removes .o files, the libraries AND the push_swap executable
make re     # fclean + make, full rebuild from scratch
```

### Step 2 — Run

Pass the numbers as separate arguments:

```bash
./push_swap 3 2 1
```
```
sa
rra
```

Count the moves with `wc`:

```bash
./push_swap 4 67 3 87 23 | wc -l
```

### Error handling

On invalid input the program prints `Error` on the **standard error** and exits with status `1`. These are all errors:

```bash
./push_swap 1 2 a              # not a number
./push_swap 1 1 2              # duplicate
./push_swap 2147483648 1       # greater than INT_MAX
./push_swap -2147483649 1      # smaller than INT_MIN
./push_swap 1 + 2              # sign without digits
./push_swap ""                 # empty argument
```

With **no arguments** the program prints nothing, and an **already sorted** input also prints nothing.

---

## ✅ Testing with the Checker

The repository includes **`checker_linux`**, the official 42 checker for Linux. It reads the instructions from the **standard input**, applies them to the stack built from its own arguments, and prints:

| Output | Meaning |
|:------:|---------|
| `OK` | the instructions sort the stack, and B is empty |
| `KO` | the instructions do **not** sort the stack |
| `Error` | invalid arguments or an invalid instruction |

The checker takes the **same numbers** you gave to `push_swap`:

```bash
chmod +x checker_linux          # only if it is not executable

ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```
```
OK
```

You can also type the instructions by hand (finish with `Ctrl+D`):

```bash
./checker_linux 2 1 3
sa
```
```
OK
```

### Test with random numbers

These one-liners use `bash` (in `zsh` or `fish` the variable is not split into arguments, so run them through `bash -c '...'`):

```bash
# 100 random numbers: check the result and count the moves
ARG=$(shuf -i 0-100000 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l

# 500 random numbers
ARG=$(shuf -i 0-100000 -n 500 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

### Memory check

Build with AddressSanitizer (it also reports leaks) and run it on any input — no output means no problems:

```bash
cc -g -fsanitize=address -Wall -Wextra -Werror *.c -o push_swap_asan \
   -Llibft -lft -Llibft/ft_printf -lftprintf
./push_swap_asan $ARG > /dev/null
```

---

## 📁 Project Structure

```
push_swap/
├── main.c            # Entry point: parse, validate, normalise, sort, free
├── push_swap.h       # Structs and prototypes
├── Makefile          # Builds libft + push_swap
├── check_error.c     # Input validation: digits, INT limits, duplicates
├── operlist.c        # Parsing, stack creation, cleanup, error exit
├── utls.c            # Sorted check + dedicated algorithms for 3, 4 and 5 numbers
├── sort_big.c        # Rank normalisation + chunk sort for 6+ numbers
├── swp.c             # sa, sb, ss
├── psh.c             # pa, pb
├── rtt.c             # ra, rb, rr
├── rrtt.c            # rra, rrb, rrr
├── checker_linux     # 42 checker (OK / KO / Error)
└── libft/            # Personal libft + ft_printf + get_next_line
```

---

## 🎯 Key Takeaways

- Chose and **tuned an algorithm** against a measurable goal — the number of operations — instead of just making it work.
- Practiced **linked-list manipulation** with raw pointers, with no copies and no arrays.
- Built **bullet-proof input parsing**: overflow, duplicates, signs and empty arguments.
- Verified the result with an **external checker**, random stress tests and **AddressSanitizer** (no leaks, no errors).
- Kept every file under the strict rules of the **42 Norminette**.
