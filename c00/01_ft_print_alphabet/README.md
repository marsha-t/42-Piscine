
## Objective
- Create a function that displays the alphabet in lowercase, on a single line, by
ascending order, starting from the letter 'a'.
- Here’s how it should be prototyped:
```
void ft_print_alphabet(void);
```

## Testing 
```
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
```
See [testing file](main.c)
## Output
```
abcdefghijklmnopqrstuvwxyz
```
## Approach(es)

<details open>
<summary><h3><b>Approach 1: Copy everything into <code>write</code></b></h3></summary>
This <a href=ft_print_alphabet_v1.c>approach</a> simply puts everything that needs to be written into a single `write()` command. It completes the task with very few lines. Just make sure the text is copied correctly and the number of characters to be printed correctly calibrated. 
</details>


<details open>
<summary><h3><b>Approach 2: Use <code>while</code> loops</b></h3></summary>
This   <a href=ft_print_alphabet_v2.c>approach</a> uses `while` loops (and more lines of code) to achieve the same.
</details>
