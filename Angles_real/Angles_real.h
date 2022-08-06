#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 64
HANDLE Angles_real_Mapping;
LPCTSTR Angles_real_Buf;
TCHAR Angles_real_Name[] = TEXT("Angles_real");
boolean Angles_real_isMapped;

struct {
    float pitch;
    float true_heading;
    float roll;
    int active;
}Angles_real_struct;

void setup_Angles_real();

void update_Angles_real();

float get_pitch();
float get_true_heading();
float get_roll();

void close_Angles_real();