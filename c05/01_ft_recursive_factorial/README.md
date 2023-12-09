## ft_recursive_factorial

|               ft_recursive_factorial        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_recursive_factorial.c |
| Allowed functions : None       |

- Create a recursive function that returns the factorial of the number given as a parameter.
- If the argument is not valid the function should return 0.
- Overflows must not be handled, the function return will be undefined.
- Here’s how it should be prototyped :
```
int ft_recursive_factorial(int nb);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	printf("3!: %d\n", ft_recursive_factorial(3));
	printf("2!: %d\n", ft_recursive_factorial(2));
	printf("1!: %d\n", ft_recursive_factorial(1));
	printf("0!: %d\n", ft_recursive_factorial(0));
	printf("-2!: %d\n", ft_recursive_factorial(-2));
	printf("11!: %d\n", ft_recursive_factorial(11));
	printf("12!: %d\n", ft_recursive_factorial(12));
	printf("13!: %d\n", ft_recursive_factorial(13));
	printf("14!: %d\n", ft_recursive_factorial(14));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>3!: 6
2!: 2
1!: 1
0!: 1
-2!: 0
11!: 39916800
12!: 479001600
13!: 1932053504
14!: 1278945280</code></pre>

The output for 14! may look different for you depending on the value of <code>INT_MAX</code> (from the <code>limits.h</code> library) on your machine. 

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_recursive_factorial.c>solution</a> uses recursion and does away with the <code>while</code> loop in the previous <a href=../00_ft_iterative_factorial>exercise</a>. 

The key to applying recursion here is recognising that a factorial of a given nnumber can be expressed as a factorial of smaller numbers. For instance, <code>nb!</code> (aka factorial of <code>nb</code>) is <code>nb * (nb - 1)!</code> which is, in turn, <code>nb * (nb - 1) * (nb - 2)!</code>. This leads directly to line 21:

<pre><code>21	r = nb * ft_recursive_factorial(nb - 1)</code></pre>

Let's run through a case of <code>nb = 2</code>:
- In running <code>ft_recursive_factorial(2)</code>, we get to line 21 where <code>r = 2 * ft_recursive_factorial(1)</code>;
- In running <code>ft_recursive_factorial(1)</code>, we get <code>r = 1 * ft_recursive_factorial(0)</code>
- In <code>ft_recursive_factorial(0)</code>, the initialised value of <code>r</code> (i.e., <code>r = 1</code>) is returned directly. Note that the commands in the <code>if</code> and <code>else if</code> statements are not executed. 
- Put it altogether: <code>r = 2 * 1 * 1</code> and eventually <code>ft_recursive_factorial(2)</code> returns <code>2</code>! (heh, literally).

</details>
