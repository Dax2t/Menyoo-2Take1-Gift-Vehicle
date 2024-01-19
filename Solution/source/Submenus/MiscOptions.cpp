/*
* Menyoo PC - Grand Theft Auto V single-player trainer mod
* Copyright (C) 2019  MAFINS
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*/
#include "MiscOptions.h"

#include "..\macros.h"

#include "..\Menu\Menu.h"
#include "..\Menu\Routine.h"

#include "..\Natives\natives2.h"
#include "..\Util\StringManip.h"
#include "..\Util\keyboard.h"
#include "..\Util\GTAmath.h"
#include "..\Scripting\Game.h"
#include "..\Scripting\GTAentity.h"
#include "..\Scripting\GTAvehicle.h"


#include <string>
#include <map>
#include <vector>
#include <algorithm>

namespace sub
{
	void MiscOps()
	{
		AddTitle("Misc Options");
		AddToggle("Setup Vehicles For Gift", loop_prep_veh_2T1_gift);
	}
}



