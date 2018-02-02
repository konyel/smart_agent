#include "maragent.h"

int AgentServer::RunImp()
{
    /* daemonize if requested */
    /* if we want to ensure our ability to dump core, don't chdir to / */
    if(_DoDaemonize){
        if(sigignore(SIGHUP) == -1){
            perror("Failed to ignore SIGHUP");
        } 
        if(daemonize(_MaxCore,_Verbose) == -1){
            fprintf(stderr, "failed to daemon() in order to daemonize\n");
            exit(EXIT_FAILURE);
        }
    }

    /* initialize main thread libevent instance */
    _MainBase = event_init();

    /*
     * ignore SIGPIPE signals; we can use errno == EPIPE if we
     * need that information
     */
    if (sigignore(SIGPIPE) == -1) {
        perror("failed to ignore SIGPIPE; sigaction");
        exit(EX_OSERR);
    }

    
    if( ret ){
        fprintf(stderr,"init threads fail %d", ret);
        exit(EX_OSERR);
    }

    /* enter the event loop */
    if (event_base_loop(_MainBase, 0) != 0) {
        ret = EXIT_FAILURE;
    }

    return ret;
}

int AgentServer::InitThreads()
{

    return ret;
}

int main (int argc, char **argv) 
{


    return 0;
}
