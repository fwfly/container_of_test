# container_of_test

## Usage
```
$ gcc container_of_test.c
$ ./a.out

# output 
$ ./a.out 
stdP:      0x7f92b1405920
phone_num: 0x7f92b1405974
Container_of: 0x7f92b1405920
Cloud Strife : 9527

Teacher name: Sephiroth
```
You can see the address extracted by container_of is the same as stdP which is declared at the beginning of the code.

the teacher name was copied without declaration.
This proved a legal memory can be operated without declaring.

the original example is from here http://adrianhuang.blogspot.com/2010/01/linux-kernel-containerof.html
