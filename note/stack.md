#### stack

**Debug in VS Code**

```c
#include <stdio.h>

int va=0, vb=1, vc=2;

void function(int a, int b, int c)
{
    /* stack: max --> min. Don't use a array.*/
    int *x = &a;
    int *y = &b;
    int *z = &c;

    int l, m, n;

    x = &l;
    y = &m;
    z = &n; 
    /* heap: min --> max may not */
    int *pa=&va;
    int *pb=&vb;
    int *pc=&vc;
}

int main()
{
    int x[4] = {1, 2, 3, 4};

    function(16, 102, 45);

    return 0;
}
```

