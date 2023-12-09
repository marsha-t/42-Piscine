## ft_strjoin

|               ft_strjoin        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_strjoin.c |
| Allowed functions : malloc       |

- Write a function that will concatenate all the strings pointed by <code>strs</code> separated by <code>sep</code>.
- <code>size</code> is the number of strings in <code>strs</code>
- if <code>size</code> is 0, you must return an empty string that you can <code>free()</code>.
- Here’s how it should be prototyped :
```
char *ft_strjoin(int size, char **strs, char *sep);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt

int	main(void)
{
	char	*strs1[4] = {"abc def", "defd", "ghi00", "1 9 "};
	char	*s = ft_strjoin(4, strs1, ", ");
	printf("%s\n", s);
	char 	*t = ft_strjoin(0, strs1, ", ");
	printf("%s\n", t);

	char *strs2[1] = {"adf,"};
	char	*u = ft_strjoin(1, strs2, ", ");
	printf("%s\n", u);
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>abc def, defd, ghi00, 1 9 

adf,</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_strjoin.c>solution</a>:
- determines the size of the concatenated string using <code>ft_totlen</code> and allocates space for it using <code>malloc</code> (line 47);
- copies the strings from <code>strs</code> (character by character), followed by the <code>sep</code> string (also, character by character) (lines 50-64);
- null-terminates the concatenated string and returns it (lines 65-66). 
- In the case of <code>size == 0</code>, an empty string is returned (line 73-78). 

Note that the bulk of the concatenation is done via <code>ft_join</code> so that the function length of <code>ft_strjoin</code> remains under 25 lines. 

One of the key ingredients in determining the size of the concatenated string is the number of characters in the string. This is computed via <code>ft_totlen</code> which will account for the strings in <code>strs</code> as well as the <code>sep</code> string: 
- First, it loops through all the strings in <code>strs</code> to count each character in each string (lines 22-33). <code>count</code> will be the total number of characters across these strings. Note that the null terminator in each string is <u>not</u> counted. 
- Then it counts the number of characters in the <code>sep</code> string (lines 34-36). Here, <code>i</code> is reused and eventually holds the string length of <code>sep</code>.
- If there are <code>size</code> strings in <code>strs</code>, the concatenated string will have <code>size - 1</code> separators.
- Hence, the total length (computed in line 37) will be the sum of 
	- number of characters across the strings in <code>strs</code> (i.e., <code>count</code>) and
	- the length of <code>sep</code> multiplied by <code>(size - 1)</code>. 

Thereafter, the size of the concatenated string is simply the number of characters given by <code>ft_totlen</code> plus the null-terminator multiplied by the size of a character (<code>sizeof(char)</code>): <code>(ft_totlen(strs, size, sep) + 1) * sizeof(char)</code>. This is used in the <code>malloc</code> to allocate sufficient space for the concatenated string (line 47). As usual, if there are any issues allocating space, we return a null pointer (lines 48-49).

To fill up the concatenated string, 3 index variables will be used: <code>p</code> will be used to index the allocated space (and used in combination with <code>ptr</code>); <code>i</code> to index the strings in <code>strs</code> and <code>j</code> to index the characters in each string in <code>strs</code> as well as in <code>sep</code>. 3 <code>while</code> loops will also be used:
- the first loops through the strings in <code>strs</code>, starting from the first (<code>i = 0</code>) to the last (<code>i = size - 1</code>) (line 52). 
- for each string, <code>j</code> is initialised to <code>0</code> and used to access individual characters in the string. Each character is copied over to the space allocated by using <code>ptr</code> (lines 54-56)
- After copying each string, <code>sep</code> is copied over, provided that we have not copied over the last string in <code>strs</code> (if <code>i  < (size - 1)</code>). Here, <code>j</code> is reused to index <code>sep</code>.
- At the end of this process, the string is null-terminated and <code>ptr</code> (a pointer to the first character) returned (for <code>ft_strjoin</code> to return).

In the case of <code>size == 0</code>, an empty string that can be freed using <code>free()</code> should be returned. Given this requirement, an empty string is created using <code>malloc</code> (line 75). An empty string created as follows cannot be freed using <code>free()</code>:

<pre><code>char ptr[1];
ptr[0] = '\0';
return (ptr)</code></pre>

</details>

