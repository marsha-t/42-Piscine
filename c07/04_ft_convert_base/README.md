## ft_convert_base

|               ft_convert_base        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_convert_base.c, ft_convert_base2.c |
| Allowed functions : malloc, free       |

- Create a function that returns the result of the conversion of the string <code>nbr</code> from a base <code>base_from</code> to a base <code>base_to</code>.
- <code>nbr</code>, <code>base_from</code>, <code>base_to</code> may be not writable.
- <code>nbr</code> will follow the same rules as <code>ft_atoi_base</code> (from another module). Beware of '+', '-' and whitespaces.
- The number represented by <code>nbr</code> must fit inside an <code>int</code>.
- If a base is wrong, <code>NULL</code> should be returned.
- The returned number must be prefix only by a single and unique '-' if necessary, no
whitespaces, no '+'.
- Here’s how it should be prototyped :
```
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt

int	main(void)
{
	printf("%s\n", ft_convert_base(" --+101010", "01", "0123456789"));
	printf("%s\n", ft_convert_base(" --+101010", "01", "ab"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "01"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "ab"));
	printf("%s\n", ft_convert_base("+2147483647", "0123456789", "012345"));
	return (0);	
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>bababa
-10000000000000000000000000000000
-baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
553032005531</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

For this exercises, two c files can be submitted. I suspect that this is because more than 5 functions (with max 25 lines each) is needed to code <code>ft_convert_base</code>. However, I think I've managed to do it. Well, please let me know if it doesn't work. 

This <a href=ft_convert_base.c>solution</a> combines two exercises from C04: <a href=../../c04/06_ft_atoi_base>ft_atoi_base</a> and <a href=../../c04/05_ft_putnbr_base>ft_putnbr_base</a>. Specifically, <code>ft_atoi_base</code> is used to convert the string (that was in a given base, <code>base_from</code>) into an <code>int</code>. Then, <code>ft_putnbr_base</code> is adapted to convert the <code>int</code> into any requested base (<code>base_to</code>) and place this into an array of characters (i.e., a string). Since this function converts an <code>int</code> to an array, the function has been renamed to <code>ft_itoa_base</code> (<u>i</u>nt <u>to</u> <u>a</u>rray).

<code>ft_base_ok</code> is used to check that both <code>base_from</code> and <code>base_to</code> are valid bases (line 113). If an invalid base is given for either, <code>ft_convert_base</code> returns a null pointer. The code is reused from the <a href=../../c04/06_ft_atoi_base>ft_atoi_base</a> exercise. The only change made is for the length of <code>base</code> to be computed within <code>ft_base_ok</code> rather than use <code>ft_strlen</code>. This is to reduce the number of functions used in this c file. 

Next, <code>ft_atoi_base</code> then converts the <code>nbr</code> string into an <code>int</code>. Again, the code is reused from the previous <a href=../../c04/06_ft_atoi_base>exercise</a> and only adapted so that the length of <code>base</code> is computed within the function. Also, since <code>base_from</code> has already been checked to be valid, this portion is removed from <code>ft_atoi_base</code>. 

Next, <code>ft_convert_base</code> computes the length of the required string after <code>x</code> has been converted into <code>base_to</code>:
- <code>base_l</code> is used to count the number of characters in <code>base_to</code> i.e., <code>base_l = ft_strlen(base_to)</code> (lines 120-122);
- the length of the eventual string is 1 + the number of times <code>x</code> can be divided by <code>base_l</code> (lines 123 and 129-133).
- An additional character is needed if <code>x</code> is negative, to accommodate the <code>-</code> sign (line 124-128). 

Finally, <code>ft_itoa_base</code> converts <code>x</code> to <code>base_to</code> using <code>count</code>, the length of the string <code>ft_itoa_base</code> needs to return. Because <code>x</code> was used to compute <code>count</code>, <code>ft_atoi_base</code> is reused to re-assign <code>x</code> to the int that <code>ft_itoa_base</code> needs to convert to string. 

In <code>ft_itoa_base</code>, 
- the length of <code>base_to</code> is computed (and stored as <code>base_l</code>) (lines 90-92).
- space for the string is allocated using <code>count + 1</code> (for the null terminator) (line 93).
- If this is unsuccessful, a null pointer is returned (lines 94-95)
- the string is null-terminated (line 96). This is done early on before the value of <code>count</code> is changed.  
- If <code>x</code> is negative, a <code>-</code> sign is inserted in <code>ptr[0]</code> and the absolute value of <code>x</code> assigned to <code>x</code>. 
- <code>x % base_l</code> is used to index <code>base_to</code> to convert <code>x</code> to <code>base_l</code>, a digit at a time. The next digit is obtained by dividing <code>x</code> by <code>base_l</code>. This uses a similar logic to <a href=../../c04/05_ft_putnbr_base>ft_putnbr_base</a>. 
- However, using the modulus extracts the digits from the end. Hence, <code>ptr</code> is filled up from back to front. 
- When done, <code>ptr</code> is returned (to <code>ft_convert_base</code> and also returned by <code>ft_convert_base</code>).

</details>

