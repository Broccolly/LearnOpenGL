#pragma once

class Texture
{
public:
	explicit Texture(const char* sourcePath, bool RGBA);
	void SetToTextureUnit(unsigned int unit);

private:

private:
	unsigned int textureID;
};