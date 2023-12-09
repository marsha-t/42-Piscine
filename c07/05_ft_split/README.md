## ft_split

|               ft_split        |
|---------------------------------|
| Turn-in directory : ex05/       |
| Files to turn in : ft_split.c |
| Allowed functions : malloc       |

- Create a function that splits a string of character depending on another string of
characters.
- You’ll have to use each character from the string <code>charset</code> as a separator.
- The function returns an array where each element of the array contains the address
of a string wrapped between two separators. The last element of that array should
equal to 0 to indicate the end of the array.
- There cannot be any empty strings in your array. Get your own conclusions accordingly.
- The string given as argument won’t be modifiable.
- Here’s how it should be prototyped :
```
char **ft_split(char *str, char *charset)
```

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt

int	main(void)
{
	char str[] = "abc def ghi ";

	printf("\\\\\\ Example 1: space as separator\n");
	char charsep1[] = " ";
	char **ptr1;
	ptr1 = ft_split(str, charsep1);
	printf("%s\n", ptr1[0]);
	printf("%s\n", ptr1[1]);
	printf("%s\n", ptr1[2]);

	printf("\\\\\\ Example 2: space and tab as separator\n");
	char charsep2[] = " \t";
	char **ptr2;
	ptr2 = ft_split(str, charsep2);
	printf("%s\n", ptr2[0]);
	printf("%s\n", ptr2[1]);
	printf("%s\n", ptr2[2]);

	printf("\\\\\\ Example 3: tab as separator\n");
	char charsep3[] = "\t";
	char **ptr3;
	ptr3 = ft_split(str, charsep3);
	printf("%s\n", ptr3[0]);

	printf("\\\\\\ Example 4: space as separator but string only has space\n");
	char *str2 = " ";
	char **ptr4;
	ptr4 = ft_split(str2, charsep1);
	printf("%s\n", ptr4[0]);
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>\\\ Example 1: space as separator
abc
def
ghi
\\\ Example 2: space and tab as separator
abc
def
ghi
\\\ Example 3: tab as separator
abc def ghi
\\\ Example 4: space as separator but string only has space
(null)</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

<a href=ft_split.c>ft_split</a> splits a longer string into various strings. I found it useful to think of the longer string as a sentence and the split strings as words. As a result, the function would split a sentence into individual words, using a space as a separator. The function will be slightly more complicated e.g., it will allow for multiple characters to be used as a separator but the basic idea is the same. 

With this framework in mind, this solution:
- counts the number of words in the sentence (i.e., in <code>str</code>) (using <code>ft_numwords</code>)
- allocates space for an array of character pointers (one for each word) and the null pointer needed to terminate the array (line 84). 
- If the above is unsuccessful, <code>ft_split</code> returns a null pointer (line 85-6)
- the null pointer to terminate the array is placed at the end of the array (line 87)
- iterate through the characters in <code>str</code>, copying characters into the correct space for each word and skipping over separators (given in charset) (lines 88-98 and using ft_putword)
- the pointer to the first character pointer in this array of character pointers is returned (line 99).

This solution will use <code>is_sep</code> to evaluate whether a character is a separating character. Specifically <code>is_sep</code> iterates through each character in <code>charset</code> and compares each one with <code>c</code>. If it is, <code>1</code> is returned immediately (line 22-23). Otherwise, the <code>while</code> loop moves on to the next character in <code>charset</code>. Reaching the end of the <code>while</code> loop with control remaining in <code>is_sep</code> means that <code>c</code> was not a character in <code>charset</code>. In this case, <code>0</code> will be returned (line 26).

<h4>Counting the number of words in str</h4>

Another helper function, <code>ft_numwords</code>, is used to count the number of words in <code>str</code>. It iterates through each character of <code>str</code>. In this <code>while</code> loop (lines 36-44), characters in <code>charset</code> are skipped, the beginning of each 'word' is counted and the rest of the word skipped:
- Using a nested <code>while</code> loop, characters in <code>charset</code> are skipped: if <code>str[i]</code> is a character in <code>charset</code>, <code>i</code> is incremented to reference the next character. This <code>while</code> loop caters for an arbitrary number of consecutive separating characters - If there are more than 1 consecutive separating characters (imagine <code>str</code> starting with multiple spaces), the nested loop skips past them; If there are <u>no</u> consecutive separating characters, the nested loop is skipped entirely to the next command. 
- At the end of this first <code>while</code> loop, regardless of the number of separating characters, <code>str[i]</code> will refer to a non-separating character. This can be the beginning of a word or the null terminator (i.e., <code>str</code> consisted only of separating characters). 
- <code>count</code> is incremented only if it is the beginning of a word. This is done via an <code>if</code> statement with the conditions that <code>str[i]</code> is neither a separating character nor a null terminator. This <code>if</code> statement can be streamlined further to only <code>if (str[i] != '\0')</code> since the first condition, <code>(!(is_sep(str[i], charset))</code>, is implied (it follows a <code>while</code> loop that can only end if a non-separating character was reached). However, I've retained this in the code as I find this version more intuitive. Note as well that an <code>if</code> statement was used so that only the first character of a word is counted and not all the characters in the word - after all, we are trying to count the number of <u>words</u>.
- A second nested <code>while</code> loop is used to iterate past the rest of the word. We want this <code>while</code> loop to stop when it reaches either a separating character or the null terminator. Hence, both conditions used for this <code>while</code> loop are needed. If (!(is_sep(str[i], charset)) is removed, the <code>while</code> loop iterates past separating characters and any subsequent words; if (str[i] != '\0') is removed, the <code>while</code> loop iterates past the null terminator and at that point, anything goes really (it depends on what was stored in the memory adjacent to where <code>str</code> is stored, which is anybody's guess).
- After iterating past the word, the <code>while</code> loop is exited if the end of the string, the null terminator, is reached. If it was not, the <code>while</code> loop goes through another round of iterating past separating characters, incrementing <code>count</code> and iterating past a word. 
- Broadly, with multiple nested <code>while</code> loops that increment <code>i</code>, it can be really easy to increment <code>i</code> past the null terminator and run into segmentation errors. This happens even if these <code>while</code> loops are nested within a bigger <code>while</code> loop that you'd think would stop <code>i</code> from incrementing past the null terminator (lines 36-44). However, this bigger <code>while</code> loop does this at the start of the <code>while</code> loop (when <code>i</code> is 0) and after line 43 (after the second nested <code>while</code> loop). It's important therefore to keep track of where <code>i</code> within the bigger while loop and not assume that <code>i</code> cannot increment past the null terminator just because a bigger <code>while</code> loop exists. In this solution, segmentation errors were avoided by making sure that the nested <code>while</code> loops include <code>str[i] != '\0'</code> in their conditions either explicitly (as in line 42) or implicitly (in line 38, where <code>str[i]</code> can't be <code>'\0'</code> if it is a separating character). 
- Note as well that the nested <code>while</code> loops could have been in reverse order to skip past a word and then the separating characters (as shown in the code below). After all, these <code>while</code> loops can handle an arbitrary number (including 0!) of separating characters and non-separating characters: they can deal with cases where <code>str</code> begins with a separating character and where <code>str</code> begins with a word. That said, do note that in the following code, all the conditions in the <code>if</code> statement are required. 

<pre><code>if (!(is_sep(str[i], charset)) && (str[i] != '\0'))
	count++;
while (!(is_sep(str[i], charset)) && (str[i] != '\0'))
	i++;
while (is_sep(str[i], charset))
	i++;</code></pre>

Phew, that seemed like a lot of work just to get the first part of this solution but this logic is consistently applied throughout so the rest of this will be a breeze. 

<h4>Splitting the words in <code>str</code></h4>

Next, <code>ft_split</code> calls <code>malloc</code> to cater space for character pointers to each word and the null pointer to terminate the array. At this point, space has <u>not</u> been allocated for each character array/string, only for character pointers. In other words, there is only space to hold the addresses for where the character arrays will be. 

Lines 88-98 are used to put the words in memory: 
- A <code>while</code> loop iterates through <code>str</code>. 
- In this <code>while</code> loop, separating characters are skipped. 
- Once <code>str[i]</code> refers to the beginning of a word, <code>ft_putword</code> allocates space for a word and copies the word from <code>str</code> into the allocated space
- Through the copying process, the word is iterated through. 
- In essence, the above mimics the same process used in <code>ft_numwords</code>!

For <code>ft_putword</code> to allocate space for a word, <code>ft_totlen</code> is used to calculate the length of the word. <code>ft_totlen</code> is given <code>str</code>, the index so far (<code>i</code>) and <code>charset</code>. Within the function, a <code>while</code> loop is used to iterate through all the characters of a word and increment <code>count</code> until either a separating character or a null terminator is reached. 

In line 66, <code>malloc</code> uses the value returned from <code>ft_totlen</code> to allocate sufficient space for a given word, including its null terminator (line 66). A similar <code>while</code> loop as that used in <code>ft_totlen</code> is used to iterate through all the characters in a word. These characters are copied over to the allocated space (line 70) before the index for <code>str</code> (<code>*i</code>) is incremented to refer to the next character and <code>j</code> is incremented to refer to the next byte that was allocated. Line 74 adds a null terminator and line 75 returns the address for the first element of this word (i.e., a character pointer). In line 95, this character pointer is assigned to one of the spaces we'd previously allocated (from line 84).

Note that a pointer to <code>i</code> instead of <code>i</code> is passed into <code>ft_putword</code>. This is so that <code>i</code> is updated even as we iterate through <code>str</code> <i>outside</i> of <code>ft_split</code>. 

Let's first imagine that the value of <code>i</code> was passed into <code>ft_putword</code>:

<pre><code>char *ft_putword(char *str, int n, char *charset)
{
	...
}

char **ft_split(char *str, char *charset)
{
	...
	ptr[k] = ft_putwords(str, i, charset);
}
</code></pre>

- a variable <code>n</code> is created to hold a copy of the value of <code>i</code>. <code>n</code> is a local variable to <code>ft_putword</code>. 
- <code>ft_putword</code> uses <code>n</code> to iterate through <code>str</code>. Specifically, <code>n</code> is used as an index to <code>str</code>; it is incremented whenever we want to access the next character in <code>str</code>. This continues until the end of a word. 
- When <code>ft_putword</code> ends and control returns to <code>ft_split</code>, the value of <code>i</code> remains the same as it was when it was passed into <code>ft_putword</code>. 

Now, let's see what happens when a pointer to <code>i</code> is passed into <code>ft_putword</code> (line 95) and <code>ft_putword</code> is configured to take an <code>int</code> pointer (line 61). 
- an <code>int</code> pointer <code>ip</code> is created and it holds a copy of the address of <code>i</code>. 
- <code>ft_putword</code> uses <code>i</code> to iterate through <code>str</code>, except that to get to <code>i</code>, it has to dereference the pointer <code>ip</code>. 
- When <code>ft_putword</code> ends and control returns to <code>ft_split</code>, <code>ft_split</code> can access the <u>updated</u> value of <code>i</code>. 

And that's all there is to it. Thanks for making it this far :)

</details>

