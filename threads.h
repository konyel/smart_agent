#pragma once

namespace MarAgent
{
    class ConnItem
    {
        public:
            ConnItem();
            static void EventHandle( const int fd, const short which, void *arg );
            void DriveMachine();
           
            
        private:
            int _Fd;
            int _InitState;
            int _EventFlags;
    };

    class ConnMgr
    {
        public:
            int PopConnQueue(ConnItem* item);
            int NewConn(ConnItem* item);

        private:
            list<ConnItem*> _ConnQueue;
            set<ConnItem*>  _ConnPool;
            pthread_mutex_t _Lock;

    };

    class ThreadUnit
    {
        public:
            int Setup();

        private:
            void ProcessEvent();

        private:
            event_base* _Base;
            event _NotifyEvent;
            int   _NotifyReceiveFd;
            int   _NotifySendFd;
            ConnMgr _ConnMgr; 
    }

    class Threads
    {
        public:
            int InitThreadsPool();

    };

}

