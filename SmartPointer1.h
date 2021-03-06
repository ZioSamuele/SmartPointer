#ifndef SMARTPOINTER1_H
#define SMARTPOINTER1_H

/*!
 * \file SmartPointer1.h
 * \brief A smart pointer based on a reference counter.
 */

template <typename T>
class SmartPointer1
{
public:
    /*!
     * Consructor
     * \brief Initialize a new smart pointer
     * \param ptr An existing pointer to a USER ALLOCATED memory
     */
    SmartPointer1(T *ptr);

    /*!
     * Destructor
     * \brief Delete reference to the pointer and delete it if no reference left
     */
    virtual ~SmartPointer1();

    /*!
     * Copy constructor
     * \brief Initialize from an existing smart pointer
     * \param smartptr An existing smart pointer
     */
    SmartPointer1(const SmartPointer1<T>& smartptr);

    /*!
     * Structure dereference operator
     * \return The wrapped pointer itself
     */
    T* operator->();

    /*!
     * Indirection operator
     * \return A reference to the object pointed by the wrapped pointer
     */
    T& operator* ();

    /*!
     * Assignement operator
     * \param smartptr An existing SmartPointer instance
     * \return A freshly initialized SmartPointer
     */
    SmartPointer1<T>& operator=(const SmartPointer1<T>& smartptr);
private:
    /*
     * Reference counting object
     * \brief Store the wrapped pointer and its reference counter
     */
    struct Counter{
        /*
         * Constructor
         * \brief Initialize the reference counter
         * \param ptr A pointer to a USER ALLOCATED memory of type T
         * \param c The reference count
         */
        Counter(T *ptr, unsigned int c): p(ptr), count(c){}
        T *p;
        unsigned int count;
    }*counter;

    /*
     * Add "this" reference to the pointer
     * \param c The pointer reference counter
     */
    void acquire(Counter *c);

    /*
     * Decrement "this" reference to the pointer and delete it if no reference left
     */
    void release();
};

#endif // SMARTPOINTER1_H
