#pragma once

#include "Drawable.h"
#include "../primitives/Shader.h"
#include <vector>
#include "Mesh.h"
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../primitives/Camera.h"
#include <glm/glm.hpp>

class Model : public Drawable
{
private:
	int m_WindowWidth;
	int m_WindowHeight;

	Camera* m_Camera;

	Shader* m_Shader;
	std::vector<Mesh*> m_Meshes;
	std::string m_Directory;
	std::vector<Texture> m_TexturesLoaded;

	void LoadModel(const std::string path);

	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh* ProcessMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(std::string path, bool gamma = false);
public:
	Model(int windowWidth, int windowHeight, Shader* shader, const std::string path);
	~Model();

	inline Camera* GetCamera() { return m_Camera; }

	// Inherited via Drawable
	virtual VertexArray* GetVertexArray() override;
	virtual IndexBuffer* GetIndexBuffer() override;
	virtual Shader* GetShader() override;
	virtual void Draw() override;
};
