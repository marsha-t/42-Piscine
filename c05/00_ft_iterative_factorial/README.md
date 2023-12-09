## ft_iterative_factorial

|               ft_iterative_factorial        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_iterative_factorial.c |
| Allowed functions : None       |

- Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.
- If the argument is not valid the function should return 0.
- Overflows must not be handled, the function return will be undefined.
- Here’s how it should be prototyped :
```
int ft_iterative_factorial(int nb);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	printf("3!: %d\n", ft_iterative_factorial(3));
	printf("2!: %d\n", ft_iterative_factorial(2));
	printf("1!: %d\n", ft_iterative_factorial(1));
	printf("0!: %d\n", ft_iterative_factorial(0));
	printf("-2!: %d\n", ft_iterative_factorial(-2));
	printf("11!: %d\n", ft_iterative_factorial(11));
	printf("12!: %d\n", ft_iterative_factorial(12));
	printf("13!: %d\n", ft_iterative_factorial(13));
	printf("14!: %d\n", ft_iterative_factorial(14));
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

This <a href=ft_iterative_factorial.c> function</a>:
- initialises <code>r</code> to <code>1</code>; and
- multiplies it with <code>nb</code> with <code>nb - 1</code>, <code>nb - 2</code>, ... etc using a <code>while</code> loop. 
- This is done until <code>nb</code> reaches 1 (or <code>nb > 0</code> as used in the line 20). 

Oh, and remember to cater for invalid arguments (i.e., <code>nb < 0</code>)! In such cases, the function will simply return <code>0</code> (line 18).

</details>
