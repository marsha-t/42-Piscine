## ft_atoi_base

|               ft_atoi_base        |
|---------------------------------|
| Turn-in directory : ex05/       |
| Files to turn in : ft_atoi_base.c |
| Allowed functions : None       |

- Write a function that converts the initial portion of the string pointed by <code>str</code> to <code>int</code> representation.
- <code>str</code> is in a specific base given as a second parameter.
- excepted the base rule, the function should work exactly like <code>ft_atoi</code>.
- If there’s an invalid argument, the function should return 0. Examples of invalid arguments :
	- base is empty or size of 1;
	- base contains the same character twice ;
	- base contains + or - or whitespaces;
- Here’s how it should be prototyped :
```
int ft_atoi_base(char *str, char *base);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &gtstdio.h&lt
int	main(void)
{
	char	str1[20] = "-101010";
    char    str2[] = "1101";
    char    str3[] = "39";
    char    str4[] = "1010";
    char    str5[] = "baba";
    char    str6[] = "4434";

	printf("str1: %d\n", ft_atoi_base(str1, "01"));
    printf("str2: %d\n", ft_atoi_base(str2, "01"));
    printf("str3: %d\n", ft_atoi_base(str3, "0123456789abcdef"));
    printf("str4: %d\n", ft_atoi_base(str4, "012"));
    printf("str5: %d\n", ft_atoi_base(str5, "abc"));
    printf("str6: %d\n", ft_atoi_base(str6, "34"));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>str1: -42
str2: 13
str3: 57
str4: 30
str5: 30
str6: 13
</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_atoi_base.c>exercise</a> builds on the previous exercises in C04 amazingly. We work off <a href=../04_ft_atoi>ft_atoi</a> and integrate bits of code done in <a href=../05/ft_putnbr_base>ft_putnbr_base</a>. 

The key differences made to <code>ft_atoi</code> to create <code>ft_atoi_base</code> are:
- Check that <code>base</code> is valid. Code from <code>ft_putnbr_base</code> is reused here.
- Adapt the part that converts numeric characters into digits and combines them into an <code>int</code> so that it converts <code>base</code> characters into digits and combines them into an <code>int</code> (lines 89-91 and <code>ft_c_is_base</code>). 

A helper function <code>ft_c_is_base</code> is used to adapt the last part of <code>ft_atoi</code>. First, <code>ft_c_is_base</code> is created to replace the role of <code>ft_c_is_numeric</code> in <code>ft_atoi</code> and do a little more. <code>ft_c_is_numeric</code> returned <code>1</code> if the character was a numeric character and <code>0</code> otherwise. <code>ft_c_is_base</code> will return the <i>index</i> if the character is found in <code>base</code>, and <code>-1</code> otherwise. <code>-1</code> is used instead of <code>0</code> since <code>0</code> is a valid index that could be returned if the character is the first element in <code>base</code>. Due to this, in lines 89-91, we loop through characters of <code>str</code> that are in <code>base</code> by using:

<pre><code>89	while (ft_c_is_base(str[i], base) > -1)</code></pre>

When converting the <code>base</code> characters into digits, what matters is the index of these characters in <code>base</code>. For instance, when faced with <code>base</code> of <code>"abc"</code>, we simply want to know that any instance of <code>'b'</code> in <code>str</code> is the 2nd character in <code>base</code>. As a result, the way <code>ft_c_is_base</code> was coded to returns a wider range of values becomes very useful. The index that is returned by <code>ft_c_is_base</code> can be directly used in place of <code>(str[i] - '0')</code> in <code>ft_atoi</code>. The last adapation is straightforward where <code>r * 10</code> in <code>ft_atoi</code> is changed to <code>r * ft_strlen(base)</code> in <code>ft_atoi_base</code>.
 
</details>