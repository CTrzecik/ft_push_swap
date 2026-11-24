*This project has been created as part of the 42 curriculum by ctrzecik, dibranco*

## Description

This project is all about ordering numbers from ascending order in the most efficent way possible, with a handful of allowed moves     
and with only two stacks available to us.

Additionally, it allowed us to discover algorithmic complexity in a very concrete way, making the choice in a algorithm extremely important,

depending on the constraints like memory usage, stability and number of operations to sort a stack.

### Technical choices

#### Simple algorithm $O(n^2)$

In regards to the simple algorithm, selection sort was the chosen choice.

Selection sort being a comparsion-based sorting algorithm. It sorts by repeatedly selecting the smallest element from the   
unsorted portion and swapping it with the first unsorted element.

However for our use case we had to adapt it for two stacks, so unstead of swapping the smallest element with the first unsorted    
element we pushed the smallest element to the stack b and did successively, until there is one element left   
and push everything back to stack a.

This algorithm was primarly chosen not just for it's simplicity but also the number of operations to organize a stack.

Being much more efficent than a standard bubble sort in terms of number of operations required to sort a stack.

#### Medium algorithm $O(\sqrt{n})$

Allusive to the medium algorithm, a chunk-based sorting algorithm was chosen.

#### Complex algorithm $O(n\log{n})$

Regarding the complex algorithm, radix sort Least Significant Digit (LSD) was used.

An adapatation had to be made for this type of algorithm, reason being that for base 10 integers,    
10 buckets would be needed to sort, however using base 2, otherwise know as binary we can reduce it to two   
buckets, which is perfect for having only two stacks to work with.

The main idea of radix sort is comparing the least significant digit between 1 or 0.

If it's 0, we push it to stack b, if not we rotate a. Everytime we go through stack a, we push everything that's   
in stack b onto a, doing this n times (n being determined by the size of the linked list).

This algorithm was primarly chosen for being the most consistent out of the bunch and also being within the two stack limit.

## Instructions

In order to create the binary for `push_swap`

You must run the command make in the root directory of the project.

```bash
make
```

Which will run the implicit rule **all**, compiling every source file into object file and archiving them.

There's also the command:

```bash
make clean
```

Which will remove all object files, excluding the archive file.

If the removal of the archive file is needed run the command below:

```bash
make fclean
```

Like the previous rule it will remove all object files, including the archive file.

Last but not least

```bash
make re
```

This will run fclean followed by all, rebuilding everything from scratch.

You can run the binary push_swap by running it in bash as shown below and also supplementing it with range of numbers that you want to order:

```bash
./push_swap 4 2 3 1
```

> [!NOTE]
> The first argument represents the top of stack, descending to the bottom.

### Strategy Selector

There's four different strategies that can be applied to a stack, in other words algorithms.

Firstly, the `--simple` flag can be used to force a $O(n^2)$ algorithm.

Secondly, the `--medium` flag can be used to force a $O(\sqrt{n})$ algorithm.

Thirdly, the `--complex` flag can be used to force a $O(n\log{n})$ algorithm.

Lastly, the `--adapive` flag can be used to run adaptive algorithm based on the disorder.

> [!IMPORTANT]
> The strategy selector flag can be omitted, doing so will default to the `--adaptive` flag.

### Optional benchmark mode

There's also a optional benchmark mode that can be used, as shown below.

```bash
./push_swap --bench 4 2 3 1
```

Using this flag will write some information after sorting:

- The computed disorder (% with two decimal places).
- The name of the strategy used and its theoretical complexity class.
- The total number of operations.
- The count of each operation type.

> [!NOTE]
> This output will be written in `stderr` and also prefixed with `[bench]`.

Here's an example:

```bash
[bench] disorder: 83.33%
[bench] strategy: Complex / O(nlog(n))
[bench] total_ops: 12
[bench] sa: 0 sb: 0 ss: 0 pa: 4 pb 4
[bench] ra: 4 rb: 0 rr: 0 rra: 0 rrb 0 rrr 0
```

## Resources

AI was mostly used for research, predominantly on the selection of each algorithm class,

also was used for implementation of code and understanding drawbacks and pros for each.
