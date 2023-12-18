## ft_strs_to_tab

|               ft_strs_to_tab        |
|---------------------------------|
| Turn-in directory : ex04/       |
| Files to turn in : ft_strs_to_tab.c |
| Allowed functions : malloc, free       |

<ul>

<li>Create a function that takes an array of string as argument and the size of this array.</li>
<li>Here’s how it should be prototyped:</li>

<pre><code>struct s_stock_str *ft_strs_to_tab(int ac, char **av);</code></pre>

<li>It will transform each element of av into a structure.</li>
<li>The structure will be defined in the <code>ft_stock_str.h</code> file that we will provided, like this:</li>

<pre><code>typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;</code></pre>

<ul>
	<li><code>size</code> being the length of the string;</li>
	<li><code>str</code> being the string;</li>
	<li><code>copy</code> being a copy of the string;</li>
</ul>

<li>It should keep the order of <code>av</code>.</li>
<li>The returned array should allocated in memory and its last element’s <code>str</code> set to <code>0</code>, this will mark the end of the array.</li>
<li>It should return a <code>NULL</code> pointer if an error occurs.</li>
<li>We’ll test your function with our <code>ft_show_tab</code> (next exercise). Make it work according to this!</li>
</ul>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_strs_to_tab.c>exercise</a> will be tackled together with the <a href=../05_ft_show_tab>next one</a> since the latter will be needed for us to test this exercise. Both exercises rely on functions that have been created in previous exercises. The tricky bit is using these functions in the context of a structure: we have to access the members in a structure using the <code>.</code> operator and that's it (so not terribly tricky after all). 

We are given <code>ft_stock_str.h</code> which creates a structure contain an <code>int</code> and two string (<code>char *</code>) member. This structure is given an alias of <code>t_stock_str</code>. Note that creating an alias <code>t_stock_str</code> does not mean that <code>struct s_stock_str</code> can no longer be used in the code. In fact, struct s_stock_str is used in the definition of <code>ft_strs_to_tab</code> (which returns a pointer to this structure).

The solution:
- allocates space for an array of <code>t_stock_str</code> and returns a null pointer when this is unsuccessful (lines 49-52);
- iterates through each string in <code>av</code> to fill up the allocated space (lines 52-59);
- <code>ft_strlen</code> is used to fill up <code>size</code> (line 55);
- <code>str</code> is pointed to the the string in <code>av</code> (line 56);
- space for a copy of <code>str</code> allocated and <code>ft_strdup</code> used to populate this allocated space. Thereafter, a character pointer to the start of this copied string is assigned to <code>copy</code> (line 57);
- <code>str</code> in the last element is set to <code>0</code> before a pointer to the array of <code>t_stock_str</code> is returned (lines 60-61)

<h4>Including <code>ft_stock_str.h</code></h4>
First, to access the structure <code>t_stock_str</code> created in <code>ft_stock_str.h</code>, this header file is included by using: <code>#include "ft_stock_str.h"</code>. Double quotes (<code>""</code>)are used instead of chevrons (<code><></code>) to inform the compiler to look for the header file in the current directory first. Otherwise, with <code><></code>, the compiler will search the system headers first. 

<h4>Allocating space for an array of <code>t_stock_str</code></h4>
Next, we use <code>malloc</code> to allocate space for an array of structures, specifically the structure called <code>t_stock_str</code>. Our array will contain <code>ac + 1</code> such structures, with the last structure functioning like a null terminator in a string (its <code>str</code> will be set to <code>0</code>). We simply multiply <code>(ac + 1)</code> by <code>sizeof(t_stock_str)</code> to get the amount of memory we will need for this array. The <code>sizeof</code> operator is incredibly useful in this case: if we were to calculate the size of <code>t_stock_str</code>, we may compute it as <code>sizeof(int) + sizeof(char *) + sizeof(char *)</code>. Unfortunately, this could be off since padding may be added between structure members so that they are aligned in memory. It's not terribly important to understand such alignment issues when coding but this is your friendly reminder to use <code>sizeof</code>, instead of making your life more difficult than it already has to be! 

A couple of notes:
- If <code>malloc</code> was unsuccessful, it will return a null pointer. In this case, <code>ft_strs_to_tab</code> will also return a null pointer (lines 50-51).
- Note that space hasn't been allocated for the <u>strings</u> that <code>str</code> and <code>copy</code> will point to. <code>str</code> and <code>copy</code> are character <u>pointers</u> and <code>malloc</code> allocated space for a <code>t_stock_str</code> structure containing these two character pointers and an <code>int</code> variable. 

<h4>Filling up the array of <code>t_stock_str</code></h4>

<code>i</code> is used to index <code>av</code> and together with a <code>while</code> loop (lines 52-59), is used to iterate through all the strings in <code>av</code>. At the same time, <code>i</code> is used to index the <code>ret</code>, the array of <code>t_stock_str</code> structures. To access the members within a structure, we use the <code>.</code> operator. For instance, <code>ret[0].size</code> accesses <code>size</code> in the first <code>t_stock_str</code> structure in the array. 

For each string, <code>ft_strlen</code> computes the length of the string. This helper function is directly copied over from a <a href=../../c01/06_ft_strlen>previous exercise</a>. 

To populate <code>str</code>, bear in mind that the string already exists in memory somewhere, and <code>av[i]</code> holds a character pointer to the start of that string. We could copy this string over again but why not have the <code>str</code> character pointer point to the same string/address that <code>av[i]</code> points to (line 56). Here, there's no need for multiple copies (that's coming up next). 

Finally, <code>copy</code> will point to a <u>copy</u> of the string pointed to by <code>av[i]</code> and <code>str</code>. <code>ft_strdup</code> will allocate space for a copy of the string pointed to by <code>av[i]</code> and populate it as well. This helper function is also taken from an <a href=../../c07/00_ft_strdup>earlier exercise</a>. Note that if <code>ft_strdup</code> was unsuccessful in allocating space for a copy of the string, it returns a null pointer i.e., <code>ret[i].copy</code> will have a null pointer. However,  <code>ft_strs_to_tab</code> will not return a null pointer due to this error. 

<h4>Finishing touches</h4>
The last structure in the array will not be populated. The only thing is to set the <code>str</code> member to <code>0</code> as mentioned in the assignment before returning <code>ret</code>. Specifically, <code>ft_strs_to_tab</code> will return a pointer to a <code>t_stock_str</code>, the first of such structures in the array of <code>t_stock_str</code>.

</details>

