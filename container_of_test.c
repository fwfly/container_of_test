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

typedef struct teacher{
     char name[16];
     STUDENT student;
}TEACHER, *TEACHER_PTR;


void print_id(char *phone_numP){
    STUDENT_PTR stdP = NULL;
    stdP = container_of(phone_numP, struct student, phone_num );
    printf("Container_of: %p\n", stdP);
    printf("%s : %d\n", stdP->name, stdP->id);
}

int main(){
    STUDENT_PTR stdP = NULL;
    stdP = (STUDENT_PTR) malloc(sizeof(STUDENT));
    strncpy(stdP->name, "Cloud Strife", sizeof(stdP->name));
    stdP->id=9527;
    strncpy(stdP->addr, "Shinra Corp", sizeof(stdP->addr));
    strncpy(stdP->phone_num, "0800092000", sizeof(stdP->phone_num));
    // Verify container_of address
    printf("stdP:      %p\n", stdP);
    printf("phone_num: %p\n", &stdP->phone_num);
    print_id(stdP->phone_num);
    printf("\n");


    // Dynamically change teacher's name after container_of even without allocate a memory.
    TEACHER_PTR teacherP = NULL;
    teacherP = container_of(stdP, struct teacher, student );
    strncpy(teacherP->name, "Sephiroth", sizeof(teacherP->name));
    printf("Teacher name: %s\n", teacherP->name);
    
    return 0;
}
