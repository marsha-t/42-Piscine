## ft_ft

|               ft_ft        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_ft.c |
| Allowed functions : None       |

- Create a function that takes a pointer to <code>int</code> as a parameter, and sets the value "42" to that <code>int</code>.
- Here’s how it should be prototyped:
```
void ft_ft(int *nbr);
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt

int	main(void)
{
	int	n;

	n = 50;
	printf("Before: %d\n", n);
	ft_ft(&n);
	printf("After:  %d\n", n);
	return (0);
} </pre></code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Before: 50
After:  42</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

Through this <a href=ft_ft.c>exercise</a>, you'd realise how functions work and consequently how pointers can be useful!

In the functions so far where we've had to pass in an argument (e.g., <a href = ../../c00/00_ft_putchar>ft_putchar</a> with a character argument or <a href = ../../c00/07_ft_putnbr>ft_putnbr</a> with an integer argument), we may have thought that the value defined in the <code>main</code> function was passed directly into the respective functions, <code>ft_putchar</code> or <code>ft_putnbr</code>. However, that's not the case. Instead, these arguments were <i>passed by value</i>. 

Let's run through the example below where <code>ft_putchar('a')</code> was called in the <code>main</code> function. a copy of <code>'a'</code> was made and stored using the name <code>c</code> (the <code>c</code> in the declaration of <code>ft_putchar</code>). 

<pre><code>#include &ltunistd.h&gt
	
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_putchar('a');
	return (0);
}</code></pre>

This remains the case even if we passed in a variable in <code>ft_putchar</code> as shown below. We passed <code>d</code> into <code>ft_putchar</code> within the <code>main</code> function but eventually a copy of <code>'a'</code> is made and stored as <code>'c'</code> for <code>ft_putchar</code> to use. 

<pre><code>#include &ltunistd.h&gt
	
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char d; 
	d = 'a';
	ft_putchar(d);
	return (0);
}</code></pre>

This behaviour is not problematic in the case of <code>ft_putchar</code> but what if we do want to use a function to change the value of a variable that was already initialised? This is precisely the task in <code>ft_ft</code> and the only way to do so is by <i>passing by reference</i> instead of <i>by value</i>. 

In the <code>main</code> function, we set a variable <code>n</code> to 50. Instead of copying the value of 50 into <code>ft_ft</code>, we pass in the reference (aka address) of nbr so that <code>ft_ft</code> can make changes directly to the original copy of <code>n</code>:

<pre><code>int	main(void)
{
	int	n;

	n = 50;
	ft_ft(&n);
	return (0);
}</code></pre>

Within the <code>ft_ft</code> function, we want to change the value of <code>n</code>, regardless of what it was previously, to 42. Within <code>ft_ft</code>, <code>nbr</code> refers to the address of <code>n</code>. To get to <code>n</code>, we <i>dereference</i> <code>nbr</code> to get from the address of <code>n</code> to the value of <code>n</code>:

<pre><code>*nbr = 42;</code></pre>

And that's it!

</details>
