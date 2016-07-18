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

#pragma once

#include "Waveform.hpp"

class PhonemeQueue;

class Synthesizer
{
public:
	Synthesizer(PhonemeQueue &queue);
	void loadSounds();
	void speakSomething();

private:

	enum PhonemeType
	{
		_ = 0,
		EH,
		TH,
		I,
		S,
		AY,
		EE,

		LENGTH
	};
	void speakSound(PhonemeType type);
	float getDefaultLength(PhonemeType type);
	Waveform waveforms[(int) PhonemeType::LENGTH];
	PhonemeQueue &queue;

};
