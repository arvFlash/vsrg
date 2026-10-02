#include "import.h"
#include <stdio.h>
#include <string.h>

void import_from_osu(char *path, Chart *chart)
{
    FILE *file = fopen(strcat(path, "map.osu"), "r");

    char buffer[128];
    while(fgets(buffer, sizeof(buffer), file)) {
                
        if(strstr(buffer, "AudioFilename: ") != NULL) {
            break;
        }
    }


    chart->song = LoadMusicStream(strcat(path, "audio.mp3"));
    return;
}
