#ifndef DIRECTION_INL
#define DIRECTION_INL

namespace engine_lib
{
    using namespace std;

    template <class T, size_t N>
    direction<T, N>::direction()
        : point<T, N>()
    {
    }

    template <class T, size_t N>
    direction<T, N>::direction(const point<T, N>& direction_point)
        : point<T, N>(direction_point),
          beginning_({0}),
          end_(direction_point.get_coordinates())
    {
    }

    template <class T, size_t N>
    direction<T, N>::direction(const point<T, N>& a, const point<T, N>& b)
        : point<T, N>(b - a),
          beginning_(a),
          end_(b)
    {
    }

    template <class T, size_t N>
    direction<T, N>::direction(const array<T, N>& direction_coordinates)
        : direction(point<T, N>(direction_coordinates))
    {
    }

    template <class T, size_t N>
    direction<T, N>::direction(const array<T, N>& a, const array<T, N>& b)
        : direction(point<T, N>(a), point<T, N>(b))
    {
    }

    template <class T, size_t N>
    direction<T, N>::direction(const direction<T, N>& other)
        : point<T, N>(other.coordinates_),
          beginning_(other.beginning_),
          end_(other.end_)
    {
    }

    template <class T, size_t N>
    array<T, N> direction<T, N>::get_beginning() const
    {
        return beginning_;
    }
    template <class T, size_t N>
    array<T, N> direction<T, N>::get_end() const
    {
        return end_;
    }


    template <class T, size_t N>
    T direction<T, N>::length() const
    {
        T sum(0);
        for (T i : this->get_coordinates())
            sum += i * i;
        return T(sqrt(sum));
    }

    template <class T, size_t N>
    T direction<T, N>::cos_axis_angle(size_t axis) const
    {
        return this->coordinate(axis) / length();
    }

    template <class T, size_t N>
    T direction<T, N>::cos_vector_angle(const direction<T, N>& other) const
    {
        T sum(0);
        for (size_t i = 0; i < N; ++i)
            sum += this->coordinate(i) * other.coordinate(i);
        return sum / (this->length() * other.length());
    }

    template <class T, size_t N>
    T direction<T, N>::projection(const direction<T, N>& other) const
    {
        if (other.zero_direction())
            throw std::invalid_argument("Cannot project on zero-direction");
        return dot_product(other) / other.length();
    }

    template <class T, size_t N>
    direction<T, N> direction<T, N>::cross_product(const direction<T, N>& other) const
    {
        static_assert(N == 3, "Cross product only defined for 3D vectors");
        return direction<T, N>({
            this->coordinate(1) * other[2] - this->coordinate(2) * other[1],
            this->coordinate(2) * other[0] - this->coordinate(0) * other[2],
            this->coordinate(0) * other[1] - this->coordinate(1) * other[0]
        });
    }


    template <class T, size_t N>
    direction<T, N> direction<T, N>::ort() const
    {
        array<T, N> ort_coordinates;
        T l(length());
        for (size_t i = 0; i < N; ++i)
            ort_coordinates[i] = this->coordinates_[i] / l;
        return direction<T, N>(ort_coordinates);
    }

    template <class T, size_t N>
    direction<T, N>& direction<T, N>::ort()
    {
        T l(length());
        for (T& i : this->coordinates_)
            i /= l;
        beginning_ = array<T, N>({0});
        end_ = this->coordinates_;
        return *this;
    }

    template <class T, size_t N>
    bool direction<T, N>::equal(const direction<T, N>& other) const
    {
        for (int i = 0; i < N; ++i)
            if (this->coordinate[i] != other[i])
                return false;
        return true;
    }


    template <class T, size_t N>
    bool direction<T, N>::orthogonal(const direction<T, N>& other) const
    {
        return dot_product(other) == 0;
    }

    template <class T, size_t N>
    bool direction<T, N>::colinear(const direction<T, N>& other) const
    {
        if (zero_direction() || other.zero_direction())
            throw std::invalid_argument("Cannot calculate colinearity with zero-direction");
        T division(this->coordinate(0) / other.coordinate(0));
        for (int i = 1; i < N; ++i)
        {
            T division2 = this->coordinate(i) / other.coordinate(i);
            if (division != division2)
                return false;
        }
        return true;
    }


    template <class T, size_t N>
    T direction<T, N>::dot_product(const direction<T, N>& other) const
    {
        T sum(0);
        for (size_t i = 0; i < N; ++i)
            sum += this->coordinate(i) * other.coordinate(i);
        return sum;
    }


    template <class T, size_t N>
    bool direction<T, N>::zero_direction() const
    {
        for (T i : this->coordinates_)
            if (i != 0)
                return false;
        return true;
    }
}
#endif
