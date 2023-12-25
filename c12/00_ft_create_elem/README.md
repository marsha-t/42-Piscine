## ft_create_elem

|               ft_create_elem        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_create_elem.c, ft_list.h |
| Allowed functions : malloc       |

- Create the function <code>ft_create_elem</code> which creates a new element of <code>t_list</code> type.
- It should assign data to the given argument and next to <code>NULL</code>.
- Here’s how it should be prototyped :
```
t_list *ft_create_elem(void *data);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include "ft_list.h"
#include <stdio.h>

int	main(void)
{
	char str[] = "abc";
	t_list *new;

	new = ft_create_elem(str);
	printf("%s", new->data);
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>abc</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

For C12, we will be using <code>ft_list.h</code>, which includes the following structure:

<pre><code>typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}					t_list</code></pre>

This is a node in a <u>linked list</u>. This node is of the data type <code>struct s_list</code> or <code>t_list</code> (its alias). Essentially, <code>t_list</code> will contain some data in its <code>data</code> member. Its <code>next</code> member will also contain a pointer to another <code>t_list</code>. With multiple such nodes, we can create a linear data structure where each node points to the one after it i.e., a list of nodes that are linked to each other. 

For this first <a href=ft_create_elem.c>exercise</a>, we will need to create a node:
- We first allocate space for a node using <code>malloc</code>. The space required is given by <code>sizeof(t_list)</code>. <code>new</code> is a pointer to this allocated space. 
- if allocation was successful, we can populate this new node (line 21):
	- <code>data</code> will be assigned to <code>new->data</code>. Note that <code>-></code> is used instead of the <code>.</code> operator since <code>new</code> is not a <code>t_list</code> but a pointer to a <code>t_list</code>
	- <code>new->next</code> is assigned to a null pointer for now. 
- <code>new</code>, the pointer to the new node, is then returned
- if allocation had been unsuccessful, <code>new</code> would be a null pointer and hence <code>ft_create_elem</code> would return a null pointer as well. 

</details>

