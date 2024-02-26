#include <stdio.h>
#include <stdlib.h>

typedef struct settings {
    float h_view_lo;
    float h_view_hi;
    float v_view_lo;
    float v_view_hi;
    int float_precision;
    int integral_steps;
    int draw_axis;
    int connect_dots;
    int erase_plot;
} Settings;

Settings* create_settings();

Settings* set_default_settings(Settings* settings);

void show_settings(Settings* settings);