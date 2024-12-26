#include"ts.h"
#include<pthread.h>

int ts_fd;
// 按钮
int btn_l = FALSE;
int btn_r = FALSE;
// 触摸屏输入的值
int TOUCH_EVENT = MOVE_EMPTY;

void *thread_touch_click()
{
    while (1)
    {
        get_user_input_click(ts_fd);
    }
    
}

int main()
{
    ts_fd = touch_init();

    pthread_t ts;
    int res = pthread_create(&ts,NULL,thread_touch_click,NULL);
    if (res != 0)
    {
        perror("Failed to create pthread");
        exit(res);
    }

    while (1)
    {
        /* code */
    }
    

    return 0;
}