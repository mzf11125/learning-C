#include <stdio.h>
int main(){
	char strings[106];
	scanf("%[^\n]",strings);
	printf("#include <stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	printf("    printf(\"%%s\\n\",\"%s\");\n",strings);
	printf("    return 0;\n");
	printf("}\n");
	return 0;
}