#include <stdio.h>
#include <string.h>

int main()
{

	// char array (not directly modifiable using = but can be with strcpy(), string stored in .text)
	char name_0[] = "test str 1";
	printf("%s \n\n", name_0);
	// in array decay, the name of the array is the same as the address of the first element
	printf("%s \n\n", &(name_0[0]));


 	// char array using strcpy (initializing using a known buffer length is best practice)
	char name_1[20];
	strncpy(name_1, "test str 2", sizeof("test str 2"));
	printf("%s \n\n", name_1);
 
	// pointer to char array (modifiable)
	char *name_1_ptr = name_1;
	printf("%s \n\n", name_1_ptr);
 
	// char pointer (where the pointer points is modifiable, string stored in .rodata). Const pointer reflects that this is not modifiable during runtime.
	const char *name_2 = "test str 3";
	printf("%s \n\n", name_2);
	

	// array of char pointers
	char a = 'a', b = 'b', c = 'c';
	char *name_3[3] = {&a, &b, &c};
	for (int i = 0; i < 3; i++)
	{
		printf("Element %d holds pointer %p which references value %d \n", i, name_3[i], *name_3[i]);
	}
	

	// array of char (array) pointers
	char *name_4[4] = {"a","bc","def","ghij"};
	for (int i = 0; i < 4; i++){
		printf("Element %d holds pointer %p which references value %d \n", i, name_4[i], *name_4[i]);	
	}  
	
}