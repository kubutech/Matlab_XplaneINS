#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 64
HANDLE GPS_Mapping;
LPCTSTR GPS_Buf;
TCHAR GPS_Name[] = TEXT("GPS");
boolean GPS_isMapped;

struct {
    double lat;
    double lon;
    double elevation;
    int active;
}GPS_struct;

void setup_GPS();

void update_GPS();

double get_lat();
double get_lon();
double get_elevation();

void close_GPS();