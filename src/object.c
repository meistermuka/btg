#include <stdio.h>
#include "object.h"
static const char *tags0[] = { "field", NULL};
static const char *tags1[] = { "cave", NULL};
static const char *tags2[] = { "silver", "coin", "silver coin", NULL};
static const char *tags3[] = { "gold", "coin", "gold coin", NULL};
static const char *tags4[] = { "guard", "burly guard", NULL};
static const char *tags5[] = { "yourself", NULL};
static const char *tags6[] = { "east", "entrance", NULL};
static const char *tags7[] = { "west", "out", NULL};
static const char *tags8[] = { "west", "north", "south", "forest", NULL};
static const char *tags9[] = { "east", "north", "south", "rock", NULL};

OBJECT objs[] = {
	{	/* 0 = field */
		 "an open field",
		tags0,
		NULL,
		NULL,
		NULL,
		 "The field is a nice and quiet place under a clear blue sky.\n",
		"You see",
		"You can't get any closer than this.\n",
		99,
		9999,
		0
	},
	{	/* 1 = cave */
		 "a little cave",
		tags1,
		NULL,
		NULL,
		NULL,
		 "The cave is just a cold, damp, rocky chamber.\n",
		"You see",
		"You can't get any closer than this.\n",
		99,
		9999,
		0
	},
	{	/* 2 = silver */
		 "a silver coin",
		tags2,
		 field,
		NULL,
		NULL,
		 "The coin has an eagle on the obverse.\n",
		"You see",
		"You can't get any closer than this.\n",
		 1,
		9999,
		0
	},
	{	/* 3 = gold */
		 "a gold coin",
		tags3,
		 cave,
		NULL,
		NULL,
		 "The shiny coin seems to be a rare and priceless artefact.\n",
		"You see",
		"You can't get any closer than this.\n",
		 1,
		9999,
		0
	},
	{	/* 4 = guard */
		 "a burly guard",
		tags4,
		 field,
		NULL,
		NULL,
		 "The guard is a really big fellow.\n",
		 "He has",
		"You can't get any closer than this.\n",
		99,
		 20,
		 100
	},
	{	/* 5 = player */
		 "yourself",
		tags5,
		 field,
		NULL,
		NULL,
		 "You would need a mirror to look at yourself.\n",
		 "You have",
		"You can't get any closer than this.\n",
		99,
		 20,
		 100
	},
	{	/* 6 = intoCave */
		 "a cave entrance to the east",
		tags6,
		 field,
		NULL,
		 cave,
		 "The entrance is just a narrow opening in a small outcrop.\n",
		"You see",
		 "The guard stops you from walking into the cave.\n",
		99,
		9999,
		0
	},
	{	/* 7 = exitCave */
		 "a way out to the west",
		tags7,
		 cave,
		 field,
		 field,
		 "Sunlight pours in through an opening in the cave's wall.\n",
		"You see",
		 "You walk out of the cave.\n",
		99,
		9999,
		0
	},
	{	/* 8 = wallField */
		 "dense forest all around",
		tags8,
		 field,
		NULL,
		NULL,
		 "The field is surrounded by trees and undergrowth.\n",
		"You see",
		 "Dense forest is blocking the way.\n",
		99,
		9999,
		0
	},
	{	/* 9 = wallCave */
		 "solid rock all around",
		tags9,
		 cave,
		NULL,
		NULL,
		 "Carved in stone is a secret password 'abccb'.\n",
		"You see",
		 "Solid rock is blocking the way.\n",
		99,
		9999,
		0
	}
};
