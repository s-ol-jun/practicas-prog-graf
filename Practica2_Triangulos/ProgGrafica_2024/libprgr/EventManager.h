#pragma once
#include "common.h"
#include "vectorMath.h"

class EventManager {
public:
	inline static map<int, bool> keyState;

	static void init(GLFWwindow* window);

	static void keybEventManager(GLFWwindow* window, int key, int scancode, int action, int mods);
};