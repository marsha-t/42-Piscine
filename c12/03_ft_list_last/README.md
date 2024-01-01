## ft_list_last

|               ft_list_last        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_list_last.c, ft_list.h |
| Allowed functions : None       |

- Create the function <code>ft_list_last</code> which returns the last element of the list.
- Here’s how it should be prototyped :
```
t_list *ft_list_last(t_list *begin_list);
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
	t_list	*empty;
	t_list	*last;

	node0 = ft_create_elem("abc");
	node1 = ft_create_elem("def");
	node2 = ft_create_elem("ghi");
	node0->next = node1;
	node1->next = node2;
	printf("List: %s, %s, %s\n", (node0)->data, (node0)->next->data, (node0)->next->next->data);
	last = ft_list_last(node0);
	printf("Last node: %s\n", last->data);
	printf("Empty List:\n");
	empty = 0;
	if (ft_list_last(empty) == 0)
		printf("null");
	return (0);
}</code></pre>

As before, even though we don't call <code>ft_create_elem</code> in <code>ft_list_last</code>, we will use it in <code>main.c</code> to create a linked list for testing. Hence, when compiling, we should  use <code>gcc ft_list_last.c main.c ft_create_elem.c</code>.

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>List: abc, def, ghi
Last node: ghi
Empty List:
null</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_list_last.c>approach</a> uses <code>current</code>, a pointer to a node, to iterate through the linked list. This is initialised with the start of the list i.e., <code>begin_list</code> (line 21). The <code>while</code> loop is then used to traverse through the linked list: in every iteration of the <code>while</code> loop, <code>current</code> is updated to point to the next node in the linked list (line 23). The <code>while</code> loop stops when <code>current</code> points at the last node in the list and the last node is indicated by having a null in its <code>next</code> member. Hence, the <code>while</code> loop condition is defined as <code>current</code> having a non-null <code>next</code> member (line 22). Eventually, <code>current</code>, which points to the last node, is returned (line 24)

If an empty list is passed into <code>ft_list_last</code> (i.e., <code>begin_list</code> is null), <code>ft_list_last</code> returns a null pointer immediately (line 19-20). At first glance, this may seem redundant (i.e., that the rest of the function would be able to return a null pointer in this scenario anyways):
- If <code>begin_list</code> is null, line 21 will assign a null pointer to <code>current</code>. 
- Since this null pointer does not have a <code>next</code> member, the <code>while</code> loop will not be executed at all
- Eventually, <code>current</code>, which is a null pointer at this point, is returned. 

However, the above logic misses the segmentation error that occurs in line 22. Since <code>current</code> is a null pointer, we can't actually access <code>next</code> and this causes a segmentation error. Not only is the <code>while</code> loop not executed but the rest of the function isn't either! Hence, to avoid forcing line 22 to access <code>current->next</code> with <code>current</code> as a null pointer, this scenario of an empty linked list is catered for early on in the function (line 19-20).


</details>

