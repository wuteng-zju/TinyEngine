#pragma once
#include "Scene.h"

TINY_ENGINE_NAMESPACE_BEGIN

class SceneSerializer
{
public:
	SceneSerializer(const Ref<Scene>& spScene);

	void Serialize(const std::string& sFilePath);
	void SerializeRuntime(const std::string& sFilePath);
	bool DeSerialize(const std::string& sFilePath);
	bool DeSerializeRuntime(const std::string& sFilePath);
	void SetSelectedScene(const Ref<Scene>& spScene);
private:
	Ref<Scene> m_spScene;
};

TINY_ENGINE_NAMESPACE_END
