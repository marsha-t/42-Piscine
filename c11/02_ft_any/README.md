## ft_any

|               ft_any        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_any.c |
| Allowed functions : None       |

- Create a function <code>ft_any</code> which will return <code>1</code> if, passed to the function <code>f</code>, at least one element of the array returns something else than <code>0</code>. Else, it should return <code>0</code>.
- This function will be applied following the array's order.
- Here’s how the function should be prototyped :

<pre><code>int ft_any(char **tab, int (*f)(char *));</code></pre>

- The array will be delimited with a null pointer.

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

int	main(void)
{
	char	**ptr;
	ptr = (char **)malloc(sizeof(char *) * 4);
	for (int i = 0; i < 3; i++)
	{
		ptr[i] = (char *)malloc(2);
	}
	ptr[3] = 0;
	ptr[0] = "f";
	ptr[1] = "f";
	ptr[2] = "a";
	printf("%d\n", ft_any(ptr, &ft_a));
	ptr[0] = "fa";
	ptr[1] = "f";
	ptr[2] = "f";
	printf("%d\n", ft_any(ptr, &ft_a));
	ptr[0] = "f";
	ptr[1] = "f";
	ptr[2] = "f";
	printf("%d\n", ft_any(ptr, &ft_a));
}</code></pre>

A function pointer to <code>ft_a</code> is used to test <code>ft_any</code>: It returns <code>1</code> if there is an <code>'a'</code> in <code>str</code> and <code>0</code> otherwise.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>1
1
0</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

As in the previous <a href=..01_ft_map>exercise</a>, <code>f</code> returns an <code>int</code> value. However, unlike the previous exercise, it now takes a <code>char *</code> (a pointer to a character and specifically a string) as an argument. 

This <a href=ft_any.c>solution</a>:
- uses <code>i</code> and a <code>while</code> iterate through all the strings in <code>tab</code> (lines 17-23);
- applies function <code>f</code> to each string and checks whether the returned value from <code>f</code> is <code>0</code> (line 20). 
- if the returned value from <code>f</code> is <code>0</code>, we move onto the next string in <code>tab</code> (line 22);
- if the returned value is not <code>0</code>, <code>ft_any</code> returns <code>1</code> immediately (line 21). 
- If all of the returned values are <code>0</code>, <code>ft_any</code> returns <code>0</code> (24).

The key things of note here:
- the <code>while</code> loop condition - we have to iterate until we reach the null pointer that terminates the <code>tab</code> array.
- the function <code>f</code> now takes a string instead of an int as in the previous exercises 

</details>

