// CAUTION GENERATED FILE
#include "catalog.h"
namespace glow {
const char *catalog_names[FRAME_COUNT] = {
"double-scanner",
"salmon-strawberry",
"sky blue scan",
"split_in_three",
"split_in_two",
"spotlight",
"strawberry",
};
Frame catalog[FRAME_COUNT]= {
{540,9,48,//
{{540,9,{540,9,0,2},{540,
{
{680,191,204},
{255,198,249},
},
0},0,0,0,100},
{540,9,{540,9,0,1},{540,
{
{1402,204,255},
{1402,204,255},
},
0},0,3,0,50},
{540,9,{540,9,0,1},{540,
{
{905,226,188},
{947,38,229},
},
0},0,3,50,100},
}},
{540,9,16,//
{{540,9,{540,9,0,2},{540,
{
{807,124,234},
{918,255,255},
},
0},0,0,0,100},
{540,9,{540,9,0,2},{540,
{
{807,124,234},
{918,255,255},
},
0},0,0,0,100},
{540,9,{540,9,0,2},{540,
{
{807,124,234},
{918,255,255},
},
0},0,0,0,100},
}},
{540,9,48,//
{{540,9,{540,9,0,2},{540,
{
{807,124,234},
{918,255,255},
},
0},0,0,0,100},
{540,9,{540,9,0,2},{540,
{
{807,124,234},
{918,255,255},
},
0},0,0,0,100},
{540,9,{540,9,0,1},{540,
{
{1402,204,255},
{1402,204,255},
},
0},0,3,0,50},
}},
{540,9,48,//
{{540,9,{540,9,0,1},{540,
{
{807,124,234},
{17,191,255},
},
5},5,0,0,33},
{540,9,{540,9,0,1},{540,
{
{807,124,234},
{17,191,255},
},
5},5,0,33,66},
{540,9,{540,9,0,1},{540,
{
{1496,196,198},
{255,102,255},
},
5},5,0,66,100},
}},
{540,9,48,//
{{540,9,{540,9,0,1},{540,
{
{807,124,234},
{17,191,255},
},
5},5,0,0,50},
{540,9,{540,9,0,1},{540,
{
{1402,204,255},
{255,198,249},
},
1},1,0,50,100},
}},
{0,0,16,//
{{0,0,{0,1,3,2},{0,
{
{0,255,255},
{1525,255,255},
},
0},0,0,0,100},
{0,0,{0,1,0,2},{0,
{
{0,0,0},
},
0},0,30,0,100},
{0,0,{0,1,3,2},{0,
{
{0,0,255},
},
0},0,30,0,100},
}},
{540,9,48,//
{{540,9,{540,9,0,2},{540,
{
{1402,204,255},
{1402,204,255},
},
0},0,0,0,100},
}},
};
Frame &from_catalog(CATALOG_INDEX index){return catalog[index%FRAME_COUNT];}
const char *catalog_name(CATALOG_INDEX index){return catalog_names[index%FRAME_COUNT];}
} // namespace glow
