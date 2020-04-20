// Routes.h

#ifndef _ROUTES_h
#define _ROUTES_h

#include <Arduino.h>

static byte callRoute = 0;
void copyArray(byte(&oldArray)[6][8], byte(&compArray)[6][8]);
void updateRoute(byte(&target)[6][8], byte(&source)[6][8]);
void checkRoute(byte& selectRoute);

extern byte activeRoute[6][8];
extern byte oldRoute[6][8];
extern byte road1[6][8];
extern byte road2[6][8];
extern byte allLeft[6][8];
extern byte allRight[6][8];
extern byte test1[6][8];
extern byte test2[6][8];

#endif

