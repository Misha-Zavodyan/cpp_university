#include <iostream>
#include <cstring>
class CVector
{
    int *val;
    size_t len;

public:
    CVector()
    {
        val = nullptr;
        len = 0;
    }
    CVector(size_t len)
    {
        SetZero();
        if (len)
        {
            this->len = len;
            val = new int[len];
            memset(val, 0, len * sizeof(*val));
        }
    }
    ~CVector()
    {
        Clean();
    }
    CVector(const CVector &other)
    {
        CopyOnly(other);
    }
    CVector(CVector &&other)
    {
        MoveOnly(other);
    }
    CVector &operator=(const CVector &other)
    {
        if (&other != this)
        {
            Clean();
            CopyOnly(other);
        }
        return *this;
    }
    CVector &operator=(CVector &&other)
    {
        Clean();
        MoveOnly(other);
        return *this;
    }
    void Clean()
    {
        delete[] val;
        SetZero();
    }
    void MoveOnly(CVector &other)
    {
        val = other.val;
        len = other.len;
        other.SetZero();
    }
    void CopyOnly(const CVector &other)
    {
        val = new int[len = other.len];
        memcpy(val, other.val, sizeof(*val) * len);
    }
    void SetZero()
    {
        val = nullptr;
        len = 0;
    }
    int &operator[](size_t ind)
    {
        if (ind >= len)
            throw -1;
        return val[ind];
    }
    const int &operator[](size_t ind)
        const
    {
        if (ind >= len)
            throw -1;
        return val[ind];
    }
    size_t length() const { return len; }
    CVector operator+(const CVector &other)
        const
    {
        std::cout << " 1 \n";
        if (len != other.len)
            throw -2;
        CVector res(len);
        for (size_t i = 0; i < len; i++)
            res[i] = val[i] + other.val[i];
        return res;
    }
    // friend CVector &&operator+(const CVector &a, CVector &&b)
    // {
    //     std::cout << " 2 \n";
    //     if (a.len != b.len)
    //         throw -2;
    //     for (size_t i = 0; i < a.len; i++)
    //         b[i] += a[i];
    //     return static_cast<CVector &&>(b);
    // }
    // friend CVector &&operator+(CVector &&a, const CVector &b)
    // {
    //     std::cout << " 3 \n";
    //     if (a.len != b.len)
    //         throw -2;
    //     for (size_t i = 0; i < a.len; i++)
    //         a[i] += b[i];
    //     return static_cast<CVector &&>(a);
    // }
    friend CVector &&operator+(CVector &&a, CVector &&b)
    {
        std::cout << " 4 \n";
        if (a.len != b.len)
            throw -2;
        for (size_t i = 0; i < a.len; i++)
            a[i] += b[i];
        return static_cast<CVector &&>(a);
    }
    friend std::ostream &operator<<(std::ostream &out, const CVector &a)
    {
        for (size_t i = 0; i < a.len; i++)
        {
            out << a[i] << " ";
        }
        return out;
    }
};