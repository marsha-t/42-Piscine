## ft_find_next_prime

|               ft_find_next_prime        |
|---------------------------------|
| Turn-in directory : ex07/       |
| Files to turn in : ft_find_next_prime.c |
| Allowed functions : None       |

- Create a function that returns the next prime number greater or equal to the number
given as argument.
- Here’s how it should be prototyped :
```
int ft_find_next_prime(int nb);
```


<summary><h3>Testing</h3></summary>

<pre><code>#include &gtstdio.h&lt
int	main(void)
{
	int	i;

	for (i = -2; i < 13; i++)
	{
		printf("next prime after %d: %d\n", i, ft_find_next_prime(i));
	}
	printf("next prime after 6700415: %d\n", ft_find_next_prime(6700415));
	printf("next prime after 6700417: %d\n", ft_find_next_prime(6700417));
	printf("next prime after 6700418: %d\n", ft_find_next_prime(6700418));
	printf("next prime after 2147483646: %d\n", ft_find_next_prime(2147483646));
	printf("next prime after 2147483647: %d\n", ft_find_next_prime(2147483647));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>next prime after -2: 2
next prime after -1: 2
next prime after 0: 2
next prime after 1: 2
next prime after 2: 2
next prime after 3: 3
next prime after 4: 5
next prime after 5: 5
next prime after 6: 7
next prime after 7: 7
next prime after 8: 11
next prime after 9: 11
next prime after 10: 11
next prime after 11: 11
next prime after 12: 13
next prime after 6700415: 6700417
next prime after 6700417: 6700417
next prime after 6700418: 6700489
next prime after 2147483646: 2147483647
next prime after 2147483647: 2147483647</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_find_next_prime.c>approach</a> makes use of the last <a href=../06_ft_is_prime>exercise</a>:
- If <code>nb</code> is less than 2 (i.e., nb is smaller than the smallest prime number), well, the next prime number is 2 (lines 33-34). 
- If <code>nb</code> is a prime number (checked using <code>ft_is_prime</code>), <code>nb</code> is returned (lines 35-35).
- If <code>nb</code> isn't a prime number, <code>nb</code> is incremented and checked whether it is a prime number. This continues until the incremented <code>nb</code> is a prime number and it can be returned. The code for the <code>while</code> loop is very short since incrementing <code>nb</code> is the only command that needs to be executed and it can be done in the <code>while</code> loop condition. Also, note that...

<pre><code>37	while (ft_is_prime(++nb) == 0);</code></pre>

is equivalent to...

<pre><code>nb++;
while (ft_is_prime(nb) == 0)
	nb++;</code></pre>

</details>


