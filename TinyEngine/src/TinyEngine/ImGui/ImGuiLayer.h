#pragma once
#include "TinyEngine/Core/Layer.h"

TINY_ENGINE_NAMESPACE_BEGIN

class ImGuiLayer :public Layer
{
public:
	// ���캯��
	ImGuiLayer();
	// ��������
	~ImGuiLayer();
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(Event&) override;
	// ��ʼ�µ�һ֡
	void BeginNewFrame();
	// �����µ�һ֡
	void EndNewFrame();
	// �����¼�
	void BlockEvents(bool bBlock);
private:
	// ���ú�ɫ������ɫ
	void SetDarkThemeColors();
private:
	// �Ƿ������¼�
	bool m_bBlockEvents;
};

TINY_ENGINE_NAMESPACE_END