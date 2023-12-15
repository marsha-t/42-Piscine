## ft.h

|               ft.h        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft.h |
| Allowed functions : None       |

- Create your <code>ft.h</code> file.
- It should countain the prototypes of all the following functions:
```
void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
```

<details>
<summary><h3>Approach</h3></summary>

In C08, we start to create our own header files, starting with a header file called <a href=ft.h>ft.h</a>. The assignment provides the bulk of the answer already i.e., the function prototypes. What's left is to include the following wrapper which prevents a header file from being included multiple times. 

<pre><code>#ifndef FT_H

#define FT_H

/*The prototypes are here*/

#endif</code></pre>

 During compilation, the pre-processor opens the files <code>#included</code> in your .c file(s) and append them into a big text file before translating this text into machine-understandable code. If you have multiple .c files which include the <code>ft.h</code> header file (<code>#include "ft.h"</code>), the contents of <code>ft.h</code> will be appended multiple times. This <i>can</i> cause compiler errors. 

Note that in this case, including the contents of <code>ft.h</code> multiple times <u>without</u> this <code>#ifndef</code> wrapper doesn't lead to a compiler error because <code>ft.h</code> contains only function prototypes (which can be included multiple times in a program). The compiler error arises when the header file defines a variable and including this file (and the variable definition) multiple times will seem to the compiler like you are redefining a variable.

So how does the <code>#ifndef</code> wrapper work? This wrapper is a conditional directive for the preprocessor where <code>#ifndef FT_H</code> and <code>#define FT_H</code> checks whether <code>FT_H</code> has been defined before:
- If it has not (i.e., this is the first time the preprocessor is encountering <code>FT_H</code>), it will define <code>FT_H</code> and use the contents between <code>#define FT_H</code> and <code>#endif</code>.
- If it has, it skips <code>FT_H</code> by continuing after <code>#endif</code>.

</details>

