## ft_strlcpy

|               ft_strlcpy        |
|---------------------------------|
| Turn-in directory : ex10/       |
| Files to turn in : ft_strlcpy.c |
| Allowed functions : None       |

- Reproduce the behavior of the function <code>strlcpy</code> (<code>man strlcpy</code>).
- Here’s how it should be prototyped :
```
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
#include &ltstring.h&gt
int	main(void)
{
	char			s[4] = "abc";
	char			d1[4];
	char			d2[4];
	unsigned int	r;
	printf("Before: s = %s, d1 = %s, d2 = %s\n", s, d1, d2);
	r = ft_strlcpy(d1, s, 3);
	printf("After ft_strlcpy: return value: %u, s = %s, d1 = %s\n", r, s, d1);
	r = strlcpy(d2, s, 3);
	printf("After strlcpy: 	  return value: %u, s = %s, d2 = %s\n", r, s, d2);
	return (0);
}</code></pre>

As with <a href=../00_ft_strcpy>ft_strcpy</a> and <a href=../01_ft_strncpy>ft_strncpy</a>, we compare <code>ft_strlcpy</code> with the original <code>strlcpy</code> function.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Before: s = abc, d1 = I☻, d2 = ╚‼.║I☻
After ft_strlcpy: return value: 3, s = abc, d1 = I☻
After strlcpy:    return value: 3, s = abc, d2 = ╚‼.║I☻
After ft_strlcpy: return value: 3, s = abc, d1 = ab
After strlcpy:    return value: 3, s = abc, d2 = ab</code></pre>

We test the cases where size is <code>0</code> and <code>3</code>. 

Note that the output from printing the null strings <code>d1</code> and <code>d2</code> before the call of <code>ft_strlcpy</code> and <code>strcpy</code> may differ since we are invoking undefined behaviour here. 

</details>

<details>
<summary><h3>Approach</h3></summary>

<code>strlcpy</code> is intended to be an improvement over <code>strcpy</code> and <code>strncpy</code> by guaranteeing that the result will be null-terminated as long as <code>size</code> is greater than 0. This is done by copying <code>size-1</code> characters from <code>src</code> to <code>dest</code>. strlcpy also returns the length of <code>src</code>. 

In this <a href=ft_strlcpy.c>solution</a>, we use a helper function to create the required return value. Since the return value is simply the length of src, we re-use <code>ft_strlen</code> from an earlier <a href=../../c01/06_ft_strlen>exercise</a>:

<pre><code>26	unsigned int	r;
27
28	r = ft_strlen(src);</code></pre>

Note that <code>r</code> is declared as an <code>unsigned int</code> since <code>ft_strlcpy</code> will return an <code>unsigned int</code>. Even though <code>ft_strlen</code> will return an int, that value will always be positive. Hence, there will typically be no issues assigning the <code>int</code> return value from <code>ft_strlen</code> to an <code>unsigned int</code> variable. The only issue is if the length of <code>src</code> exceeds the capacity of <code>int</code>. This was not a scenario that Moulinette tested but it can be easily resolved by amending <code>ft_strlen</code> to return an <code>unsigned int</code> value:

<pre><code>13	unsigned int	ft_strlen(char *str)
14	{
15		unsigned int i;</code></pre>


Meanwhile, the copying is completed within <code>ft_strlcpy</code>:

<pre><code>32	while ((src[i] != '\0') && (i < (size - 1)))
33	{
34		dest[i] = src[i];
35		i++;
36	}
37	dest[i] = '\0';</code></pre>

The <code>while</code> loop conditions ensure that only <code>size - 1</code> characters from <code>src</code> will be copied to <code>dest</code>. Note that the maximum value of <code>i</code> for the <code>while</code> loop to run is <code>size - 2</code>: this is because arrays are 0-indexed and the index of <code>size-2</code> will refer to the (<code>size - 1</code>)th element. Finally, the last byte within <code>size</code> is used for the null terminator (line 39). 

Another thing of note is that <code>strlcpy</code> does not copy if <code>size</code> is less than <code>1</code>. Despite this, it will still return a value corresponding to the length of <code>src</code>. An <code>if</code> statement is written early in the <code>ft_strlcpy</code> function to cater for this:

<pre><code>30	if (size < 1)
31		return (r);</code></pre>

</details>