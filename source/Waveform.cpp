/*
 * Copyright (C) 2016 Matthew D. Scholefield
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Waveform.hpp"
#include <cstdint>
#include <limits.h>
#include <fstream>
#include <iostream>

Waveform::Waveform() : NAME(), data() { }

Waveform::Waveform(const std::string &NAME) : NAME(NAME), data() { }

void Waveform::loadData()
{
	if (NAME.compare("") == 0)
	{
		data.push_back(0.f);
		return;
	}
	std::string fileName = NAME + ".s32le.raw";
	std::ifstream file(fileName, std::ios::binary);
	if (!file)
	{
		std::cout << "Failed to open file." << std::endl;
		return;
	}
	
	
	// Sane maximum to prevent overflow if wrong file is read
	const int MAX_SAMPLES_TO_LOAD = 5000;
	for (int i = 0; i < MAX_SAMPLES_TO_LOAD; ++i)
	{
			int32_t val;
		file.read((char*) (&val), sizeof (int32_t));
		data.push_back((val) / (float)INT_MAX);
		if (file.eof())
			break;
	}
	if (!file.eof())
		std::cout << "File to long to read." << std::endl;
}

float Waveform::get(int id) const
{
	return data[id];
}

size_t Waveform::size() const
{
	return data.size();
}
