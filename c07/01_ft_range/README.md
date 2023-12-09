## ft_range

|               ft_range        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_range.c |
| Allowed functions : malloc       |

- Create a function <code>ft_range</code> which returns an array of <code>int</code>s. This <code>int</code> array should contain all values between <code>min</code> and <code>max</code>.
- <code>min</code> included - <code>max</code> excluded.
- Here’s how it should be prototyped :
```
int *ft_range(int min, int max);
```
- If <code>min</code>´s value is greater or equal to <code>max</code>’s value, a null pointer should be returned.

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	i;
	int	*ptr;

	printf("ft_range(3,7): ");
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", ft_range(3, 7)[i]);
	}
	printf("\nft_range(-4, 0): ");
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", ft_range(-4, 0)[i]);
	}
	printf("\nft_range(0, 0): ");
	ptr = ft_range(0, 0);
	if (ptr == 0)
		printf("Null pointer returned\n");
	printf("ft_range(7,3): ");
	ptr = ft_range(7, 3);
	if (ptr == 0)
		printf("Null pointer returned\n");
	return (0);
}
</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>ft_range(3,7): 3, 4, 5, 6, 
ft_range(-4, 0): -4, -3, -2, -1,
ft_range(0, 0): Null pointer returned
ft_range(7,3): Null pointer returned</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_range.c>solution</a>...
- returns a null pointer when <code>min</code> is greater than or equal to <code>max</code> (lines 20-21); 
- allocates space for the array of <code>int</code> if <code>min</code> is less than <code>max</code>;
- populates the range starting from <code>min</code> and ending right before <code>max</code>; and
- returns a pointer to the start of this array. 

The number of elements in the required array of <code>int</code> is given by <code>max - min</code>. This is sufficient since <code>max</code> is excluded from the array. The overall size of this array is given by the number of <code>int</code> (i.e., <code>max - min</code>) multiplied by the number of bytes an <code>int</code> variable takes. The latter is typically 4 bytes but again, for portability, the <code>sizeof</code> operator is used to calculate the size of an <code>int</code> variable.

If successful, <code>malloc</code> will return a pointer to the allocated space. This is assigned to <code>ptr</code> (line 22). If unsuccessful, <code>malloc</code> returns a null pointer and <code>ft_range</code> will similarly return a null pointer - the <code>0</code> in line 24 refers to a null pointer. 

Lines 26-27 fills up <code>ptr</code> with the required <code>int</code>, taking care not to include <code>max</code> in the array. Since <code>ptr</code> is an array of <code>int</code>, there is also no need to null-terminate it before returning (line 28). 

</details>

