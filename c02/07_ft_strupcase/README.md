## ft_strupcase

|               ft_strupcase        |
|---------------------------------|
| Turn-in directory : ex07/       |
| Files to turn in : ft_strupcase.c |
| Allowed functions : None       |

- Create a function that transforms every letter to uppercase.
- Here’s how it should be prototyped :
```
char *ft_strupcase(char *str);
```
- It should return <code>str</code>.


<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	str1[4] = "abc";
	char	str2[4] = "AbC";
	char	str3[6] = "d 0 e";
	char	str4[1] = "";
	char	str5[1];

	ft_strupcase(str1);
	ft_strupcase(str2);
	ft_strupcase(str3);
	ft_strupcase(str4);
	ft_strupcase(str5);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	printf("%s\n", str5);
	return (0);
}</code></pre>

When working with strings, it's useful to also test with empty (<code>str4</code>) and null (<code>str5</code>) strings. Even though this may not be required by the task, it can be useful to understand what happens when you do apply the function you've written to an empty or null string. 

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>ABC
ABC
D 0 E

╚</code></pre>

The output for the last test using a null string may differ since it is undefined behaviour. 

</details>


<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_strupcase.c>exercise</a> builds upon the previous exercises: 
- The <code>ft_strupcase</code> function will loop through each character in the string, ...

<pre><code>18	while (str[i] != '\0')</code></pre>

- Identify lowercase characters (similar to <a href=../04_ft_str_is_lowercase>ft_str_is_lowercase</a>), ...

<pre><code>20	if ((str[i] >= 'a') && (str[i] <= 'z'))</code></pre>

- Convert them to uppercase characters...

<pre><code>21	str[i] = str[i] - ('a' - 'A');</code></pre>

- Before returning the entire string

<pre><code>	return (str);</code></pre>

Note that when converting the characters, <code>('a' - 'A')</code> was used. This is equivalent to deducting 32 from the ASCII values. Using <code>('a' - 'A')</code> will be more portable to machines that do not use ASCII values. 

Also, as with <a href=../00_ft_strcpy>ft_strcpy</a> and <a href=../01_ft_strncpy>ft_strncpy</a>, the return of the string is not strictly necessary since the characters in <code>str</code> have already been changed to uppercase (where appropriate). That said, because the string was returned, the function could also be tested as follows:

<pre><code>printf("%s\n", ft_strupcase(str1));</code></pre>

As before, we should also be mindful to not shift the address that <code>str</code> points to when capitalising characters. This is why an indexing variable <code>i</code> was used to refer to the elements in the <code>str</code> (using <code>str[i]</code>) rather than <code>*str</code>.

Finally, we note that nothing is converted and undefined behaviour occurs when an empty string and a null string are passed respectively into <code>ft_strupcase</code>.

</details>
