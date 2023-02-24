#pragma once

TINY_ENGINE_NAMESPACE_BEGIN

class MathUtils
{
public:
	static bool DecomposeTransform(const glm::mat4& mat4Transform, glm::vec3& vec3Translation,
		glm::vec3& vec3Rotation, glm::vec3& vec3Scale);
};

TINY_ENGINE_NAMESPACE_END