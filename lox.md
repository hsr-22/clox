## The purpose of this file is simply to list out some of the important <u>Lox</u> semantics

- Global variables in Lox are "**late bound**", or resolved dynamically. <br> This means something like the following works - 

''' 
fun showVariable() {
    print global;
}

var global = "after";
showVariable();
'''
