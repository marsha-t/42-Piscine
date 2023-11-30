## ft_strcapitalize

|               ft_strcapitalize        |
|---------------------------------|
| Turn-in directory : ex09/       |
| Files to turn in : ft_strcapitalize.c |
| Allowed functions : None       |

- Create a function that capitalizes the first letter of each word and transforms all other letters to lowercase.
- A word is a string of alphanumeric characters.
- Here’s how it should be prototyped :
```
char *ft_strcapitalize(char *str);
```
- It should return <code>str</code>.
- For example:
```
salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
```
- Becomes:
```
Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
```

<details>
<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int	main(void)
{
	char	str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	str2[] = "abC+aSa+AsA de0a AbC";
	char	str3[] = "123";
	char	str4[1] = "";
	char	str5[1];
	
	ft_strcapitalize(str1);
	ft_strcapitalize(str2);
	ft_strcapitalize(str3);
	ft_strcapitalize(str4);
	ft_strcapitalize(str5);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	printf("%s\n", str5);
	return (0);
}</code></pre>

When working with strings, it's useful to also test with empty (<code>str4</code>) and null (<code>str5</code>) strings. Even though this may not be required by the task, it can be useful to understand what happens when you do apply the function you've written to an empty or null string. 

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
Abc+Asa+Asa De0a Abc
123

U</code></pre>

The output for the last test using a null string may differ since it is undefined behaviour. 

</details>

<details>
<summary><h3>Approach 1: Capitalise what needs to be capitalised and make lowercase what needs to be lowercase</h3></summary>

This <a href=ft_strcapitalize_v1.c>exercise</a> uses a lot of helper functions to make <code>ft_strcapitalize</code> relatively succinct. Specifically, these helper functions are used to simplify the <code>if</code> statements within <code>ft_strcapitalize</code>.

 First, a <code>while</code> loop is used to go through each character in a string (line 43). When a character is alphabetical (line 45), there are additional checks for whether something needs to be made uppercase (line 47) or uppercase (line 49): 
 - Alphabetical characters that follow after non-alphanumeric characters as well as the first character of the string should be capitalised. It is important to use non-alphanumeric characters to define characters that are not part of words (as instructed). This is also clear from the example where words are not just separated by spaces but also <code>+</code>. 
 - Meanwhile, alphabetical characters within each word (i.e, those that follow alphanumeric characters) should be made lowercase. This is not immediately obvious from the example given in the assignment since everything is already lowercase but it was mentioned as part of the assignment. 

<pre><code>43	while (str[i] != '\0')
44	{
45		if ((ft_c_is_lowercase(str[i])) || (ft_c_is_uppercase(str[i])))
46		{
47			if ((ft_c_is_lowercase(str[i])) && ((!ft_c_is_alphaumeric(str[i - 1])) || (i == 0)))
48				str[i] = str[i] - ('a' - 'A');
49			else if ((ft_c_is_uppercase(str[i])) && (ft_c_is_alphaumeric(str[i - 1])))
50				str[i] = str[i] + ('a' - 'A');</code></pre>

Finally, an index variable <code>i</code> was used to select characters within <code>str</code> so that <code>str</code> continued to point at the first element of the array when it is returned. 

The helper functions contain the bulk of the <code>if</code> statements and evaluate to <code>1</code> or <code>0</code> depending on the character passed as an argument. However, within <code>ft_strcapitalize</code>, we did not explicitly specify the values returned by the helper functions e.g., we'd used <code>if (ft_c_is_lowercase(str[i]) ...)</code> instead of <code>if (ft_c_is_lowercase(str[i]) == 1 ...)</code>. This works because <code>0</code> is interpreted as false and anything non-zero interpreted as true in C.

</details>

<details>
<summary><h3>Approach 2.1: Make everything lowercase and then capitalise what needs to be capitalised</h3></summary>

In the previous approach, the function identified two types of characters that need to be changed: those that needed to be uppercase and those that needed to be lowercase. However, this could also be simplified by making everything uppercase or everything lowercase in the first place. 

In this <a href=ft_strcapitalize_v2_1.c>approach</a>, we'll make everything lowercase first, using the function created in a previous <a href=../08_ft_strlowcase>exercise</a>. Thereafter, the code looks similar to <a href=ft_strcapitalize_v1.c>Approach 1</a>, except that we only need to consider one situation where change needs to happen.

</details>

<details>
<summary><h3>Approach 2.2: Make everything uppercase and then make lowercase what needs to be lowercase</h3></summary>

Similar to <a href=ft_strcapitalize_v2_1.c>Approach 2.1</a>, this <a href=ft_strcapitalize_v2_2.c>approach</a> simplifies the number of changes that need to be specified. Everything is first capitalised using <a href=../07_ft_strupcase>ft_strupcase</a> before specific characters are made lowercase. 

</details>