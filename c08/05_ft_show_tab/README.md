## ft_show_tab

|               ft_show_tab        |
|---------------------------------|
| Turn-in directory : ex05/       |
| Files to turn in : ft_show_tab.c |
| Allowed functions : write       |

- Create a function that displays the content of the array created by the previous function.
- Here’s how it should be prototyped:
```
void ft_show_tab(struct s_stock_str *par);
```
- The structure will be the same as the previous exercise and will be defined in the <code>ft_stock_str.h</code> file
- For each element, we’ll display:
	- the string followed by a <code>'\n'</code>
	- the size followed by a <code>'\n'</code>
	- the copy of the string (that could have been modified) followed by a <code>'\n'</code>
- We’ll test your function with our <code>ft_strs_to_tab</code> (previous exercise). Make it work according to this !

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include "ft_stock_str.h"
#include &ltstdio.h&gt

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(void)
{
	char	*strs[3] = {"abceee", "de", "ghiddf"};

	ft_show_tab(ft_strs_to_tab(3, strs));
	return (0);
}</code></pre>

<code>ft_stock_str.h</code> has to be included so that the program can access the created <code>t_stock_str</code> structure. I've retained this header file as specified in the previous <a href=../04_ft_strs_to_tab>exercise</a> i.e., the file only contains the creation of <code>t_stock_str</code>. 

Consequently, <code>main.c</code> will also need to include the function prototype for <code>ft_strs_to_tab</code>.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>abceee
6
abceee
de
2
de
ghiddf
6
ghiddf</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_show_tab.c>approach</a> iterates the array of <code>t_stock_str</code> using a <code>while</code> loop. <code>i</code> is used to index this array and naturally starts at <code>0</code> to reference the first element of the array. But how do we know the end of the array?

This detail was given in the <a href=../04_ft_strs_to_tab>last exercise</a>: the last <code>t_stock_str</code> has its <code>str</code> member set to <code>0</code>. We can therefore use this to define our <code>while</code> loop condition. 

For each <code>t_stock_str</code>, we use <code>ft_putstr</code> (from a <a href=../../c01/05_ft_putstr>previous exercise</a>) to display <code>str</code> and <code>copy</code> and <code>ft_putnbr</code> (also from a <a href=../../c00/07_ft_putnbr>previous exercise</a>) to display <code>size</code>. For this exercise, <code>ft_putnbr</code> is simplified since we will not be displaying any negative values (<code>size</code> will never be negative).

Finally, we just need to make sure that the displayed strings and numbers are separated by new lines (line 43, 44 and 45). That's it!

</details>
