/*
* Menyoo PC - Grand Theft Auto V single-player trainer mod
* Copyright (C) 2019  MAFINS
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*/
#include "MainMenu.h"
#include "..\macros.h"
#include "..\Menu\Menu.h"
#include "..\Menu\Routine.h"
#include "..\Natives\natives2.h"

namespace sub
{
	void MainMenu()
	{
		AddTitle("MENYOO");
		AddOption("Misc Options", null, nullFunc, SUB::MISCOPS);
	}

}




