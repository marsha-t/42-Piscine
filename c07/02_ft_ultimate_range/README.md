## ft_ultimate_range

|               ft_ultimate_range        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_ultimate_range.c |
| Allowed functions : malloc       |

- Create a function <code>ft_ultimate_range</code> which allocates and assigns an array of <code>int</code>s. This <code>int</code> array should contain all values between <code>min</code> and <code>max</code>.
- <code>min</code> included - <code>max</code> excluded.
- Here’s how it should be prototyped :
```
int ft_ultimate_range(int **range, int min, int max);
```
- The size of <code>range</code> should be returned (or <code>-1</code> on error).
- If <code>min</code>´s value is greater or equal to <code>max</code>’s value, <code>range</code> will point on <code>NULL</code> and it should return <code>0</code>.


<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	*range;
	int	d;
	int	i;

	d = ft_ultimate_range(&range, 3, 7);
	printf("ft_ultimate_range(range, 3, 7): ");
	printf("size: %d\n", d);
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", range[i]);
	}
	d = ft_ultimate_range(&range, -4, 0);
	printf("\nft_ultimate_range(range, -4, 0): ");
	printf("size: %d\n", d);
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", range[i]);
	}
	d = ft_ultimate_range(&range, 0, 0);
	printf("\nft_ultimate_range(range, 0, 0): ");
	printf("size: %d\n", d);
	if (range == 0)
		printf("Null pointer returned\n");
	
	d = ft_ultimate_range(&range, 7, 3);
	printf("ft_ultimate_range(range, 7, 3): ");
	printf("size: %d\n", d);
	if (range == 0)
		printf("Null pointer returned\n");
	return (0);
}
</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>ft_ultimate_range(range, 3, 7): size: 4
3, 4, 5, 6,
ft_ultimate_range(range, -4, 0): size: 4
-4, -3, -2, -1,
ft_ultimate_range(range, 0, 0): size: 0
Null pointer returned
ft_ultimate_range(range, 7, 3): size: 0
Null pointer returned</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_ultimate_range.c>exercise</a> is very similar to the <a href=../01_ft_range>last one</a>. The key differences are:
- to return the number of <code>int</code> in the array; and
- to 'return' the array via <code>range</code>. 

The number of <code>int</code> in the array is <code>max - min</code> so this is the return value in most cases (line 34). However, ...
- where <code>min</code> is greater than or equal to <code>max</code>, <code>0</code> is returned. Note that the <code>0</code> in line 23 (<code>return (0)</code>) refers to the integer.
- where there is an error allocating space using <code>malloc</code>, <code>-1</code> is returned. 

The rest of the code proceeds similarly to <code>ft_range</code>. <code>ptr</code> is created and filled with the required <code>int</code>. Note that <code>ptr</code> is a pointer to an <code>int</code> (the first element of the array).

With the <code>return</code> statement intended to return an <code>int</code>, there is no direct mechanism to return <code>ptr</code>. Instead, <code>ptr</code> will be 'returned' via <code>range</code> (line 33). 

<code>range</code> is declared as <code>int **range</code> meaning that it is a pointer to a pointer of <code>int</code>. Specifically in this case, <code>range</code> is a pointer to a pointer of the first element in an array. It is a <u>double</u> pointer. Hence, we need to dereference it in order to assign <code>ptr</code> and 'return' <code>ptr</code> via <code>range</code>. A double pointer is needed here to 'return' the array - more details below:

If <code>range</code> was declared as <code>int *range</code>, we would be able to assign <code>ptr</code> to <code>range</code> within <code>ft_ultimate_range</code> so that both are pointers to the first element of the array. However, we would not be able to access the generated array outside of the function. 

Suppose we attempted the following:
<pre><code>int ft_ultimate_range(int *range, int min, int max);

int main(void){
	int *main_range;
	int temp;
	int d;
	
	temp = 42;
	main_range = &temp;
	d = ft_ultimate_range(main_range, 3, 7);
}

int ft_ultimate_range(int *range, int min, int max)
{
	int *ptr;
	...
	range = ptr;
}</code></pre>

- In the <code>main</code> function, a pointer to an <code>int</code> is declared using <code>main_range</code>. In this example, it has been initialised to hold the address of <code>temp</code>, a <code>int</code> variable that holds <code>42</code>. 
- <code>main_range</code> is passed into <code>ft_ultimate_range</code>. Within this function, another variable, <code>range</code>, is created. This too is a pointer to an <code>int</code> and also holds the address of <code>temp</code>. 
- In <code>ft_ultimate_range</code>, we generate the necessary <code>int</code> array and end up with <code>ptr</code>, a pointer to the first element of the <code>int</code> array. In other words, <code>ptr</code> holds the address for an <code>int</code> (the number <code>3</code>).
- <code>ptr</code> is assigned to <code>range</code>. range now also holds the address for <code>3</code>. 
- but how is the <code>main</code> function supposed to access <code>range</code> and the address it holds? In the <code>main</code> function, <code>main_range</code> continues to hold <code>42</code>.

Now let's try it with a double pointer:
<pre><code>int ft_ultimate_range(int **range, int min, int max);

int main(void){
	int *main_range;
	int temp;
	int d;
	
	temp = 42;
	main_range = &temp;
	d = ft_ultimate_range(&main_range, 3, 7);
}

int ft_ultimate_range(int **range, int min, int max)
{
	int *ptr;
	...
	*range = ptr;
}</code></pre>

- As before, <code>main_range</code> is initialised to hold the address of <code>temp</code>.
- This time, the <i>address</i> of <code>main_range</code> is passed into <code>ft_ultimate_range</code>. In this function, <code>range</code> holds an address as before but this time, the address is of <code>main_range</code>! In other words, if we go to the address held in <code>range</code> (by dereferencing <code>range</code>), we will reach <code>main_range</code>. If we dereference <code>range</code> twice, we essentially dereference <code>main_range</code> and access the <code>temp</code>. 
- After creating <code>ptr</code> to contain the address for the first element of the int array, we assign it to <code>*range</code>, which is <code>main_range</code>. 
- When control returns to the main function at the end of running ft_ultimate_range, main_range has been altered to point at the start of the newly generated array!

</details>

