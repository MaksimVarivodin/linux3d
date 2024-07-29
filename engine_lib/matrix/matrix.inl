//
// Created by maksymvarivodin on 7/29/24.
//
#ifndef MATRIX_INL
#define MATRIX_INL


namespace engine_lib
{
    using namespace std;

    template <class T, size_t N, size_t M>
    matrix<T, N, M>::matrix()
        : table_({})
    {
    }

    template <class T, size_t N, size_t M>
    matrix<T, N, M>::matrix(const array<array<T, M>, N>& data)
        : table_(data)
    {
    }

    template <class T, size_t N, size_t M>
    matrix<T, N, M>::matrix(const matrix<T, N, M>& other)
        : table_(other.table_)
    {
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_row_valid(size_t row) const
    {
        return row < N;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_column_valid(size_t column) const
    {
        return column < M;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_zero_row(size_t row) const
    {
        T zero(0);
        for (auto& value : table_[row])
            if (value != zero)
                return false;
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_zero_column(size_t column) const
    {
        T zero(0);
        for (auto& row : table_)
            if (row[column] != zero)
                return false;
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_non_zero_row(size_t row) const
    {
        T zero(0);
        for (auto& value : table_[row])
            if (value == zero)
                return false;
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_non_zero_column(size_t column) const
    {
        T zero(0);
        for (auto& row : table_)
            if (row[column] == zero)
                return false;
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_zero_matrix() const
    {
        T zero(0);
        for (auto& row : table_)
            for (auto& value : row)
                if (value != zero)
                    return false;
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_square_matrix() const
    {
        return N == M;
    }


    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_vector_row() const
    {
        return N == 1;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_vector_column() const
    {
        return M == 1;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_diagonal_matrix() const
    {
        if (!is_square_matrix())
            return false;
        T zero(0);
        auto diagonal_elements(main_diagonal());
        for (auto& value : diagonal_elements)
            if (value == zero)
                return false;
        for (int i(0); i < N; ++i)
        {
            // upper triangular part
            for (int j(i + 1); j < N; ++j)
                if (table_[i][j] != zero)
                    return false;
            // diagonal part
            if (table_[i][i] == zero)
                return false;
            // lower triangular part
            for (int j(0); j < i; ++j)
                if (table_[i][j] != zero)
                    return false;
        }
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_identity_matrix() const
    {
        if (!is_square_matrix())
            return false;
        T zero(0);
        T one(1);
        auto diagonal_elements(main_diagonal());
        for (auto& value : diagonal_elements)
            if (value == zero)
                return false;
        for (int i(0); i < N; ++i)
        {
            // upper triangular part
            for (int j(i + 1); j < N; ++j)
                if (table_[i][j] != zero)
                    return false;
            // diagonal part
            if (table_[i][i] != one)
                return false;
            // lower triangular part
            for (int j(0); j < i; ++j)
                if (table_[i][j] != zero)
                    return false;
        }
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_upper_triangular_matrix() const
    {
        T zero(0);
        for (int i(0); i < N; ++i)
        {
            // upper triangular part
            for (int j(i + 1); j < M; ++j)
                if (table_[i][j] != zero)
                    return false;
        }
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_lower_triangular_matrix() const
    {
        T zero(0);
        for (int i(0); i < N; ++i)
        {
            // lower triangular part
            for (int j(0); j < i; ++j)
                if (table_[i][j] != zero)
                    return false;
        }
        return true;
    }

    template <class T, size_t N, size_t M>
    bool matrix<T, N, M>::is_echelon_matrix() const
    {
        // проверить что найден ненулевой елемент
        // проверить что он больше предыдущего ненулевого элемента
        // если ненулевой елмент не найден смотрим чтобы не было ненулевых строк
        T zero(0);
        bool zero_row_found(false);
        int non_zero_position(0);
        int i(0);
        for (; i < N; ++i)
        {
            int j(0);
            for (; j < M; ++j)
            {

                if (table_[i][j] != zero )
                {
                    non_zero_position = j;
                    break;
                }
            }
            if(j == M)
                break;
        }
    }
} // engine_lib
#endif
