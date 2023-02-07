#pragma once

#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

#include "job_system.h"

#ifndef THREAD_POOL_SZ
#define THREAD_POOL_SZ 16
#endif

namespace Dexterity::Threading
{
    class ThreadPool
    {
    public:
        ThreadPool();
        ~ThreadPool();

        JobSystem *jobs() { return &m_jobSystem; }

    private:
        JobSystem m_jobSystem;
        void threadFn();
        std::thread threads[THREAD_POOL_SZ];

        std::mutex m_mutex;
        std::condition_variable m_cvar;
    };
} // namespace Dexterity::Threading
