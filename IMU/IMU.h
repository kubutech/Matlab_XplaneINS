#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 28
HANDLE IMU_Mapping;
LPCTSTR IMU_Buf;
TCHAR IMU_Name[] = TEXT("IMU");
boolean IMU_isMapped;

struct {
    float p;
    float q;
    float r;
    float axial_acceleration;
    float normal_acceleration;
    float side_acceleration;
    int active;
}IMU_struct;

void setup_IMU();

void update_IMU();

float get_p();
float get_q();
float get_r();
float get_axial_acceleration();
float get_normal_acceleration();
float get_side_acceleration();

void close_IMU();