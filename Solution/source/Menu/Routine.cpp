/*
* Menyoo PC - Grand Theft Auto V single-player trainer mod
* Copyright (C) 2019  MAFINS
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*/
#include "Routine.h"

#include "..\macros.h"

#include "Menu.h"

#include "..\Util\FileLogger.h"
#include "..\Util\ExePath.h"
#include "..\Util\keyboard.h"
#include "..\Scripting\enums.h"
#include "..\Natives\types.h" // RGBA/RgbS & types
#include "..\Natives\natives2.h"
#include "..\Scripting\DxHookIMG.h"
#include "..\Scripting\Model.h"
#include "..\Memory\GTAmemory.h"
#include "..\Scripting\GTAentity.h"
#include "..\Scripting\GTAvehicle.h"
//#include "..\Scripting\GTAprop.h"
#include "..\Scripting\Game.h"
#include "..\Scripting\Raycast.h"

#include "..\Submenus\MiscOptions.h"

#include <Windows.h>
#include <thread>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <time.h> // time/localtime_s


//--------------------------------Threads--------------------------------------------------------

void Menu::justopened()
{
	Game::Print::PrintBottomLeft(oss_ << "Menyoo PC v" << MENYOO_CURRENT_VER_ << " by MAFINS.");
	SET_THIS_SCRIPT_CAN_BE_PAUSED(0);
	g_menuNotOpenedYet = false;
}
inline void MenyooMain()
{
	DxHookIMG::LoadAllMenyooTexturesInit();
	srand(GetTickCount());
	SET_RANDOM_SEED(GetTickCount());
	for (;;)
	{
		DxHookIMG::DxTexture::GlobalDrawOrderRef() = -9999;
		Menu::Tick();
		WAIT(0);
	}

}
void ThreadMenyooMain()
{
	MenyooMain();
}

//--------------------------------On tick--------------------------------------------------------

#pragma region variables used define // p.s. this ain't it chief
bool loop_prep_veh_2T1_gift = 0, loop_hide_hud = 0;
#pragma endregion

#pragma region methods used define // p.s. this ain't it chief
void prep_veh_for_2Take1_gift()
{
	std::vector<Entity> all_vehicles;
	GTAmemory::GetVehicleHandles(all_vehicles, Vector3(200.0f, 1500.0f, 0.0f), 6000.0);
	for (GTAentity current_veh : all_vehicles)
	{
		int veh = current_veh.Handle();
		if (IS_ENTITY_A_VEHICLE(veh) && NETWORK_HAS_CONTROL_OF_ENTITY(veh))
		{
			if (DECOR_GET_INT(veh, "MPBitset") == 1024)
			{
				if (!IS_ENTITY_A_MISSION_ENTITY(veh) && !DOES_ENTITY_BELONG_TO_THIS_SCRIPT(veh, false))
				{
					auto veh_address = GTAmemory::GetEntityAddress(veh);
					if (veh_address != 0)
					{
						auto mission_state = GTAmemory::ReadInt(veh_address + 0xDA);
						if (mission_state != 7)
						{
							GTAmemory::WriteInt(veh_address + 0xDA, 7);
						}
					}
				}
			}
		}
	}
}
#pragma endregion

void Menu::loops()
{
	MenuInput::UpdateDeltaCursorNormal();
	if (!IS_PLAYER_SWITCH_IN_PROGRESS())
	{
		if (loop_prep_veh_2T1_gift)
			prep_veh_for_2Take1_gift();
	}
}
