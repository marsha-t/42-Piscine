## ft_fibonacci

|               ft_fibonacci        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_fibonacci.c |
| Allowed functions : None       |

- Create a function <code>ft_fibonacci</code> that returns the n-th element of the Fibonacci sequence, the first element being at the 0 index. We’ll consider that the Fibonacci sequence starts like this: 0, 1, 1, 2.
- Overflows must not be handled, the function return will be undefined.
- Here’s how it should be prototyped :
```
int ft_fibonacci(int index);
```
- Obviously, <code>ft_fibonacci</code> has to be recursive.
- If the <code>index</code> is less than 0, the function should return <code>-1</code>.

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &gtstdio.h&lt
int	main(void)
{
	for (int i = -2; i < 15; ++i)
		printf("index %d: %d\n", i, ft_fibonacci(i));
	return (0);
}</code></pre>

See [testing file](main.c)

</details>


<details>
<summary><h3>Output</h3></summary>

<pre><code>index -2: -1
index -1: -1
index 0: 0
index 1: 1
index 2: 1
index 3: 2
index 4: 3
index 5: 5
index 6: 8
index 7: 13
index 8: 21
index 9: 34
index 10: 55
index 11: 89
index 12: 144
index 13: 233
index 14: 377</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

To use recursion for the Fibonacci sequence, this <a href=ft_fibonacci.c>approach</a> simply uses the definition for the sequence: the <code>n</code>th element in the sequence is the sum of the <code>(n - 1)</code>th element and the <code>(n - 2)</code>th element. In other words: 

<pre><code>ft_fibonacci(index) == ft_fibonacci(index - 1) + ft_fibonacci(index - 2);</code></pre>

This is rearranged into line 23: 

<pre><code>23	r = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);</code></pre>

The solution is slightly longer to cater for unreasonable <code>index</code> values and to 'start' the sequence:
- Where <code>index</code> is negative, the function returns <code>-1</code>.
- Where <code>index == 1</code> (referring to the 2nd element in the sequence), the function returns <code>1</code>. Note that when <code>index == 0</code>, the initialised value of <code>r</code> is returned i.e., <code>0</code>.


</details>
