#include "structure.h"
int input_to_system(){
    struct student stu[3];
    struct student *p = stu;

    void input(struct student stu[]);

    input(stu);

    for(int i=0; i<_number; i++) {
        printf("%s\t%.2lf\t%.2lf\t%.2lf\n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].aver);
    }

    return 0;
}

void input(struct student stu[]){
    printf("Please input the name and grades:\r\n");

    for(int i=0; i< _number; i++) {
#ifdef DEBUG
        printf("A new group of data. . .\r\n");
#endif
        scanf("%s%f%f",&stu[i].name,&stu[i].score[0],&stu[i].score[1]);
        stu[i].aver=(stu[i].score[0]+stu[i].score[1])/2.0;
    }
}

void find_next(){
    lanuage a, b, c, *p;

    strcpy(a.message, "Python");a.next = &b;
    strcpy(b.message, "JavaScript");b.next = &c;
    strcpy(c.message, "C");c.next = NULL;
    p = &a;
    do {
        printf("name: %s\r\n", p->message);
        p = p->next;
    } while (p != NULL);
}
