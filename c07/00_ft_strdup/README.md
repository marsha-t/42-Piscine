## ft_strdup

|               ft_strdup        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_strdup.c |
| Allowed functions : malloc       |

- Reproduce the behavior of the function <code>strdup</code> (<code>man strdup</code>).
- Here’s how it should be prototyped :
```
char *ft_strdup(char *src);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int	main(void)
{
	char	str1[20] = "abcd";

	printf("String value: %s\n", str1);
	printf("ft_strdup string value: %s\n", ft_strdup(str1));
	printf("strdup string value: %s\n", strdup(str1));
	printf("String location: %p\n", str1);
	printf("ft_strdup string location: %p\n", ft_strdup(str1));
	printf("strdup string location: %p\n", strdup(str1));
	char str2[] = "";
	printf("String value: %s\n", str2);
	printf("ft_strdup string value: %s\n", ft_strdup(str2));
	printf("strdup string value: %s\n", strdup(str2));
	printf("String location: %p\n", str2);
	printf("ft_strdup string location: %p\n", ft_strdup(str2));
	printf("strdup string location: %p\n", strdup(str2));
	return (0);
}
</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>String value: abcd
ft_strdup string value: abcd
strdup string value: abcd
String location: 00000014079ff700
ft_strdup string location: 00000141cb1f1490
strdup string location: 00000141cb1f14b0
String value:
ft_strdup string value:
strdup string value: 
String location: 00000014079ff6ff
ft_strdup string location: 00000141cb1f1510
strdup string location: 00000141cb1f1530</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

<code>strdup</code> duplicates a string and returns a pointer to the string. The memory for the new string is created using <code>malloc</code> and hence, the memory can also be freed with <code>free</code>. 

To recreate this, <a href=ft_strdup.c>ft_strdup</a>:
- determines the space needed for the new string (line 31); 
- allocates space for it using <code>malloc</code> (lines 32-34);
- copies characters from <code>src</code> to the new string before null-terminating it (lines 35-38); and
- returns a pointer to the start of the duplicated string (line 39). 

First, the space needed for a new string is the number of characters in <code>src</code> (including the null terminator) multiplied by the size of characters. <code>ft_strlen</code> is used to calculate the number of characters in src (line 31). However, for <code>malloc</code>, an additional character is added since <code>ft_strlen</code> does not include the null terminator in its count. The size of a character is 1 byte in most cases. However, to make our code more portable, this code uses the sizeof operator: <code>sizeof(char)</code>. These elements are combined into an expression that is fed into malloc. The exact amount of space for a duplicate of <code>src</code>, null terminator and all, is then (hopefully) allocated by <code>malloc</code>.

If all goes well, <code>malloc</code> returns a <u>pointer</u> to the allocated space. This pointer is assigned to the <code>ptr</code> variable, which will eventually be returned. If something went wrong with the memory allocation process, <code>malloc</code> returns a null pointer. This scenario is catered for in lines 33-34 where <code>ft_strdup</code> will return a null pointer too if <code>malloc</code> returns one. Note that the <code>0</code> in <code>return (0)</code> here refers to a null pointer.

Lines 35-38 copies characters from <code>src</code> into <code>ptr</code>, using <code>i</code> to index <code>src</code> and <code>ptr</code>. After copying these characters over, <code>ptr</code> is null-terminated. To make the code more succinct, <code>i</code> is incremented within the <code>while</code> loop condition (which is why <code>i</code> is initialised to <code>-1</code>).

</details>

