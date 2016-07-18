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

#include "Phoneme.hpp"
#include "SoundSystem.hpp"
#include "Waveform.hpp"

Phoneme::Phoneme(const Waveform &WAVEFORM, const float SEC) :
WAVEFORM(&WAVEFORM), numLoops(calcNumLoops(SEC)), samplePos(0), loopCount(0) { }

int Phoneme::calcNumLoops(const float SEC)
{
	const float SEC_PER_LOOP = WAVEFORM->size() / (float)SoundSystem::SAMPLE_RATE;
	float NUM_LOOPS = SEC / SEC_PER_LOOP;
	return NUM_LOOPS;
}

float Phoneme::getSample()
{
	float sample = WAVEFORM->get(samplePos);
	if (++samplePos >= WAVEFORM->size())
	{
		samplePos = 0;
		++loopCount;
	}
	return sample;
}

bool Phoneme::donePlaying()
{
	return loopCount >= numLoops;
}
