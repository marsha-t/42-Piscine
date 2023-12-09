## ft_ultimate_div_mod

|               ft_ultimate_div_mod        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_ultimate_div_mod.c |
| Allowed functions : None       |

- Create a function <code>ft_ultimate_div_mod</code> with the following prototype:
```
void ft_ultimate_div_mod(int *a, int *b);
```
- This function divides parameters <code>a</code> by <code>b</code>. The result of this division is stored in the <code>int</code> pointed by <code>a</code>. The remainder of the division is stored in the <code>int</code> pointed <code>b</code>

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 3;
	printf("Before: a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("After:  a = %d, b = %d\n", a, b);
	return (0);
} </pre></code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Before: a = 10, b = 3
After:  a = 3, b = 1</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_ultimate_div_mod.c>exercise</a> is very similar to <a href=../03_ft_div_mod>ft_div_mod</a>, except that the results of division and modulus 'returned' into the values of <code>a</code> and <code>b</code>. 

But before you get carried away, remember that the code is executed sequentially. If we were to execute the following code, we would return the result of <code>a</code> divided by <code>b</code> in <code>a</code> but we would no longer be using the original value of <code>a</code> for the modulus operation:

<pre><code>void	ft_ultimate_div_mod(int *a, int *b)
{
	if (*b != 0)
	{
		*a = *a / *b;
		*b = *a % *b ;
	}
}</code></pre>

We'll need a temporary variable to retain the original value of <code>a</code>. Specifically, <code>temp_a</code> will store the original value of <code>a</code> and this value will be retrieved for the modulus operation:

<pre><code>void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;

	if (*b != 0)
	{
		temp_a = *a;
		*a = *a / *b;
		*b = temp_a % *b;
	}
}</code></pre>

</details>

