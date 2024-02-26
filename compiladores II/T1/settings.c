#include <stdio.h>
#include "settings.h"

Settings* create_settings() {
    Settings* settings = (Settings*) malloc(sizeof(Settings));

    settings = set_default_settings(settings);

    return settings;
}

Settings* set_default_settings(Settings* settings) {
    settings->h_view_lo = -6.500000;
    settings->h_view_hi = 6.500000;
    settings->v_view_lo = -3.500000;
    settings->v_view_hi = 3.500000;
    settings->float_precision = 6;
    settings->integral_steps = 1000;
    settings->draw_axis = 1;
    settings->erase_plot = 1;
    settings->connect_dots = 0;

    return settings;
}

Settings* set_settings(Settings* settings, float h_view_lo, float h_view_hi, float v_view_lo, float v_view_hi, int integral_steps, int draw_axis, int connect_dots, int erase_plot) {
    settings->h_view_lo = h_view_lo;
    settings->h_view_hi = h_view_hi;
    settings->v_view_lo = v_view_lo;
    settings->v_view_hi = v_view_hi;
    settings->integral_steps = integral_steps;
    settings->draw_axis = draw_axis;
    settings->connect_dots = connect_dots;
    settings->erase_plot = erase_plot;

    return settings;
}

void show_settings(Settings* settings) {
    printf("\nh_view_lo: %.6f", settings->h_view_lo);
    printf("\nh_view_hi: %.6f", settings->h_view_hi);
    printf("\nv_view_lo: %.6f", settings->v_view_lo);
    printf("\nv_view_hi: %.6f", settings->v_view_hi);
    printf("\nfloat precision: %d", settings->float_precision);
    printf("\nintegral_steps: %d", settings->integral_steps);

    if(settings->draw_axis == 1) {
        printf("\nDraw Axis: ON");
    } else {
        printf("\nDraw Axis: OFF");
    }

    if(settings->erase_plot == 1) {
        printf("\nErase Plot: ON");
    } else {
        printf("\nErase Plot: OFF");
    }

    printf("\n\n");
}