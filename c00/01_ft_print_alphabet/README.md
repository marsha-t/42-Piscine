## ft_print_alphabet

|               ft_print_alphabet        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_print_alphabet.c |
| Allowed functions : write       |

- Create a function that displays the alphabet in lowercase, on a single line, by
ascending order, starting from the letter 'a'.
- Here’s how it should be prototyped:
```
void ft_print_alphabet(void);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code>int	main(void)
{
	ft_print_alphabet();
	return (0);
}
</pre></code>

See [testing file](main.c)

</details>
<details>
<summary><h3>Output</h3></summary>
<pre><code>abcdefghijklmnopqrstuvwxyz</code></pre>
</details>

<details>
<summary><h3>Approach 1: Copy everything into <code>write</code></h3></summary>
This <a href=ft_print_alphabet_v1.c>approach</a> simply puts everything that needs to be written into a single <code>write</code> command. It completes the task with very few lines. Just make sure the text is copied correctly and the number of characters to be printed correctly calibrated. 
</details>


<details>
<summary><h3>Approach 2: Use <code>while</code> loops</h3></summary>
This <a href=ft_print_alphabet_v2.c>approach</a> uses <code>while</code> loops (and more lines of code) to achieve the same. In particular, it uses increment to achieve ascending order.

Note that even though the <code>write</code> function was used for each character, there's no separator between each printed character. For instance, there isn't a space or a new line in between each character such that eventually, all the characters are printed in a single line together.

We can also use ASCII values in the code
<pre><code>...
x = 97;
while (x <= 122)
...</code></pre>
</details>
