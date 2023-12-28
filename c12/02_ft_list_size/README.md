## ft_list_size

|               ft_list_size        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_list_size.c, ft_list.h |
| Allowed functions : None       |

- Create the function <code>ft_list_size</code> which returns the number of elements in the list.
- Here’s how it should be prototyped :
```
int ft_list_size(t_list *begin_list);
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include "ft_list.h"
#include &ltstdlib.h&gt
#include &ltstdio.h&gt

int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	*empty;

	node0 = ft_create_elem("abc");
	node1 = ft_create_elem("def");
	node2 = ft_create_elem("ghi");
	node0->next = node1;
	node1->next = node2;
	printf("List: %s, %s, %s\n", (node0)->data, (node0)->next->data, (node0)->next->next->data);
	printf("Size: %d\n", ft_list_size(node0));
	empty = 0;
	printf("Empty List:\n");
	printf("Size: %d\n", ft_list_size(empty));
	return (0);
}</code></pre>

Note that while we will not call <code>ft_create_elem</code> in <code>ft_list_size</code>, we will use it in <code>main.c</code> to create a linked list for testing. Hence, when compiling, we should continue to use <code>gcc ft_list_size.c main.c ft_create_elem.c</code>.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>List: abc, def, ghi
Size: 3
Empty List:
Size: 0</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_list_size.c>solution</a>
- uses <code>size</code> to keep track of the number of nodes that we traversed through in the provided linked list. This is initialised to <code>0</code> (line 21). 
- uses <code>current</code>o iterate through nodes in the linked list and this is first initialised to <code>begin_list</code> i.e., the start of the linked list (line 22). 
- To aid in the iteration, a <code>while</code> loop is used as long as <code>current</code> is a non-empty node. To move onto the next node, <code>current</code> is assigned to the next member (line 25)
- As we move through the linked list, we add to <code>size</code>. 
- When <code>current</code> no longer points to a valid node, we have reached the end of the linked list and can return <code>size</code> (line 28)
- Note that if <code>begin_list</code> was a null pointer (i.e., there's no list), <code>current</code> will also be a null pointer. The <code>while</code> loop is skipped entirely and a value of <code>0</code> is returned. 

</details>

