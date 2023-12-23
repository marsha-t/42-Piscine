## ft_count_if

|               ft_count_if        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_count_if.c |
| Allowed functions : None       |

- Create a function <code>ft_count_if</code> which will return the number of elements of the array that does not return <code>0</code> when passed to the function <code>f</code>.
- This function will be applied following the array’s order.
- Here’s how the function should be prototyped :
```
int ft_count_if(char **tab, int length, int(*f)(char*));
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstdlib.h&gt

int	ft_a(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int	main (void)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * 4);
	for (int i = 0; i < 3; i++)
	{
		ptr[i] = (char *)malloc(2);
	}
	ptr[3] = 0;
	ptr[0] = "a";
	ptr[1] = "b";
	ptr[2] = "c";
	printf("%d\n", ft_count_if(ptr, 3, &ft_a));
	ptr[0] = "a";
	ptr[1] = "a";
	ptr[2] = "a";
	printf("%d\n", ft_count_if(ptr, 3, &ft_a));
	ptr[0] = "b";
	ptr[1] = "b";
	ptr[2] = "b";
	printf("%d\n", ft_count_if(ptr, 3, &ft_a));
}</code></pre>

A function pointer to <code>ft_a</code> is used to test <code>ft_count_if</code>: It returns <code>1</code> if there is an <code>'a'</code> in <code>str</code> and <code>0</code> otherwise.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>1
3
0</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_count_if.c>solution</a> is very similar to that used in the last <a href=../02_ft_any>exercise</a>.

The key difference is to use <code>count</code> to count the number of times the function <code>f</code> returns a non-zero value. Eventually, after iterating through all the strings in <code>tab</code>, <code>ft_count_if</code> returns <code>count</code>.

Also, here, we will assume that tab is terminated with a null pointer as in the previous <a href=../02_ft_any>exercise</a>.

</details>

