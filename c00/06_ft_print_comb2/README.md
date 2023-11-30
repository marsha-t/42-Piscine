## ft_print_comb2

|               ft_print_comb2        |
|---------------------------------|
| Turn-in directory : ex06/       |
| Files to turn in : ft_print_comb2.c |
| Allowed functions : write       |
- Create a function that displays all different combination of two two digits numbers
(XX XX) between 00 and 99, listed by ascending order.
- Here’s the expected output :
```
$>./a.out | cat -e
00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>
```
- Here’s how it should be prototyped:
```
void ft_print_comb2(void);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code> int	main(void)
{
	ft_print_comb2();
	return (0);
} </code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

This is a shortened version of the output (The full output is 34,648 characters)
<pre><code>00 01, 00 02, 00 03, 00 04, 00 05, 00 06, 00 07, 00 08, 00 09, 00 10, 00 11, 00 12, 00 13, 00 14, 00 15, 00 16, 00 17, 00 18, 00 19, 00 20, 00 21, 00 22, 00 23, 00 24, 00 25, 00 26, 00 27, 00 28, 00 29, 00 30, 00 31, 00 32, 00 33, 00 34, 00 35, 00 36, 00 37, 00 38, 00 39, 00 40, 00 41, 00 42, 00 43, 00 44, 00 45, 00 46, 00 47, 00 48, 00 49, 00 50, 00 51, 00 52, 00 53, 00 54, 00 55, 00 56, 00 57, 00 58, 00 59, 00 60, 00 61, 00 62, 00 63, 00 64, 00 65, 00 66, 00 67, 00 68, 00 69, 00 70, 00 71, 00 72, 00 73, 00 74, 00 75, 00 76, 00 77, 00 78, 00 79, 00 80, 00 81, 00 82, 00 83, 00 84, 00 85, 00 86, 00 87, 00 88, 00 89, 00 90, 00 91, 00 92, 00 93, 00 94, 00 95, 00 96, 00 97, 00 98, 00 99, 01 02, 01 03, 01 04, 01 05, 01 06, ... , 95 96, 95 97, 95 98, 95 99, 96 97, 96 98, 96 99, 97 98, 97 99, 98 99</code></pre>

Note that <code>00 99</code> is followed by <code>01 02</code>. In other words, <code>01 00</code> is skipped because <code>00</code> is less than <code>01</code> and <code>01 01</code> is skipped since the 2-digit combinations are the same. As the first 2-digit combination 'increases', there will be fewer possible combinations for the second 2-digit combination, such that by the time the first 2-digit combination is <code>98</code>, there is only one possible combination for the second 2-digit combination (i.e., <code>99</code> to make <code>98 99</code>)

</details>

<details>
<summary><h3>Approach 1.1: Use 1 function and 4 variables to represent the 4 digits</h3></summary>

This <a href=ft_print_comb2_v1_1.c>answer</a> uses the same approach as was used for <a href=../05_ft_print_comb>ft_print_comb</a>. In other words, it uses 4 variables to represent each of the 4 digits and 4 <code>while</code> loops to go through each of their values. 

A key thing to note is that we don't use the last combination of digits (i.e., <code>98 99</code>) to set the <code>while</code> loop conditions. This is unlike <a href=../05_ft_print_comb>ft_print_comb</a> where we had used the last combination of <code>789</code> to set the conditions. Here, if we had used the following (i.e., only allow <code>a2</code> to go up to 8), we would not be able to get combinations like <code>09 10</code>. 

<pre><code>a1 = 47;
while (++a1 <= 57)
	a2 = 47;
	while (++a2 <= 56)
		b1 = 47; 
		while (++b1 <= 57)
			b2 = 47; 
			while (++b2 <= 57)</code></pre>

As a result, we rely on a big <code>if</code> statement to make sure that the 2-digit combinations differ from each other (i.e., <code>(a1 != b1 || a2 != b2)</code>) and that the second 2-digit combination is lower than the first (i.e., <code>((a1 < b1) || ((a1 == b1) && (a2 < b2)))</code>). When these conditions are not met, the loops moves onto the next values and does not print combinations like <code>00 00</code>, <code>10 01</code>, or <code>01 00</code>.

To keep this code succinct, a few tricks were used: 
- Since the <code>if</code> statement only has one command, we omit the curly braces for it, saving two lines 
- Instead of using a line for each while loop to increment the variable at the end of the <code>write</code> commands, we increment the variables in the <code>while</code> loop <i>before</i> they are used. Because of this, we have to take care when initialising the variables. We would typically initialise the variables at <code>'0'</code> or <code>48</code> so that this value is used for the first loop. Since we are incrementing the values before they are used in the first loop, we should initialise them at <code>47</code> instead. Given this, I prefer to use the ASCII numbers. Instead of ASCII numbers, the code would have to use <code>'\\'</code> (ASCII number 47):

<pre><code>a1 = '\';
while (++a1 <= '9')
+++
	a2 = '\';
	while (++a2 <= '9')
	...
		b1 = '\';
		while (++b1 <= '9')
		...
			b2 = '\';
			while (++b2 <= '9')
			... </code></pre>

Despite the above efforts, the function remains over 25 lines long and thus not in line with The Norme. <a href=ft_print_comb2_v1_2.c>Approach 1.2</a> uses 2 functions to overcome this issue. 

</details>

<details>
<summary><h3>Approach 1.2: Use 2 functions and 4 variables to represent the 4 digits</h3></summary>

This <a href=ft_print_comb2_v1_2.c>answer</a> splits the code in <a href=ft_print_comb2_v1_1.c>Approach 1.1</a> into two functions. 

Specifically, the commands to write the digits are delegated to the <code>ft_write_it_all</code> function. This is simply done by copying and pasting the necessary codes into the new function and making sure that all the ingredients needed in the new function are specified (i.e., the 4 variables representing the 4 digits).

When creating such helper functions, I personally find it easier to think about how the function will be used (What information does it need? Do I need it to return something for something else in the code to work?) and first come up with: <code>ft_write_it_all(a1, a2, b1, b2);</code>. Thereafter, I declare it as follows: <code>void	ft_write_it_all(char a1, char a2, char b1, char b2)</code> and begin writing the commands within <code>ft_write_it_all</code>.

</details>

<details>
<summary><h3>Approach 2: Use an array of 2 integers</h3></summary>

This <a href=ft_print_comb2_v2.c>approach</a> uses an array to 'hold' all the variables needed for the task. An array is suitable since the variables we need are of the same data type (either <code>char</code> or <code>int</code>). 

While we can use an array to hold the 4 digits, I chose to hold two integers within the array. For instance, for the last combination of numbers (<code>98 99</code>), <code>array[0]</code> will hold <code>98</code> and <code>array[1]</code> will hold <code>99</code>. As a result, the <code>while</code> loop conditions can simply be set according to the last combination (<code>98 99</code>). Also, the <code>if</code> statement comparing the two 2-digit combinations is more intuitive.

<pre><code>40	while (++array[0] <= 98)
41	{
...
43		while (++array[1] <= 99)
44		{
45			if (array[0] < array[1])</code></pre>

The logic of the <code>while</code> loops in <code>ft_print_comb2</code> is for the first number to loop from 0 to 98 and the second number to loop from 1 to 99. Since I've chosen to increment the value before it is used in the <code>while</code> loop condition, the first number (array[0]) is initialised at -1. The second number would typically be initialised at <code>array[1] = array[0] + 1</code>, but given the way the incrementing has been set up, it is now simply <code>array[1] = array[0]</code>. 

The code would look as follows if I had incremented inside the <code>while</code> loops:

<pre><code>array[0] = 0; 
while (array[0] <= 98)
{
	array[1] = array[0] + 1;
	while (array[1] <= 99>)
	{
		...
		array[1]++;
	}
	array[0]++;	
}</code></pre> 

We use <code>ft_print_nb</code> to write these numbers. Let's start first with numbers that of a single digit (i.e., those less than 10):

<pre><code>29	write(1, "0", 1);
30	nb += 48;
31	write(1, &nb, 1); </code></pre>

Here, we first remember to print '0' in front of the actual number. We also add 48 to the number to get to the actual character. For instance, if the <code>nb</code> was 1, trying to display nb as it is will cause the <code>write</code> command to refer to "Start of Heading", a non-printable character with the ASCII value of 1. Instead, we want to print <code>'1'</code> which has an ASCII value of 49. Therefore, we add 48 to <code>nb</code> before printing it.

Now, for numbers greater than 9, we print the first digit separately to the second digit:

<pre><code>22	a = nb / 10 + 48;
23	b = nb % 10 + 48;
24	write(1, &a, 1);
25	write(1, &b, 1); </code></pre>

To get the first digit, we divide the number by 10. If the number was 42, dividing it by 10 will give us 4. It won't give us 4.2 because we are dealing purely with integers here: since the dividend and the divisor are integers, the quotient (i.e., the result) will also be an integer. As before, we add 48 to the result so that we print the character (e.g., <code>'4'</code>).

To get the second digit, we use the modulo operator. If the number was 42, 42 modulo 10 will give us 2 (i.e., the remainder after we divide 42 by 10). We add 48 to this result and viola, we get <code>'2'</code>.

</details>
