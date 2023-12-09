## ft_sqrt

|               ft_sqrt        |
|---------------------------------|
| Turn-in directory : ex05/       |
| Files to turn in : ft_sqrt.c |
| Allowed functions : None       |

- Create a function that returns the square root of a number (if it exists), or 0 if the square root is an irrational number.
- Here’s how it should be prototyped :
```
int ft_sqrt(int nb);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	i;
	int	sq;

	for (i = 1; i < 9; i++)
	{
		sq = i * i;
		printf("sq of %d: %d --> sqrt: %d\n", i, sq, ft_sqrt(sq));
	}
	printf("sqrt of 14: %d\n", ft_sqrt(14));
	printf("sqrt of -2: %d\n", ft_sqrt(-2));
	printf("sqrt of 2147395600: %d\n", ft_sqrt(2147395600));
	printf("sqrt of 2147483647: %d\n", ft_sqrt(2147483647));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>sq of 1: 1 --> sqrt: 1
sq of 2: 4 --> sqrt: 2
sq of 3: 9 --> sqrt: 3
sq of 4: 16 --> sqrt: 4
sq of 5: 25 --> sqrt: 5
sq of 6: 36 --> sqrt: 6
sq of 7: 49 --> sqrt: 7
sq of 8: 64 --> sqrt: 8
sqrt of 14: 0
sqrt of -2: 0
sqrt of 2147395600: 46340
sqrt of 2147483647: 0</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_sqrt.c>approach</a> tests whether <code>nb</code> is a square via a brute-force method: it squares all the numbers starting from 1, comparing the squared number with <code>nb</code> until
- the squared number is the same as <code>nb</code> (in which case <code>nb</code> is a square number) or 
- the squared number is greater than <code>nb</code>.

Note that in the <code>while</code> loop condition (line 18), we use <code>test_sq * test_sq <= nb</code> even though we increment <code>test_sq</code>. When the squared number is the same as <code>nb</code>, we return <code>test_sq</code>. If not, we keep searching. Thereafter, if the squared number eventually exceeds <code>nb</code>, nb is not a square number and <code>0</code> is returned (line 24).

The key thing to note is that <code>test_sq</code> is restricted from exceeding <code>46340</code> in the <code>while</code> loop. The square of <code>46340</code> is the highest square number that can fit within <code>INT_MAX</code> (which is <code>2147483647</code> on my machine). This is required because <code>test_sq * test_sq <= nb</code> is evaluated in <code>int</code>. When <code>test_sq</code> exceeds <code>46340</code>, their square will exceed <code>INT_MAX</code> and cause overflow <i>before</i> this value is compared to <code>nb</code>. The overflow causes the value to be expressed as a negative <code>int</code> value, which is compared to <code>nb</code>, causing the <code>while</code> loop condition to remain true infinitely!

Other ways around this include specifying a 'bigger' data type. The other variables (i.e., <code>test_square</code>) are promoted to <code>long long</code> and then squared. The squared value can be safely expressed as a <code>long long</code>, avoiding issues relating to overflow, before it is compared to <code>square</code>.

<pre><code>long long square
square = nb;
while (test_sq * test_sq <= square)</code></pre>

</details>
