
#include<iostream>
#include<string>
#include<fstream>
#include<cassert>
#include "matrix.h"
/**
 *@file matrix.cpp
 *
 * @brief The implementation of the matrix class.
 * Author Karo
 * Copyright (c) 2020 Karo
 */

 
void Matrix :: set_matrix_with_value(int z,int y,int x,int &value)
{
	assert(z>=0 && z<m_z);/*!< @brief used for check z size of Matrix*/
	assert(y>=0 && y<m_y);
	assert(x>=0 && x<m_x);
	matrix[z][y][x]=value;
}

void Matrix :: make_matrix()
{
	assert(m_z > 0);
	assert(m_y > 0);
	assert(m_x > 0);
	matrix = new int**[m_z];
	for (int i = 0; i < m_z; ++i)
	{
		matrix[i] = new int*[m_y];
		for (int j = 0; j < m_y; ++j)
		{
			matrix[i][j]=new int[m_x];
		}
	}
}
void Matrix :: clean_matrix()
{
	for (int i = 0; i < m_z; ++i)
	{
		for (int j = 0; j < m_y; ++j)
		{
			delete [] matrix[i][j];
		}
		delete [] matrix[i];
	}
	delete [] matrix;
}
void Matrix::read_from_file(const std::string &filename)
{
	std::fstream file;
	file.open(filename);
	int value(0);
	int z(0);
	int y(0);
	int x(0);
	file>>value;
	while(file.fail()!=true)
	{
		matrix[z][y][x]=value;
		file>>value;
		x++;
		if(x==m_x) {x=0;y++;}
		if(y==m_y) {y=0;z++;}
	}
	file.close();
}
void Matrix::write_to_file(const std::string &filename)
{
	std::fstream file;
	file.open(filename);
	for (int i = 0; i < m_z; ++i)
	{
		for (int j = 0; j < m_y; ++j)
		{
			for (int k = 0; k < m_x; ++k)
			{
				file<<matrix[i][j][k]<<" ";
			}
			file<<std::endl;
		}
		file<<std::endl<<std::endl;
	}
	file.close();
}

void Matrix::display_matrix()
{
	std::cout<<std::endl;
	std::cout<<"display_matrix"<<std::endl;
	for (int i = 0; i < m_z; ++i)
	{
		for (int j = 0; j < m_y; ++j)
		{
			for (int k = 0; k < m_x; ++k)
			{
				std::cout<<matrix[i][j][k]<<" ";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl<<std::endl;
	}
	std::cout<<std::endl;
}


Matrix::Matrix(int z, int y, int x)
    : m_z(z)
    , m_y(y)
    , m_x(x)
{
    make_matrix();
}

Matrix::~Matrix()
{
    clean_matrix();
}
