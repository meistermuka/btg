#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

OBJECT *parseObject(const char *noun) {
	OBJECT *obj, *found = NULL;
	for (obj = objs; obj < endOfObjs; obj++) {
		if (noun != NULL && strcmp(noun, obj->tag) == 0) {
			found = obj;
		}
	}

	return found;
}

OBJECT *personHere(void) {
	OBJECT *obj;

	for (obj = objs; obj < endOfObjs; obj++) {
		if (obj->location == player->location && obj == guard) {
			return obj;
		}
	}
	return NULL;
}

int listOfObjectsAtLocation(OBJECT *location) {
	int count = 0;
	OBJECT *obj;

	for(obj = objs; obj < endOfObjs; obj++) {
		if (obj != player && obj->location == location) {
			if (count++ == 0) {
				printf("You see:\n");
			}
			printf("%s\n", obj->description);
		}
	}

	return count;
}

OBJECT *getPassageTo(OBJECT *targetLocation) {
	OBJECT *obj;
	for (obj = objs; obj < endOfObjs; obj++) {
		if (obj->location == player->location && obj->destination == targetLocation) {
			return obj;
		}
	}
	return NULL;
}