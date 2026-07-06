To determine `BuildMaxHeapify` time complexity, we look at the jobs in each `MaxHeapify`. For any given heigh `h`, the time complexity of `MaxHeapify` is directly proprtional to `h` or `O(h)`.

In any given height `h`, we have the maximum number of nodes at $\left\lfloor \frac{n}{2^{h + 1}}\right\rfloor$. To find the total time, we multiply the number of nodes at each height by the work done at that heigh, and sum up from height $h = 0$ to `H`:

$$T(n) = \sum^{\lfloor \log_2{n} \rfloor}_{h = 0} {\frac{n}{2^{h + 1}} * O(h)}$$

$$T(n) = O(\frac{n}{2} \sum^{\lfloor \log_2{n} \rfloor}_{h = 0} {\frac{h}{2^h}})$$

Now we expand the infinite series, we have:

$$S = \frac{1}{2} + \frac{2}{4} + \frac{3}{8} + \dots$$

If we multiply `S` by $\frac{1}{2}$, we have:

$$\frac{1}{2}S = \frac{1}{4} + \frac{2}{8} + \frac{3}{16} + \dots$$

Now we subtract $\frac{1}{2}S$ from `S`, we have:

$$S - \frac{1}{2}S = \frac{1}{2} + \left(\frac{2}{4} - \frac{1}{4}\right) + \left(\frac{3}{8} - \frac{2}{8}\right) + \dots = \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \dots$$

$$\frac{1}{2}S = 1 \implies S = 2$$

Finally, we have:

$$T(n) \leq \frac{n}{2} * 2 = n$$

Or, the `BuildMaxHeapify` algorithm has the time complexity of:

$$T(n) = O(n)$$