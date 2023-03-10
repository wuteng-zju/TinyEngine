#pragma once

TINY_ENGINE_NAMESPACE_BEGIN

// Shader类型：顶点着色器和片元着色器
enum class ShaderType
{
	VETEX_SHADER = 0,
	FRAGMENT_SHADER
};

// 编译类型
enum class CompileType
{
	LINK_STATUS = 0,
	PROGRAM_STATUS
};

// 着色器信息
struct ShaderInfo
{
	// 着色器类型
	ShaderType Type;
	// 着色器名称
	std::string Name;
	// 着色器文件路径
	std::string Path;

	// 构造函数
	ShaderInfo(ShaderType shaderType, const std::string& sPath, const std::string& sName = "")
		: Type(shaderType), Path(sPath), Name(sName)
	{}
};

// 着色器类
class Shader
{
public:
	virtual ~Shader() = default;
	virtual void Bind()const = 0;
	virtual void UnBind()const = 0;

	virtual void SetFloat(const std::string& sName, float fValue) = 0;
	virtual void SetFloat2(const std::string& sName, const glm::vec2& vec2Value) = 0;
	virtual void SetFloat3(const std::string& sName, const glm::vec3& vec3Value) = 0;
	virtual void SetFloat4(const std::string& sName, const glm::vec4& vec4Value) = 0;

	virtual void SetMat3(const std::string& name, const glm::mat3& mat3Value) = 0;
	virtual void SetMat4(const std::string& sName, const glm::mat4& mat4Value) = 0;

	virtual void SetInt(const std::string& sName, int iValue) = 0;
	virtual void SetInt2(const std::string& sName, const glm::ivec2& vec2Value) = 0;
	virtual void SetInt3(const std::string& sName, const glm::ivec3& vec3Value) = 0;
	virtual void SetInt4(const std::string& sName, const glm::ivec4& vec4Value) = 0;
	virtual void SetIntArray(const std::string& sName, const int* pValues, unsigned int uiCount) = 0;

	virtual void SetBool(const std::string& sName, bool bValue) = 0;

	virtual void SetUniformBlock(const std::string& sName, int iBlockBinding) = 0;

	virtual const std::string& GetName() const = 0;

	static Ref<Shader> Create(const std::vector<ShaderInfo>& vecShaderInfo, const std::string& sShaderName = "shader");

protected:
	std::string ReadFile(const std::string& filepath);
	Shader() = default;

private:
	Shader(Shader&) = delete;
	Shader& operator=(const Shader&) = delete;
};

// 
class ShaderLibrary
{
public:
	void Add(const Ref<Shader>& spShader);
	void Add(const Ref<Shader>& spShader, const std::string& sShaderName = "shader");
	Ref<Shader> Load(const std::vector<ShaderInfo>& vecShaderInfo, const std::string& sShaderName = "shader");
	Ref<Shader> Get(const std::string& sShaderName);
private:
	std::unordered_map<std::string, Ref<Shader>> m_mapShaders;
};
TINY_ENGINE_NAMESPACE_END