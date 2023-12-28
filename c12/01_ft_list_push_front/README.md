## ft_list_push_front

|               ft_list_push_front        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_list_push_front.c, ft_list.h |
| Allowed functions : ft_create_elem       |

- Create the function <code>ft_list_push_front</code> which adds a new element of type <code>t_list</code> to the beginning of the list.
- It should assign <code>data</code> to the given argument.
- If necessary, it’ll update the pointer at the beginning of the list.
- Here’s how it should be prototyped :
```
void ft_list_push_front(t_list **begin_list, void *data);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include "ft_list.h"
#include &ltstdio.h&gt

int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	**begin;

	node0 = ft_create_elem("abc");
	node1 = ft_create_elem("def");
	node2 = ft_create_elem("ghi");
	node0->next = node1;
	node1->next = node2;
	begin = &node0;
	printf("Before: %s, %s, %s\n", (*begin)->data, (*begin)->next->data, (*begin)->next->next->data);
	ft_list_push_front(begin, "123");
	printf("After:  %s, %s, %s, %s\n", (*begin)->data, (*begin)->next->data, (*begin)->next->next->data, (*begin)->next->next->next->data);
	return (0);
}</code></pre>

To compile, use <code>gcc ft_list_push_front.c main.c ft_create_elem.c</code> need to include <code>ft_create_elem.c</code> used in the <code>ft_list_push_front.c</code>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Before: abc, def, ghi
After:  123, abc, def, ghi</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

For this <a href=ft_list_push_front.c>solution</a>, 

- we include the function prototype for <code>ft_create_elem</code> in <code>ft_list.h</code> for us to use. For convenience, a copy of <code>ft_create_elem.c</code> also included in this directory. 
- If <code>begin_list</code> is an empty list (i.e., the address it points to doesn't contain anything), we will create a new list with the <code>data</code> provided. This is simply done by calling <code>ft_create_elem</code> to create the node with <code>data</code>. This pointer to this new node is then assigned to the address that <code>begin_list</code> points to. (Lines 25-26) 
- If there is already an existing list (i.e., <code>begin_list</code> points to the address of a <code>t_list</code> structure), we will also create a new node using <code>ft_create_elem</code> and assign its address to <code>new</code> (line 21). Note that <code>new</code> is the address of the new node and not the new node itself. Since the new node is to be inserted at the front of the linked list, the <code>next</code> member of the new node will be assigned to the start of the line pointed to by <code>begin_list</code> (line 22). We have placed the new node in the correct order! To ensure that the next use of <code>begin_list</code> refers to the front of the linked list, we assign the address of the new node to the address that <code>begin_list</code> points to (line 23). 

</details>

