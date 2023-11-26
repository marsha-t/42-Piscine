## ft_sort_int_tab

|               ft_sort_int_tab        |
|---------------------------------|
| Turn-in directory : ex08/       |
| Files to turn in : ft_sort_int_tab.c |
| Allowed functions : None       |

- Create a function which sorts an array of integers by ascending order.
- The arguments are a pointer to int and the number of ints in the array.
- Here’s how it should be prototyped :
```
void ft_sort_int_tab(int *tab, int size);
```

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	int	num[4];

	num[0] = 3;
	num[1] = 2;
	num[2] = 1;
	num[3] = 0;
	printf("Before: %d, %d, %d, %d\n", num[0], num[1], num[2], num[3]);
	ft_sort_int_tab(num, 4);
	printf("After:  %d, %d, %d, %d\n", num[0], num[1], num[2], num[3]);
	return (0);

}

</pre></code>

See [testing file](main.c)

</details>
<details>
<summary><h3>Output</h3></summary>
<pre><code>Before: 3, 2, 1, 0
After:  0, 1, 2, 3</code></pre>
</details>


<details>
<summary><h3>Approach 1: Compare an integer with the next integer </h3></summary>
As with the last <a href=../07_ft_rev_int_tab/ft_rev_int_tab.c>exercise</a>, this <a href=ft_sort_int_tab_v1.c>answer</a> involves the swapping of integers within the array. Specifically, we compare an integer with the integer that comes after it and swap them if they are not in order. 

We will use <code>i</code> to select an element of the array and compare this element with the next. We will need to loop through all the elements except the last one. Hence, the <code>while</code> loop condition is defined as <code>i < size - 1</code> (which is equivalent to <code>i <= size - 2</code>). If we allow <code>i</code> to reach <code>size - 1</code> (i.e, to refer to the last element), we would be asking the machine to compare the last element to the element that comes after it (which does not exist!).

Within this loop, if the integers are out of order (line 21), we swap them (lines 23-25); Otherwise, we move along the array (line 29). 
<pre><code>21	if (tab[i] > tab[i + 1])
22	{
23		temp = tab[i];
24		tab[i] = tab[i + 1];
25		tab[i + 1] = temp;
26		i = 0;
27	}
28	else
29		i++;</code></pre>

Sounds simple enough but with this approach, it is important to remember to reset <code>i</code> whenever we swap integers (line 26). Imagine an array of <code>{2, 3, 1}</code> to sort:
- When <code>i = 0</code>, we compare <code>2</code> to <code>3</code> and move on to <code>i = 1</code>. 
- When <code>i = 1</code>, we compare <code>3</code> to <code>1</code> and swap them. The array would then look like this: <code>{2, 1, 3}</code>.
- The function should return to <code>i = 0</code> so that <code>2</code> and <code>1</code> are swapped and the final array is in order: <code>{1, 2, 3}</code>. 
In essence, resetting <code>i = 0</code> forces the function to check that the newly swapped integer is placed in the correct order among all the other integers that have been checked before. 
</details>

<details>
<summary><h3>Approach 2: Compare an integer with all the integers that come after it</h3></summary>
Instead of resetting <code>i</code> after every swap, another <a href=ft_sort_int_tab_v2.c>approach</a> would be to compare an integer with <u>all</u> the other integers that come after it. 

As before, <code>i</code> is used to select an element of the array and a <code>while</code> loop used to go through all the elements in the array except the last one. Other than this, we will also use <code>j</code> to select the elements that come after <code>i</code>. We initialise <code>j = i + 1</code> and loop through all the elements until and including the last element. Within these nested <code>while</code> loops, an <code>if</code> statement is used to swap these <code>i</code> and <code>j</code> elements whenever they are not in order. 

<pre><code>19	i = 0;
20	while (i < size - 1)
21	{
22		j = i + 1;
23		while (j < size)
24		{
25			if (tab[i] > tab[j])
				...
31			j++;
32		}
33		i++;
34	} </code></pre>

</details>
