#pragma once
TINY_ENGINE_NAMESPACE_BEGIN

class Texture;
class ContentBrowserPanel
{
public:
	// 构造函数
	ContentBrowserPanel();

	// 
	void OnImGuiRender();

private:
	// 当前文件夹
	std::filesystem::path m_currentDirectory;

	// 
	Ref<Texture> m_spDirectoryIcon;

	// 
	Ref<Texture> m_spFileIcon;
};

TINY_ENGINE_NAMESPACE_END

