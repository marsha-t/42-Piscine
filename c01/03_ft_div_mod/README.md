## ft_div_mod

|               ft_div_mod        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_div_mod.c |
| Allowed functions : None       |

- Create a function <code>ft_div_mod</code> prototyped like this:
```
void ft_div_mod(int a, int b, int *div, int *mod);
```
- This function divides parameters <code>a</code> by <code>b</code> and stores the result in the <code>int</code> pointed by <code>div</code>. It also stores the remainder of the division of <code>a</code> by <code>b</code> in the <code>int</code> pointed by <code>mod</code>

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	div;
	int	mod;

	ft_div_mod(10, 3, &div, &mod);
	printf("div: %d\n", div);
	printf("mod: %d\n", mod);
	return (0);
} </pre></code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>div: 3
mod: 1</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

Even though the <code>ft_div_mod</code> function in this <a href=ft_div_mod.c>exercise</a> does not return any value, it is able to return the results of division and modulus back to the <code>main</code> function due to the use of pointers. 

Specifically, in the <code>main</code> function, <code>div</code> and <code>mod</code> are declared and their addresses passed into <code>ft_div_mod</code>. Within <code>ft_div_mod</code>, we simply have to make sure that the results of division and modulus are passed to the values of the <code>div</code> and <code>mod</code> pointers. We are able to 'return' two integers even though this function is declared to not return anything at all!

One thing to take note of here is the case where the divisor is 0. In such cases, the result is undefined, hence we should only run the <code>ft_div_mod</code> function in cases where the divisor is not 0. This is taken care of with an <code>if</code> statement: <code>if (b != 0)</code>. 

</details>
