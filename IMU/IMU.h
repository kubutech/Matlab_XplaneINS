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
    float ax;
    float ay;
    float az;
    int active;
}IMU_struct;

void setup_IMU();

void update_IMU();

float get_p();
float get_q();
float get_r();
float get_ax();
float get_ay();
float get_az();

void close_IMU();