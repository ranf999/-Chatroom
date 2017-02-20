#ifndef _GLOBAL_H_
#define _GLOBAL_H_

typedef struct _packet {
	char type;
	long length;
	char *text;
} Packet;

#endif
