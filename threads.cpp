
static void thread_libevent_process(int fd, short which, void *arg)
{
    ((ThreadUint*)arg)->ProcessEvent();
}

int ThreadUnit::Setup()
{
    _Base = event_init();
    if( !_Base ){
        fprintf(stderr, "Can't allocate event base\n");
        exit(1);
    }
    /* Listen for notifications from other threads */
    event_set(&_NotifyEvent, _NotifyReceiveFd
              EV_READ | EV_PERSIST, thread_libevent_process, this);
    event_base_set(me->base, &me->notify_event);

    if (event_add(&me->notify_event, 0) == -1) {
        fprintf(stderr, "Can't monitor libevent notify pipe\n");
        exit(1);
    }
}

void ThreadUnit::ProcessEvent()
{
    ConnQueueItem* item = NULL;

    char buf[1];
    if (read(_NotifyReceiveFd, buf, 1) != 1) {
        if (settings.verbose > 0)  //todo setting
            fprintf(stderr, "Can't read from libevent pipe\n");
        return;
    }

    switch(buf[0]) {
        case 'c':
            ret = _NewConnQueue->Pop(item);
            if( NULL == item )
                break;
            switch (item->mode) {
                case queue_new_conn:

    }
}

void ConnItem::EventHandle(const int fd, const short which, void *arg)
{
    //todo if (fd != c->sfd)
    ((ConnItem*) arg)->DriveMachine();
}

void ConnItem::DriveMachine()
{


}

int ConnMgr::NewConn(ConnItem* item)
{
    event_set(&c->event, sfd, event_flags, ConnItem::EventHandle, (void *)item);
    event_base_set(base, &c->event);
    c->ev_flags = event_flags;

    if (event_add(&c->event, 0) == -1) {
        perror("event_add");
        return NULL;
    }
    return 0;
}
