#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 16
HANDLE Angles_Mapping;
LPCTSTR Angles_Buf;
TCHAR Angles_Name[] = TEXT("Angles");
boolean Angles_isMapped;

struct {
    float pitch;
    float true_heading;
    float roll;
    int active;
}Angles_struct;

void setup_Angles();

void update_Angles();

float get_pitch();
float get_true_heading();
float get_roll();

void close_Angles();