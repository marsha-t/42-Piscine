## ft_atoi

|               ft_atoi        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_atoi.c |
| Allowed functions : write       |

- Write a function that converts the initial portion of the string pointed by <code>str</code> to its <code>int</code> representation
- The string can start with an arbitray amount of white space (as determined by <code>isspace(3)</code>)
- The string can be followed by an arbitrary amount of <code>+</code> and <code>-</code> signs, <code>-</code> sign will change the sign of the <code>int</code> returned based on the number of <code>-</code> is odd or even.
- Finally the string can be followed by any numbers of the base 10.
- Your function should read the string until the string stop following the rules and return the number found until now.
- You should not take care of overflow or underflow. result can be undefined in that case.
- Here’s an example of a program that prints the <code>atoi</code> return value:

<pre><code>$>./a.out " ---+--+1234ab567"
-1234</code></pre>

- Here’s how it should be prototyped :
```
int ft_atoi(char *str);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &gtstdio.h&lt
int	main(void)
{
	char	str1[20] = "   ---+--+1234a567";
	char	str2[20] = " -+--345678a";
	char	str3[20] = "\n12345678";
	char	str4[20] = "a12345678";
	char	str5[20] = "--12345678";
	char	str6[20] = "9999999999";

	printf("str1: %d\n", ft_atoi(str1));
	printf("str2: %d\n", ft_atoi(str2));
	printf("str3: %d\n", ft_atoi(str3));
	printf("str4: %d\n", ft_atoi(str4));
	printf("str5: %d\n", ft_atoi(str5));
	printf("str6: %d\n", ft_atoi(str6));
	return (0);
}
</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>str1: -1234
str2: -345678
str3: 12345678
str4: 0
str5: 12345678
str6: 1410065407</code></pre>

<code>ft_atoi(str6)</code> attempts to convert to <code>int</code> a number greater than the <code>INT_MAX</code> (from the <code>limits.h</code> library). Since <code>INT_MAX</code> differs across machines, the output for the last test case will differ too. 

</details>

<details>
<summary><h3>Approach</h3></summary>

First, note that <code>ft_atoi</code> here does not reproduce <code>atoi</code> - the broad logic is similar but there are some slight differences. 

This <a href=ft_atoi.c>solution</a>:
- skips past an arbitrary amount of whitespace (lines 37-38 and the helper function <code>ft_c_is_whitespace</code>);
- decipher an arbitrary number of <code>+</code> and <code>-</code> signs and determine the eventual sign of the <code>int</code> (lines 39-44); 
- converts and combines numeric characters into an <code>int</code> (lines 45-49); and
- returns the <code>int</code> with the correct sign (line 50).

To skip past an arbitrary amount of whitespace, we use a <code>while</code> loop, with the condition that the characters are whitespace. This is determined via a helper function <code>ft_c_is_whitespace</code> which returns 1 if the character is whitespace and 0 otherwise. Using this function allows the code for <code>ft_atoi</code> to be more easily understood. 

To work through an arbirary amount of <code>+</code> and <code>-</code> signs, we use another <code>while</code> loop. In the loop, we pay particular attention to the <code>-</code> signs since these can change the sign of the <code>int</code>. To keep track of the eventual sign, we declare a variable <code>s</code> and initialise it to <code>1</code>. Each time <code>-</code> is encountered, we multiply <code>s</code> by -1:
- One <code>-</code> sign in <code>str</code> will mean a negative number and <code>s</code> will be converted to -1.
- Two <code>-</code> signs will mean a positive number and <code>s</code> will eventually be 1 by the end of the loop.
- Three <code>-</code> signs will mean a negative number and <code>s</code> will eventually be -1 by the end of the loop.

Note that the <code>+</code> and <code>-</code> signs can be in any order (as long as they are after whitespace and before the numeric characters) since the <code>while</code> loop loops <i>both</i> <code>+</code> and <code>-</code> signs. 

Now for the numbers. A third <code>while</code> loop is used to loop through the rest of <code>str</code> <i>provided that they are numeric characters</i>. We use a second helper function <code>ft_c_is_numeric</code> to simplify the code in <code>ft_atoi</code>. Specifically, <code>ft_c_is_numeric</code> returns 1 when c is numeric and 0 otherwise. Note that there is no need to also include the condition <code>str[i] != '\0'</code> in the <code>while</code> loop since it is also covered by the <code>ft_c_is_numeric</code> condition and therefore redundant: when the character is numeric, it's definitely not null too!

<pre><code>47	r = r * 10 + (str[i] - '0');</code></pre>

With r initialised to 0, we use line 47 to convert <i>and</i> combine the numeric characters to produce an <code>int</code>. First, to convert numeric characters to integers, we simply deduct <code>'0'</code>. This is handled by the second half of line 47: <code>str[i] - '0'</code>. 

Next, the key to combining these digits is bearing in mind that the digits need not move to their positions immediately. For instance, the <code>'1'</code> in <code>"123"</code> need not move immediately to the 'hundred' position - it only needs to be there by the end! Second, we can 'move' a digit to the left by mulitplying it by 10! This is what the first half of line 47 does - it is the mechanism by which the digits will move to the left. 

Hence, working with <code>"123"</code> for line 47, we will
- convert <code>'1'</code> to <code>1</code> and add it to <code>r</code> (so <code>r = 1</code>);
- mutiply <code>r</code> by 10 to move <code>1</code> to the 'ten' position (<code>r = 10</code>);
- convert <code>'2'</code> to <code>2</code> and add it to <code>r</code> (<code>r = 12</code>);
- multiply <code>r</code> by 10 to move <code>1</code> to the 'hundred' position and <code>2</code> to the 'ten' position (<code>r = 120</code>); and
- convert <code>'3'</code> to <code>3</code> and add it to <code>r</code> (<code>r = 123</code>). Ta da!

Phew, and finally, we return <code>r</code>, remembering to turn it into the correct sign by multiplying it by <code>s</code> (line 50).

</details>
