typedef enum {
    distPlayer,
    distHeld,
    distHeldContained,
    distLocation,
    distHere,
    distHereContained,
    distOverthere,
    distNotHere,
    distUnknownObject,
    distNoObjectSpecified
} DISTANCE;

extern DISTANCE distanceTo(OBJECT *obj);
extern OBJECT *getPassageTo(OBJECT *targetLocation);
extern OBJECT *parseObject(const char *noun);
extern OBJECT *personHere(void);
extern int listOfObjectsAtLocation(OBJECT *location);
