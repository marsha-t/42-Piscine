## ft_strcat

|               ft_strcat        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_strcat.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>strcat</code> (<code>man strcat</code>).
- Here’s how it should be prototyped:
```
char *ft_strcat(char *dest, char *src);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int	main(void)
{
	char    str1[10] = "abcd";
	char    str2[10] = "abcd";
	char    str3[3] = "fg";
	ft_strcat(str1, str3);
	printf("ft_strcat: str1: %s, str3: %s\n", str1, str3);
	strcat(str2, str3);
	printf("strcat:    str2: %s, str3: %s\n", str2, str3);
	char    str4[5] = "abcd";
	char    str5[5] = "abcd";
	char    str6[3] = "fg";
	ft_strcat(str4, str6);
	printf("ft_strcat: str4: %s, str6: %s\n", str4, str6);
	strcat(str5, str6);
	printf("strcat:    str5: %s, str6: %s\n", str5, str6);
    return (0);
}</code></pre>

We test cases where the destination string has enough capacity for the concatenated string (<code>str1</code> and <code>str2</code>) and where there isn't sufficient capacity (<code>str4</code> and <code>str5</code>)

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>ft_strcat: str1: abcdfg, str3: fg
strcat:    str2: abcdfg, str3: fg
ft_strcat: str4: abcdfg, str6: fg
strcat:    str5: abcdfg, str6: fg</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

<code>strcat</code> appends a copy of <code>src</code> to the end of <code>dest</code> and null-terminates it. The concatenated string in <code>dest</code> is then returned. 

This <a href=ft_strcat.c>solution</a>:
- loops to the end of the <code>dest</code> string; (lines 18-20)
- copies over characters from <code>src</code> to <code>dest</code> (lines 21-27); and
- null-terminates <code>dest</code> before returning it (lines 28-29).

The key thing is that index variables (<code>i</code> and <code>j</code>) are used to loop through <code>dest</code> and <code>src</code> respectively. By using <code>i</code> to loop through <code>dest</code>, we ensure that the <code>dest</code> pointer continues to point at the first element of the string when we return it. 

</details>