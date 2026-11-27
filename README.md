*This project has been created as part of the 42 curriculum by ctrzecik, dibranco*

## Table of Contents

1. [Description](#description)
    - [Technical choices](#technical-choices)
        - [Simple algorithm](#simple-algorithm)
        - [Medium algorithm](#medium-algorithm)
        - [Complex algorithm](#complex-algorithm)
        - [Performance](#performance)
2. [Instructions](#instructions)
    - [Strategy selector](#strategy-selector)
    - [Optional benchmark mode](#optional-benchmark-mode)
3. [Resources](#resources)

## Description

This project is all about sorting numbers in ascending order in the most efficient way possible, with a handful of allowed moves     
and with only two stacks available to us.

Additionally, it allowed us to discover algorithmic complexity in a very concrete way, making the choice in an algorithm extremely important, depending on the constraints like memory usage, stability and number of operations to sort a stack.

### Technical choices

#### Simple algorithm $O(n^2)$

In regards to the simple algorithm, selection sort was chosen.

Selection sort is a comparison-based sorting algorithm. It sorts by repeatedly selecting the smallest element from the unsorted portion and swapping it with the first unsorted element.

However for our use case we had to adapt it for two stacks, so instead of swapping the smallest element with the first unsorted element we pushed the smallest element to the stack b and did this repeatedly,     
until one element remains, then push everything back to stack a.

This algorithm was primarily chosen not just for its simplicity but also the number of operations to organize a stack.

Being much more efficent than a standard bubble sort in terms of number of operations required to sort a stack.

#### Medium algorithm $O(\sqrt{n})$

Allusive to the medium algorithm, a chunk-based sorting algorithm was chosen.

Chunk-based sort is a sorting technique that involves dividing elements into $\sqrt{n}$ buckets.

These buckets are formed by uniformly distrubuting the elements. Once the elements are divided into buckets into buckets, they can be sorted using any other sorting algorithm.

In our case a selection sort, which seaches for the biggest value and pushes that back to stack a and repeats the process until stack b is empty.

The reason for chooseing this sorting algorithm was for operation efficency. Choosing pushes depending on value ranges in a chunk and rotating if not within that range, reduces unneccessary operations and sorts the stack in chunks making the selection sort spend less operations to sort everything correctly.

#### Complex algorithm $O(n\log{n})$

Regarding the complex algorithm, radix sort Least Significant Digit (LSD) was used.

An adaptation had to be made for this type of algorithm, reason being that for base 10 integers, 10 buckets would be needed to sort, however using base 2, otherwise known as binary we can reduce it to two
buckets, which is perfect for having only two stacks to work with.

The main idea of radix sort is comparing the least significant digit between 1 or 0, simulating two buckets.

We do n passes through stack a (n being the bit-width of the highest rank, so typically $O(n\log{n})$ in passes). Each pass processes the elements, giving rougly $O(n\log{n})$ operations.

For each pass we verify if the bit is 1, if so we rotate a, if not we push it to b, which keeps within the stack limit of this project and keeps operations count reasonable.

However knowing that negative numbers are the largest in binary format, rankings had to be implemented and then sorted to prevent this issue.

To do the rankings, quicksort with Hoare's partition algorithm was used to sort the stack and then give rankings accordingly, then find each value within the stack and give it the index from where it found the value.

Quicksort with Hoare's parition algorithm typically $O(n\log{n})$ average time and $O(n^2)$ worst-case time, also being $O(1)$ in space.

This algorithm was primarily chosen for being the most consistent out of the bunch and also being within the two stack limit.

#### Performance


| Algorithm | 100 nums | 500 nums |
|:----------|:---------|:---------|
|Selection sort|*1,481*|*31,894*|
|Chunk-based sort|*790*|*8,164*|
|Binary Radix sort|*1,084*|*6,784*|


> [!NOTE]
> Below is the performance of each algorithm determined by quantity of nums, results are based off the average of three runs.

## Instructions

In order to create the binary for `push_swap`

You must run the command make in the root directory of the project.

```bash
make
```

Which will run the implicit rule **all**, compiling every source file into an object file and linking them into the `push_swap` binary.

There's also the command:

```bash
make clean
```

Which will remove all object files, excluding the binary.

If the removal of the binary is needed run the command below:

```bash
make fclean
```

Like `clean` it removes all object files, including the binary.

Last but not least

```bash
make re
```

This will run fclean followed by all, rebuilding everything from scratch.

You can run the binary `push_swap` in the shell as shown below and also supplementing it with numbers to sort:

```bash
./push_swap 4 2 3 1
```

> [!NOTE]
> The first argument represents the top of stack, descending to the bottom.

### Strategy selector

There's four sorting strategies that can be applied to a stack.

Firstly, the `--simple` flag can be used to force a $O(n^2)$ algorithm.

Secondly, the `--medium` flag can be used to force a $O(\sqrt{n})$ algorithm.

Thirdly, the `--complex` flag can be used to force a $O(n\log{n})$ algorithm.

Lastly, the `--adaptive` flag can be used to run adaptive algorithm based on the disorder.

> [!IMPORTANT]
> The strategy selector flag can be omitted, doing so will default to the `--adaptive` flag.

### Optional benchmark mode

There's also an optional benchmark mode that can be used, as shown below.

```bash
./push_swap --bench 4 2 3 1
```

Using this flag will write some information after sorting:

- The computed disorder (% with two decimal places).
- The name of the strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type.

> [!NOTE]
> This output will be written to `stderr` and also prefixed with `[bench]`.

Here's an example:

```bash
[bench] disorder: 83.33%
[bench] strategy: Complex / O(nlog(n))
[bench] total_ops: 12
[bench] sa: 0 sb: 0 ss: 0 pa: 4 pb: 4
[bench] ra: 4 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

## Resources

AI was mostly used for research, predominantly on algorithm choice and explanation, however it also helped with explaining and debugging code.

Additionally, it also helped spell check and drafting advice for the readme.

Also some other resources like websites were used:   

[Which sorting algorithm is best and why - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/gfact-which-sorting-algorithm-is-best-and-why/)

[Explanation on selection sort - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
