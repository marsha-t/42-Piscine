## ft_print_comb

|               ft_print_comb        |
|---------------------------------|
| Turn-in directory : ex05/       |
| Files to turn in : ft_print_comb.c |
| Allowed functions : write       |
- Create a function that displays all different combinations of three different digits in
ascending order, listed by ascending order - yes, repetition is voluntary.
- Here’s the intended output :
```
$>./a.out | cat -e
012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$>
```
- 987 isn’t there because 789 already is.
- 999 isn’t there because the digit 9 is present more than once.
- Here’s how it should be prototyped:
```
void ft_print_comb(void);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code> int	main(void)
{
	ft_print_comb();
	return (0);
}
 </code></pre>

See [testing file](main.c)
</details>

<details>
<summary><h3>Output</h3></summary>
<pre><code>012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789</code></pre>
</details>

<details>
<summary><h3><b>Approach</b></h3></summary>
This <a href=ft_print_comb.c>answer</a> sets 3 variables to represent the 3 digits in a combination and then uses 3 <code>while</code> loops to loop their values.

Within each combination, the digits must be ascending order, hence the variables are initialised to at least be higher than the previous digit:
<pre><code>x = '0';
...
	y = x + 1;
	...
		z = y + 1;
		...</code></pre>

Since we know that the last combination is 789, we can use this to set the <code>while</code> loop conditions. Also, to use these loops in combination, these loops are nested within each other.
<pre><code>while (x <= '7')
...
	while (y <= '8')
	...
		while (z <= '9')
		...
	</code></pre>

Within these nested loops, we write the digits in combination, remembering to separate them with a comma (and a space). However, to avoid putting a comma after 789 as well, we place the command to write the comma within an <code>if</code> statement. Since there is only one combination that starts with 7 that the loops will get to (as intended), we don't need to add more conditions
<pre><code>if (x != '7')
	write(1, ", ", 2);</code></pre>
</details>
