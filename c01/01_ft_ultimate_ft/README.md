## ft_ultimate_ft

|               ft_ultimate_ft        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_ultimate_ft.c |
| Allowed functions : None       |

- Create a function that takes a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to int as a parameter and sets the value "42" to that int
- Here’s how it should be prototyped:
```
void ft_ultimate_ft(int *********nbr);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code>#include &ltstdio.h&gt

int	main(void)
{
	int	x;
	int	*ptr1;
	int	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;

	x = 50;
	ptr1 = &x;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	printf("%d", x);
	ft_ultimate_ft(&ptr8);
	printf("%d", x);
	return (0);
}</pre></code>

See [testing file](main.c)

</details>
<details>
<summary><h3>Output</h3></summary>
<pre><code>Before: 50
After:  42</code></pre>
</details>

<details>
<summary><h3>Approach</h3></summary>
From this <a href=ft_ultimate_ft.c>exercise</a>, you'd realise that <code>*</code> and <code>&</code> (the referencing and dereferencing operators respectively) can be layered upon each other multiple times. 

First, in our <code>main</code> function, we will create a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to <code>int</code> (note that this is one less 'pointer to' than that listed in the assignment instructions). We declare an integer and initialise it to 50. 

<pre><code>#include &ltstdio.h&gt

int	main(void)
{
	int	x;
	int	*ptr1;
	int	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;

	x = 50;
	ptr1 = &x;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ft_ultimate_ft(&ptr8);
	return (0);
}</code></pre>

Now we start creating pointers. We first create a pointer <code>ptr1</code> which will hold the address of <code>x</code>:
- When we use <code>ptr1</code> directly in our codes, we will refer to the address of <code>x</code>
- When we use <code>*ptr1</code>, we will refer to the value of <code>x</code>. 

Next, we create <code>ptr2</code> which will hold the address of <code>ptr1</code> (yes, pointers also have addresses because they also take up space in memory!):
- When we refer to <code>ptr2</code>, we get the address of <code>ptr1</code>
- When we refer to <code>*ptr2</code>, we get the value of <code>ptr1</code> which is the address of <code>x</code>
- When we refer to <code>**ptr2</code>, we get the value of <code>x</code>!

By the time we create <code>ptr8</code>, we need to use <code>********ptr8</code> to get to the value of <code>x</code>. This is easy to keep track of - you can figure out how many <code>*</code> are needed by looking at the declaration of <code>ptr8</code>: <code>int ********ptr8</code>. These declarations can be broken into two parts: <code>int</code> and <code>********ptr8</code>. The second part tells you what you must use in order to get the first! The tip will be useful as you navigate through more complex data types in C.

So far, we've created a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to <code>int</code> but it's not an ultimate pointer just yet. We referencing <code>ptr8</code> using <code>&ptr8</code> and pass that into <code>ft_ultimate_ft</code>. We've passed in pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to <code>int</code> as required! 

Take note that 'pointer' was mentioned 9 times. So within <code>ft_ultimate_ft</code>, we just need to use 9 asterisks to get to the <code>int</code> value:
<pre><code>*********nbr = 42;</code></pre>

</details>
