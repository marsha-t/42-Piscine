## ft_strcpy

|               ft_strcpy        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_strcpy.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>strcpy</code> (<code>man strcpy</code>).
- Here’s how it should be prototyped:
```
char *ft_strcpy(char *dest, char *src);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int	main(void)
{
	char	s[4] = "abc";
	char	d1[4] = "def";
	char	d2[4] = "def";
	char	d3[4];
	char	d4[4];

	printf("Before: s = %s, d1 = %s, d2 = %s\n", s, d1, d2);
	ft_strcpy(d1, s);
	printf("After ft_strcpy: s = %s, d1 = %s\n", s, d1);
	strcpy(d2, s);
	printf("After strcpy:    s = %s, d2 = %s\n", s, d2);
	printf("Before: s = %s, d3 = %s, d4 = %s\n", s, d3, d4);
	ft_strcpy(d3, s);
	printf("After ft_strcpy: s = %s, d3 = %s\n", s, d3);
	strcpy(d4, s);
	printf("After strcpy:    s = %s, d4 = %s\n", s, d4);
	return (0);
}</code></pre>

When reproducing other functions, it is useful to test whether the function works as you intended as well as compare the function's output with the original function. In this case, we compare <code>ft_strcpy</code> with <code>strcpy</code> - Sometimes, the function to be reproduced may produce output that was not described in the manual!

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Before: s = abc, d1 = def, d2 = def
After ft_strcpy: s = abc, d1 = abc
After strcpy:    s = abc, d2 = abc
Before: s = abc, d3 = ╚‼☺>abc, d4 =
After ft_strcpy: s = abc, d3 = abc
After strcpy:    s = abc, d4 = abc</code></pre>

Note that attempting to display the contents of <code>d3</code> and <code>d4</code> which were never initialised causes undefined behaviour. In this case, <code>╚‼lAabc</code> was displayed for <code>d3</code> and nothing for <code>d4</code> but a different set of characters may have appeared for you. What's important is that <code>d3</code> and <code>d4</code> change to <code>abc</code> after the use of <code>ft_strcpy</code> and <code>strcpy</code>.
</details>

<details>
<summary><h3>Approach</h3></summary>

The <a href=ft_strcpy.c>ft_strcpy</a> reproduces the behaviour of a function that already exists: <code>strcpy</code> in the <code>string.h</code> library copies the string <code>src</code> to <code>dest</code> and <i>returns</i> the <code>dest</code> string. The <code>strcpy</code> function does not check whether there is enough space in <code>dest</code> for the copied <code>src</code> string - This is left to the user to check that the size of <code>dest</code> is large enough so as to avoid undefined behaviour. 

To begin with, we declare a variable <code>i</code> to index the strings and use a <code>while</code> loop to loop through all the characters in <code>src</code> until we reach the null-terminator in the <code>src</code> string. Within the <code>while</code> loop, each character in <code>src</code> is copied into <code>dest</code> before moving onto the next character.

<pre><code>15	int	i;
16
17	i = 0;
18	while (src[i] != '\0')</code></pre>

You might be tempted to end the function there but we did not ensure that the <code>dest</code> string is null-terminated. In the <code>main</code> function, we use two <code>dest</code> strings. If we do not end the <code>dest</code> string in <code>ft_strcpy</code> with a null character, you'd find that <code>d1</code> would still be null-terminated while <code>d2</code> would not be. This is because <code>d1</code> originally had a null-terminator when it stored <code>"def"</code>. However, <code>d2</code> was never initialised and thus would not have a null-terminator. 

<pre><code>	char	d1[4] = "def";
	char	d2[4];</code></pre>

There's a simple fix: simply add <code>dest[i] = '\0'</code>. This works because after the <code>while</code> loop, the index <code>i</code> points to the allocated space after all the characters copied from <code>src</code>. 

In the final part of the function, we return the <code>dest</code> string. Note that this is not strictly necessary since we've already changed the characters in the <code>dest</code> string. This is why in the <code>main</code> function, we could change and display the <code>dest</code> string without assigning the result of <code>ft_strcpy</code> to a variable:

<pre><code>int main(void){
	...
	ft_strcpy(d1, s);
	printf("After:  s = %s, d1 = %s\n", s, 	d1);
}</code></pre>

Since <code>ft_strcpy</code> returns the <code>dest</code> string, we could also have tested the function by calling it within the <code>printf</code> function call:
<pre><code>int main(void){
	...
	printf("After:  s = %s, d1 = %s\n", s, ft_strcpy(d1, s));
}</code></pre>

Finally, we should return the pointer to the first element of <code>dest</code>. If we had moved the <code>dest</code> pointer while copying <code>src</code> to <code>dest</code> as follows, we will return a <code>dest</code> pointer that points to the null-terminator in the array.

<pre><code>char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}</code></pre>

The output will then differ depending on how we test. For instance, this testing code...

<pre><code>#include <stdio.h>
int	main(void)
{
	char	s[4] = "abc";
	char	d1[4] = "def";

	ft_strcpy(d1, s);
	printf("After:  s = %s, d1 = %s\n", s, 	ft_strcpy(d1, s));
	printf("After:  s = %s, d1 = %s\n", s, d1);
	return (0);
}</code></pre>

...will return this output:

<pre><code>After:  s = abc, d1 = 
After:  s = abc, d1 = abc</code></pre>

Testing with the return value (like in the first <code>printf</code> function call) displays nothing because the return value points at the null-terminator! However, <code>d1</code> will continue to the start of the array and hence, printing <code>d1</code> will display the copied <code>src</code> string.

</details>