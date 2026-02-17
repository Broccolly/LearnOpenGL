#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Camera.h"

Camera::Camera(const glm::vec3& position, const glm::quat& orientation, float fov) : pos(position), orientation(orientation), fov(fov)
{
}

Camera::~Camera()
{
}

void Camera::GetViewMatrix(glm::mat4& transform) const
{
	//cameraTransform = glm::rotate(glm::mat4(1.0f), 0.2f * deltaTime, glm::vec3(0.0f, 1.0f, 0.0f)) * cameraTransform;
	transform = glm::identity<glm::mat4>();
	transform = glm::translate(transform, pos);
	transform = transform * glm::toMat4(orientation);
	transform = glm::inverse(transform);
}

void Camera::GetProjectionMatrix(glm::mat4& proj) const
{
	proj = glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 100.0f); // Identity
}

void DebugCamera::ApplyLookControls(float dx, float dy)
{
	glm::vec3 axis = GetOrientation() * glm::vec3(0.0f, 1.0f, 0.0f);

	PostApplyRotation(glm::rotate(glm::quat_identity<float, glm::packed_highp>(), -sensitivity * dx, glm::vec3(0.0f, 1.0f, 0.0f)));

	glm::quat newQuat = glm::rotate(GetOrientation(), -sensitivity * dy, glm::vec3(1.0f, 0.0f, 0.0f));

	// Shortcut to test newY against Y and stop overrotation vertically
	if (newQuat.w * newQuat.w + newQuat.y * newQuat.y - newQuat.x * newQuat.x - newQuat.z * newQuat.z >= 0)
	{
		SetOrientation(newQuat);
	}
}

void DebugCamera::ApplyMoveControls(float dx, float dy, float dz, float dt)
{
	PreApplyTranslation(glm::vec3(moveSpeed * dt * dx, moveSpeed * dt * dy, moveSpeed * dt * dz));
}

void DebugCamera::ApplyScrollControls(float dScroll)
{
	SetFOV(GetFOV() - dScroll);
	if (GetFOV() < 1.0f)
		SetFOV(1.0f);
	if (GetFOV() > 80.0f)
		SetFOV(80.0f);
}
