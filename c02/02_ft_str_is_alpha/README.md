## ft_str_is_alpha

|               ft_str_is_alpha        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_str_is_alpha.c |
| Allowed functions : None       |

- Create a function that returns <code>1</code> if the string given as a parameter contains only alphabetical characters, and <code>0</code> if it contains any other character.
- Here’s how it should be prototyped :
```
int ft_str_is_alpha(char *str);
```
- It should return <code>1</code> if <code>str</code> is empty.

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	str1[4] = "abc";
	char	str2[4] = "de0";
	char	str3[4] = "123";
	char	str4[1] = "";
	char	str5[1];

	printf("%d\n", ft_str_is_alpha(str1));
	printf("%d\n", ft_str_is_alpha(str2));
	printf("%d\n", ft_str_is_alpha(str3));
	printf("%d\n", ft_str_is_alpha(str4));
	printf("%d\n", ft_str_is_alpha(str5));
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
1</code></pre>

The output for the last test using a null string may differ since it is undefined behaviour. 

</details>

<details>
<summary><h3>Approach 1: Use <code>return</code> once</h3></summary>

This <a href=ft_str_is_alpha_v1.c>approach</a> creates an integer variable <code>r</code> to hold the return value. It is initialised at <code>1</code> and is changed to <code>0</code> whenever there is a non-alphabetical character. At the end of the function, <code>r</code> is returned.  

Note that the <code>while</code> loop is set up to go through all the characters in a string <i>as long as</i> <code>r</code> remains 1: the commands within the loop are executed at the start (right after <code>r</code> is initialised) and when the characters encountered so far are alphabetical. As soon as a non-alphabetical character is encountered, <code>r</code> is converted to <code>0</code> and the <code>while</code> loop is exited.

<pre><code>20	while ((str[i] != '\0') && (r == 1))
21	{
		...
25		else
26			r = 0;</code></pre>

Alternatively, a <code>break</code> statement could have been used to exit the <code>while</code> loop:

<pre><code>while (str[i] != '\0')
{
	...
	else
	{
		r = 0;
		break;
	}</code></pre>

It is worth thinking through how the code will work with empty and null strings:
- For an empty string, the <code>while</code> loop would be skipped since the first character is a null character. The function will return <code>1</code>, the value <code>r</code> was initialised with. 
- Meanwhile, a null string has no values since it has not been assigned any elements, not even a null character. Here, we attempt to access an element in a string that has no elements, and thus end up invoking undefined behaviour. Using <code>printf</code>, we can see what undefined behaviour does occur when we pass a null string into <code>ft_str_is_alpha</code>. As I want to see both the ASCII number and the character symbol for that number, I've passed in two format specifications (<code>%d</code> for the number and <code>%c</code> for the character symbol) into <code>printf</code>. 

<pre><code>while ((str[i] != '\0') && (r == 1))
{
	printf("%d, %c\n", str[i], str[i]);</code></pre>

Across repeated runs of the same code, I've obtained different output when testing the null string. Some of these would've given me a return value of 0 while others would've given me a return value of 1. 

<pre><code>-106, û
113, q
-53, ╦
32, </code></pre>

When I first started coding in C, I found it easier to work with fewer <code>return</code> statements since I found this behaviour quite drastic and resulted in many functions terminating much earlier than I had intended. Using an integer to hold the return value and then using only one return value at the end of the function was less error-prone for me. That said, as I became more comfortable articulating with logic statements, I found the <a href=ft_str_is_alpha_v2.c>second approach</a> more intuitive.

</details>

<details>
<summary><h3>Approach 2: Use <code>return</code> often</h3></summary>

Even though this <a href=ft_str_is_alpha_v2.c>approach</a> continues to define a <code>while</code> loop to go through every character in the string, it <i>returns</i> 0 as soon as a non-alphabetical character is found.

<pre><code>27	while (str[i] != '\0')
28	{
29		if (ft_c_is_alpha(str[i]) == 0)
30			return (0);</code></pre>

For better legibility, a helper function <code>ft_c_is_alpha</code> is created to replace the need for a long <code>if</code> statement. ft_c_is_alpha evaluates whether a character is alphabetical. Without it, the if statement would look as follows:

<pre><code>if ((str[i] < 'A') || ((str[i] > 'Z') && (str[i] < 'a')) || (str[i] > 'z'))</code></pre>

</details>
