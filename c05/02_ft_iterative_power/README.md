## ft_iterative_power

|               ft_iterative_power        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_iterative_power.c |
| Allowed functions : None       |

- Create an iterated function that returns the value of a power applied to a number.
- A power lower than 0 returns 0.
- Overflows must not be handled.
- We’ve decided that 0 power 0 will returns <code>1</code>
- Here’s how it should be prototyped :
```
int ft_iterative_power(int nb, int power);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	printf("2^2 %d\n", ft_iterative_power(2, 2));
	printf("1^1 %d\n", ft_iterative_power(1, 1));
	printf("3^1 %d\n", ft_iterative_power(3, 1));
	printf("1^0 %d\n", ft_iterative_power(1, 0));
	printf("1^-1 %d\n", ft_iterative_power(1, -1));
	printf("0^0 %d\n", ft_iterative_power(0, 0));
	printf("2500^2500 %d\n", ft_iterative_power(2500, 5));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>2^2 4
1^1 1
3^1 3
1^0 1
1^-1 0
0^0 1
2500^2500 -1957116928</code></pre>

The output for 2500 to the power of 2500 may look different for you depending on the value of <code>INT_MAX</code> (from the <code>limits.h</code> library) on your machine. 

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_iterative_power.c>function</a>:
- initialises <code>r</code> to <code>1</code>; 
- multiplies it by <code>nb</code> as many times as <code>power</code>.
- It also returns <code>0</code> when <code>power</code> is negative. 

</details>
