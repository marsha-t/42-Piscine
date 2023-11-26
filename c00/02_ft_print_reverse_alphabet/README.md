## ft_print_reverse_alphabet

|               ft_print_reverse_alphabet        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_print_reverse_alphabet.c |
| Allowed functions : write       |

- Create a function that displays the alphabet in lowercase, on a single line, by
descending order, starting from the letter 'z'.
- Here’s how it should be prototyped:
```
void ft_print_reverse_alphabet(void);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code>int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
</pre></code>

See [testing file](main.c)
</details>

<details>
<summary><h3>Output</h3></summary>
<pre><code>zyxwvutsrqponmlkjihgfedcba</code></pre>
</details>

<details>
<summary><h3>Approach 1: Copy everything into <code>write</code></h3></summary>
This <a href=ft_print_reverse_alphabet_v1.c>approach</a> simply puts everything that needs to be written into a single <code>write</code> command. It completes the task with very few lines. Just make sure the text is copied correctly and the number of characters to be printed correctly calibrated. 
</details>


<details>
<summary><h3>Approach 2: Use <code>while</code> loops</h3></summary>
This <a href=ft_print_reverse_alphabet_v2.c>approach</a> uses <code>while</code> loops (and more lines of code) to achieve the same. This time, the loop uses decrement to achieve descending order and the condition in the <code>while</code> loop will need to be adapted accordingly

We can also use ASCII values in the code
<pre><code>...
x = 122;
while (x >= 97)
...</code></pre>
</details>
