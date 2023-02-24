#pragma once
TINY_ENGINE_NAMESPACE_BEGIN

class Texture;
class ContentBrowserPanel
{
public:
	// ���캯��
	ContentBrowserPanel();

	// 
	void OnImGuiRender();

private:
	// ��ǰ�ļ���
	std::filesystem::path m_currentDirectory;

	// 
	Ref<Texture> m_spDirectoryIcon;

	// 
	Ref<Texture> m_spFileIcon;
};

TINY_ENGINE_NAMESPACE_END

