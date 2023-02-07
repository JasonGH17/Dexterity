#pragma once

#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

namespace Dexterity::Threading
{
    class JobSystem
    {
    public:
        JobSystem(std::condition_variable *cvar, std::mutex *mutex);
        ~JobSystem();

        void queue(std::function<void()> job);
        std::function<void()> fetch();

    private:
        std::queue<std::function<void()>> m_queue;
        std::condition_variable *m_cvar;
        std::mutex *m_mutex;
    };
} // namespace Dexterity::Threading
