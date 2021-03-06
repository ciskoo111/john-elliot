/************************************************************************

    JOYCE v1.90 - Amstrad PCW emulator

    Copyright (C) 1996, 2001  John Elliott <seasip.webmaster@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*************************************************************************/

#include <SDL.h>
#include <string>
#include "UiTypes.hxx"
#include "UiControl.hxx"
#include "UiSeparator.hxx"

UiSeparator::UiSeparator(UiDrawer *d) : UiControl(d)
{

}

UiSeparator::~UiSeparator()
{

}
	
void UiSeparator::draw(int selected)
{
	SDL_Rect rc = getBounds();
	m_drawer->drawSeparator(selected, rc);
}


Uint16 UiSeparator::getHeight()
{
        Uint16 x, y;

        m_drawer->measureString(" ", &x, &y);
        return y;
}


Uint16 UiSeparator::getWidth()
{
        Uint16 x, y;
        
        m_drawer->measureString(" ", &x, &y);
        return x;       
}





