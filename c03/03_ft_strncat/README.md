## ft_strncat

|               ft_strncat        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_strncat.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>strncat</code> (<code>man strncat</code>).
- Here’s how it should be prototyped:
```
char *ft_strncat(char *dest, char *src, unsigned int nb);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int	main(void)
{
	char    str1[15] = "abcd";
	char    str2[15] = "abcd";
	char    str3[6] = "12345";
	ft_strncat(str1, str3, 9);
	printf("ft_strncat: str1: %s, str3: %s\n" , str1, str3);
	strncat(str2, str3, 9);
	printf("strncat:    str2: %s, str3: %s\n" , str2, str3);
	char    str4[5] = "abcd";
	char    str5[5] = "abcd";
	char    str6[6] = "12345";
	ft_strncat(str4, str6, 3);
	printf("ft_strncat: str4: %s, str6: %s\n" , str4, str6);
	strncat(str5, str6, 3);
	printf("strncat:    str5: %s, str6: %s\n" , str5, str6);
	return (0);
}</code></pre>

We test cases where the destination string has enough capacity for the concatenated string (<code>str1</code> and <code>str2</code>) and where there isn't sufficient capacity (<code>str4</code> and <code>str5</code>)

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>ft_strncat: str1: abcd12345, str3: 12345
strncat:    str2: abcd12345, str3: 12345
ft_strncat: str4: abcd123, str6: 12345
strncat:    str5: abcd123, str6: 12345</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

<code>strncat</code> appends up to <code>nb</code> characters from <code>src</code> to the end of <code>dest</code> and null-terminates it. The concatenated string in <code>dest</code> is then returned. 

This <a href=ft_strncat.c>solution</a>:
- loops to the end of the <code>dest</code> string; (lines 20-22)
- copies over up to <code>nb</code> characters from <code>src</code> to <code>dest</code> (lines 24-29); 
- null-terminates <code>dest</code> before returning it (lines 30-31); and
- caters for unreasonable values of <code>nb</code> (lines 18-19).

This code is adapted from the previous <a href=../02_ft_strcat>exercise</a>. These adaptations include ensuring that not more than <code>nb</code> characters are copied over. This is done by adapting the <code>while</code> loop condition to include <code>j < nb</code> in line 24.

The other adaptation is catering for unreasonable values of <code>nb</code>:
- When <code>nb</code> is negative, <code>strncat</code> throws an error. As before, we will not attempt to recreate this. 
- When <code>nb</code> is <code>0</code>, nothing is copied over and the original <code>dest</code> string is returned. This is done in lines 18-19. 

</details>