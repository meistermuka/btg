#include <stdio.h>
#include <object.h>

OBJECT objs[] = {
	// description		tag		location	destination
	{"an open field",	"field",	NULL,	NULL},
	{"a little cave",	"cave", 	NULL,	NULL},
	{"a silver coin",	"silver", 	field,	NULL},
	{"a gold coin",		"gold", 	cave,	NULL},
	{"a fat guard",		"guard",	field,	NULL},
	{"yourself",		"yourself",	field,	NULL},
	{"a cave entrance", "entrance", field,	cave},
	{"a cave exit", 	"out", 		cave,	field}
};