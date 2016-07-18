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

#include <portaudio.h>
#include "PhonemeQueue.hpp"

PhonemeQueue::PhonemeQueue() : queue{}, readingQueueId(0), writingQueueId(0) { }

void PhonemeQueue::add(const Waveform &WAVEFORM, const float SEC)
{
	queue[writingQueueId] = Phoneme(WAVEFORM, SEC);
	if (++writingQueueId >= MAX_QUEUES)
		writingQueueId = 0;
}

float PhonemeQueue::getSample()
{
	if (readingQueueId >= writingQueueId)
		return 0.f;
	float sample = queue[readingQueueId].getSample();
	if (queue[readingQueueId].donePlaying())
	{
		if (++readingQueueId >= MAX_QUEUES)
			readingQueueId = 0;
	}
	return sample;
}

bool PhonemeQueue::hasMore()
{
	return readingQueueId < writingQueueId;
}
