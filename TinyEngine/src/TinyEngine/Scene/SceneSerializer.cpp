#include "pch.h"
#include "SceneSerializer.h"

#include "TinyEngine/Scene/Entity.h"
#include "TinyEngine/Scene/Components.h"
#include "TinyEngine/Render/Texture/Texture2D.h"

#include <yaml-cpp/yaml.h>

namespace YAML
{
	template<>
	struct convert<glm::vec2>
	{
		static Node encode(const glm::vec2& value)
		{
			Node node;
			node.push_back(value.x);
			node.push_back(value.y);
			node.SetStyle(EmitterStyle::Flow);
			return node;
		}

		static bool decode(const Node& node, glm::vec2& value)
		{
			if (!node.IsSequence() || node.size() != 2)
				return false;

			value.x = node[0].as<float>();
			value.y = node[1].as<float>();
			return true;
		}
	};

	template<>
	struct convert<glm::vec3>
	{
		static Node encode(const glm::vec3& value)
		{
			Node node;
			node.push_back(value.x);
			node.push_back(value.y);
			node.push_back(value.z);
			node.SetStyle(EmitterStyle::Flow);
			return node;
		}

		static bool decode(const Node& node, glm::vec3& value)
		{
			if (!node.IsSequence() || node.size() != 3)
				return false;

			value.x = node[0].as<float>();
			value.y = node[1].as<float>();
			value.z = node[2].as<float>();
			return true;
		}
	};

	template<>
	struct convert<glm::vec4>
	{
		static Node encode(const glm::vec4& value)
		{
			Node node;
			node.push_back(value.x);
			node.push_back(value.y);
			node.push_back(value.z);
			node.push_back(value.w);
			node.SetStyle(EmitterStyle::Flow);
			return node;
		}

		static bool decode(const Node& node, glm::vec4& value)
		{
			if (!node.IsSequence() || node.size() != 4)
				return false;

			value.x = node[0].as<float>();
			value.y = node[1].as<float>();
			value.z = node[2].as<float>();
			value.w = node[3].as<float>();
			return true;
		}
	};
}

TINY_ENGINE_NAMESPACE_BEGIN

