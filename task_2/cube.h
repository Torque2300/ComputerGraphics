#ifndef CUBE_H
#define CUBE_H
#include <cmath>
#include <vector>


class coordinate
{
    float _x;
    float _y;
    float _z;

public:

    coordinate() : _x(), _y(), _z()
    {
    }

    coordinate(float x, float y, float z) : _x(x), _y(y), _z(z)
    {
    }

    float get_x()
    {
        return _x;
    }

    float get_y()
    {
        return _y;
    }

    float get_z()
    {
        return _z;
    }

};


class Cube
{
private:

    int _vertices_count;
    float _side_size;

public:

    Cube() = delete;

    Cube(int count, float side_size) : _vertices_count(count), _side_size(side_size){
    }

    std::vector<coordinate> create_cube()
    {
        float triangle_side = _side_size / _vertices_count;
        std::vector<coordinate> _vertices;
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < _vertices_count; i++)
            {
                for (int j = 0; j < _vertices_count; j++)
                {
                    if (k == 0)
                    {
                        _vertices.emplace_back(coordinate(j * triangle_side, i * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate(j * triangle_side, (i + 1) * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate((j + 1) * triangle_side, i * triangle_side, k * triangle_side * _vertices_count));

                        _vertices.emplace_back(coordinate((j + 1) * triangle_side, (i + 1) * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate((j + 1) * triangle_side, i * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate(j * triangle_side, (i + 1) * triangle_side, k * triangle_side * _vertices_count));
                    }
                    if (k == 1)
                    {
                        _vertices.emplace_back(coordinate(j * triangle_side, i * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate((j + 1) * triangle_side, i * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate(j * triangle_side, (i + 1) * triangle_side, k * triangle_side * _vertices_count));

                        _vertices.emplace_back(coordinate((j + 1) * triangle_side, (i + 1) * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate(j * triangle_side, (i + 1) * triangle_side, k * triangle_side * _vertices_count));
                        _vertices.emplace_back(coordinate((j + 1) * triangle_side, i * triangle_side, k * triangle_side * _vertices_count));

                    }
                }
            }
        }
        for (int k = 0; k < 2; k++)
                {
                    for (int i = 0; i < _vertices_count; i++)
                    {
                        for (int j = 0; j < _vertices_count; j++)
                        {
                            if (k == 0)
                            {
                                _vertices.emplace_back(coordinate(j * triangle_side, k * triangle_side * _vertices_count, i * triangle_side));
                                _vertices.emplace_back(coordinate((j + 1) * triangle_side, k * triangle_side * _vertices_count, i * triangle_side));
                                _vertices.emplace_back(coordinate(j * triangle_side, k * triangle_side * _vertices_count, (i + 1) * triangle_side));

                                _vertices.emplace_back(coordinate((j + 1) * triangle_side, k * triangle_side * _vertices_count, (i + 1) * triangle_side));
                                _vertices.emplace_back(coordinate(j * triangle_side, k * triangle_side * _vertices_count, (i + 1) * triangle_side));
                                _vertices.emplace_back(coordinate((j + 1) * triangle_side, k * triangle_side * _vertices_count, i * triangle_side));
                            }
                            if (k == 1)
                            {
                                _vertices.emplace_back(coordinate(j * triangle_side, k * triangle_side * _vertices_count, i * triangle_side));
                                _vertices.emplace_back(coordinate(j * triangle_side, k * triangle_side * _vertices_count, (i + 1) * triangle_side));
                                _vertices.emplace_back(coordinate((j + 1) * triangle_side, k * triangle_side * _vertices_count, i * triangle_side));

                                _vertices.emplace_back(coordinate((j + 1) * triangle_side, k * triangle_side * _vertices_count, (i + 1) * triangle_side));
                                _vertices.emplace_back(coordinate((j + 1) * triangle_side, k * triangle_side * _vertices_count, i * triangle_side));
                                _vertices.emplace_back(coordinate(j * triangle_side, k * triangle_side * _vertices_count, (i + 1) * triangle_side));
                            }
                        }
                    }
                }
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < _vertices_count; i++)
            {
                for (int j = 0; j < _vertices_count; j++)
                {
                    if (k == 0)
                    {
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, j * triangle_side, i * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, j * triangle_side, (i + 1) * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, (j + 1) * triangle_side, i * triangle_side));

                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, (j + 1) * triangle_side, (i + 1) * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, (j + 1) * triangle_side, i * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, j * triangle_side, (i + 1) * triangle_side));
                    }
                    if (k == 1)
                    {
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, j * triangle_side, i * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, (j + 1) * triangle_side, i * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, j * triangle_side, (i + 1) * triangle_side));


                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, (j + 1) * triangle_side, (i + 1) * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, j * triangle_side, (i + 1) * triangle_side));
                        _vertices.emplace_back(coordinate(k * triangle_side * _vertices_count, (j + 1) * triangle_side, i * triangle_side));

                    }
                }
            }
        }
        return _vertices;
    }

};


#endif // CUBE_H
