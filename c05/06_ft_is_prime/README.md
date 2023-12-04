## ft_is_prime

|               ft_is_prime        |
|---------------------------------|
| Turn-in directory : ex06/       |
| Files to turn in : ft_is_prime.c |
| Allowed functions : None       |

- Create a function that returns 1 if the number given as a parameter is a prime
number, and 0 if it isn’t.
- Here’s how it should be prototyped :
```
int ft_is_prime(int nb);
```

<summary><h3>Testing</h3></summary>

<pre><code>#include &gtstdio.h&lt
int	main(void)
{
	int	i;

	for (i = 1; i < 15; i++)
	{
		printf("%d prime?: %d\n", i, ft_is_prime(i));
	}
	printf("-1 prime?: %d\n", ft_is_prime(-1));
	printf("0 prime?: %d\n", ft_is_prime(0));
	printf("1 prime?: %d\n", ft_is_prime(1));
	printf("2147483646 prime?: %d\n", ft_is_prime(2147483646));
	printf("2147483647 prime?: %d\n", ft_is_prime(2147483647));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>1 prime?: 0
2 prime?: 1
3 prime?: 1
4 prime?: 0
5 prime?: 1
6 prime?: 0
7 prime?: 1
8 prime?: 0
9 prime?: 0
10 prime?: 0
11 prime?: 1
12 prime?: 0
13 prime?: 1
14 prime?: 0
-1 prime?: 0
0 prime?: 0
1 prime?: 0
2147483646 prime?: 0
2147483647 prime?: 1</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

Like the previous <a href=../05_ft_sqrt>exercise</a>, this <a href=ft_is_prime.c>solution</a> uses a brute-force method to determine if <code>nb</code> is a prime number. The function divides <code>nb</code> by numbers, starting from 2 and ending before <code>nb</code>. At the first instance where the remainder from this division is 0 (i.e., <code>nb</code> is divisible by this number), <code>0</code> is returned, indicating that <code>nb</code> is not a prime number. If <code>nb</code> is not divisible by any of these numbers, <code>nb</code> is a prime number (and the function returns <code>1</code>).

Note that the function starts the divisor at 2 (there's no point start with 1 or 0) and increments it until until the number right <i>before</i> nb. Do not include <code>nb</code> since all numbers are divisible by itself and the function would end up concluding that there are no prime numbers.  

Since the smallest prime number is 2, numbers smaller than 2 (i.e., <code>nb < 2</code> in line 17) cannot be prime numbers and <code>0</code> should be returned (line 18).

</details>
