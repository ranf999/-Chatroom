#include "chatserver.h"

Group *groups;
int groupNum;



int main(int argc, char *argv[])
{
    return 0;
}

void groupInit(char *filename)
{
	FILE *fp;
	char name[1024];
	int capacity;
	int groupId;
	
	fp = fopen(filename, "r");
	if(fp == NULL) {
		fprintf(stderr, "Cannot open file!\n");
		exit(1);
	}
	
	fscanf(fp, "%d", &groupNum);
	groups = (Group *)calloc(groupNum, sizeof(Group));
	if(groups == NULL) {
		fprintf(stderr, "unable to calloc\n");
		exit(1);
	}
	for(groupId = 0; groupId < groupNum; groupId++) {
		if(fscanf(fp, "%s %d", name, &capacity) != 2) {
			fprintf(stderr, "no info in file\n");
			exit(0);
		}

		groups[groupId].name = name;
		groups[groupId].capacity = capacity;
		groups[groupId].current = 0;
		groups[groupId]. members = NULL;
 	}
}


int listGroups(int sock)
{
	
}
int joinGroup(int sock, char *groupName, char *memName);
int leaveGroup(int sock);
int relaymsg(int sock, char *text);
int findGroup(char *name);
Member *findMemberByName(char *name);
Member *findMemberBySock(int sock);




