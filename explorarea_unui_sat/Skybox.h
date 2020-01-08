


#include <string>



#include <vector>



#include <glm.hpp>


#include <GL/glew.h>
#include <glfw3.h>



#include "stb_image.h"


#include "Shader.h"

class Skybox
{
public:
	Skybox();

	void Draw(const glm::mat4& view, const glm::mat4& projection);

private:
	unsigned int cubemapTexture;

	GLuint VAO;
	GLuint VBO;

	Shader* shader = new Shader("Skybox");

	GLuint loadCubemap(std::vector<std::string> faces);
};

