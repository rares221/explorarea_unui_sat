
#include<string>
#include<GL\glew.h>
#include<fstream>
#include<iostream>

class ShaderManager
{
public:
	ShaderManager(const std::string& filename);
	virtual ~ShaderManager();
	void ShaderBinder();
private:
	ShaderManager(const ShaderManager& other) {}
	void operator=(const ShaderManager& other) {}
	static const unsigned int NUM_TRANSF=3;
	static const unsigned int NUM_SHADER=3;
	

	GLuint m_program;
	GLuint m_shaders[NUM_SHADER];
	GLuint m_uniformVariables[NUM_TRANSF];
	


};


