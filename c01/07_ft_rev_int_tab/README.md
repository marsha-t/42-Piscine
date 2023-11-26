## ft_rev_int_tab

|               ft_rev_int_tab        |
|---------------------------------|
| Turn-in directory : ex07/       |
| Files to turn in : ft_rev_int_tab.c |
| Allowed functions : None       |

- Create a function which reverses a given array of integer (first goes last, etc).
- The arguments are a pointer to int and the number of ints in the array.
- Here’s how it should be prototyped :
```
void ft_rev_int_tab(int *tab, int size);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	num[4];

	num[0] = 1;
	num[1] = 2;
	num[2] = 3;
	num[3] = 4;
	printf("Before: %d, %d, %d, %d\n", num[0], num[1], num[2], num[3]);
	ft_rev_int_tab(num, 4);
	printf("After:  %d, %d, %d, %d\n", num[0], num[1], num[2], num[3]);
	return (0);
}</pre></code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Before: 1, 2, 3, 4
After:  4, 3, 2, 1</code></pre>

</details>

<details>
<summary><h3>Approach 1: Swap first half of the array with the second half</h3></summary>

We continue to work with arrays in this exercise, this time with an array of integers. These are less commonly null-terminated, hence it is super useful that the user would have to specify the number of elements in the array when calling <code>ft_rev_int_tab</code> function. 

With this <a href=ft_rev_int_tab_v1.c>approach</a>, , we reverse the order of the integers in the array by swapping the integers around, the last element with the first, the second with the penultimate, etc. However, we can't loop through all the integers in the array and initiate a swap for all of them, else we risk swapping everything back to its original order. Instead, we only really need to swap the first half of the elements with the second half. Hence, the <code>while</code> loop condition is set to go through only the first half of the array:

<pre><code>19	i = 0;
20	mid = size / 2;
21	while (i < mid)</code></pre>

Within this loop, we swap the first and last element of the array where <code>tab[0]</code> refers to the first element and <code>tab[size - 1]</code> refers to the last element. We use <code>size - 1</code> because arrays are 0-indexed, hence the nth element in an array has an index of n - 1. A similar set of commands are used for swapping as in <a href=../02_ft_swap/ft_swap.c>ft_swap</a>. To move to the second element, we use <code>i++</code> and to the penultimate element, we use <code>size--</code>.

We could also have defined the while loop condition differently using <code>while (i < size)</code>. This  would also avoid initiating too many unnecessary swaps and is written with fewer lines of code.

</details>

<details>
<summary><h3>Approach 2: Use another array to store the reversed integers</h3></summary>

If asked to reverse a list of numbers, I would begin writing another list and writing the numbers in reverse. 

Applying this <a href=ft_rev_int_tab_v2.c>approach</a> in C would be equivalent as defining another array to hold the reversed integers e.g., <code>new_tab</code>. Note that <code>new_tab</code> will have the same size as <code>tab</code>.

<pre><code>19	i = 0;
20	while (size - i - 1 >= 0)
21	{
22		new_tab[i] = tab[size - i - 1];
23		i++;
24	}</code></pre>

In the above code, we fill <code>new_tab</code> with numbers from <code>tab</code> but in reverse:
- When <code>i = 0</code>, line 22 will refer to the first element of <code>new_tab</code> and the last element of <code>tab</code>
- When <code>i = 1</code>, line 22 will refer to the second element of new_tab and the penultimate element of tab
- When <code>i = size - 1</code>, line 22 will refer to the last element of <code>new_tab</code> and the first element of <code>tab</code>

The annoying thing is that we have to 'return' <code>new_tab</code> in <code>tab</code>. It may be tempting to simply assign <code>new_tab</code> to <code>tab</code>:

<pre><code>tab = new_tab</code></pre>

Unfortunately, <code>tab</code> is a pointer to (or address of) the first element of the array. Correspondingly, <code>new_tab</code> is a pointer to the first element of the array. This line of code therefore only assigns the first element of the <code>new_tab</code> array to the first element of the <code>tab</code> array. The rest of the <code>tab</code> array remains unchanged. As a result, another <code>while</code> loop is required to replace all the elements in <code>tab</code> with that from <code>new_tab</code>:

<pre><code>25	i = 0;
26	while (i <= size - 1)
27	{
28		tab[i] = new_tab[i];
29		i++;
30	}</code></pre>

</details>
