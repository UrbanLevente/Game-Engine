#pragma once

#include "Engine.h"
#include "Core/Event.h"

#include <iostream>

#include <Windows.h>

namespace Engine {
	namespace Events {
		Event<void(int)> OnCollision;
	}
}
