#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

static int nounIsInTags(const char *noun, const char **tags) {
	while (*tags != NULL) {
		if (strcmp(noun, *tags++) == 0) return 1;
	}
	return 0;
}

OBJECT *parseObject(const char *noun) {
	OBJECT *obj, *found = NULL;
	for (obj = objs; obj < endOfObjs; obj++) {
		if (noun != NULL && nounIsInTags(noun, obj->tags) && distanceTo(obj) < distanceTo(found)) {
			found = obj;
		}
	}

	return found;
}

OBJECT *personHere(void) {
	OBJECT *obj;

	for (obj = objs; obj < endOfObjs; obj++) {
		if (distanceTo(obj) == distHere  && obj == guard) {
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

DISTANCE distanceTo(OBJECT *obj) {
	return
		obj == NULL									? distUnknownObject	:
		obj == player								? distPlayer :
		obj == player->location						? distLocation :
		obj->location == player						? distHeld :
		obj->location == player->location			? distHere :
		getPassageTo(obj) != NULL					? distOverthere :
		obj->location == NULL						? distNotHere :
		obj->location->location == player			? distHeldContained :
		obj->location->location == player->location	? distHereContained :
													  distNotHere;
}
