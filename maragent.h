#pragma once

namespace MarAgent
{
class AgentServer
{
    public:
        AgentServer();
        ~AgentServer();
        int Run(int argc, char **argv);

    private:
        int RunImp();
        int InitThreads(); 
        
    //setting
    private:
        bool _DoDaemonize;
        int  _MaxCore;
        int  _Verbose;

    //libevent
    private:
        event_base* _MainBase;
};
}
