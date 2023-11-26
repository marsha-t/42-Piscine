## ft_putchar

|               ft_putchar        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_putchar.c |
| Allowed functions : write       |

- Write a function that displays the character passed as a parameter.
- It will be prototyped as follows:
```
void ft_putchar(char c);
```
- To display the character, you must use the write function as follows.
```
write(1, &c, 1);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>int	main(void)
{
	ft_putchar('a');
	ft_putchar('\n');
	ft_putchar('z');
	return (0);
}
</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>a
z</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

The <a href=ft_putchar.c>answer</a> is in the question.

</details>
