## ft_strstr

|               ft_strstr        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_strstr.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>strstr</code> (<code>man strstr</code>).
- Here’s how it should be prototyped4
```
char *ft_strstr(char *str, char *to_find);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int	main(void)
{
    char	haystack[20] = "Point132  fd01";
	char	needle1[2] = "m";
	char	needle2[3] = "oi";
	char	needle3[2] = "1";
	char	needle4[2] = "0";

	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle1), strstr(haystack, needle1));
	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle2), strstr(haystack, needle2));
	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle3), strstr(haystack, needle3));
	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle4), strstr(haystack, needle4));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>result: ft_strstr: (null)
           strstr: (null)
result: ft_strstr: oint132  fd01
           strstr: oint132  fd01
result: ft_strstr: 132  fd01
           strstr: 132  fd01
result: ft_strstr: 01
           strstr: 01</code></pre>

</details>


<details>
<summary><h3>Approach</h3></summary>

<code>strstr</code> finds <code>to_find</code> in <code>str</code> and returns a pointer to that occurence in <code>str</code>. If there are multiple instances of <code>to_find</code> in <code>str</code>, the pointer to the first instance is returned. If <code>to_find</code> is not in <code>str</code>, <code>NULL</code> is returned. Finally, if <code>to_find</code> is an empty string, <code>str</code> is returned. 

This <a href=ft_strstr.c>solution</a>:
- returns str if <code>to_find</code> is an empty string (lines 18-19);
- loops through <code>str</code> (lines 20-31);
- returns a pointer to where the first instance of <code>to_find</code> in <code>str</code> if the whole of <code>to_find</code> can be found in <code>str</code> (lines 23-29); and
- returns null if <code>to_find</code> was not in <code>str</code> (line 32).

An empty string is one that contains only a null character i.e., the first character in the string is a null character. Hence, we can use <code>to_find[0] == '\0'</code> in line 18 to identify cases where <code>to_find</code> is an empty string. 

To find <code>to_find</code> in <code>str</code>, we loop through the characters in <code>str</code> until the character in <code>str</code> matches the character in <code>to_find</code>. Thereafter, we check that the subsequent characters in <code>to_find</code> also match the subsequent characters in <code>str</code>. If we are able to find all the characters in <code>to_find</code> until the null terminator, we return a pointer to the start of <code>to_find</code> that was found within <code>str</code>. 

If <code>to_find</code> is always of the same length, we could hardcode as many <code>if</code> statements as there are characters in <code>to_find</code> to check each character in <code>to_find</code>:

<pre><code>i = 0;
while (str[i] != '\0')
{
	if (str[i] == to_find[0])
	{
		if (str[i + 1] == to_find[1])
		{
			if (str[i + 2] == to_find[2])
			{
				...
				return (&str[i]);
	}
	i++;
}</code></pre>

Since we want to <i>loop</i> through as many <code>if</code> statements as there are characters in <code>to_find</code>, we can consider using a <code>while</code> loop!

<pre><code>i = 0;
while (str[i] != '\0')
{
	j = 0;
	while ((str[i + j] == to_find[j]) && (to_find[j] != '\0'))
	{
		if (to_find[j + 1] == '\0')
			return (&str[i]);
		j++;
	}
	i++;
}</code></pre>

We use another index variable <code>j</code> to loop through <code>to_find</code>. Using <code>i + j</code> to index <code>str</code> during this <code>while</code> loop (instead of incrementing <code>i</code> as well) is also helpful for us to later return a pointer to the start of <code>to_find</code> within <code>str</code>. 

</details>