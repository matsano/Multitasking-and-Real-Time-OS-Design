#include "Mutex.h"

Mutex::Mutex(bool isInversionSafe)
{
    // Initialize a recursive mutex attribute
    pthread_mutexattr_t mutexAttribute;
    pthread_mutexattr_init(&mutexAttribute);
    pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);

    // Inverser la priorité
    if (isInversionSafe)
    {
        std::cout << "INVERSE!!!" << std::endl;
    }
    
    // Initialize the condition and its associated mutex
    pthread_mutex_init(&posixId, &mutexAttribute);
    pthread_cond_init(&posixCondId, NULL);

    // Destroy attribute once mutex has been initialized
    pthread_mutexattr_destroy(&mutexAttribute);
}

Mutex::~Mutex()
{
    // Destruction of condition and associated mutex
    pthread_mutex_destroy(&posixId);
    pthread_cond_destroy(&posixCondId);
}

void Mutex::lock()
{
    pthread_mutex_lock(&posixId);
}

bool Mutex::lock(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    if (pthread_mutex_timedlock(&posixId, &timeout_ts) == 0)
    {
        return true;
    }

    return false;
}

bool Mutex::trylock()
{
    if (pthread_mutex_trylock(&posixId) == 0)
    {
        return true;
    }

    return false;
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&posixId);
}
