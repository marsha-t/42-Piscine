## ft_strlen

|               ft_strlen        |
|---------------------------------|
| Turn-in directory : ex06/       |
| Files to turn in : ft_strlen.c |
| Allowed functions : None       |

- Create a function that counts and returns the number of characters in a string.
- Here’s how it should be prototyped :
```
int ft_strlen(char *str);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	string[4] = "abc";

	printf("%d", ft_strlen(string));
	return (0);
}</pre></code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>3</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

Similar to the previous <a href=../05_ft_putstr>exercise</a>, this <a href=ft_strlen.c>exercise</a> makes use of the fact that strings are null-terminated.

To keep count of the number of characters, we use an integer <code>i</code> initialised at 0. As we loop through each character in the string, we add 1 to <code>i</code>. By the end of the string, we return <code>i</code>. 

The function also offers a different way to loop through the elements of an array i.e., by using an index, rather than direct changing the address pointer. Unlike <a href=../05_ft_putstr>ft_putstr</a>, at the end of <code>ft_strlen</code>, <code>str</code> will continue to point to the first element in the array.

</details>
