//
// Created by maksymvarivodin on 7/26/24.
//

#ifndef DIRECTION_HPP
#define DIRECTION_HPP
#include "../includes.hpp"
#include "../point/point.hpp"

namespace engine_lib
{
    using namespace std;

    /**
    * @class direction
    * @brief A class representing a direction in N-dimensional space, inheriting from the point class.
    *
    * @tparam T The type of the coordinates (e.g., float, double).
    * @tparam N The number of dimensions.
    */
    template <class T, size_t N>
    class direction : public point<T, N>
    {
        array<T, N> beginning_; /// The beginning point of the direction.
        array<T, N> end_; /// The end point of the direction.

    public:
        /**
         * @brief Default constructor for the direction class.
         */
        direction<T, N>();

        /**
         * @brief Constructs a direction from a single point.
         *
         * @param direction_point The point representing the direction.
         */
        explicit direction<T, N>(const point<T, N>& direction_point);

        /**
         * @brief Constructs a direction from two points.
         *
         * @param a The starting point.
         * @param b The ending point.
         */
        explicit direction<T, N>(const point<T, N>& a, const point<T, N>& b);

        /**
         * @brief Constructs a direction from an array of direction coordinates.
         *
         * @param direction_coordinates The array representing the direction coordinates.
         */
        explicit direction<T, N>(const array<T, N>& direction_coordinates);

        /**
         * @brief Constructs a direction from two arrays of coordinates.
         *
         * @param a The array representing the starting point coordinates.
         * @param b The array representing the ending point coordinates.
         */
        explicit direction<T, N>(const array<T, N>& a, const array<T, N>& b);

        /**
         * @brief Copy constructor for the direction class.
         *
         * @param other The direction to copy from.
         */
        direction<T, N>(const direction<T, N>& other);
        /**
         * @brief Retrieves the beginning point of the direction.
         *
         * @return An array representing the beginning point coordinates.
         */
        array<T, N> get_beginning() const;

        /**
         * @brief Retrieves the end point of the direction.
         *
         * @return An array representing the end point coordinates.
         */
        array<T, N> get_end() const;

        /**
         * @brief Calculates the length of the direction.
         *
         * @return The length of the direction.
         */
        T length() const;

        /**
         * @brief Calculates the cosine of the angle between the direction and a specified axis.
         *
         * @param axis The axis to calculate the angle with.
         * @return The cosine of the angle.
         */
        T cos_axis_angle(size_t axis) const;

        /**
         * @brief Calculates the cosine of the angle between this direction and another direction.
         *
         * @param other The other direction.
         * @return The cosine of the angle.
         */
        T cos_vector_angle(const direction<T, N>& other) const;

        /**
         * @brief Projects this direction onto another direction.
         *
         * @param other The other direction.
         * @return The projection of this direction onto the other direction.
         */
        T projection(const direction<T, N>& other) const;

        /**
         * @brief Calculates the dot product of this direction and another direction.
         *
         * @param other The other direction.
         * @return The dot product.
         */
        T dot_product(const direction<T, N>& other) const;

        /**
         * @brief Calculates the cross product of this direction and another direction.
         *
         * @param other The other direction.
         * @return The cross product.
         */
        direction<T, N> cross_product(const direction<T, N>& other) const;

        /**
         * @brief Calculates the mixed product of this direction and two other directions.
         *
         * @param b The second direction.
         * @param c The third direction.
         * @return The mixed product.
         */
        T mixed_product(const direction<T, N>& b, const direction<T, N>& c) const;

        /**
         * @brief Returns the orthogonal direction of this direction.
         *
         * @return The orthogonal direction.
         */
        direction<T, N> ort() const;

        /**
         * @brief Returns a reference to the orthogonal direction of this direction.
         *
         * @return A reference to the orthogonal direction.
         */
        direction<T, N>& ort();

        /**
         * @brief Checks if this direction is a zero direction.
         *
         * @return True if this is a zero direction, false otherwise.
         */
        [[nodiscard]] bool zero_direction() const;

        /**
         * @brief Checks if this direction is equal to another direction.
         *
         * @param other The other direction.
         * @return True if the directions are equal, false otherwise.
         */
        bool equal(const direction<T, N>& other) const;

        /**
         * @brief Checks if this direction is orthogonal to another direction.
         *
         * @param other The other direction.
         * @return True if the directions are orthogonal, false otherwise.
         */
        bool orthogonal(const direction<T, N>& other) const;

        /**
         * @brief Checks if this direction is colinear with another direction.
         *
         * @param other The other direction.
         * @return True if the directions are colinear, false otherwise.
         */
        bool colinear(const direction<T, N>& other) const;

        /**
         * @brief Checks if this direction is complanar with two other directions.
         *
         * @param b The second direction.
         * @param c The third direction.
         * @return True if the directions are complanar, false otherwise.
         */
        bool complanar(const direction<T, N>& b, const direction<T, N>& c) const;
    };
}
#endif //DIRECTION_HPP

#include "direction.inl"
