#pragma once
#include <glm.hpp>
#include <gtx/transform.hpp>

#include "Settings.h"

struct Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		this->pos = pos;
		this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, zNear, zFar);
	}

	glm::mat4 GetViewProjection() const
	{
		return projection * glm::lookAt(pos, pos + forward, up);
	}
	glm::mat4 GetView() const
	{
		return glm::lookAt(pos, pos + forward, up);
	}
	glm::mat4 GetProjection() const
	{
		return projection;
	}
	void MoveForward(float amt)
	{
		pos += forward * amt;
	}

	void MoveRight(float amt)
	{
		pos += glm::cross(up, forward) * amt;
	}

	void Pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, forward));

		forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		up = glm::normalize(glm::cross(forward, right));
	}

	void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

	void MouseControl(float xPos, float yPos)
	{
		const int xMid = Settings::WindowWidth / 2;
		const int yMid = Settings::WindowHeight / 2;
		const float xChange = (xPos - xMid)*mouseSensitivity;
		const float yChange = (yPos - yMid)*mouseSensitivity;

		ProcessMouseMovement(xChange, yChange);
	}

private:
	void ProcessMouseMovement(float xOffset, float yOffset, bool constrainPitch = true)
	{
		yaw += xOffset;
		pitch += yOffset;

		// Ensuring no overhead camera movement appears
		if (constrainPitch) {
			if (pitch > 89.0f)
			{
				pitch = 89.0f;
				yOffset = 0;
			}
			if (pitch < -89.0f)
			{
				pitch = -89.0f;
				yOffset = 0;
			}
		}

		const float radRotationAngle = xOffset * glm::pi<float>() / 180.0f;
		const float radPitchAngle = -yOffset * glm::pi<float>() / 180.0f;
		RotateY(-radRotationAngle);
		Pitch(-radPitchAngle);
	}

public:
	// Camera movement sesnivity
	const float cameraSpeedFactor = 0.05f;

private:
	// Mouse sesnivity
	const float mouseSensitivity = 0.1f;
	// Euler Angles
	float yaw = 0.0f;
	float pitch = 0.0f;


private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
};
