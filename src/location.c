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
		OBJECT *obj = parseObject(noun);
		DISTANCE distance = distanceTo(obj);

		if (distance >= distUnknownObject) {
			printf("I don't understand what you want to see.\n");
		} else if (distance == distNotHere) {
			printf("You don't see any %s here.\n", noun);
		} else if (distance == distOverthere) {
			printf("Too far away, move closer please.\n");
		} else if (distance == distHereContained) {
			printf("Hard to see, try to get it first.\n");
		} else {
			printf("%s\n", obj->details);
			listOfObjectsAtLocation(obj);
		}
	}
}

static void movePlayer(OBJECT *passage) {
	printf("%s", passage->textGo);
	if (passage->destination != NULL) {
		player->location = passage->destination;
		printf("\n");
		executeLook("around");
	}
}

void executeGo(const char *noun) {
	OBJECT *obj = parseObject(noun);
	DISTANCE distance = distanceTo(obj);

	if (distance >= distUnknownObject) {
		printf("I don't understand where you want to go.\n");
	} else if (distance == distLocation) {
		printf("You are already there");
	} else if (distance == distOverthere) {
		movePlayer(getPassageTo(obj));
	} else if (distance == distHere) {
		movePlayer(obj);
	} else if (distance < distNotHere) {
		printf("You cannot get any closer than this.\n");
	} else {
		printf("You do not see any %s here.\n", noun);
	}
	
}