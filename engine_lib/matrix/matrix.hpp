//
// Created by maksymvarivodin on 7/29/24.
//

#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "../includes.hpp"

namespace engine_lib
{
    using namespace std;


    template <class T, size_t N, size_t M>
    class matrix
    {
        array<array<T, M>, N> table_;

    public:
        matrix<T, N, M>();
        matrix<T, N, M>(const array<array<T, M>, N>& data);
        matrix<T, N, M>(const matrix<T, N, M>& other);

        array<T, N> main_diagonal() const;
        array<T, N> secondary_diagonal() const;
        T trace() const;

        matrix<T, N, M> operator*(T value) const;
        matrix<T, N, M>& operator*=(T value);

        matrix<T, N, M> operator/(T value) const;
        matrix<T, N, M>& operator/=(T value);

        template <size_t G, size_t H>
        matrix<T, N, M> operator*(const matrix<T, G, H>& other) const;
        template <size_t G, size_t H>
        matrix<T, N, M> operator*=(const matrix<T, G, H>& other);

        matrix<T, N, M> operator+(const matrix<T, N, M>& other) const;
        matrix<T, N, M>& operator+=(const matrix<T, N, M>& other);


        matrix<T, N, M> operator-(const matrix<T, N, M>& other) const;
        matrix<T, N, M>& operator-=(const matrix<T, N, M>& other);

        matrix<T, M, N> transposed_matrix() const;
        matrix<T, N - 1, M - 1> minor_matrix(size_t row, size_t column) const;

        T algebraic_complement(size_t row, size_t col) const;

        matrix<T, N, M> union_matrix() const;

        matrix<T, N, M> inverted_matrix() const;

        T determinant() const;

        bool is_row_valid(size_t row) const;
        bool is_column_valid(size_t column) const;

        bool is_zero_row(size_t row) const;
        bool is_zero_column(size_t column) const;
        bool is_non_zero_row(size_t row) const;
        bool is_non_zero_column(size_t column) const;

        bool is_zero_matrix() const;
        bool is_square_matrix() const;
        bool is_vector_row() const;
        bool is_vector_column() const;
        bool is_diagonal_matrix() const;
        bool is_identity_matrix() const;
        bool is_upper_triangular_matrix() const;
        bool is_lower_triangular_matrix() const;
        bool is_echelon_matrix() const;
    };
} // engine_lib

#endif //MATRIX_HPP
#include "matrix.inl"
