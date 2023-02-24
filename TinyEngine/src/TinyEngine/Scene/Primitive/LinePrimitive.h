#pragma once
#include "Primitive.h"

TINY_ENGINE_NAMESPACE_BEGIN

const std::vector<VertexBufferElement> vecLineBufferElement
{
	{ VertexDataType::Float3 },
	{ VertexDataType::Float4 },
	{ VertexDataType::Float }
};

class LinePrimitive:public Primitive
{
public:
	struct LineVertex
	{
		glm::vec3 Position;
		glm::vec4 Color;

		float EntityID;
	};
	LinePrimitive();
	~LinePrimitive();
};

TINY_ENGINE_NAMESPACE_END


