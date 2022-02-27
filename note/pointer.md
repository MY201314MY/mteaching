



###### 确认数组尺寸的大小

```c
#include <stdio.h>

int a[10] = {3};

#define SIZE(array) ((sizeof(array))/sizeof(array[0]))

int main()
{
    printf("size:%lu\r\n", SIZE(a));

    return 0;
}
```

###### 指针数组

```c
#include <stdio.h>
/* "[]"的优先级高于"*" */

typedef struct {
    int value;
} Node_t;

Node_t *po, value;

int main()
{
    char abc[] = "hello, world.";
    char *xyz = "uname -a";
    char *pointer[] = {"ls", "Amazon", "Beijing", "Shanghai"};
    char **baidu = {"ls", "Amazon", "Beijing", "Shanghai"};

    char ***address = &baidu;

    printf("%s\r\n", *pointer);
    printf("%s\r\n", pointer[0]);
    printf("%s\r\n", pointer[1]);
    printf("%s\r\n", *(pointer+1));
    printf("%c\r\n", (*(pointer+1))[3]);
    printf("%c\r\n", *(*(pointer+1) + 3));
    printf("%s\r\n",  (*(pointer+1) + 3));
    printf("%c\r\n", (*pointer)[0]);

    value.value = 3;
    po = &value;

    printf("%d\r\n", po->value);
    printf("%d\r\n", (*po).value);

    return 0;
}
```

数组指针

```c
#include <stdio.h>

int main()
{
    int array[3][4] = { 1, 2, 3, 4,
                        5, 6, 7, 8,
                        9,10,11,12,
                        13,14,15,16};

    int (*p)[4] = array;

    printf("%d\r\n", **(array+1));
    printf("%d\r\n", *(*(array+1)+2));

    return 0;
}
```

###### 布尔类型的运算结果

```c
#include <stdio.h>

int main()
{
    int a=1, b=2, c=3;

    int i = a++ || b++ || c++;

    printf("%d - %d - %d - %d\r\n", i, a, b, c);

    return 0;
}
/* 1 - 2 - 2 - 3*/
```

**"e"的作用**

```c
#include <stdio.h>

int main()
{
    printf("%f", 2e3);

    return 0;
}
/* 2000.000000 */
```

