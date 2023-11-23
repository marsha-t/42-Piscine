## ft_is_negative

|               ft_is_negative        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_is_negative.c |
| Allowed functions : write       |

- Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’.
- It will be prototyped as follows:
```
void ft_is_negative(int n);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code> #include &ltlimits.h&gt
int	main(void)
{
	ft_is_negative(INT_MAX);
	write(1, "\n", 1);
	ft_is_negative(5);
	write(1, "\n", 1);
	ft_is_negative(0);
	write(1, "\n", 1);
	ft_is_negative(-5);
	write(1, "\n", 1);
	ft_is_negative(INT_MIN);
	write(1, "\n", 1);
	return (0);
} </code></pre>
When testing with integers, it's always good to test with the extreme values. Instead of memorising the minimum and maximum values, simply use the limits.h library which has the macros INT_MIN and INT_MAX which represent the integer minimum and maximum respectively.

See [testing file](main.c)
</details>

<details>
<summary><h3>Output</h3></summary>
<pre><code>P
P
P
N
N</code></pre>
</details>

<details>
<summary><h3><b>Approach</b></h3></summary>
The <a href=ft_is_negative.c>answer</a> uses <code>if/else</code>. In this version, we write 'N' if the number is negative and 'P' otherwise. We could've flipped the conditions as well:

<pre><code>if (n >= 0)
	write(1, "P", 1);
else
	write(1, "N", 1);</code></pre>

Since there is only one line of code in both the <code>if</code> and <code>else</code> commands, we can omit the curly braces (though these braces were included in this <a href=ft_is_negative.c>answer</a>)
</details>
