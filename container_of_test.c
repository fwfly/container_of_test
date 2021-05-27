#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) * __mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })



/* The student structure definition */
typedef struct student {
     char name[16];
     int id;
     char addr[64];
     char phone_num[16];
}STUDENT, *STUDENT_PTR;

void print_id(char *phone_numP){
    STUDENT_PTR stdP = NULL;
    stdP = container_of(phone_numP, struct student, phone_num );
    printf("%s : %d\n", stdP->name, stdP->id);
}

int main(){
    STUDENT_PTR stdP = NULL;
    stdP = (STUDENT_PTR) malloc(sizeof(STUDENT));
    strncpy(stdP->name, "Sheng-Wen", sizeof(stdP->name));
    stdP->id=9527;
    strncpy(stdP->addr, "homeless", sizeof(stdP->addr));
    strncpy(stdP->phone_num, "0800092000", sizeof(stdP->phone_num));
    print_id(stdP->phone_num);
    return 0;
}
