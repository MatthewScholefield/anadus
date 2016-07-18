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

#include "SoundSystem.hpp"
#include "Phoneme.hpp"
#include "PhonemeQueue.hpp"
#include "Synthesizer.hpp"

int main()
{
	PhonemeQueue queue;
	Synthesizer synth(queue);
	SoundSystem system(queue);
	
	synth.loadSounds();
	system.initialize();
	synth.speakSomething();
	while (queue.hasMore());
	Pa_Sleep(1000);
	system.terminate();
	return 0;
}

