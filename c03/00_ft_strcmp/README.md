## ft_strcmp

|               ft_strcmp        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_strcmp.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>strcmp</code> (<code>man strcmp</code>).
- Here’s how it should be prototyped:
```
int ft_strcmp(char *s1, char *s2);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int main(void)
{
    char    str1[] = "abcde";
    char    str2[] = "ab";
    char    str3[] = "Abcd";
    char    str4[] = "0d";
    char    str5[] = "\ns";
    char    str6[] = " s";
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str2));
    printf("strcmp:    %d\n", strcmp(str1, str2));
    printf("ft_strcmp: %d\n", ft_strcmp(str3, str1));
    printf("strcmp:    %d\n", strcmp(str3, str1));
    printf("ft_strcmp: %d\n", ft_strcmp(str2, str3));
    printf("strcmp:    %d\n", strcmp(str2, str3));
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str1));
    printf("strcmp:    %d\n", strcmp(str1, str1));
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str4));
    printf("strcmp:    %d\n", strcmp(str1, str4));
    printf("ft_strcmp: %d\n", ft_strcmp(str2, str5));
    printf("strcmp:    %d\n", strcmp(str2, str5));
    printf("ft_strcmp: %d\n", ft_strcmp(str5, str4));
    printf("strcmp:    %d\n", strcmp(str5, str4));
    printf("ft_strcmp: %d\n", ft_strcmp(str5, str6));
    printf("strcmp:    %d\n", strcmp(str5, str6));
    return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>ft_strcmp: 99
strcmp:    99
ft_strcmp: -32
strcmp:    -32
ft_strcmp: 32
strcmp:    32
ft_strcmp: 0
strcmp:    0
ft_strcmp: 49
strcmp:    49
ft_strcmp: 87
strcmp:    87
ft_strcmp: -38
strcmp:    -38
ft_strcmp: -22
strcmp:    -22
</code></pre>

Output for strcmp may differ: some implementations may give output of -1, 1 and 0 only. 

</details>

<details>
<summary><h3>Approach</h3></summary>

<code>strcmp</code> compares two strings, <code>s1</code> and <code>s2</code>, and returns 
- <code>0</code> if the strings are the same; 
- a negative value if <code>s1</code> is less than <code>s2</code>; or
- a positive value if <code>s1</code> is greater than <code>s2</code>. 

Depending on the implementation, <code>strcmp</code> may give <code>0</code>, <code>-1</code> and <code>1</code> corresponding to the three cases listed above. Other implementations will provide the difference between the last compared character in <code>s1</code> and <code>s2</code> and a much wider range of values can thus be returned. Moulinette appears to accept both versions. 

This <a href=ft_strcmp.c>solution</a> compares the two strings by comparing each character within the strings. Where the characters are the same, we move onto the next character. When the characters are no longer the same, we return the difference between these two characters. This can be coded as follows:

<pre><code>i = 0; 
while ((s1[i] != '\0') && (s2[i] != '\0'))
{
	if (s1[i] == s2[i])
		i++;
	else
		return (s1[i] - s2[i])
}
</code></pre>

The code will compile if you use a lower tolerance for errors (if you omit the usual flags <code>-Wall -Wextra -Werror</code>). The construction of <code>ft_strcmp</code> above is largely correct and will lead <code>ft_strcmp</code> to behave similarly to <code>strcmp</code> in most cases. However, once the flags are included, there is an error message that "control reaches the end of a non-void function.". This is because the return statement is nested within the <code>while</code> loop. If the <code>while</code> loop is exited when comparing certain strings, there is no <code>return</code> statement to end the function. In practice, running the compiler without the flags will cause the function to return <code>0</code> by default (at least on my machine). 

The <code>while</code> loop is exited in two cases and both are related to the null-terminator:
- Where two strings are the same, the above code will skip through all the characters until the null terminator, after which there is no <code>return</code> statement. In this case, we want the function to return <code>0</code>. My machine returns <code>0</code> by default (not a terrible outcome) but my code would not have compiled if I had included the usual flags. 
- Where two strings are of different lengths, i.e., we reach the null terminator in one string before the null terminator in the other string, we will also be taken out of the <code>while</code> loop. In this case, we do <u>not</u> want a return value of <code>0</code>. We want a comparison between a non-null character in the longer string and the null terminator in the shorter string. However, as previously mentioned, my machine returns <code>0</code> by default.

This can be fixed by adding a return statement at the end of the <code>while</code> loop:

<pre><code>while(...)
	...
return (s1[i] - s2[i]);</code></pre>

Where the two strings are the same, we compare the two null terminators to return a value of 0. Where the strings are of different lengths, we compare the non-null character in the longer string to the null terminator in the shorter string. Perfect!

That said, there is scope to streamline the code a bit more since we have two <code>return</code> statements that look the same. It is tempting to remove the return statement within the while loop as follows:

<pre><code>while ((s1[i] != '\0') && (s2[i] != '\0'))
{
	if (s1[i] == s2[i])
		i++;
}
return (s1[i] - s2[i]);</code></pre>

However, in cases where two strings differ because their characters are different (not because of their lengths), we would never exit the <code>while</code> loop! In that case, if the whole point of the <code>while</code> loop is to skip over characters that are the same, we can weave the <code>if</code> statement into the <code>while</code> loop conditions:

<pre><code>18	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
19	i++;</code></pre>

We weave the <code>if</code> statement in the <code>while</code> loop by including <code>s1[i] == s2[i]</code>. Meanwhile, we include the original <code>while</code> loop condition using <code>s1[i] != '\0'</code>. Note that it is not necessary to include <code>s2[i] != '\0'</code> since this is assured by having <code>s1[i] == s2[i]</code>. This is the eventual form used in the <a href=ft_strcmp.c>solution</a>. 

</details>
