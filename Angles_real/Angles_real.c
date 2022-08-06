#include "Angles_real.h"


void setup_Angles_real()
{
    Angles_real_Mapping = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,   // read/write access
        FALSE,                 // do not inherit the name
        Angles_real_Name);               // name of mapping object
    
    if (Angles_real_Mapping == NULL) {
        Angles_real_isMapped = false;
        return;
    }

    Angles_real_Buf = (LPTSTR)MapViewOfFile(Angles_real_Mapping, // handle to map object
        FILE_MAP_ALL_ACCESS,  // read/write permission
        0,
        0,
        BUF_SIZE);
    
    if (Angles_real_Buf == NULL) {
        Angles_real_isMapped = false;
        return;
    }
    Angles_real_isMapped = true;
}


float get_pitch()
{
    if (Angles_real_isMapped) {
        return Angles_real_struct.pitch;
    } else {
        return 0;
    }
}

float get_true_heading()
{
    if (Angles_real_isMapped) {
        return Angles_real_struct.true_heading;
    } else {
        return 0;
    }
}

float get_roll()
{
    if (Angles_real_isMapped) {
        return Angles_real_struct.roll;
    } else {
        return 0;
    }
}

void update_Angles_real() {
    if (Angles_real_isMapped) {
        memcpy(&Angles_real_struct, Angles_real_Buf, sizeof(Angles_real_struct));
    }
}

void close_Angles_real()
{
    if (Angles_real_isMapped) {
        
        UnmapViewOfFile(Angles_real_Buf);
        CloseHandle(Angles_real_Mapping);
    }
}