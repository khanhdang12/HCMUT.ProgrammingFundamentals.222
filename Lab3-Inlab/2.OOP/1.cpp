template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void print();
    
private:
    int size;
    T * p;
};

template <typename T>
Array<T>::Array(int size, T initValue) : size(size), p(new T[size])
{
    for (int i = 0; i < size; i++) {
        p[i] = initValue;
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] p;
}

// template <typename T>
// void Array<T>::print()
// {
//     for (int i = 0; i < size; i++) {
//         std::cout << p[i] << " ";
//     }
//     std::cout << std::endl;
// }
