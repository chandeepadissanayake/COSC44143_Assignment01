/*
 * Definitions for Mesh.h
 */

#include "Mesh.h"

#include <GL/GL.h>

Mesh::Mesh(Shader* shader, std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
    :m_Shader(shader), m_Vertices(vertices), m_Indices(indices), m_Textures(textures)
{
    m_Va = new VertexArray();
    m_Va->Bind();

    m_Vb = new VertexBuffer(&m_Vertices[0], (unsigned int) m_Vertices.size() * sizeof(Vertex));
    m_Ib = new IndexBuffer(&m_Indices[0], (unsigned int) m_Indices.size());

    m_Vbl = new VertexBufferLayout();
    m_Vbl->Push<float>(3, true);
    m_Vbl->Push<float>(3, true);
    m_Vbl->Push<float>(2, true);

    m_Va->AddBuffer(*m_Vb, *m_Vbl);

    m_Va->Unbind();
}

Mesh::~Mesh()
{
    delete m_Va;
    delete m_Vb;
    delete m_Ib;
    delete m_Vbl;
}

VertexArray* Mesh::GetVertexArray()
{
    return m_Va;
}

IndexBuffer* Mesh::GetIndexBuffer()
{
    return m_Ib;
}

Shader* Mesh::GetShader()
{
    return m_Shader;
}

std::vector<Vertex>& Mesh::GetVertices()
{
    return m_Vertices;
}

std::vector<unsigned int>& Mesh::GetIndices()
{
    return m_Indices;
}

std::vector<Texture>& Mesh::GetTextures()
{
    return m_Textures;
}

void Mesh::Draw()
{
    Shader* shader = GetShader();

    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    for (unsigned int i = 0; i < m_Textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);

        std::string number;
        std::string name = m_Textures[i].type;
        if (name == "texture_diffuse")
        {
            number = std::to_string(diffuseNr++);
        }

        shader->SetUniform1i((name + number).c_str(), i);

        glBindTexture(GL_TEXTURE_2D, m_Textures[i].id);
    }
    glActiveTexture(GL_TEXTURE0);

    m_Va->Bind();
    glDrawElements(GL_TRIANGLES, (unsigned int) m_Indices.size(), GL_UNSIGNED_INT, 0);
    m_Va->Unbind();
}
