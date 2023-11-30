## ft_strncpy

|               ft_strncpy        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_strncpy.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>ft_strncpy</code> (<code>man ft_strncpy</code>).
- Here’s how it should be prototyped:
```
char *ft_strncpy(char *dest, char *src, unsigned int n);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt

int	main(void)
{
	char	s[10] = "123456789";
	char	d1[10] = "abc";
	char	d1_2[10] = "abc";
	char	d2[10] = "";
	char	d2_2[15] = "";
	char	d3[15] = "";
	char	d3_2[15] = "";
	char	d4[10] = "";
	char	d4_2[10] = "";
	char	d5[4] = "";
	char	d5_2[4] = "";
	
	printf("Before: s = %s, d1 = %s\n", s, d1);
	ft_strncpy(d1, s, 10);
	printf("After ft_strncpy: s = %s, d1 = %s\n", s, d1);
	strncpy(d1_2, s, 10);
	printf("After strncpy: 	  s = %s, d1 = %s\n", s, d1_2);
	printf("Before: s = %s, d2 = %s\n", s, d2);
	ft_strncpy(d2, s, 5);
	printf("After ft_strncpy: s = %s, d2 = %s\n", s, d2);
	strncpy(d2_2, s, 5);
	printf("After strncpy:    s = %s, d2 = %s\n", s, d2_2);
	printf("Before: s = %s, d3 = %s\n", s, d3);
	ft_strncpy(d3, s, 15);
	printf("After ft_strncpy: s = %s, d3 = %s\n", s, d3);
	strncpy(d3_2, s, 15);
	printf("After strncpy:    s = %s, d3 = %s\n", s, d3_2);
	printf("Before: s = %s, d4 = %s\n", s, d4);
	ft_strncpy(d4, s, 5);
	printf("After ft_strncpy: s = %s, d4 = %s\n", s, d4);
	strncpy(d4_2, s, 5);
	printf("After strncpy:    s = %s, d4 = %s\n", s, d4_2);
	printf("Before: s = %s, d5 = %s\n", s, d5);
	ft_strncpy(d5, s, 5);
	printf("After ft_strncpy: s = %s, d5 = %s\n", s, d5);
	strncpy(d5_2, s, 5);
	printf("After strncpy:     s = %s, d5 = %s\n", s, d5_2);
	return (0);
}</code></pre>

We test the cases where 
- <code>n</code> is the same length as <code>src</code> (including the null terminator);
- <code>n</code> is smaller than the length of <code>src</code>; and
- <code>n</code> is greater than the length of <code>src</code>.
Finally, where <code>n</code> is smaller than the length of <code>src</code>, we also test cases where
- the size of <code>dest</code> is bigger than <code>n</code>; and
- the size of <code>dest</code> is smaller than <code>n</code>.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

There may be an error messge when you attempt to run 
<pre><code>strncpy(d5_2, s, 5);
printf("After strncpy:     s = %s, d5 = %s\n", s, d5_2);</code></pre>

This is because strncpy is '5 bytes into a region of size 4 overflows the destination'. The following output was generated after commenting out these two lines of code. 

<pre><code>Before: s = 123456789, d1 = abc
After ft_strncpy: s = 123456789, d1 = 123456789
After strncpy:    s = 123456789, d1 = 123456789
Before: s = 123456789, d2 =
After ft_strncpy: s = 123456789, d2 = 12345
After strncpy:    s = 123456789, d2 = 12345
Before: s = 123456789, d3 =
After ft_strncpy: s = 123456789, d3 = 123456789
After strncpy:    s = 123456789, d3 = 123456789
Before: s = 123456789, d4 =
After ft_strncpy: s = 123456789, d4 = 12345
After strncpy:    s = 123456789, d4 = 12345
Before: s = 123456789, d5 =
After ft_strncpy: s = 123456789, d5 = 123452345</code></pre>

The output may look different for you for last case where <code>n</code> is smaller than the length of <code>src</code> <i>and</i> the size of <code>dest</code> is smaller than <code>n</code>. 

</details>


<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_strncpy.c>exercise</a> reproduces the <code>strncpy</code> function, which is an improvement over <code>strcpy</code> and <a href=../00_ft_strcpy>ft_strcpy</a> (though not by much). Instead of copying the whole <code>src</code> string, the user can define how many characters to copy over to <code>dest</code>. There are also some issues with strncpy that the user should be aware of:

- If <code>n</code> is less than the length of <code>src</code> (i.e, there is no null terminator among the <code>n</code> characters in <code>src</code>), the <code>dest</code> string won't be null-terminated.

- If <code>n</code> is greater than the length of <code>src</code>, <code>strncpy</code> will write additional null characters to <code>dest</code> (aka pad the <code>dest</code> string with null characters) so that <code>n</code> characters are still written overall.

The main part of <code>ft_strncpy</code> looks similar to <a href=../00_ft_strcpy>ft_strcpy</a> since it still has to copy <code>src</code> over to <code>dest</code>. The key difference is that only up to <code>n</code> characters are copied. This is reflected in the additional <code>while</code> loop condition of <code>i < n</code>.

<pre><code>17	i = 0;
18	while ((src[i] != '\0') && (i < n))
19	{
20		dest[i] = src[i];
21		i++;
22	}</code></pre>

Where <code>n</code> is greater than the length of <code>src</code>, the dest string is padded with additional null characters. This is accomplished with the following code:

<pre><code>23	while (i < n)
24		dest[i++] = '\0';</code></pre>

Finally, we return dest. This points at the first element of the dest string since we used <code>i</code> to refer to elements in the strings (instead of shifting the pointers).

Notice that when <code>n</code> is smaller than the length of <code>src</code>, the first <code>while</code> will stop because of its second condition <code>(i < n)</code>. The second while loop will be skipped entirely. As a result, there will be no null characters in the <code>dest</code> string.
<pre><code>18	while ((src[i] != '\0') && (i < n))
	...
23	while (i < n)
	...
</code></pre>

Omitting the null terminator can be problematic since functions may assume the presence of a null terminator when working with strings. For instance, when we tested the case where <code>n</code> is smaller than the length of <code>src</code> <i>and</i> the size of <code>dest</code> is smaller than <code>n</code>...

<pre><code>char	s[10] = "123456789";
char	d5[4] = "";
ft_strncpy(d5, s, 5);
printf("After:  s = %s, d5 = %s\n", s, d5);
</code></pre>

...we obtained some surprising output:

<pre><code>After:  s = 123456789, d5 = 123452345</code></pre>

The first 5 characters of <code>s</code> were copied into <code>d5</code> but it was not null terminated. When <code>d5</code> was passed as an argument into <code>printf</code>, the function proceeded to access memory that is outside the bounds of <code>d5</code> (which has only a memory of 4). The actual output may be different depending on what is stored adjacent to <code>d5</code>. 

Meanwhile, <code>strcpy</code> (at least for me) throws an error message when it realises that <code>n</code> is greater than the capacity of <code>dest</code>. It appears that reproducing error messages as <code>strcpy</code> does is beyond the scope of C02 since Moulinette OK'd this solution. 

</details>
