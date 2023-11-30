## ft_strlowcase

|               ft_strlowcase        |
|---------------------------------|
| Turn-in directory : ex08/       |
| Files to turn in : ft_strlowcase.c |
| Allowed functions : None       |

- Create a function that transforms every letter to lowercase.
- Here’s how it should be prototyped :
```
char *ft_strlowcase(char *str);
```
- It should return <code>str</code>.

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	str1[4] = "ABC";
	char	str2[4] = "aBc";
	char	str3[6] = "D 0 E";
	char	str4[1] = "";
	char	str5[1];

	ft_strlowcase(str1);
	ft_strlowcase(str2);
	ft_strlowcase(str3);
	ft_strlowcase(str4);
	ft_strlowcase(str5);
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

<pre><code>abc
abc
d 0 e

╚</code></pre>

The output for the last test using a null string may differ since it is undefined behaviour. 

</details>


<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_strlowcase.c>exercise</a> is very similar to the <a href=../07_ft_strupcase>previous exercise</a>. Now, the function looks for uppercase characters (line 20) and then converts them to lowercase ones (line 21). 

</details>
