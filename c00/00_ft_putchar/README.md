## Objective

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

## Testing
```
int	main(void)
{
	ft_putchar('a');
	ft_putchar('\n');
	ft_putchar('z');
	return (0);
}
```
See [testing file](main.c)
## Output
```
a
z
```
## Approach

<details open>
<summary><h3><b>Approach</b></h3></summary>
The <a href=ft_putchar.c>answer</a> is in the question.
</details>
