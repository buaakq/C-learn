#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu{
	int ID;
	char name[32];
};

void visit(struct stu *s)
{
	printf("my name is %s id is %d\n", s->name, s->ID);
}

int main()
{
	struct stu* s = malloc(sizeof(struct stu) * 2);
	s[0].ID  = 1;
	strcpy(s[0].name, "kang");
	visit(&s[0]);

	s[1].ID  = 2;
	strcpy(s[1].name, "xie");
	visit(&s[1]);

	return 0;
}