namespace 
{
	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec2& value)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << value.x << value.y << YAML::EndSeq;
		return out;
	}

	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec3& value)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << value.x << value.y << value.z << YAML::EndSeq;
		return out;
	}

	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec4& value)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << value.x << value.y << value.z << value.w << YAML::EndSeq;
		return out;
	}

	void SerializeEntity(YAML::Emitter& out, Entity& entity)
	{
		out << YAML::BeginMap;
		out << YAML::Key << "Entity" << YAML::Value << entity.GetUUID();

		if (entity.HasComponent<TagComponent>())
		{
			out << YAML::Key << "TagComponent";
			out << YAML::BeginMap; // TagComponent

			auto& tag = entity.GetComponent<TagComponent>().Tag;
			out << YAML::Key << "Tag" << YAML::Value << tag;

			out << YAML::EndMap; // TagComponent
		}

		if (entity.HasComponent<TransformComponent>())
		{
			out << YAML::Key << "TransformComponent";
			out << YAML::BeginMap; // TransformComponent

			auto& tc = entity.GetComponent<TransformComponent>();
			out << YAML::Key << "Translation" << YAML::Value << tc.Translation;
			out << YAML::Key << "Rotation" << YAML::Value << tc.Rotation;
			out << YAML::Key << "Scale" << YAML::Value << tc.Scale;

			out << YAML::EndMap; // TransformComponent
		}

		if (entity.HasComponent<CameraComponent>())
		{
			out << YAML::Key << "CameraComponent";
			out << YAML::BeginMap; // CameraComponent

			auto& cameraComponent = entity.GetComponent<CameraComponent>();

			out << YAML::Key << "Ortho Camera" << YAML::Value;
			out << YAML::BeginMap; // Camera
			auto spOrthoCamera = std::dynamic_pointer_cast<OrthoGraphicCamera>(cameraComponent.OrthoCamera);
			TINY_ENGINE_ASSERT(spOrthoCamera, "Ortho Camera is null in Serialize");
			out << YAML::Key << "ProjectionType" 
				<< YAML::Value << static_cast<int>(spOrthoCamera->GetProjectionType());
			out << YAML::Key << "OrthographicSize" << YAML::Value << spOrthoCamera->GetOrthoSize();
			out << YAML::Key << "OrthographicNear" << YAML::Value << spOrthoCamera->GetNearClip();
			out << YAML::Key << "OrthographicFar" << YAML::Value << spOrthoCamera->GetFarClip();
			out << YAML::Key << "AspectRatio" << YAML::Value << spOrthoCamera->GetAspectRatio();
			out << YAML::EndMap; // Camera

			out << YAML::Key << "Perspective Camera" << YAML::Value;
			out << YAML::BeginMap; // Camera
			auto spPerspecCamera = std::dynamic_pointer_cast<PerspectiveGraphicCamera>(cameraComponent.PerspecCamera);
			TINY_ENGINE_ASSERT(spPerspecCamera, "Perspective Camera is null in Serialize");
			out << YAML::Key << "ProjectionType"
				<< YAML::Value << static_cast<int>(spPerspecCamera->GetProjectionType());
			out << YAML::Key << "PerspectiveFOV" << YAML::Value << spPerspecCamera->GetPerspectiveFOV();
			out << YAML::Key << "PerspectiveNear" << YAML::Value << spPerspecCamera->GetNearClip();
			out << YAML::Key << "PerspectiveFar" << YAML::Value << spPerspecCamera->GetFarClip();
			out << YAML::Key << "AspectRatio" << YAML::Value << spPerspecCamera->GetAspectRatio();
			out << YAML::EndMap; // Camera

			out << YAML::Key << "Primary" << YAML::Value << cameraComponent.Primary;
			out << YAML::Key << "FixedAspectRatio" << YAML::Value << cameraComponent.FixedAspectRatio;

			out << YAML::EndMap; // CameraComponent
		}

		if (entity.HasComponent<SpriteRenderComponent>())
		{
			out << YAML::Key << "SpriteRenderComponent";
			out << YAML::BeginMap;

			auto& spriteRendererComponent = entity.GetComponent<SpriteRenderComponent>();
			out << YAML::Key << "Color" << YAML::Value << spriteRendererComponent.spQuadPrimitive->GetColor();

			if (spriteRendererComponent.spTexture != nullptr)
			{
				out << YAML::Key << "TexturePath" << YAML::Value << spriteRendererComponent.spTexture->GetTexturePath();
			}
			out << YAML::EndMap; // SpriteRendererComponent
		}

		if (entity.HasComponent<CircleRenderComponent>())
		{
			out << YAML::Key << "CircleRenderComponent";
			out << YAML::BeginMap;

			auto& circleRenderComponent = entity.GetComponent<CircleRenderComponent>();
			out << YAML::Key << "Color" << YAML::Value << circleRenderComponent.spCirclePrimitive->GetColor();
			out << YAML::Key << "Thickness" << YAML::Value << circleRenderComponent.spCirclePrimitive->GetThickness();
			out << YAML::Key << "Fade" << YAML::Value << circleRenderComponent.spCirclePrimitive->GetFade();
			if (circleRenderComponent.spTexture != nullptr)
			{
				out << YAML::Key << "TexturePath" << YAML::Value << circleRenderComponent.spTexture->GetTexturePath();
			}
			out << YAML::EndMap; // SpriteRendererComponent
		}

		if (entity.HasComponent<RigidBody2DComponent>())
		{
			out << YAML::Key << "RigidBody2DComponent";
			out << YAML::BeginMap;
			auto& rigidBody = entity.GetComponent<RigidBody2DComponent>();
			out << YAML::Key << "BodyType" << YAML::Value << static_cast<int>(rigidBody.Type);
			out << YAML::Key << "FixedRotation" << YAML::Value << rigidBody.FixedRotation;
			out << YAML::EndMap;
		}

		if (entity.HasComponent<BoxCollider2DComponent>())
		{
			out << YAML::Key << "BoxCollider2DComponent";
			out << YAML::BeginMap;
			auto& boxCollider = entity.GetComponent<BoxCollider2DComponent>();
			out << YAML::Key << "Offset" << YAML::Value << boxCollider.Offset;
			out << YAML::Key << "Size" << YAML::Value << boxCollider.Size;
			out << YAML::Key << "Density" << YAML::Value << boxCollider.Density;
			out << YAML::Key << "Friction" << YAML::Value << boxCollider.Friction;
			out << YAML::Key << "Restitution" << YAML::Value << boxCollider.Restitution;
			out << YAML::Key << "RestitutionThreshold" << YAML::Value << boxCollider.RestitutionThreshold;
			out << YAML::EndMap;
		}

		if (entity.HasComponent<CircleCollider2DComponent>())
		{
			out << YAML::Key << "CircleCollider2DComponent";
			out << YAML::BeginMap;
			auto& circleCollider = entity.GetComponent<CircleCollider2DComponent>();
			out << YAML::Key << "Offset" << YAML::Value << circleCollider.Offset;
			out << YAML::Key << "Radius" << YAML::Value << circleCollider.Radius;
			out << YAML::Key << "Density" << YAML::Value << circleCollider.Density;
			out << YAML::Key << "Friction" << YAML::Value << circleCollider.Friction;
			out << YAML::Key << "Restitution" << YAML::Value << circleCollider.Restitution;
			out << YAML::Key << "RestitutionThreshold" << YAML::Value << circleCollider.RestitutionThreshold;
			out << YAML::EndMap;
		}

		out << YAML::EndMap;
	}
}

