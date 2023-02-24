#pragma once
#include "pch.h"
#include "TinyEngine/Events/Event.h"

TINY_ENGINE_NAMESPACE_BEGIN

// Layer¿‡
class Layer
{
public:
	Layer(const std::string& sLayerName = "Layer") :m_sLayerName(sLayerName) {}
	virtual ~Layer() {};
	virtual void OnAttach() {};
	virtual void OnDetach() {};
	virtual void OnUpdate(const TimeStep&) {};
	virtual void OnEvent(Event&) {};
	virtual void OnImGuiRender() {}
	const std::string& GetName()const { return m_sLayerName; }
protected:
	std::string m_sLayerName;
};

TINY_ENGINE_NAMESPACE_END