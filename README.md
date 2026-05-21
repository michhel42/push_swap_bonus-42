*This project has been created as part of the 42 curriculum by sloubiat, vihardy.*

# Push_swap
```
██████╗ ██╗   ██╗███████╗██╗  ██╗     ███████╗██╗    ██╗ █████╗ ██████╗
██╔══██╗██║   ██║██╔════╝██║  ██║     ██╔════╝██║    ██║██╔══██╗██╔══██╗
██████╔╝██║   ██║███████╗███████║     ███████╗██║ █╗ ██║███████║██████╔╝
██╔═══╝ ██║   ██║╚════██║██╔══██║     ╚════██║██║███╗██║██╔══██║██╔═══╝ 
██║     ╚██████╔╝███████║██║  ██║     ███████║╚███╔███╔╝██║  ██║██║     
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝     ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     
by sloubiat and vihardy
```

## Description

**Push_swap** is a sorting algorithm project from the 42 curriculum.  
The objective is to sort a stack of integers using **two stacks (A and B)** and a limited set of predefined operations, while minimizing the number of moves.

The project focuses on:

- Algorithm design and optimization
- Time/operation complexity
- Data structures (linked lists)
- Memory management (no leaks)
- Clean architecture and norm compliance

The program receives a list of integers as arguments and outputs the smallest possible sequence of operations needed to sort them in ascending order.

---

## Available Operations

The project allows only the following stack operations:

- `sa`, `sb`, `ss` — swap
- `pa`, `pb` — push
- `ra`, `rb`, `rr` — rotate
- `rra`, `rrb`, `rrr` — reverse rotate

All operations are implemented in:

- functions\
├── push.c\
├── swap.c\
├── rotate.c\
└── reverse_rotate.c

## Project Architecture

.\
├── algos `Sorting strategies`\
│ ├── simple.c\
│ ├── medium.c\
│ ├── complex.c\
│ └── utils.c\
├── parser/ 	`Input parsing & validation`\
├── functions/ 	`Stack operations`\
├── gnl/ 	   	`get_next_line (checker)`\
├── printf/ `Custom printf (bench/debug)`\
├── libft/ `Personal standard library`\
├── headers/ `All project headers`\
├── checker `Bonus checker`\
├── Makefile `compiler`\
└── push_swap `main program`


The project is modular:

- Parsing is fully isolated
- Algorithms are separated by complexity
- Stack operations are abstracted
- No memory leaks (Valgrind clean)
- Norminette compliant

---

# Algorithms & Strategy

The project dynamically selects a strategy depending on disorder.

---

## 1️⃣ Simple Algo Selection O(n²)(disorder < 0.2)

File: `algos/simple.c`

For very small disorder:

- Hardcoded optimal sequences
- Direct minimal-move solutions
- Guaranteed minimal operations

This ensures perfect scoring for small inputs.

---

## 2️⃣ Medium Algo Bucket Sort O(n√n) (disorder < 0.5)

File: `algos/medium.c`

Used for medium-sized inputs (e.g., 100 numbers).

### Strategy:

1. Compute:
   - Minimum value
   - Maximum value
   - Number of buckets = √n
2. Divide values into buckets (ranges).
3. Push elements bucket by bucket to stack B.
4. Use **smart rotations**:
   - If element is closer to top → `ra`
   - If closer to bottom → `rra`
5. Reinsert elements from B in descending order.

### Why √n buckets?

Using √n provides a balanced tradeoff between:

- Too many buckets (overhead)
- Too few buckets (inefficient grouping)

This significantly reduces unnecessary rotations and improves average performance.

---

## 3️⃣ Complex Algorithm Radix by index O(n log n) (disorder >= 0.5)

File: `algos/complex.c`

For large inputs (e.g., 500 numbers).

### Key Features:

- Values are indexed.
- Sorting relies on normalized indices instead of raw values.
- Uses adaptive pushing strategies.
- Minimizes unnecessary stack traversal.

The algorithm focuses on:

- Reducing total rotations
- Pre-organizing stack B
- Minimizing final reinsertion cost

# Instructions

- compilation
```
make
make bonus
make clean
make fclean
```
- lancement pushswap
```
$>./push_swap [LIST_NB] [FLAG=--simple,--medium,--complex,--adaptive(default)] [BENCH=--bench]
```
- lancement checker bonus
```
$>./checker [LIST_NB] [STDIN operations]
```
`Examples:`
```
$>./push_swap 4 2 3 5 1 6 0 9 --simple --bench
rra
rra
pb
rra
rra
pb
ra
ra
ra
pb
pb
rra
pa
pa
pa
pa
[bench] disorder: 42.85%
[bench] strategy: Simple / O(n²)
[bench] total_ops: 16
[bench] sa:  0  sb:  0  ss:  0  pa:  4  pb  4
[bench] ra:  3  rb:  0  rr:  0  rra: 5  rrb 0  rrr: 0

$>./push_swap 4 2 3 5 1 6 0 9 --simple | ./checker 4 2 3 5 1 6 0 9
OK

$>ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
13

$>shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
6784

$>shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt)
OK

$>cat bench.txt 
[bench] disorder: 51.18%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 6784
[bench] sa:  0  sb:  0  ss:  0  pa:  2284  pb  2284
[bench] ra:  2216  rb:  0  rr:  0  rra: 0  rrb 0  rrr: 0

$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK

$>./checker 3 2 1 0
sa
rra
pb
KO

$>./checker 3 2 one 0
Error

$>./checker "" 1
Error


```


## Task Allocation

### Sloubiat

- libft
- parser
- operations
- checker (bonus)
- algo simple selection
- debug 
- headers
- gnl

### Vihardy
- structures
- printf
- new gnl
- Makefile
- algo medium
- algo complex
- reorganisation du code et norme
- Readme
- headers
- debug

## Resources

### Researchs
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [GNU make](https://www.gnu.org/software/make/manual/make.html)
- [Frog process](https://youtu.be/PLGLFkwPYh8)
- [Chat GPT](https://www.youtube.com/watch?v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&start_radio=1)
- peer to peer
