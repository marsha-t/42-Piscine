## ft_is_sort

|               ft_is_sort        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_is_sort.c |
| Allowed functions : None       |

- Create a function <code>ft_is_sort</code> which returns <code>1</code> if the array is sorted and <code>0</code> if it isn’t.
- The function given as argument should return a negative integer if the first argument is lower than the second, <code>0</code> if they’re equal or a positive integer for anything else.
- Here’s how the function should be prototyped :
```
int ft_is_sort(int *tab, int length, int(*f)(int, int));
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstdlib.h&gt

int	ft_cmp(int x, int y)
{
	if (x < y)
		return (-1);
	else if (x == y)
		return (0);
	return (1);
}

int	main(void)
{
	int	ptr[] = {9,8,7,6,5,4,3,2,1,0};
	int	ptr2[] = {0,1,2,3,4,5,6,7,9,8};
	int	ptr3[] = {0,1,2,3,4,5,6,7,8,9};

	printf("%d\n", ft_is_sort(ptr, 10, &ft_cmp));
	printf("%d\n", ft_is_sort(ptr2, 10, &ft_cmp));
	printf("%d\n", ft_is_sort(ptr3, 10, &ft_cmp));
	return (0);
}
</code></pre>

A function pointer to <code>ft_cmp</code> is used to test <code>ft_is_sort</code>. As described in the assignment, <code>ft_cmp</code> returns a negative integer if the first argument is lower than the second, <code>0</code> if they're equal or a positive integer for anything else. 

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>0
0
1</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

Unlike the previous exercises, function <code>f</code> takes two arguments, both of them <code>int</code>. 

This <a href=ft_is_sort.c>solution</a>
- uses <code>i</code> to index tab and a <cde>while</cde> loop to iterate through pairs of <code>int</code> in <code>tab</code> (lines 17-23).
- the pair of <code>int</code> (<code>tab[i]</code> and <code>tab[i + 1]</code>) are compared to each other using <code>f</code> (line 20)
- if <code>f</code> returns a positive value, it means that the first <code>int</code> is larger than the second and hence, that the array is out of order. In this scenario, <code>ft_is_sort</code> returns <code>0</code> immediately (lines 20-21)
- if <code>f</code> returns a negative integer or <code>0</code>, the array is sorted so far and the <code>while</code> loop moves onto the next pair of <code>int</code> (line 22).
- when the <code>while</code> loop has finished iterating through all the pairs of <code>int</code> (making sure not to exceed the length of <code>tab</code> using <code>i + 1 < length</code> as the <code>while</code> loop condition), the array is considered sorted and <code>ft_is_sort</code> returns <code>1</code>.

</details>

