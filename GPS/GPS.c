#include "GPS.h"


void setup_GPS()
{
    GPS_Mapping = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,   // read/write access
        FALSE,                 // do not inherit the name
        GPS_Name);               // name of mapping object
    
    if (GPS_Mapping == NULL) {
        GPS_isMapped = false;
        return;
    }

    GPS_Buf = (LPTSTR)MapViewOfFile(GPS_Mapping, // handle to map object
        FILE_MAP_ALL_ACCESS,  // read/write permission
        0,
        0,
        BUF_SIZE);
    
    if (GPS_Buf == NULL) {
        GPS_isMapped = false;
        return;
    }
    GPS_isMapped = true;
}


double get_lat()
{
    if (GPS_isMapped) {
        return GPS_struct.lat;
    } else {
        return 0;
    }
}

double get_lon()
{
    if (GPS_isMapped) {
        return GPS_struct.lon;
    } else {
        return 0;
    }
}

double get_elevation()
{
    if (GPS_isMapped) {
        return GPS_struct.elevation;
    } else {
        return 0;
    }
}

void update_GPS() {
    if (GPS_isMapped) {
        memcpy(&GPS_struct, GPS_Buf, sizeof(GPS_struct));
    }
}

void close_GPS()
{
    if (GPS_isMapped) {
        
        UnmapViewOfFile(GPS_Buf);
        CloseHandle(GPS_Mapping);
    }
}