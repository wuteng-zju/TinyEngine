#include "SandBox2DLayer.h"

SandBox2DLayer::SandBox2DLayer() :m_vec4Color(glm::vec4(0.2f, 0.3f, 0.8f, 1.0f))
{
	m_spOrthoGraphicCameraController = CreateRef<OrthoGraphicCameraController>
		(Application::GetApplication()->GetWindowWidth(), Application::GetApplication()->GetWindowHeight());
}

SandBox2DLayer::~SandBox2DLayer()
{
}

void SandBox2DLayer::OnAttach()
{
	m_spTexture = Texture2D::Create("assets/textures/Checkerboard.png");
	m_spTextureStar = Texture2D::Create("assets/textures/Star.png");

	m_spTextureSprite = Texture2D::Create("assets/games/textures/RPGpack_sheet_2X.png");
	m_spSubTexStairs = CreateRef<SubTexture2D>(m_spTextureSprite, glm::vec2(7, 6), glm::vec2(128, 128));
	m_spSubTexBarrel = CreateRef<SubTexture2D>(m_spTextureSprite, glm::vec2(1, 11), glm::vec2(128, 128));
	m_spSubTexTree = CreateRef<SubTexture2D>(m_spTextureSprite, glm::vec2(2, 1), glm::vec2(128, 128), glm::vec2(1.f, 2.f));

	m_spParticleSystem2D = CreateRef<ParticleSystem2D>();

	m_Particle.Position = glm::vec2(0.0f);
	m_Particle.Velocity = glm::vec2(0.0f);
	m_Particle.VelocityVariation = glm::vec2(3.0f, 1.0f);
	m_Particle.ColorBegin = glm::vec4(254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f);
	m_Particle.ColorEnd = glm::vec4(254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f);
	m_Particle.SizeBegin = 0.5f;
	m_Particle.SizeEnd = 0.0f;
	m_Particle.SizeVariation = 0.3f;
	m_Particle.LifeTime = 1.0f;
	m_Particle.ParticleType = ParticleRenderType::TEXTURE;
	m_Particle.RefTexture = m_spTextureStar;
}

void SandBox2DLayer::OnDetach()
{

}

void SandBox2DLayer::OnUpdate(const TimeStep& timeStep)
{
	TINY_ENGINE_PROFILE_SCOPE("SandBox2DLayer::OnUpdate");

	{
		TINY_ENGINE_PROFILE_SCOPE("CameraController::OnUpdate");
		m_spOrthoGraphicCameraController->OnUpdate(timeStep);
	}

	Render2D::ResetStats();
	{
		TINY_ENGINE_PROFILE_SCOPE("Render Prep");
		RenderCommand::SetClearColor(glm::vec4(glm::vec3(0.1f), 1.0f));
		RenderCommand::Clear();
	}

	if (Input::IsMouseButtonPressed(Mouse::ButtonLeft))
	{
		auto mousePos= Input::GetMousePos();
		float width = Application::GetApplication()->GetWindowWidth();
		float height = Application::GetApplication()->GetWindowHeight();
		auto cameraBound = m_spOrthoGraphicCameraController->GetOrthoGraphicCameraBounds();
		auto cameraPos = m_spOrthoGraphicCameraController->GetCamera()->GetPositon();
		auto x = (mousePos.x / width) * cameraBound.GetWidth() - cameraBound.GetWidth() * 0.5f;
		auto y = cameraBound.GetHeight() * 0.5f - (mousePos.y / height) * cameraBound.GetHeight();
		m_Particle.Position = glm::vec2(cameraPos.x + x, cameraPos.y + y);
		for (int i = 0; i < 5; i++)
		{
			m_spParticleSystem2D->Emit(m_Particle);
		}
	}

	Render2D::BeginScene(m_spOrthoGraphicCameraController->GetCamera());
	//Render2D::DrawQuad(glm::vec3(0.f, 0.f, 0.5f), 0.f, glm::vec2(1.f), m_spSubTexStairs);
	//Render2D::DrawQuad(glm::vec3(1.f, 0.f, 0.5f), 0.f, glm::vec2(1.f), m_spSubTexBarrel);
	//Render2D::DrawQuad(glm::vec3(-1.f, 0.f, 0.5f), 0.f, glm::vec2(1.f,2.f), m_spSubTexTree);
	Render2D::EndScene();

	m_spParticleSystem2D->OnUpdate(timeStep);
	m_spParticleSystem2D->OnRender(m_spOrthoGraphicCameraController->GetCamera());
}

void SandBox2DLayer::OnImGuiRender()
{
	ImGui::Begin("Settings");
	auto spQuadStatic = Render2D::GetQuadStatic();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", spQuadStatic->GetDrawCalls());
	ImGui::Text("Draw Quads: %d", spQuadStatic->GetDrawCount());
	ImGui::Text("Draw Vertices: %d", spQuadStatic->GetTotalVertexCount());
	ImGui::Text("Draw Indices: %d", spQuadStatic->GetTotalIndexCount());
	ImGui::End();
	ImGui::ShowDemoWindow();
}

void SandBox2DLayer::OnEvent(Event& e)
{
	m_spOrthoGraphicCameraController->OnEvent(e);
}
