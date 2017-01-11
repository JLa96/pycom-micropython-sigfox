#include <stdbool.h>
#include <timer.h>

#include "py/mpconfig.h"
#include "py/nlr.h"
#include "py/runtime.h"

#include "mods/machtimer_alarm.h"
#include "mods/machtimer_chrono.h"

#define CLK_FREQ (APB_CLK_FREQ / 2)

static uint64_t us_timer_calibration;

STATIC IRAM_ATTR mp_obj_t delay_us(mp_obj_t delay);

void calibrate_us_timer(void) {
    uint64_t t1, t2;
    uint primsk;
    mp_obj_t tz = mp_obj_new_int(0);

    us_timer_calibration = 0;
    delay_us(tz);
    primsk = MICROPY_BEGIN_ATOMIC_SECTION();
    timer_get_counter_value(TIMER_GROUP_0, TIMER_0, &t1);
    delay_us(tz);
    timer_get_counter_value(TIMER_GROUP_0, TIMER_0, &t2);
    MICROPY_END_ATOMIC_SECTION(primsk);
    us_timer_calibration = t2 - t1;
}

void modtimer_init0(void) {
    timer_config_t config = {.alarm_en = false, .counter_en = false, .counter_dir = TIMER_COUNT_UP, .intr_type = TIMER_INTR_LEVEL, .auto_reload = false, .divider = 2};

    init_alarm_heap();

    timer_init(TIMER_GROUP_0, TIMER_0, &config);

    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_start(TIMER_GROUP_0, TIMER_0);
    calibrate_us_timer();
}

STATIC IRAM_ATTR mp_obj_t delay_us(mp_obj_t delay) {
    uint64_t d = mp_obj_get_int(delay);
    uint64_t t;

    d *= CLK_FREQ / 1000000;

    d -= us_timer_calibration;
    timer_get_counter_value(TIMER_GROUP_0, TIMER_0, &t);
    d += t;

    do {
        timer_get_counter_value(TIMER_GROUP_0, TIMER_0, &t);
    } while(t < d);

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(delay_us_obj, delay_us);

STATIC const mp_map_elem_t mach_timer_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__),            MP_OBJ_NEW_QSTR(MP_QSTR_timer)},
    { MP_OBJ_NEW_QSTR(MP_QSTR_Alarm),               (mp_obj_t)&mach_timer_alarm_type },
    { MP_OBJ_NEW_QSTR(MP_QSTR_Chrono),              (mp_obj_t)&mach_timer_chrono_type },
    // { MP_OBJ_NEW_QSTR(MP_QSTR_delay_us),            (mp_obj_t)&delay_us_obj },
};

STATIC MP_DEFINE_CONST_DICT(mach_timer_globals, mach_timer_globals_table);

const mp_obj_type_t mach_timer_type = {
   { &mp_type_type },
   .name = MP_QSTR_Timer,
   .locals_dict = (mp_obj_t)&mach_timer_globals,
};