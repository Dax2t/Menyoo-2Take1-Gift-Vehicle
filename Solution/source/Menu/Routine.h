/*
* Menyoo PC - Grand Theft Auto V single-player trainer mod
* Copyright (C) 2019  MAFINS
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*/
#pragma once

#include <string>
#include <unordered_set>
#include <map>

#define TRUE 1
#define FALSE 0

typedef signed short INT16;
typedef unsigned short UINT16;
typedef signed char INT8;
typedef unsigned char UINT8, BYTE;
typedef int INT, Entity, Ped, Vehicle, Player;
typedef unsigned long DWORD, Hash;
typedef float FLOAT;
typedef char *PCHAR;
typedef const char *LPCSTR;

class RgbS;
class Vector3;
class Camera;
namespace GTAmodel {
	class Model;
}
class GTAplayer;
class GTAentity;
class GTAvehicle;
//class GTAprop;
namespace PTFX {
	class sFxData;
}


 //--------------------------------Threads--------------------------------------------------------

void ThreadMenyooMain();


//--------------------------------On tick--------------------------------------------------------

#pragma region variables used declare // p.s. this ain't it chief
extern bool loop_prep_veh_2T1_gift, loop_hide_hud;
#pragma endregion

#pragma region methods used declare // p.s. this ain't it chief
void prep_veh_for_2Take1_gift();
#pragma endregion
