#pragma once
#include "Scene.h"

TINY_ENGINE_NAMESPACE_BEGIN

// 场景序列化类
class SceneSerializer
{
public:
	// 构造函数
	SceneSerializer(const Ref<Scene>& spScene);

	// 序列化
	void Serialize(const std::string& sFilePath);
	void SerializeRuntime(const std::string& sFilePath);

	// 反序列化
	bool DeSerialize(const std::string& sFilePath);
	bool DeSerializeRuntime(const std::string& sFilePath);

	// 
	void SetSelectedScene(const Ref<Scene>& spScene);
private:
	// 场景
	Ref<Scene> m_spScene;
};

TINY_ENGINE_NAMESPACE_END
