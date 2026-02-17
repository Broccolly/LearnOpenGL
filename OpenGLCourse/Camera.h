#pragma once
class Camera
{
public:
	Camera() = default;
	Camera(const glm::vec3& position, const glm::quat& orientation, float fov);
	~Camera();

	void SetOrientation(const glm::quat& newOrientation) {orientation = newOrientation;}
	const glm::quat& GetOrientation() const { return orientation; }

	void SetAspectRatio(const float& newAspectRatio) { aspectRatio = newAspectRatio; }
	const float GetAspectRatio() const { return aspectRatio; }

	void PreApplyRotation(const glm::quat& rotationQuat) { orientation = orientation * rotationQuat; }
	void PostApplyRotation(const glm::quat& rotationQuat) { orientation = rotationQuat * orientation; }

	void SetPosition(const glm::vec3& newPosition) { pos = newPosition; }
	void PreApplyTranslation(const glm::vec3& translation) { pos += orientation * translation; }
	void PostApplyTranslation(const glm::vec3& translation) { pos += translation; }

	const glm::vec3& GetPosition() const { return pos; }
	
	void SetFOV(float newFov) { fov = newFov; }
	float GetFOV() const { return fov; }

	void GetViewMatrix(glm::mat4&) const;
	void GetProjectionMatrix(glm::mat4&) const;

private:
	float fov{ 45.0f };
	float aspectRatio{ 1.0f };
	glm::vec3 pos{ 0.0f, 0.0f, 0.0f };
	glm::quat orientation{ 1.0f, 0.0f, 0.0f, 0.0f };

};

class DebugCamera : public Camera
{
public :
	void ApplyLookControls(float dx, float dy);
	void ApplyMoveControls(float dx, float dy, float dz, float dt);
	void ApplyScrollControls(float dScroll);

private:
	float sensitivity = 0.002f;
	float moveSpeed = 10.0f;

};

