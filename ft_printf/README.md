# ft_printf

This is my implementation of printf. The project primarily aimed at gaining insights into variadic functions. Additionally, I intend to apply this knowledge in upcoming projects as part of the curriculum.

The prototype of ft_printf() is:
int ft_printf(const char *, ...);

Here are the requirements:

• Don’t implement the buffer management of the original printf().

• Your function has to handle the following conversions: cspdiuxX%

• Your function will be compared against the original printf().

• You must use the command ar to create your library.
Using the libtool command is forbidden.

• Your libftprintf.a has to be created at the root of your repository.



# usage
clone the repository

```
git clone git@github.com:Robin-Lenz/ft_printf.git ft_printf
```

enter the directory
```
cd ft_printf
make
```
compile your project with ft_printf, for example

```
cc main.c libftprintf.a
```
you can use ft_printf() in your code now
