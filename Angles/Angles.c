#include "Angles.h"


void setup_Angles()
{
    Angles_Mapping = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,   // read/write access
        FALSE,                 // do not inherit the name
        Angles_Name);               // name of mapping object
    
    if (Angles_Mapping == NULL) {
        Angles_isMapped = false;
        return;
    }

    Angles_Buf = (LPTSTR)MapViewOfFile(Angles_Mapping, // handle to map object
        FILE_MAP_ALL_ACCESS,  // read/write permission
        0,
        0,
        BUF_SIZE);
    
    if (Angles_Buf == NULL) {
        Angles_isMapped = false;
        return;
    }
    Angles_isMapped = true;
}


float get_pitch()
{
    if (Angles_isMapped) {
        return Angles_struct.pitch;
    } else {
        return 0;
    }
}

float get_true_heading()
{
    if (Angles_isMapped) {
        return Angles_struct.true_heading;
    } else {
        return 0;
    }
}

float get_roll()
{
    if (Angles_isMapped) {
        return Angles_struct.roll;
    } else {
        return 0;
    }
}

void update_Angles() {
    if (Angles_isMapped) {
        memcpy(&Angles_struct, Angles_Buf, sizeof(Angles_struct));
    }
}

void close_Angles()
{
    if (Angles_isMapped) {
        
        UnmapViewOfFile(Angles_Buf);
        CloseHandle(Angles_Mapping);
    }
}