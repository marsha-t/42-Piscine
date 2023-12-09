## ft_recursive_power

|               ft_recursive_power        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_recursive_power.c |
| Allowed functions : None       |

- Create a recursive function that returns the value of a power applied to a number.
- A power lower than 0 returns 0.
- Overflows must not be handled, the function return will be undefined.
- We’ve decided that 0 power 0 will returns <code>1</code>
- Here’s how it should be prototyped :
```
int ft_recursive_power(int nb, int power);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	printf("2^2 %d\n", ft_recursive_power(2, 2));
	printf("1^1 %d\n", ft_recursive_power(1, 1));
	printf("3^1 %d\n", ft_recursive_power(3, 1));
	printf("1^0 %d\n", ft_recursive_power(1, 0));
	printf("1^-1 %d\n", ft_recursive_power(1, -1));
	printf("0^0 %d\n", ft_recursive_power(0, 0));
	printf("2500^2500 %d\n", ft_recursive_power(2500, 5));
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

This <a href=ft_recursive_power.c>solution</a> replaces the <code>while</code> loop with recursion. Similar to <a href=../01_ft_recursive_factorial>ft_recursive_factorial</a>, the key to applying recursion is recognising that the value to be returned can be decomposed: <code>nb^power</code> (<code>nb</code> to the power of <code>power</code>) is equivalent to <code>nb * nb^(power - 1)</code>:

<pre><code>21	r = nb * ft_recursive_power(nb, power - 1);</code></pre>
 
Let's try <code>ft_recursive_power(2, 2)</code> 
- <code>ft_recursive_power(2, 2)</code> leads to <code>r = 2 * ft_recursive_power(2, 1)</code>
- <code>ft_recursive_power(2, 1)</code> in turn leads to <code>r = 2 * ft_recursive_power(2, 0)</code>. 
- Finally, <code>ft_recursive_power(2, 0)</code> returns <code>1</code>, the initialised value of <code>r</code>.
- With everything combined: <code>r = 2 * 2 * 1</code> such that <code>ft_recursive_power(2, 2)</code> returns <code>4</code>. Yay!

</details>
