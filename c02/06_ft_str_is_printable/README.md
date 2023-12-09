## ft_str_is_printable

|               ft_str_is_printable        |
|---------------------------------|
| Turn-in directory : ex06/       |
| Files to turn in : ft_str_is_printable.c |
| Allowed functions : None       |

- Create a function that returns <code>1</code> if the string given as a parameter contains only printable characters, and <code>0</code> if it contains any other character.
- Here’s how it should be prototyped :
```
int ft_str_is_printable(char *str);
```
- It should return <code>1</code> if <code>str</code> is empty.


<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	str1[4] = "abc";
	char	str2[4] = " ";
	char	str3[2] = "\t";
	char	str4[1] = "";
	char	str5[1];

	printf("%d\n", ft_str_is_printable(str1));
	printf("%d\n", ft_str_is_printable(str2));
	printf("%d\n", ft_str_is_printable(str3));
	printf("%d\n", ft_str_is_printable(str4));
	printf("%d\n", ft_str_is_printable(str5));
	return (0);
}</code></pre>

When working with strings, it's useful to also test with empty (<code>str4</code>) and null (<code>str5</code>) strings. Even though this may not be required by the task, it can be useful to understand what happens when you do apply the function you've written to an empty or null string. 

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>1
1
0
1
0</code></pre>

The output for the last test using a null string may differ since it is undefined behaviour. 

</details>

<details>
<summary><h3>Approach 1: Use <code>return</code> once</h3></summary>

This <a href=ft_str_is_printable_v1.c>approach</a> creates an integer variable <code>r</code> to hold the return value. This is to avoid using multiple <code>return</code> statements. 

The logic of this approach is very similar to Approach 1 for <a href=../02_ft_str_is_alpha>ft_str_is_alpha</a>. The only difference is adjusting the <code>if</code> statement to check for printable characters instead of alphabetical characters.

</details>

<details>
<summary><h3>Approach 2: Use <code>return</code> often</h3></summary>

This <a href=ft_str_is_printable_v2.c>approach</a> uses more return statements as well as a helper function. It has a very similar logic to Approach 2 for <a href=../02_ft_str_is_alpha>ft_str_is_alpha</a>. The only difference is adjusting the <code>if</code> statement to check for printable characters instead of alphabetical characters. This time, the helper function evaluates whether a character is a printable. 

</details>
