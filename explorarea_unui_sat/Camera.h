#pragma once

#include "GeneralWindowData.h"

#define GLM_FORCE_CTOR_INIT 
#include <GLM.hpp>

#include<gtx/transform.hpp>

#include <iostream>


class Camera
{
public:

	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		m_forward = glm::vec3(0.0f, 0.0f, 1.0f);
		m_up = glm::vec3(0.0f, 1.0f, 0.0f);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}

	inline glm::mat4 GetView() const
	{
		return glm::lookAt(m_position, m_position + m_forward, m_up);
	}

	inline glm::mat4 GetPerspective() const
	{
		return m_perspective;
	}

	void MoveForward(float amt)
	{
		m_position += m_forward * amt;
	}

	void MoveRight(float amt)
	{
		m_position += glm::cross(m_up, m_forward) * amt;
	}

	void Pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(m_up, m_forward));

		m_forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(m_forward, 0.0)));
		m_up = glm::normalize(glm::cross(m_forward, right));
	}

	void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		m_forward = glm::vec3(glm::normalize(rotation * glm::vec4(m_forward, 0.0)));
		m_up = glm::vec3(glm::normalize(rotation * glm::vec4(m_up, 0.0)));
	}

	void MouseControl(float xPos, float yPos)
	{
		const int xMid = WindowData::SCR_WIDTH / 2;
		const int yMid = WindowData::SCR_HEIGHT / 2;
		const float xChange = (xPos - xMid) * mouseSensitivity;
		const float yChange = (yPos - yMid) * mouseSensitivity;

		ProcessMouseMovement(xChange, yChange);
	}

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

	// Camera movement sesnivity
	const float cameraSpeedFactor = 0.05f;

private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;	
	const float mouseSensitivity = 0.1f;
	// Mouse sesnivity

	// Euler Angles
	float yaw = 0.0f;
	float pitch = 0.0f;
};






