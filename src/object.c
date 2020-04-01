#include <stdio.h>
#include <object.h>

static const char *tags0[] = {"field", NULL};
static const char *tags1[] = {"cave", NULL};
static const char *tags2[] = {"silver", "coin", "silver coin", NULL};
static const char *tags3[] = {"gold", "coin", "gold coin", NULL};
static const char *tags4[] = {"guard", "fat guard", NULL};
static const char *tags5[] = {"yourself", NULL};
static const char *tags6[] = {"east", "entrance", NULL};
static const char *tags7[] = {"west", "out", NULL};
static const char *tags8[] = {"west", "north", "south", "forest", NULL};
static const char *tags9[] = {"east", "north", "south", "rock", NULL};

OBJECT objs[] = {
	// description					tags	location	destination
	{"an open field",				tags0,	NULL,	NULL},
	{"a little cave",				tags1, 	NULL,	NULL},
	{"a silver coin",				tags2, 	field,	NULL},
	{"a gold coin",					tags3, 	cave,	NULL},
	{"a fat guard",					tags4,	field,	NULL},
	{"yourself",					tags5,	field,	NULL},
	{"a cave entrance to the east", tags6, 	field,	cave},
	{"a cave exit to the west", 	tags7, 	cave,	field},
	{"a dense forest all around",	tags8, 	field,	NULL},
	{"solid rock all around",		tags9,	cave,	NULL}
};