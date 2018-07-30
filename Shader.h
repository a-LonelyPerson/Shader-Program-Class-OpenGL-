class Shader
	{
	private:
		unsigned int m_ShaderID;
		std::unordered_map<std::string, int> m_UniformLocationCache;

	public:
		Shader(const std::string& vertexPath,
			   const std::string& fragmentPath);

		Shader(const std::string& vertexPath,
			   const std::string& fragmentPath,
			   const std::string& geometryPath);

		~Shader();

		void Bind() const;
		void UnBind() const;

		// Setters (Uniforms)
		// -------------------------------------------------------------------------------
		void SetUniform1f(const std::string& name, float value);
		void SetUniform1i(const std::string& name, int value);

		void SetUniform2f(const std::string& name, float v1, float v2);
		void SetUniform2f(const std::string& name, const glm::vec2& value);
		
		void SetUniform3f(const std::string& name, float v1, float v2, float v3);
		void SetUniform3f(const std::string& name, const glm::vec3& value);

		void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
		void SetUniform4f(const std::string& name, const glm::vec4& value);

		void SetUniformMat4(const std::string& name, const glm::mat4& value);

	private:
		unsigned int CompileShader(unsigned int type, const std::string& source);
		int GetUniformLocation(const std::string& name);
	};
