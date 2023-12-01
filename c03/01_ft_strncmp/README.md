## ft_strncmp

|               ft_strncmp        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_strncmp.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>strncmp</code> (<code>man strncmp</code>).
- Here’s how it should be prototyped:
```
int ft_strncmp(char *s1, char *s2, unsigned int n);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int	main(void)
{
	char    str1[] = "abcde";
    char    str2[] = "ab";
    char    str3[] = "Abcd";
    char    str4[] = "0d";
    char    str5[] = "\ns";
    char    str6[] = " s";
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str1, 4));
    printf("strncmp:    %d\n", strncmp(str1, str1, 4));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 2));
    printf("strncmp:    %d\n", strncmp(str1, str2, 2));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 3));
    printf("strncmp:    %d\n", strncmp(str1, str2, 3));
    printf("ft_strncmp: %d\n", ft_strncmp(str3, str1, 6));
    printf("strncmp:    %d\n", strncmp(str3, str1, 6));
    printf("ft_strncmp: %d\n", ft_strncmp(str2, str3, 0));
    printf("strncmp:    %d\n", strncmp(str2, str3, 0));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str1, 10));
    printf("strncmp:    %d\n", strncmp(str1, str1, 10));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str4, 1));
    printf("strncmp:    %d\n", strncmp(str1, str4, 1));
    printf("ft_strncmp: %d\n", ft_strncmp(str2, str5, 2));
    printf("strncmp:    %d\n", strncmp(str2, str5, 2));
    printf("ft_strncmp: %d\n", ft_strncmp(str5, str4, 3));
    printf("strncmp:    %d\n", strncmp(str5, str4, 3));
    printf("ft_strncmp: %d\n", ft_strncmp(str5, str6, 1));
    printf("strncmp:    %d\n", strncmp(str5, str6, 1));
    return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>ft_strncmp: 0
strncmp:    0
ft_strncmp: 0
strncmp:    0
ft_strncmp: 99
strncmp:    99
ft_strncmp: -32
strncmp:    -32
ft_strncmp: 0
strncmp:    0
ft_strncmp: 0
strncmp:    0
ft_strncmp: 49
strncmp:    49
ft_strncmp: 87
strncmp:    87
ft_strncmp: -38
strncmp:    -38
ft_strncmp: -22
strncmp:    -22</code></pre>

As with <code>strcmp</code>, output for <code>strncmp</code> may differ: some implementations may give output of -1, 1 and 0 only. 

</details>

<details>
<summary><h3>Approach</h3></summary>

<code>strncmp</code> is similar to <code>strcmp</code> except that it compares up to n characters of <code>s1</code> and <code>s2</code>. 

This <a href=ft_strncmp.c>solution</a> is hence very similar to <a href=../00_ft_strcmp>ft_strcmp</a>. The key differences are
- adjusting the comparison of characters in the strings to only go up to n characters; and 
- catering for unconventional/unreasonable values of n. 

To adjust for <code>n</code>, we add yet another condition into the <code>while</code> loop: <code>i < n - 1</code>. Note that <code>i</code> will only go up to <code>n - 2</code>. We woudl typically use i < n to account for the fact that the indices start at 0. Here, we have to reduce the number of loops further by 1 because after the <code>while</code> loop, there will be one more comparison of characters between <code>s1</code> and <code>s2</code> in the <code>return</code> statement. To account for this, we use <code>i < n - 1</code>.

If we had used <code>i < n</code> like in the code below and wanted to compare the first character in <code>s1</code> which is initialised to <code>"ab"</code> and <code>s2</code> which is initialised to <code>"ac"</code>. Since the first character in both strings is <code>'a'</code>, we'd expect a return value of <code>0</code>. Let's see what happens in the code:
- When <code>i == 0</code>, all the conditions in the <code>while</code> loop are met so the command within the <code>while</code> loop is executed i.e., <code>i</code> is incremented to <code>1</code>.
- When <code>i == 1</code>, <code>s1[i] != s2[i]</code> and <code>i == n</code> i.e., the conditions in the <code>while</code> loop are no longer met. Hence, we exit the <code>while</code> loop.
- We return the difference between s1[1] - s2[1] i.e., the difference between <code>'b'</code> and <code>'c'</code>, which is <code>-1</code>. 

<pre><code>while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n))
	i++; 
return (s1[i] - s2[i]);</code></pre>

To avoid the above situation, we account for the additional comparison done in the <code>return</code> statement by reducing the number of loops in the <code>while</code> loop.

Now to cater for unconventional/unreasonable values of <code>n</code>:
- When <code>n</code> is negative, <code>strcmp</code> throws an error (Please verify this for yourself!). Recreating this is beyond the scope of the Piscine.
- When <code>n</code> is <code>0</code>, <code>strcmp</code> returns a value of <code>0</code>. This, we can recreate in our function simply by adding an <code>if</code> statement early on in the <code>ft_strncmp</code> function:

<pre><code>18	if (n == 0)
19		return (0);</code></pre>

</details>