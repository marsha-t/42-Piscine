## ft_putstr_non_printable

|               ft_putstr_non_printable        |
|---------------------------------|
| Turn-in directory : ex11/       |
| Files to turn in : ft_putstr_non_printable.c |
| Allowed functions : write       |

- Create a function that displays a string of characters onscreen. If this string contains
characters that aren’t printable, they’ll have to be displayed in the shape of
hexadecimals (lowercase), preceeded by a "backslash".
- For example :
```
Coucou\ntu vas bien ?
``````
- The function should display :
```
Coucou\0atu vas bien ?
```
- Here’s how it should be prototyped :
```
void ft_putstr_non_printable(char *str);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	str[] = "Coucou\ntu \tvas \vbien ?";
	char	str2[] = "a \a b\b f\f r\r";
	printf("Original: %s\n", str);
	ft_putstr_non_printable(str);
	printf("\nOriginal: %s\n", str2);
	ft_putstr_non_printable(str2);
	return (0);
}</code></pre>

See [testing file](main.c)

</details>


<details>
<summary><h3>Output</h3></summary>

<pre><code>Original: Coucou
tu      vas
bien ?
After: Coucou\0atu \09vas \0bbien ?
Original: a   f
 r
After: a \07 b\08 f\0c r\0d
Original:
After: \7f</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

In this <a href=ft_putstr_non_printable.c>solution</a>, we will simply print printable characters as they are and convert non-printable characters to their hex equivalent. We will also use helper functions to print characters (to make the overall code more legible), to evaluate if a character is printable (re-using code from <a href=../06_ft_str_is_printable>ft_str_is_printable</a>) and to print a character's corresponding hex representation. 

The first part is simple enough: We use a <code>while</code> loop to go through every character in a string (line 42). If the character is printable (line 44), we display it (line 45).

<pre><code>41	i = 0;
42	while (str[i] != '\0')
43	{
44		if (ft_c_is_printable(str[i]) == 1)
45			ft_putchar(str[i]);</code></pre>

If the character is non-printable, we will first display a backslash (line 48) and then the hex representation (line 49):

<pre><code>46	else
47	{
48		ft_putchar('\\');
49		ft_tohex(str[i]);
50	}</code></pre>

Because the backslash is typically used for escape sequences (e.g, <code>\n</code> refers to a new line), we have to use two backslashes to insert a single backslash character (line 56). 

Within <code>ft_tohex</code>, we adapt Approach 3 in <a href=../../c00/07_ft_putnbr>ft_putnbr</a> for base 16 (i.e., hex representation). 

First, a straightforward adaptation of Approach 3 would result in the following code:
<pre><code>void	ft_tohex(char c)
{
	char 		*base; 

	base = "0123456789abcdef";
	if (c > 15)
		ft_tohex(c / 16);
	write(1, &base[c % 16], 1);
}</code></pre>

However, this code omits <code>'0'</code> when displaying the first 16 characters in ASCII. For instance, a new line (<code>'\n'</code>) will be displayed simply as <code>'a'</code> instead of <code>'0a'</code>.

Specifically, we want <code>ft_tohex</code> to add <code>'0'</code> when the character is among the first 16 characters of the ASCII table (i.e., 0-15 in ASCII) and it's the first time we're calling it. We do not want <code>ft_tohex</code> to add <code>'0'</code> if it was called as part of the recursion. We can use a second parameter to keep track of this. In the code below, we use an <code>int</code> parameter <code>recursion</code>. When <code>ft_tohex</code> calls itself as part of the recursive process, <code>recursion</code> will be set to 1. However, when we call <code>ft_tohex</code> from <code>ft_putstr_non_printable</code>, we will set <code>recursion</code> to 0. 

<pre><code>void	ft_tohex(char c, int recursion)
{
	char 		*base; 

	base = "0123456789abcdef";
	if (c < 16 && recursion == 0)
		write(1, "0", 1);
	if (c >= 16)
		ft_tohex(c / 16, 1);
	write(1, &base[c % 16], 1);
}</code></pre>

However, there is scope to simplify the code even further by recognising that bases greater than 11 can use 2 characters to represent all 128 characters in the ASCII table. For instance, <code>7F</code> in base 16 represents the <code>DEL</code> character but 3 digits is needed to represent it in base 10 and 8 (specifically, <code>127</code> and <code>177</code> respectively). Note that for base 11, 2 characters can only represent up to 11 * 11 = 121 characters. However, for base 12, 2 characters can represent up to 12 * 12 = 144 characters, which is more than enough for the 128 characters in ASCII. 

After streamlining the code, we can omit recursion altogether and display the first and second character separately:
<pre><code>33	ft_putchar(hex[c / 16]);
34	ft_putchar(hex[c % 16]);</code></pre>

Let's go through a few characters to see how this works:
- To display the start of heading character which has an ASCII value of <code>1</code> in base 10 and 16, we display <code>hex[1 / 16 = 0]</code> i.e., <code>'0'</code> from line 33 and <code>hex[1 % 16 = 1]</code> i.e., <code>'1'</code> from line 34. 
- To display a unit separator character which has an ASCII value of <code>31</code> in base 10 and <code>1F</code> in base 16, we display <code>hex[31 / 16 = 1]</code> i.e., <code>'1'</code> from line 33 and <code>hex[31 % 16 = 15]</code> i.e., <code>'f'</code>
- To display the delete character which has an ASCII value of <code>127</code> in base 10 and <code>7F</code> in base 16, we display <code>hex[127 / 16 = 7]</code> i.e., <code>'7'</code> from line 33 and <code>hex[127 % 16 = 15]</code> i.e., <code>'f'</code> from line 34

</details>