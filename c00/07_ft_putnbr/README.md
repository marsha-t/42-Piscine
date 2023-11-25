## ft_putnbr

|               ft_putnbr        |
|---------------------------------|
| Turn-in directory : ex07/       |
| Files to turn in : ft_putnbr.c |
| Allowed functions : write       |
- Create a function that displays the number entered as a parameter. The function
has to be able to display all possible values within an <code>int</code> type variable.
- Here’s how it should be prototyped:
```
void ft_putnbr(int nb);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code>#include &ltunistd.h&gt
#include &ltlimits.h&gt

int	main(void)
{
	ft_putnbr(INT_MIN);
	write(1, "\n", 1);
	ft_putnbr(-5);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(5);
	write(1, "\n", 1);
	ft_putnbr(INT_MAX);
	write(1, "\n", 1);
	return (0);
}</code></pre>

As with <a href=..\04_ft_is_negative.c>ft_is_negative</a>, when testing with integers, it's good to test with the extreme values. The <code>limits.h</code> library with the macros <code>INT_MIN</code> and <code>INT_MAX</code> for integer minimum and maximum makes this very simple.

See [testing file](main.c)
</details>

</details>
<details>
<summary><h3>Output</h3></summary>
<pre><code>-2147483648
-5
0
5
2147483647</code></pre>
</details>

<details>
<summary><h3><b>Approach 1: Use an array</code></b></h3></summary>
This <a href=ft_putnbr_v1.c>approach</a> first separates each digit within the integer and stores the digits in an array (lines 30-34). Thereafter, it prints these digits (lines 35-40). It also caters for the case of <code>0</code> (lines 23-24) and negative cases (lines 25-29).

<h4>Separating digits from the integer (i.e,. how we get <code>'1'</code>, <code>'2'</code> and <code>'3'</code> from <code>123</code>). </h4>

<pre><code>30	while (x % 10 != 0 || (x > 0 && x % 10 == 0))
31	{
32		array[i++] = (x % 10) + 48;
33		x = x / 10;
34	}</code></pre>

Note that here, <code>x</code> refers to the number we have to display. The reason for using this instead of <code>nb</code> will be explained later. The easiest way to get digits from an integer is to use the modulo by 10. For instance, 123 modulo 10 will return 3. We add <code>48</code> or <code>'0'</code> to obtain the character <code>'3'</code>. We then add <code>'3'</code> into the array. This is what line 30 does. 

In line 31, we divide 123 by 10. Since both the divident (123) and the divisor (10) are integers, the result is also an integer (12). If we apply the modulo again, we would be able to back out <code>'2'</code>. 

We want this process to continue while the number is greater than 0. 0 is not included in the <code>while</code> loop condition because it would not be possible to escpae the <code>while</code> loop when the escape condition is based on a division. Say, we have already backed out <code>'1'</code> from 123 and are ready to exit the <code>while</code> loop: we divide 1 by 10 and obtain 0 (since the arithmetic is done with integers). The next time we reach line 33, we divide 0 by 10 again and still get 0. This situation continues ad infinitum and we never escape the <code>while</code> loop. 

<h4>Displaying the digits but in reverse</h4>
Our array has all the digits from the integer but in reverse order. Hence, we should display the last element in the array, and then the second last, etc. in order to get the digits the right way round again. 
<pre><code>35	i--;
36	while (i >= 0)
37	{
38		write(1, &array[i], 1);
39		i--;
40	}</code></pre>

But first, our index of <code>i</code> in our array is now after the last digit because of <code>i++</code> in line 32. Hence, before we loop through the digits in the array, we first deduct 1 from <code>i</code> in line 35 (<code>i--;</code>) to return to the last digit in the array. 

To print in reverse, we start at the last digit, decrement <code>i</code> in each instance of the <code>while</code> loop until we reach the first digit in the array, held in <code>array[0]</code>. In the loop, we use <code>write</code> to display the digit in array[i]. 

If we wanted to save one line of code, we can consider the following code. We decrement <i>before</i> we <code>write</code> the digit so that we move to the last digit in the first instance of the <code>while</code> loop. Also, due to this, the <code>while</code> loop condition cannot include <code>'0'</code>. If it does, we will end up trying to display <code>array[-1]</code>.
<pre><code>while (i > 0)
{
	i--;
	write(1, &array[i], 1);
}</code></pre>

<h4>Dealing with <code>nb == 0</code></h4>
Since the <code>while</code> loop set-up in line 30 does not allow us to display a single '0' (if we tried, we won't be able to escape the <code>while</code> loop for reasons discussed above), we have to cater for it separately in lines 23-24. 

<h4>Dealing with negative integers or <code>nb < 0</code></h4>
Broadly, for negative integers, we display <code>'-'</code>, convert the integer back into a positive number and proceed as usual. Sounds simple enough but unfortunately, the minimum value for an integer is typically higher in absolute terms than the maximum value for an integer. For instance, <code>INT_MIN</code> for most of you will be -2,147,483,64<b>8</b> while <code>INT_MAX</code> will be 2,147,483,64<b>7</b>. If we were to convert nb = -2,147,483,648 into a positive figure, we attempt to assign 2,147,483,648 to an integer that cannot actually hold it! The solution is to use another variable capable of holding a larger numbers. In my code, I have defined a <code>long long</code> integer variable called <code>x</code> to do this. For some of you, it may be sufficient to define a <code>long</code> integer - it's just that for me, it turns out that <code>LONG_MAX</code> is the same as <code>INT_MAX</code>, forcing me to use <code>long long</code> instead. Confirm the minimum and maximum values within your machine using the <code>limits.h</code> library to know what is necessary/sufficient for you. 

Note that <code>x = -x</code> was used and not <code>x = -nb</code>. With the latter, as <code>nb</code> is an integer value, the right-hand-side of <code>=</code> is evaluated as an integer and we end up forcing 2,147,483,648 into an integer again. This happens before  the value is assigned to a <code>long</code> variable.
</details>

<details>
<summary><h3><b>Approach 2: Use recursion</code></b></h3></summary>
This <a href=ft_putnbr_v2.c>approach</a> produces succinct code but it requires you to understand and use recursion where the function calls upon itself. 

Where the number is less than 10, say 8, the function calculates the 8 modulo 10 (i.e., 8) and adds 48 to display <code>'8'</code>. Straightforward enough! 

<pre><code>32	c = nb % 10 + 48;</code></pre>
Here, we don't even need the modulo to display the single digit (but we will need it for the recursion)!

When the number is 10 or greater, we call on the <code>ft_putnbr</code> function to display the number divided by 10: <code>ft_putnbr(x / 10)</code>.
<pre><code>30	if (nb > 9)
31	ft_putnbr(nb / 10);</code></pre>

For instance, if we want to display 12 (i.e., <code>ft_putnbr(12)</code>), we will first call the function to display 12 divided 10 (i.e., <code>ft_putnbr(12/10)</code> which is equivalent to <code>ft_putnbr(1)</code>). Within <code>ft_putnbr(1)</code>, the code runs exactly as described above for numbers less than 10. We then exit <code>ft_putnbr(1)</code> and return to <code>ft_putnbr(12)</code> and run <code>c = x % 10 + 48</code>: 12 % 10 = 2 and we convert this to <code>'2'</code> by adding 48. We have successfully printed <code>'1'</code> and <code>'2'</code> and in that order! 

Let's try again with 123: <code>ft_putnbr(123)</code> will call <code>ft_putnbr(12)</code> which will in turn call <code>ft_putnbr(1)</code>. <code>ft_putnbr(1)</code> will display <code>'1'</code> and return control back to <code>ft_putnbr(12)</code> which will display <code>'2'</code>. Control returns to <code>ft_putnbr(123)</code> and <code>'3'</code> is printed. Viola!

<h4>Dealing with <code>nb == -2147483648</code></h4>
Unlike the 
<a href=ft_putnbr_v1.c> previous approach</a>, we use another method to cater to the case where <code>nb ==  INT_MIN == -2147483648</code>. Specifically, we use an <code>if</code> statement:
<pre><code>19	if (nb == -2147483648)
20	{
21		write(1, "-2", 2);
22		ft_putnbr(147483648)
23		return;
24	}</code></pre>
We first display <code>"-2"</code> and use recursion to display the rest of the digits. Consequently, there's no need to use a variable like <code>long</code> or <code>long long</code> to cater for the absolute value of <code>INT_MIN</code>! 

Of course, we can also take this approach to the extreme and avoid recursion for the case of <code>nb == 2147483648</code>: We simply get <code>write</code> to display all the necessary digits at once!
<pre><code>if (nb == -2147483648)
{
	write(1, "-2147483648", 11);
	return;
}</code></pre>
</details>

<details>
<summary><h3><b>Approach 3: Use recursion but make it adaptable to any base</code></b></h3></summary>
This <a href=ft_putnbr_v3.c>approach</a> is similar to <a href=ft_putnbr_v2.c>approach</a> except that the function could be more easily adapted to handle displaying integers in any base (more on this later).

First, we define all the characters used in base 10 within a string: <code>char	base[11] = "0123456789"</code>. There are 10 characters that are used in base 10 but I've catered for 11 spaces in my array - the last one is for the null terminator!

Then in line 31, we use <code>nb % 10</code> to select a digit from the string <code>base</code>. If <code>nb % 10</code> is 2, we display <code>str[2]</code> which is <code>'2'</code>. 

Seems a little extra but imagine you had to display a number in base 8. This function is now easily adaptable to this use case: 
<pre><code>1	# include &ltunisted.h&gt
2	void	ft_putnbr_base8(int nb)
3	{
4		char		base[9] = "012345678";
5		long long	x;
6		x = nb;
7		if (x < 0)
8	{
9		write(1, "-", 1);
10		x = -x;
11	}
12	if (x > 7)
13		ft_putnbr_base8(x / 8);
14	write(1, &base[x % 8], 1);
15	} </code></pre>

We've specified the string <code>base</code> accordingly <i>and</i> adjusted the rest of the function to account for base 8. Importantly, the mathematical expressions now use 8 instead of 10 e.g., we use <code>x / 8</code> and <code>x % 8</code> in lines 13 and 14 instead of <code>x / 10</code> and <code>x % 10</code>. 

In this approach, <code>base</code> is declared and initialised in the same line. For this to pass The Norme, the code would need to be amended as follows:
<pre><code>char base[11];
base[0] = '0';
base[1] = '1';
base[2] = '2';
base[3] = '3';
base[4] = '4';
base[5] = '5';
base[6] = '6';
base[7] = '7';
base[8] = '8';
base[9] = '9';
base[10] = '\0';</code></pre>
or we can use a <code>while</code> loop to make this less tedious:
<pre><code>char base[11];
int i; 
i = -1;
while (++i <= 9)
	base[i] = i + 48; 
base[++i] = '\0'</code></pre>
Do note that this is many more lines of code even when using the <code>while</code> loop and removing lines for incrementing (e.g., a line just for <code>i++;</code>). Technically, <code>str[10] = '\0'</code> is not required but it's a good practice to end strings with a null terminator.
</details>
