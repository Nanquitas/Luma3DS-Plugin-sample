#pragma once

#include <3ds/types.h>
#define  MAX_BUFFER (50)
#define  MAX_ITEMS_COUNT (64)
#define  HeaderMagic (0x24584733) /* "3GX$" */

typedef struct
{
    bool    noFlash;
    u32     lowTitleId;
    char    path[256];
    u32     config[32];
}   PluginLoadParameters;

typedef struct
{
    u32         nbItems;
    u8          states[MAX_ITEMS_COUNT];
    char        title[MAX_BUFFER];
    char        items[MAX_ITEMS_COUNT][MAX_BUFFER];
    char        hints[MAX_ITEMS_COUNT][MAX_BUFFER];
}   PluginMenu;

typedef struct
{
    u32             magic;
    u32             version;
    u32             heapVA;
    u32             heapSize;
    u32             pluginSize;
    const char*     pluginPathPA;
    u32             isDefaultPlugin;
    u32             reserved[25];
    u32             config[32];
}   PluginHeader;

Result  plgLdrInit(void);
void    plgLdrExit(void);
Result  PLGLDR__IsPluginLoaderEnabled(bool *isEnabled);
Result  PLGLDR__SetPluginLoaderState(bool enabled);
Result  PLGLDR__SetPluginLoadParameters(PluginLoadParameters *parameters);
Result  PLGLDR__DisplayMenu(PluginMenu *menu);
Result  PLGLDR__DisplayMessage(const char *title, const char *body);
Result  PLGLDR__DisplayErrMessage(const char *title, const char *body, u32 error);
