/*
 * Definitions for a Mesh and its functionality.
 * Adopted, with appropriate changes, from the Learn OpenGL Tutorials
 * Tutorial URL: https://learnopengl.com/
 */

#pragma once

#include "Drawable.h"

#include <glm/glm.hpp>
#include <string>
#include <vector>

#include "../primitives/VertexArray.h"
#include "../primitives/VertexBuffer.h"
#include "../primitives/IndexBuffer.h"
#include "../primitives/VertexBufferLayout.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh : public Drawable
{
private:
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
    std::vector<Texture> m_Textures;

    Shader* m_Shader;
    VertexArray* m_Va;
    VertexBuffer* m_Vb;
    IndexBuffer* m_Ib;
    VertexBufferLayout* m_Vbl;
public:
    Mesh(Shader* shader, std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    ~Mesh();

    // Inherited via Drawable
    virtual VertexArray* GetVertexArray() override;
    virtual IndexBuffer* GetIndexBuffer() override;
    virtual Shader* GetShader() override;

    std::vector<Vertex>& GetVertices();
    std::vector<unsigned int>& GetIndices();
    std::vector<Texture>& GetTextures();

    virtual void Draw() override;
};

