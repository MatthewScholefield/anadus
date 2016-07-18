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

#include "UserData.hpp"
#include <vector>
#include <stdint.h>
#include <portaudio.h>

class PhonemeQueue;

class SoundSystem
{
public:
	SoundSystem(PhonemeQueue &queue);
	void initialize();
	void terminate();

	static const int SAMPLE_RATE = 44100;

private:
	template<typename Func, typename ...Args>
	void wrapper(Func func, Args... args);
	static PaError openStream(PaStream **stream, UserData *data);
	static int calcAudio(const void*, void*, unsigned long,
						const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void*);

	PaStream *stream;
	UserData data;
	std::vector<float> eh;
};

#include "SoundSystem.inl"
