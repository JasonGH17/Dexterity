#include "thread_pool.h"

namespace Dexterity::Threading
{
    ThreadPool::ThreadPool() : m_jobSystem(JobSystem(&m_cvar, &m_mutex))
    {
        for (int i = 0; i < THREAD_POOL_SZ; i++)
        {
            threads[i] = std::thread(std::bind(&ThreadPool::threadFn, this));
        }

        printf("[THREAD] Created %d Threads\n", THREAD_POOL_SZ);
    }

    ThreadPool::~ThreadPool() {}

    void ThreadPool::threadFn()
    {
        while (1)
        {
            (m_jobSystem.fetch())();
        }
    }
} // namespace Dexterity::Threading
