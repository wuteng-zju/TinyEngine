#pragma once
#include "TinyEngine/Core/Layer.h"

TINY_ENGINE_NAMESPACE_BEGIN

class ImGuiLayer :public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer();
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(Event&) override;
	void BeginNewFrame();
	void EndNewFrame();
	void BlockEvents(bool bBlock);
private:
	void SetDarkThemeColors();
private:
	bool m_bBlockEvents;
};

TINY_ENGINE_NAMESPACE_END