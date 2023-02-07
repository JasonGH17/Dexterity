#include "job_system.h"

namespace Dexterity::Threading
{
    JobSystem::JobSystem(std::condition_variable *cvar, std::mutex *mutex) : m_cvar(cvar), m_mutex(mutex) {}
    JobSystem::~JobSystem() {}

    void JobSystem::queue(std::function<void()> job)
    {
        std::unique_lock<std::mutex> lock(*m_mutex);
        m_queue.push(job);
        m_cvar->notify_one();
    }

    std::function<void()> JobSystem::fetch()
    {
        std::unique_lock<std::mutex> lock(*m_mutex);
        std::function<void()> ret;
        if (m_queue.empty())
            m_cvar->wait(lock);

        ret = m_queue.front();
        m_queue.pop();
        return ret;
    }
} // namespace Dexterity::Threading
