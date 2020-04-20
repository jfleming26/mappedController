// 
// 
// 

#include "Routes.h"


void copyArray(byte(&oldArray)[6][8], byte(&compArray)[6][8])
{
    for (int i = 0; i < 6; ++i)
    {
        for (int x = 0; x < 8; ++x)
        {
            compArray[i][x] = oldArray[i][x];
        }
    };
}

void updateRoute(byte(&target)[6][8], byte(&source)[6][8])
{
    for (int i = 0; i < 6; ++i)
    {
        for (int x = 0; x < 8; ++x)
        {
            if (source[i][x] > 0 && source[i][x] != target[i][x])
            {
                target[i][x] = source[i][x];
            }
        }
    }
}

void checkRoute(byte& selectRoute)
{
    Serial.println("Updating Array");
    switch (selectRoute)
    {
    case 1:
    {
        updateRoute(activeRoute, allLeft);
        break;
    }
    case 2:
    {
        updateRoute(activeRoute, allRight);
        break;
    }
    case 3:
    {
        updateRoute(activeRoute, road1);
        break;
    }
    case 4:
    {
        updateRoute(activeRoute, road2);
        break;
    }
    case 5:
    {
        updateRoute(activeRoute, test1);
        break;
    }
    case 6:
    {
        updateRoute(activeRoute, test2);
        break;
    }
    }

}


byte activeRoute[6][8] =
{
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1}
};

byte oldRoute[6][8] = {};

byte road1[6][8] =
{
    {},
    {},
    {2,2,2,2,2,2,2,2},
    {},
    {2,1,2,1,2,1,2,1},
    {}
};

byte road2[6][8] =
{
    {},
    {2,2,2,2,2,2,2,2},
    {},
    {},
    {},
    {2,2,2,2,2,2,2,2}
};

byte allLeft[6][8] =
{
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2}
};

byte allRight[6][8] =
{
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1}
};

byte test1[6][8] =
{
    {2,2,2,0,0,0,0,0},
    {},
    {},
    {},
    {},
    {}
};

byte test2[6][8] =
{
    {1,1,1,0,0,0,0,0},
    {},
    {},
    {},
    {},
    {}
};