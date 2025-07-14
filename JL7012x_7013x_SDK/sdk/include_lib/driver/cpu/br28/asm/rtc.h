
#ifndef __RTC_H__
#define __RTC_H__

#include "typedef.h"
#include "system/sys_time.h"
#include "device/rtc_calculate.h"


struct rtc_dev_platform_data {
    const struct sys_time *default_sys_time;
    const struct sys_time *default_alarm;
    void (*cbfun)(u8);
    u8 clk_sel;
    u8 x32xs;
    u8 wkup_1hz_en;
    u8 wkup_2hz_en;
    u8 wkup_64hz_en;
    u8 wkup_256hz_en;
    void (*wkup_1hz_handle)(void);
    void (*wkup_2hz_handle)(void);
    void (*wkup_64hz_handle)(void);
    void (*wkup_256hz_handle)(void);
};

#define RTC_DEV_PLATFORM_DATA_BEGIN(data) \
	const struct rtc_dev_platform_data data = {

#define RTC_DEV_PLATFORM_DATA_END()  \
    .x32xs = 0, \
};

extern const struct device_operations rtc_dev_ops;

int rtc_init(const struct rtc_dev_platform_data *arg);
int rtc_ioctl(u32 cmd, u32 arg);
void set_alarm_ctrl(u8 set_alarm);
void write_sys_time(struct sys_time *curr_time);
void read_sys_time(struct sys_time *curr_time);
void write_alarm(struct sys_time *alarm_time);
void read_alarm(struct sys_time *alarm_time);

#endif // __RTC_API_H__
