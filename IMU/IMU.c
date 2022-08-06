#include "IMU.h"


void setup_IMU()
{
    IMU_Mapping = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,   // read/write access
        FALSE,                 // do not inherit the name
        IMU_Name);               // name of mapping object
    
    if (IMU_Mapping == NULL) {
        IMU_isMapped = false;
        return;
    }

    IMU_Buf = (LPTSTR)MapViewOfFile(IMU_Mapping, // handle to map object
        FILE_MAP_ALL_ACCESS,  // read/write permission
        0,
        0,
        BUF_SIZE);
    
    if (IMU_Buf == NULL) {
        IMU_isMapped = false;
        return;
    }
    IMU_isMapped = true;
}


float get_p()
{
    if (IMU_isMapped) {
        return IMU_struct.p;
    } else {
        return 0;
    }
}

float get_q()
{
    if (IMU_isMapped) {
        return IMU_struct.q;
    } else {
        return 0;
    }
}

float get_r()
{
    if (IMU_isMapped) {
        return IMU_struct.r;
    } else {
        return 0;
    }
}

float get_axial_acceleration()
{
    if (IMU_isMapped) {
        return IMU_struct.axial_acceleration;
    } else {
        return 0;
    }
}

float get_normal_acceleration()
{
    if (IMU_isMapped) {
        return IMU_struct.normal_acceleration;
    } else {
        return 0;
    }
}

float get_side_acceleration()
{
    if (IMU_isMapped) {
        return IMU_struct.side_acceleration;
    } else {
        return 0;
    }
}

void update_IMU() {
    if (IMU_isMapped) {
        memcpy(&IMU_struct, IMU_Buf, sizeof(IMU_struct));
    }
}

void close_IMU()
{
    if (IMU_isMapped) {
        
        UnmapViewOfFile(IMU_Buf);
        CloseHandle(IMU_Mapping);
    }
}