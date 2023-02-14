/*
 * Definitions for BresenhamLine.h
 */
#include "BresenhamLine.h"

#include <iostream>
#include <cstdlib>

BresenhamLine::BresenhamLine(int windowWidth, int windowHeight, Vec2 p1, Vec2 p2)
{
    unsigned int dx = (unsigned int) std::abs(p2.x - p1.x);
    unsigned int dy = (unsigned int) std::abs(p2.y - p1.y);

    m_CoordsCount = 2 * (dx + 1);
    m_Points = new float[m_CoordsCount];

    int _2dy = 2 * dy;
    int _2dy_2dx = _2dy - (2 * dx);

    float xk = p1.x, yk = p1.y;
    m_Points[0] = xk; m_Points[1] = yk;

    int pk = _2dy - dx;
    for (unsigned int i = 1; i <= dx; i++)
    {
        m_Points[2 * i] = GetNormalizedCoordinate(++xk, 0, windowWidth);

        if (pk < 0)
        {
            m_Points[(2 * i) + 1] = GetNormalizedCoordinate(yk, 0, windowHeight);
            pk += _2dy;
        }
        else
        {
            m_Points[(2 * i) + 1] = GetNormalizedCoordinate(++yk, 0, windowHeight);
            pk += _2dy_2dx;
        }
    }

    m_Va = new VertexArray();
    m_Va->Bind();

    m_Vb = new VertexBuffer(m_Points, m_CoordsCount * sizeof(float));
    m_Vbl = new VertexBufferLayout();
    m_Vbl->Push<float>(2, false);
    m_Va->AddBuffer(*m_Vb, *m_Vbl);
}

BresenhamLine::~BresenhamLine()
{
    delete m_Points;
    delete m_Va;
    delete m_Vb;
    delete m_Vbl;
}

VertexArray* BresenhamLine::GetVertexArray()
{
    return m_Va;
}

IndexBuffer* BresenhamLine::GetIndexBuffer()
{
    return nullptr;
}

void BresenhamLine::Draw()
{
    glDrawArrays(GL_POINTS, 0, m_CoordsCount / 2);
}
