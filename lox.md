## The purpose of this file is simply to list out some of the important <u>Lox</u> semantics

- Global variables in Lox are "**late bound**" (late means *resolved after compile time i.e. at run-time*), or resolved dynamically. <br> This means something like the following works - 

```
fun showVariable() {
    print global;
}

var global = "after";
showVariable();
```
- Lox doesn't do *implicit* variable declaration
- Local variables are not late bound (*essentially, they should never be, hampers performance*). We use **lexical scoping** (*we can resolve a local variable just by looking at the text of the program i.e. not at run-time*)
