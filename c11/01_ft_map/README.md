## ft_map

|               ft_map        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_map.c |
| Allowed functions : malloc       |

- Create the function <code>ft_map</code> which, for a given <code>int</code> array, applies a function on all elements of the array (in order) and returns a array of all the return values.
- This function will be applied following the array's order.
- Here’s how the function should be prototyped :
```
int *ft_map(int *tab, int length, int(*f)(int));
```
<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdlib.h&gt
#include &ltstdio.h&gt

int	ft_sq(int n)
{
	return (n * n);
}

int	main(void)
{
	int	i;
	int	*ptr;
	int	length;
	int	*ptr2;

	length = 5;
	ptr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		ptr[i] = i;
		i++;
	}
	ptr2 = ft_map(ptr, length, &ft_sq);
	i = 0;
	while (i < length)
	{
		printf("%d\n", ptr2[i]);
		i++;
	}
}</code></pre>

A function pointer to <code>ft_sq</code> is used to <code>ft_map</code>: This function squares <code>n</code>.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>0
1
4
9
16</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

Before we begin on the solution, let's investigate function <code>f</code>. As in the previous <a href=../00_ft_foreach>exercise</a>, <code>f</code> takes a <code>int</code> as an argument. But unlike the previous exercise, it now returns an <code>int</code> value.

This <a href=ft_map.c>solution</a>:
- allocates space for the array of returned <code>int</code> and returns a null pointer if this allocation was unsuccessful (lines 20-22);
- iterates through <code>tab</code> using <code>i</code> and a <code>while</code> loop (lines 23-28);
- applies the function <code>f</code> to each <code>int</code> in <code>tab</code> and assigns the returned <code>int</code> into the previously allocated space (line 26);
- the pointer to the start of the new array of <code>int</code> is returned (line 29).

<h4>Allocating space for the new array</h4>
Let's first examine the function <code>f</code>. This is a function that takes an <code>int</code> - which is good, since we want to apply it to all the <code>int</code> in <code>tab</code>. It then returns another <code>int</code>. From this, we now know that the array of returned values we need to return from <code>ft_map</code> is an array of <code>int</code>. 

Since the function <code>f</code> will be applied to all elements in <code>tab</code>, the new array to be returned will contain the same number of elements as the number of <code>int</code> in <code>tab</code>. With this information (i.e., the new array will contain <code>int</code>, precisely <code>length</code> of them), we can begin allocating space for the new array:

<pre><code>	ptr = (int *)malloc(sizeof(int) * length)</code></pre>

As usual if this allocation was unsuccessful, <code>malloc</code> returns a null pointer. <code>ft_map</code> will in turn return a null pointer as well (lines 21-22).

<h4>Applying the function to each <code>int</code> in <code>tab</code></h4>

<code>i</code> is used to index the <code>int</code> in <code>tab</code> and a <code>while</code> loop to iterate through all of them. We are given <code>length</code>, the number of <code>int</code> in <code>tab</code>, and hence we can simply loop from the first <code>int</code> in <code>tab</code> i.e., <code>(i = 0)</code> to the last <code>int</code> i.e., <code>i = length - 1</code>.

<code>f</code> is called and given an <code>int</code> argument - specifically <code>tab[i]</code>. This will return an <code>int</code> that will be stored in <code>ptr</code> (a pointer to where we'd allocated space). 

Finally, a pointer to the start of the new array is returned. Note that since we'd used <code>i</code> to index the new array, we have not moved <code>ptr</code> from the start of the array and can safely return <code>ptr</code> as is.

</details>

