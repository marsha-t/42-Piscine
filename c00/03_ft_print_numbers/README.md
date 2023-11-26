## ft_print_numbers

|               ft_print_numbers        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_print_numbers.c |
| Allowed functions : write       |

- Create a function that displays all digits, on a single line, by
ascending order.
- Here’s how it should be prototyped:
```
void ft_print_numbers(void);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code>int	main(void)
{
	ft_print_numbers();
	return (0);
}
</pre></code>

See [testing file](main.c)
</details>

<details>
<summary><h3>Output</h3></summary>
<pre><code>0123456789</code></pre>
</details>

<details>
<summary><h3>Approach 1: Copy everything into <code>write</code></h3></summary>
This <a href=ft_print_numbers_v1.c>approach</a> simply puts everything that needs to be written into a single <code>write</code> command. It completes the task with very few lines. Just make sure the text is copied correctly and the number of characters to be printed correctly calibrated. 
</details>


<details>
<summary><h3>Approach 2: Use <code>while</code> loops</h3></summary>
This <a href=ft_print_numbers_v2.c>approach</a> uses <code>while</code> loops (and more lines of code) to achieve the same. Even though we are dealing with digits, we continue to put the digits in quotes to refer to these characters. 
Alternatively, we can use ASCII values like so:
<pre><code>...
x = 48; 
while (x <= 57)
...</code></pre>
</details>
