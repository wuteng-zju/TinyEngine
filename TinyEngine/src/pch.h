#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <filesystem>

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include "TinyEngine/Core/Core.h"
#include "TinyEngine/Core/Logger.h"
#include "TinyEngine/Debug/Instrumentor.h"
#include "TinyEngine/Core/TimeStep.h"

// glm���
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>

#ifdef TINY_ENGINE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif