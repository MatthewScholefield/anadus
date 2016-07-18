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

#include "Synthesizer.hpp"
#include "PhonemeQueue.hpp"

Synthesizer::Synthesizer(PhonemeQueue &queue) : waveforms{
	{},
	{"eh"},
	{"th"},
	{"i"},
	{"s"},
	{"ay"},
	{"ee"}
}

, queue(queue) { }

void Synthesizer::loadSounds()
{
	for (Waveform &i : waveforms)
		i.loadData();
}

float Synthesizer::getDefaultLength(PhonemeType type)
{
	switch (type)
	{
	case _:
		return 0.2f;
	case AY:
		return 0.2f;
	case TH:
		return 0.15f;
	case EH:
		return 0.2f;
	case S:
		return 0.15f;
	default:
		return 0.1f;
	}
}

void Synthesizer::speakSound(PhonemeType type)
{
	queue.add(waveforms[(int) type], getDefaultLength(type));
}

void Synthesizer::speakSomething()
{
	PhonemeType word[] = {
		TH, I, S, _, I, S, _, AY
	};
	size_t len = sizeof (word) / sizeof (word[0]);
	for (int i = 0; i < len; ++i)
		speakSound(word[i]);
}
