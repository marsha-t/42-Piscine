~write more about passing by reference with arrays~
## ft_putstr

|               ft_putstr        |
|---------------------------------|
| Turn-in directory : ex05/       |
| Files to turn in : ft_putstr.c |
| Allowed functions : write       |

- Create a function that displays a string of characters on the standard output.
- Here’s how it should be prototyped :
```
void ft_putstr(char *str);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>int	main(void)
{
	char	string[4] = "abc";

	ft_putstr(ptr);
	return (0);
} </pre></code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>abc</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

As this <a href=ft_putstr.c>exercise</a> shows, there are two ways to pass by reference in C. So far, we've used pointers but we can also use arrays. 

An array of characters in C is called a string and these are typically terminated with a null character. For instance, <code> char string[4] = "abc"</code> defines a string with 3 characters. That said, there are four character slots explicitly allocated to cater for the last null character (the null terminator, as it is typically called). This null terminator is automatically added when we put the characters within double quotes. 

When the array <code>string</code> is passed into <code>ft_putstr</code> (i.e., <code>ft_putstr(string)</code>), the <i>address</i> to the first element in the array was passed. Hence, this is another way of passing by reference. Arrays are always pass by reference in C. 

Within ft_putstr, we loop through every character of the array and display it, before moving onto the next one. Specifically, we define the while loop condition in line 17 such that it continues looping until it reaches the null terminator. This is why terminating arrays of characters with null characters are so useful!

<pre><code>15	void	ft_putstr(char *str)
16	{
17		while (*str != '\0')
18		{
19			write(1, str, 1);
20			str++;
21		}
22	}</code></pre>

To move onto the next character in the array, we use line 20 i.e., <code>str++</code>. By adding 1 to an address, we move to the adjacent address. By the end of the <code>ft_putstr</code> function, <code>str</code> would no longer point to the first element of the array but to the null terminator. This may be an issue for functions that return the string but not in this case where the <code>ft_putstr</code> function simply displays characters without returning. 

</details>
