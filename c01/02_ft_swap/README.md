## ft_swap

|               ft_swap        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_swap.c |
| Allowed functions : None       |

- Create a function that swaps the value of two integers whose addresses are entered as parameters.
- Here’s how it should be prototyped:
```
void ft_swap(int *a, int *b);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 9;
	printf("Before: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After:  a = %d, b = %d\n", a, b);
	return (0);
}</pre></code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Before: a = 1, b = 9
After:  a = 9, b = 1</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This is a relatively straightforward <a href=ft_swap.c>exercise</a> after realising how pointers refer to addresses of variables so that changes can be made to these variables in another function. 

The only trick here is remembering that you can't swap two values directly - you'r going to need a holding area for one of the values for the swap to happen. Imagine you had coded the following function and <code>*a</code> is 1 and <code>*b</code> is 9 when we first start the function. It seems like the value of the pointer <code>a</code> is assigned the value of the pointer <code>b</code> and vice versa. That <i>sounds</i> like the values have been swapped such that <code>*a</code> is 9 and <code>*b</code> is 1. 

<pre><code>void	ft_swap(int *a, int *b)
{
	*a = *b;
	*b = *a;
}
</code></pre>

However, these commands were executed sequentially. First, the value of the pointer <code>a</code> is assigned the value of the pointer <code>b</code>. So now <code>*a</code> is 9. So far so good. Thereafter, the value of the pointer <code>b</code> is assigned the value of the pointer a. Now, <code>*b</code> is 9 again. Both pointers now point to a value of 9 and we've lost the value of 1 altogether!

This is easily resolved by creating a temporary variable to hold that value of 1 (line 17 below). We change <code>*a</code> to 9 as before (line 18). Then we change <code>*b</code> to 1. Ta da!

<pre><code>13	void	ft_swap(int *a, int *b)
14	{
15		int	temp;
16
17		temp = *a;
18		*a = *b;
19		*b = temp;
20	}
</code></pre>

</details>
