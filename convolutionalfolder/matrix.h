#ifndef MATRIX
#define MATRIX
#include <string>
/**
 * @class Matrix
 * @brief Matrix class represents 3D matrix
 *
 * More detailed description.
 */
class Matrix
{
private:
	int*** matrix;/*!<3 dimensional pointer for input or output of files */
	int m_z;/*!< int @param m_z - is z size of Matrix*/
	int m_y;/*!< int @param m_y - is y size of Matrix*/
	int m_x;/*!< int @param m_x - is x size of Matrix*/
public:

	int getZ() const {return m_z;}/*!< @brief used for return z size of Matrix*/
	int getY() const {return m_y;}/*!< @brief used for return y size of Matrix*/
	int getX() const {return m_x;}/*!< @brief used for return x size of Matrix*/

	int get_matrix_value(int z,int y,int x) const { return matrix[z][y][x];} /*!< used for return Matrix value*/
/**
 * @brief set up matrix
 * used cordinates @param z @param y @param x @param value to set up Matrix 
	                                                                       
 */
	void set_matrix_with_value(int z,int y,int x,int & value);
       
	void make_matrix(); /*!<@brief used for making matrix from given sizes*/
	void clean_matrix();/*!< @briefused for deleting the matrix */
        /**
         * @brief Reads matrix data from given file
         * @param filename - name of the file where data is
         */
	void read_from_file(const std::string& filename); 
	void write_to_file(const std::string& filename);/*!< @function write_to_file(const std::string& filename) function for output file */
	void display_matrix(); /*!< used for display the matrix */

	~Matrix(); /*!< Destructor used for destruction of objects of Matrix  */
	/**
	 *@brief constructor of Matrix using parametrs to make matrix 
	 *@param z
	 *@param y
	 *@param x
	*/
	Matrix(int z,int y,int x);
};
#endif
