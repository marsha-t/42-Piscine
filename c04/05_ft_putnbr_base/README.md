## ft_putnbr_base

|               ft_putnbr_base        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_putnbr_base.c |
| Allowed functions : write       |

- Create a function that displays a number in a base system in the terminal.
- This number is given in the shape of an <code>int</code>, and the radix in the shape of a string
of characters.
- The base-system contains all useable symbols to display that number :
	- <code>0123456789</code> is the commonly used base system to represent decimal numbers;
	- <code>01</code> is a binary base system ;
	- <code>0123456789ABCDEF</code> an hexadecimal base system ;
	- <code>poneyvif</code> is an octal base system.
- The function must handle negative numbers.
- If there’s an invalid argument, nothing should be displayed. Examples of invalid
arguments :
	- base is empty or size of 1;
	- base contains the same character twice ;
	- base contains + or - ;
- Here’s how it should be prototyped: 
```
void ft_putnbr_base(int nbr, char *base);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &gtunistd.h&lt
int	main(void)
{
	int	a;

	a = -2147483648;
	ft_putnbr_base(a, "01");
	write(1, "\n", 1);
	a = -42;
	ft_putnbr_base(a, "01");
	write(1, "\n", 1);
	a = 13;
	ft_putnbr_base(a, "34");
	write(1, "\n", 1);
	a = 30;
	ft_putnbr_base(a, "abc");
	write(1, "\n", 1);
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>-10000000000000000000000000000000
-101010
4434
baba</code></pre>

The output for the first test may look different if <code>INT_MIN</code> (from the <code>limits.h</code> library) on your machine is different. 

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_putnbr_base.c>exercise</a> extends <code>ft_putnbr</code> by being able to display the number in any base. In fact, <code>ft_putnbr</code> is equivalent to <code>ft_putnbr_base</code> where <code>"0123456789"</code> is passed as <code>base</code>.

The solution:
- checks that <code>base</code> is valid; and
- adapts <a href=../../c00/07_ft_putnbr>Approach 3 for ft_putnbr</a> to display the <code>int</code> provided in a given <code>base</code>.

To keep the code in <code>ft_putnbr_base</code> concise, the check for whether <code>base</code> is valid is done entirely via the helper function <code>ft_base_ok</code>. This function returns 1 when the base is valid and 0 otherwise. It covers the following conditions:
- <code>base</code> cannot be empty or size of 1 (line 37-38);
- <code>base</code> cannot contain +, - nor any non-printable characters (lines 42-44 and the helper function <code>ft_c_printable</code>);
- <code>base</code> cannot contain the same character twice (lines 45-51).

First, we will use <a href=../../c01/06_ft_strlen>ft_strlen</a> to measure the size of the <code>base</code>. Where <code>ft_strlen(base)</code> is 0 or 1, <code>ft_base_ok</code> will return 0 and <code>ft_putnbr_base</code> will do nothing. The same will happen if any character is base is <code>+</code>, <code>-</code> or non-printable. 

To check that characters do not repeat in <code>base</code>, each character is compared with all the characters that come after it. Specifically, <code>j</code> is used as a second indexing variable to refer to the characters that come after. <code>j</code> is initialised to the index after <code>i</code> and a <code>while</code> loop used to go through each character until the end of <code>base</code> (the last index in <code>base</code> is <code>ft_strlen(base) - 1</code>). Within the <code>while</code> loop, an <code>if</code> statement checks if the character at index <code>i</code> is the same as the character at index <code>j</code> - if they are, <code>ft_base_ok</code> returns 0. Note that <code>j</code> is initialised within the while loop that increments <code>i</code> - that means that <code>j</code> is reset everytime there is a new value of <code>i</code> which is what we want!

To write the integer in any base, we adapt <a href=../../c00/07_ft_putnbr>Approach 3 for ft_putnbr</a> accordingly:

<pre><code>71	if (x >= b)
72		ft_putnbr_base(x / b, base);
73	write(1, &base[x & b], 1);</code></pre>

</details>
