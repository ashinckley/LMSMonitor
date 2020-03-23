/*
 *	(c) 2020 Stuart Hunter
 *
 *	TODO:
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	See <http://www.gnu.org/licenses/> to get a copy of the GNU General
 *	Public License.
 *
 */

#ifndef VISUALIZE_H
#define VISUALIZE_H

#include "visdata.h"

void setVisList(char *vlist);
void setVisMode(vis_type_t mode);
char getVisMode(void);
void sayVisList(void);

void visualize(struct vissy_meter_t *vissy_meter);
bool isVisualizeActive(void);
char currentMeter(void);

void activateVisualizer(void);
void deactivateVisualizer(void);

#endif
