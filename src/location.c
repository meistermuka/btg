#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

struct location {
	const char *description;
	const char *tag;
}
locs[] = {
	{"an open field", "field"},
	{"a little cave", "cave"}
};

#define numberOfLocations	(sizeof(locs) / sizeof(*locs))

static unsigned locationOfPlayer = 0;

void executeLook(const char *noun) {
	if (noun != NULL && strcmp(noun, "around") == 0) {
		printf("You are in %s\n", player->location->description);
		listOfObjectsAtLocation(player->location);
	} else {
		printf("I don't understand what you want to see.\n");
	}
}

void executeGo(const char *noun) {
	OBJECT *obj = parseObject(noun);

	if (obj == NULL) {
		printf("I don't understand where you want to go.\n");
	} else if (obj == player->location) {
		printf("You are already there");
	} else {
		printf("Ok.\n");
		player->location = obj;
		executeLook("around");
	}
	
}