SceneSerializer::SceneSerializer(const Ref<Scene>& spScene):m_spScene(spScene)
{

}

void SceneSerializer::Serialize(const std::string& sFilePath)
{
	YAML::Emitter out;
	out << YAML::BeginMap;
	out << YAML::Key << "Scene" << YAML::Value << "Untitled";
	out << YAML::Key << "Entities" << YAML::Value << YAML::BeginSeq;
	auto spRegistry = m_spScene->Registry();
	spRegistry->each([&](auto entityID)
	{
			Entity entity(spRegistry, entityID);
			SerializeEntity(out, entity);
	});
	out << YAML::EndSeq;
	out << YAML::EndMap;

	std::ofstream fout(sFilePath);
	fout << out.c_str();

}

void SceneSerializer::SerializeRuntime(const std::string& sFilePath)
{

}

bool SceneSerializer::DeSerialize(const std::string& sFilePath)
{
	std::ifstream stream(sFilePath);
	std::stringstream sStream;
	sStream << stream.rdbuf();

	YAML::Node data = YAML::Load(sStream.str());
	if (!data["Scene"])
	{
		return false;
	}

	std::string sSceneName = data["Scene"].as<std::string>();
	LOG_DEV_TRACE("DeSerializing scene '{0}'", sSceneName);

	auto entities = data["Entities"];
	if (entities)
	{
		for (auto entity : entities)
		{
			uint64_t uuid = entity["Entity"].as<uint64_t>();

			std::string sName;
			auto tagComponent = entity["TagComponent"];
			if (tagComponent)
				sName = tagComponent["Tag"].as<std::string>();

			LOG_DEV_TRACE("Deserialized entity with ID = {0}, name = {1}", uuid, sName);

			Ref<Entity> deserializedEntity = m_spScene->CreateEntityWithUUID(uuid, sName);

			auto transformComponent = entity["TransformComponent"];
			if (transformComponent)
			{
				// Entities always have transforms
				auto& tc = deserializedEntity->GetComponent<TransformComponent>();
				tc.Translation = transformComponent["Translation"].as<glm::vec3>();
				tc.Rotation = transformComponent["Rotation"].as<glm::vec3>();
				tc.Scale = transformComponent["Scale"].as<glm::vec3>();
			}

			auto cameraComponent = entity["CameraComponent"];
			if (cameraComponent)
			{
				auto& cc = deserializedEntity->AddComponent<CameraComponent>();

				auto& orthoCameraProps = cameraComponent["Ortho Camera"];
				auto spOrthoCamera = std::dynamic_pointer_cast<OrthoGraphicCamera>(cc.OrthoCamera);
				TINY_ENGINE_ASSERT(spOrthoCamera, "Ortho Camera is null in Serialize");
				spOrthoCamera->SetProjectionType(static_cast<ProjectionType>(orthoCameraProps["ProjectionType"].as<int>()));
				spOrthoCamera->SetOrthoSize(orthoCameraProps["OrthographicSize"].as<float>());
				spOrthoCamera->SetNearClip(orthoCameraProps["OrthographicNear"].as<float>());
				spOrthoCamera->SetFarClip(orthoCameraProps["OrthographicFar"].as<float>());
				spOrthoCamera->SetAspectRatio(orthoCameraProps["AspectRatio"].as<float>());

				auto& persCameraProps = cameraComponent["Perspective Camera"];
				auto spPerspecCamera = std::dynamic_pointer_cast<PerspectiveGraphicCamera>(cc.PerspecCamera);
				TINY_ENGINE_ASSERT(spPerspecCamera, "Perspective Camera is null in Serialize");
				spPerspecCamera->SetProjectionType(static_cast<ProjectionType>(persCameraProps["ProjectionType"].as<int>()));
				spPerspecCamera->SetPerspectiveFOV(persCameraProps["PerspectiveFOV"].as<float>());
				spPerspecCamera->SetNearClip(persCameraProps["PerspectiveNear"].as<float>());
				spPerspecCamera->SetFarClip(persCameraProps["PerspectiveFar"].as<float>());
				spPerspecCamera->SetAspectRatio(orthoCameraProps["AspectRatio"].as<float>());

				cc.Primary = cameraComponent["Primary"].as<bool>();
				cc.FixedAspectRatio = cameraComponent["FixedAspectRatio"].as<bool>();
			}

			auto spriteRenderComponent = entity["SpriteRenderComponent"];
			if (spriteRenderComponent)
			{
				auto& src = deserializedEntity->AddComponent<SpriteRenderComponent>();
				src.spQuadPrimitive->SetColor(spriteRenderComponent["Color"].as<glm::vec4>());
				if (spriteRenderComponent["TexturePath"].IsDefined())
				{
					std::string sPath = spriteRenderComponent["TexturePath"].as<std::string>();
					src.spTexture = Texture2D::Create(sPath);
				}
			}

			auto circleRenderComponent = entity["CircleRenderComponent"];
			if (circleRenderComponent)
			{
				auto& src = deserializedEntity->AddComponent<CircleRenderComponent>();
				src.spCirclePrimitive->SetColor(circleRenderComponent["Color"].as<glm::vec4>());
				src.spCirclePrimitive->SetThickness(circleRenderComponent["Thickness"].as<float>());
				src.spCirclePrimitive->SetFade(circleRenderComponent["Fade"].as<float>());
				if (circleRenderComponent["TexturePath"].IsDefined())
				{
					std::string sPath = circleRenderComponent["TexturePath"].as<std::string>();
					src.spTexture = Texture2D::Create(sPath);
				}
			}

			auto rigidBody2DComponent = entity["RigidBody2DComponent"];
			if (rigidBody2DComponent)
			{
				auto& rigidBody2D = deserializedEntity->AddComponent<RigidBody2DComponent>();
				rigidBody2D.Type = static_cast<BodyType>(rigidBody2DComponent["BodyType"].as<int>());
				rigidBody2D.FixedRotation = rigidBody2DComponent["FixedRotation"].as<bool>();
			}

			auto boxCollider2DComponent = entity["BoxCollider2DComponent"];
			if (boxCollider2DComponent)
			{
				auto& boxCollider2D = deserializedEntity->AddComponent<BoxCollider2DComponent>();
				boxCollider2D.Offset = boxCollider2DComponent["Offset"].as<glm::vec2>();
				boxCollider2D.Size = boxCollider2DComponent["Size"].as<glm::vec2>();
				boxCollider2D.Density = boxCollider2DComponent["Density"].as<float>();
				boxCollider2D.Friction = boxCollider2DComponent["Friction"].as<float>();
				boxCollider2D.Restitution = boxCollider2DComponent["Restitution"].as<float>();
				boxCollider2D.RestitutionThreshold = boxCollider2DComponent["RestitutionThreshold"].as<float>();
			}

			auto circleCollider2DComponent = entity["CircleCollider2DComponent"];
			if (circleCollider2DComponent)
			{
				auto& circleCollider2D = deserializedEntity->AddComponent<CircleCollider2DComponent>();
				circleCollider2D.Offset = circleCollider2DComponent["Offset"].as<glm::vec2>();
				circleCollider2D.Radius = circleCollider2DComponent["Radius"].as<float>();
				circleCollider2D.Density = circleCollider2DComponent["Density"].as<float>();
				circleCollider2D.Friction = circleCollider2DComponent["Friction"].as<float>();
				circleCollider2D.Restitution = circleCollider2DComponent["Restitution"].as<float>();
				circleCollider2D.RestitutionThreshold = circleCollider2DComponent["RestitutionThreshold"].as<float>();
			}
		}
	}

	return true;
}

bool SceneSerializer::DeSerializeRuntime(const std::string& sFilePath)
{
	return false;
}

void SceneSerializer::SetSelectedScene(const Ref<Scene>& spScene)
{
	m_spScene = spScene;
}

TINY_ENGINE_NAMESPACE_END