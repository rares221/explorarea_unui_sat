#include "ShaderManager.h"
#include<iostream>
#include<fstream>
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreateShader(const std::string& fullShaderText, GLenum shaderType);

ShaderManager::ShaderManager(const std::string& filename)
{
	m_program = glCreateProgram();
	m_shaders[0]=CreateShader(LoadShader(filename+".vs"),GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(filename+".fs"), GL_FRAGMENT_SHADER);
	for (unsigned int i = 0; i < NUM_SHADER; i++)
		glAttachShader(m_program, m_shaders[i]);

	glBindAttribLocation(m_program, 0, "position");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Shader Program failed to link  ");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Shader Program is invalid ");
	

}
ShaderManager::~ShaderManager()
{
	for (unsigned int i = 0; i < NUM_SHADER; i++)
	{
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);

	}

	glDeleteProgram(m_program);

}
void ShaderManager::ShaderBinder()
{
	glUseProgram(m_program);

}
static GLuint CreateShader(const std::string& fullShaderText, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	if (shader == 0)
	{
		std::cerr << "Error: Shader cration failed! " << std::endl;

	}

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringsLenghts[1];

	shaderSourceStrings[0] = fullShaderText.c_str();
	shaderSourceStringsLenghts[0] = fullShaderText.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLenghts);
	glCompileShader(shader);
	
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");

	return shader;
	
}


static std::string LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());

	std::string output;
	std::string line;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	} 
	else
	{
		std::cerr << "Unable to load shader: " << fileName << std::endl;

	}
	return output;

}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader,flag,&success);
	if (success == GL_FALSE)
	{
		if (isProgram)
		{
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);

		}
		else	
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

	}
	std::cerr << errorMessage << ": " << error << std::endl;


}




