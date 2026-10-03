#include "import.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void import_from_osu(char *path, Chart *chart)
{
    char map_path[128];
    strcpy(map_path, path);
    strcat(map_path, "map.osu");
    FILE *file = fopen(map_path, "r");

    char line[512];
    char audio_filename[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "AudioFilename: %255[^\r\n]", audio_filename) == 1) {
            break;
        }
    }
    char audio_path[256];
    strcpy(audio_path, path);
    strcat(audio_path, audio_filename);
    chart->song = LoadMusicStream(audio_path);
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "CircleSize: %d", (int*)&chart->lanes) == 1) {
            break;
        }
    }

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "[HitObjects]", 12) == 0) {
            break;
        }
    }
    int n = 0;
    chart->notes = malloc(sizeof(Note) * 1);
    while (fgets(line, sizeof(line), file)) {
        int x, y, time_ms, type, end_time;
        sscanf(line, "%d,%d,%d,%d,%d", &x, &y, &time_ms, &type, &end_time);
        chart->notes[n].time_ms = time_ms;
        chart->notes[n].state = NOTE_PENDING;
        chart->notes[n].lane = floor((double)x * chart->lanes / 512);
        if (chart->notes[n].lane < 0) {
            chart->notes[n].lane = 0;
        } else if(chart->notes[n].lane > chart->lanes - 1) {
            chart->notes[n].lane = chart->lanes - 1;
        }
        if((type & 128) == 128) {
            chart->notes[n].end_time_ms = end_time;
        } else {
            chart->notes[n].end_time_ms = 0;
        }
        n++;
        printf("%d\n", n);
        chart->notes = realloc(chart->notes, sizeof(Note) * (n + 1));
    }
    chart->note_count = n;
    chart->notes = realloc(chart->notes, sizeof(Note) * n);
    fclose(file);
    return;
}
