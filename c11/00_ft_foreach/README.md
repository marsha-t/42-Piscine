## ft_foreach

|               ft_foreach        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_foreach.c |
| Allowed functions : None       |

- Create the function <code>ft_foreach</code> which, for a given <code>int</code> array, applies a function on
all elements of the array. This function will be applied following the array’s order.
- Here’s how the function should be prototyped :
```
void ft_foreach(int *tab, int length, void(*f)(int));
```
- For example, the function <code>ft_foreach</code> could be called as follows in order to display all <code>int</code> of the array :
```
ft_foreach(tab, 1337, &ft_putnbr);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdlib.h&gt
#include &ltunistd.h&gt

void	ft_putchar(char c);
void	ft_putnbr(int nb);

void	ft_sq(int n)
{
	n = n * n;
	ft_putnbr(n);
	ft_putchar('\n');
}

int	main(void)
{
	int	*ptr;
	int	length;
	int	i;

	length = 5;
	ptr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		ptr[i] = i;
		i++;
	}
	ft_foreach(ptr, length, &ft_putnbr);
	ft_putchar('\n');
	ft_foreach(ptr, length, &ft_sq);
	return (0);
}
</code></pre>

To summarise the testing code, I've used function prototypes for <code>ft_putchar</code> and <code>ft_putnbr</code> but the full functions are included in the [main.c](main.c). 

Function pointers to <code>ft_putnbr</code> and <code>ft_sq</code> are used in the testing of <code>ft_foreach</code>:
- <code>ft_putnbr</code> displays <code>nb</code>; and
- <code>ft_sq</code> squares <code>n</code> and displays the squared number followed by a new line. 

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>01234
0
1
4
9
16</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

In C11, we start playing around with function pointers. Function pointers are indicated by putting brackets around the asterisk and the name of the function:
- <code>void *f(int)</code> is a function called <code>f</code> that returns a <code>void</code> pointer (and takes an <code>int</code> argument).
- <code>void (*f)(int)</code> is a pointer to a function that returns nothing (or <code>void</code>) (and takes an <code>int</code> argument)

For this <a href=ft_foreach.c>exercise</a>, we simply need to apply the function called <code>f</code> on the <code>int</code> in <code>tab</code>.

We use <code>i</code> and a <code>while</code> loop to iterate through the <code>int</code> in <code>tab</code>. Within the <code>while</code> loop, we call the <code>f</code> function as we would any other function: <code>f(tab[i])</code>. We just need to make sure that an <code>int</code> argument was fed into it.

</details>

