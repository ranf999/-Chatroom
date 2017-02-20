#ifndef _CHATSERVER_H_
#define _CHATSERVER_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include "global.h"

typedef struct _member {
	int memId;
	char *name;
	int sock;
	int groupId;
	struct _member *next;
	struct _member *prev;
} Member;

typedef struct _group {
	int groupId;
	char *name;
	int capacity;
	int current;
	struct _member *members;
} Group;

void groupInit(char *filename);
int listGroups(int sock);
int joinGroup(int sock, char *groupName, char *memName);
int leaveGroup(int sock);
int relaymsg(int sock, char *text);
int findGroup(char *name);
Member *findMemberByName(char *name);
Member *findMemberBySock(int sock);




#endif 
