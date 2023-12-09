## ft_str_is_lowercase

|               ft_str_is_lowercase        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_str_is_lowercase.c |
| Allowed functions : None       |

- Create a function that returns <code>1</code> if the string given as a parameter contains only lowercase alphabetical characters, and <code>0</code> if it contains any other character.
- Here’s how it should be prototyped :
```
int ft_str_is_lowercase(char *str);
```
- It should return <code>1</code> if <code>str</code> is empty.

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	str1[4] = "abc";
	char	str2[4] = "de0";
	char	str3[4] = "ABC";
	char	str4[1] = "";
	char	str5[1];

	printf("%d\n", ft_str_is_lowercase(str1));
	printf("%d\n", ft_str_is_lowercase(str2));
	printf("%d\n", ft_str_is_lowercase(str3));
	printf("%d\n", ft_str_is_lowercase(str4));
	printf("%d\n", ft_str_is_lowercase(str5));
	return (0);
}</code></pre>

When working with strings, it's useful to also test with empty (<code>str4</code>) and null (<code>str5</code>) strings. Even though this may not be required by the task, it can be useful to understand what happens when you do apply the function you've written to an empty or null string. 

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>1
0
0
1
0</code></pre>

The output for the last test using a null string may differ since it is undefined behaviour. 

</details>

<details>
<summary><h3>Approach 1: Use <code>return</code> once</h3></summary>

This <a href=ft_str_is_lowercase_v1.c>approach</a> creates an integer variable <code>r</code> to hold the return value. This is to avoid using multiple <code>return</code> statements. 

The logic of this approach is very similar to Approach 1 for <a href=../02_ft_str_is_alpha>ft_str_is_alpha</a>. The only difference is adjusting the <code>if</code> statement to check for lowercase alphabetical instead of all alphabetical characters.

</details>

<details>
<summary><h3>Approach 2: Use <code>return</code> often</h3></summary>

This <a href=ft_str_is_lowercase_v2.c>approach</a> uses more return statements as well as a helper function. It has a very similar logic to Approach 2 for <a href=../02_ft_str_is_alpha>ft_str_is_alpha</a>. The only difference is adjusting the <code>if</code> statement to check for lowercase alphabetical instead of all alphabetical characters. This time, the helper function evaluates whether a character is alphabetical and lowercase. 

</details>
