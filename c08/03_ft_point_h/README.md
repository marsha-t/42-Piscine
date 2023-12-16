## ft_point.h

|               ft_point.h        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_point.h |
| Allowed functions : None       |

- Create a file <code>ft_point.h</code> that’ll compile the following main:
```
#include "ft_point.h"
void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
int main(void)
{
	t_point point;
	set_point(&point);
	return (0);
}
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include "ft_point.h"
#include &ltstdio.h&gt

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;

	printf("x: %d, y: %d\n", point.x, point.y);
	set_point(&point);
	printf("x: %d, y: %d\n", point.x, point.y);
	return (0);
}</code></pre>

The <code>printf</code> calls were added to the <code>main.c</code> code provided in the assigment so that we can see that <code>set_point</code> successfully assigned the values to <code>x</code> and <code>y</code>. 

See [testing file](main.c). 

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>x: -1708977184, y: 713
x: 42, y: 21</code></pre>

The first <code>printf</code> call attempts to display uninitialised variables which invokes undefined behaviour. Hence, your output for the first line wil likely be different. The key thing is that the second <code>printf</code> call shows that the values of <code>x</code> and <code>y</code> have been changed to <code>42</code> and <code>21</code> respectively.

</details>

<details>
<summary><h3>Approach</h3></summary>

As with a <a href=../01_ft_boolean_h>previous exercise</a>, the task becomes clearer once we scrutinise the <a href=main.c>main.c</a> code. The unfamiliar components are <code>t_point</code> and the arrow (<code>-></code>) operator.

A quick Google search on the arrow operator tells us that we will likely be dealing with a structure or a union:
- A structure is a user-defined data type that groups items of possibly different types (aka, the members of this group) into a single type. A structure thus contains data in multiple members at the same time. 
- A union is similar but only one member is stored. As a result, only one member can contain data at any time.

In either case, <code>-></code> is used to access a member when used in combination with a <u>pointer variable</u> pointing to a structure or union. This implies that <code>point</code> declared in the <code>main</code> function is either a structure or union. Which is it?

Well, since <code>set_point</code> appears to access two members (<code>x</code> and <code>y</code>), we can rule out that we are working with unions. Instead, we are working with a structure with two members <code>x</code> and <code>y</code>. Let's begin building our <a href=ft_point.h>solution</a> by creating this structure:

<pre><code>struct StructureName {
	int	x;
	int	y;
}</code></pre>

To use this structure in <code>main.c</code>, we will need to declare it as follows:

<pre><code>int main(void)
{
	struct StructureName struct1;
	struct.x = 10;
	struct.y = 12;
}</code></pre>

Note that we use <code>struct StructureName</code> the same way we use <code>int</code> or <code>char</code> to declare an <code>int</code> or <code>char</code> variable. It's unfortunately quite a long name for a datatype. To access and initialise the members in <code>struct1</code>, we then use the <code>.</code> operator.

But in <code>main.c</code>, the <code>struct</code> keyword was not used at all! Instead, to avoid having to use long names for datatypes, <code>typedef</code> is often used to create an alias for existing data types. For example, in <code>ft_point.h</code>, we create <code>t_point</code> as an alias for <code>struct StructureName</code>.

<pre><code>typedef struct StructureName {
	int	x;
	int	y;
}	t_point; </code></pre>

</details>

