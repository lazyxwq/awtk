/**
 * File:   time_clock.h
 * Author: AWTK Develop Team
 * Brief:  time_clock
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-08-29 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "base/mem.h"
#include "base/utils.h"
#include "base/image_manager.h"
#include "time_clock/time_clock.h"

ret_t time_clock_set_hour(widget_t* widget, int32_t hour) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  time_clock->hour = hour;

  return RET_OK;
}

ret_t time_clock_set_minute(widget_t* widget, int32_t minute) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  time_clock->minute = minute;

  return RET_OK;
}

ret_t time_clock_set_second(widget_t* widget, int32_t second) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  time_clock->second = second;

  return RET_OK;
}

ret_t time_clock_set_hour_image(widget_t* widget, const char* hour_image) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(time_clock->hour_image);
  time_clock->hour_image = tk_strdup(hour_image);

  return RET_OK;
}

ret_t time_clock_set_minute_image(widget_t* widget, const char* minute_image) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(time_clock->minute_image);
  time_clock->minute_image = tk_strdup(minute_image);

  return RET_OK;
}

ret_t time_clock_set_second_image(widget_t* widget, const char* second_image) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(time_clock->second_image);
  time_clock->second_image = tk_strdup(second_image);

  return RET_OK;
}

ret_t time_clock_set_bg_image(widget_t* widget, const char* bg_image) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(time_clock->bg_image);
  time_clock->bg_image = tk_strdup(bg_image);

  return RET_OK;
}

ret_t time_clock_set_image(widget_t* widget, const char* image) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  TKMEM_FREE(time_clock->image);
  time_clock->image = tk_strdup(image);

  return RET_OK;
}

static ret_t time_clock_get_prop(widget_t* widget, const char* name, value_t* v) {
  time_clock_t* time_clock = TIME_CLOCK(widget);
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, TIME_CLOCK_PROP_HOUR)) {
    value_set_int(v, time_clock->hour);
    return RET_OK;
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_MINUTE)) {
    value_set_int(v, time_clock->hour);
    return RET_OK;
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_SECOND)) {
    value_set_int(v, time_clock->second);
    return RET_OK;
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_HOUR_IMAGE)) {
    value_set_str(v, time_clock->hour_image);
    return RET_OK;
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_SECOND_IMAGE)) {
    value_set_str(v, time_clock->second_image);
    return RET_OK;
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_MINUTE_IMAGE)) {
    value_set_str(v, time_clock->minute_image);
    return RET_OK;
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_BG_IMAGE)) {
    value_set_str(v, time_clock->bg_image);
    return RET_OK;
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_IMAGE)) {
    value_set_str(v, time_clock->image);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t time_clock_set_prop(widget_t* widget, const char* name, const value_t* v) {
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, TIME_CLOCK_PROP_HOUR)) {
    return time_clock_set_hour(widget, value_int(v));
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_MINUTE)) {
    return time_clock_set_minute(widget, value_int(v));
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_SECOND)) {
    return time_clock_set_second(widget, value_int(v));
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_HOUR_IMAGE)) {
    return time_clock_set_hour_image(widget, value_str(v));
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_SECOND_IMAGE)) {
    return time_clock_set_second_image(widget, value_str(v));
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_MINUTE_IMAGE)) {
    return time_clock_set_minute_image(widget, value_str(v));
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_BG_IMAGE)) {
    return time_clock_set_bg_image(widget, value_str(v));
  } else if (tk_str_eq(name, TIME_CLOCK_PROP_IMAGE)) {
    return time_clock_set_image(widget, value_str(v));
  }

  return RET_NOT_FOUND;
}

static ret_t time_clock_destroy(widget_t* widget) {
  time_clock_t* time_clock = TIME_CLOCK(widget);

  TKMEM_FREE(time_clock->image);
  TKMEM_FREE(time_clock->bg_image);
  TKMEM_FREE(time_clock->hour_image);
  TKMEM_FREE(time_clock->minute_image);
  TKMEM_FREE(time_clock->minute_image);

  return RET_OK;
}

static ret_t time_clock_load_image(const char* name, bitmap_t* bitmap) {
  if(name != NULL && bitmap != NULL) {
    return image_manager_load(image_manager(), name, bitmap);
  }

  return RET_FAIL;
}

static ret_t time_clock_on_paint_self(widget_t* widget, canvas_t* c) {
  bitmap_t bitmap;
  float_t rotation = 0;
  float_t anchor_x = 0;
  float_t anchor_y = 0;
  vgcanvas_t* vg = lcd_get_vgcanvas(c->lcd);
  time_clock_t* time_clock = TIME_CLOCK(widget);
  rect_t dst = rect_init(0, 0, widget->w, widget->h);

  if(time_clock_load_image(time_clock->bg_image, &bitmap) == RET_OK) {
    canvas_draw_image_ex(c, &bitmap, IMAGE_DRAW_CENTER, &dst);
  }
  
  if(time_clock_load_image(time_clock->hour_image, &bitmap) == RET_OK) {
    float_t dx = (dst.w-bitmap.w)/2;
    float_t dy = dst.h/2+bitmap.w/2 - bitmap.h;

    rotation = (2 * M_PI * time_clock->hour)/12.0f;
    anchor_x = bitmap.w/2;
    anchor_y = bitmap.h-bitmap.w/2;
    vgcanvas_save(vg);
    vgcanvas_translate(vg, c->ox+dx, c->oy+dy);
    vgcanvas_translate(vg, anchor_x, anchor_y);
    vgcanvas_rotate(vg, rotation);
    vgcanvas_translate(vg, -anchor_x, -anchor_y);
    vgcanvas_draw_image(vg, &bitmap, 0, 0, bitmap.w, bitmap.h, 0, 0, bitmap.w, bitmap.h);

    vgcanvas_restore(vg);
  }
  
  if(time_clock_load_image(time_clock->minute_image, &bitmap) == RET_OK) {
    float_t dx = (dst.w-bitmap.w)/2;
    float_t dy = dst.h/2+bitmap.w/2 - bitmap.h;

    rotation = (2 * M_PI * time_clock->minute)/60.0f;
    anchor_x = bitmap.w/2;
    anchor_y = bitmap.h-bitmap.w/2;
    vgcanvas_save(vg);
    vgcanvas_translate(vg, c->ox+dx, c->oy+dy);
    vgcanvas_translate(vg, anchor_x, anchor_y);
    vgcanvas_rotate(vg, rotation);
    vgcanvas_translate(vg, -anchor_x, -anchor_y);
    vgcanvas_draw_image(vg, &bitmap, 0, 0, bitmap.w, bitmap.h, 0, 0, bitmap.w, bitmap.h);

    vgcanvas_restore(vg);
  }
  
  if(time_clock_load_image(time_clock->second_image, &bitmap) == RET_OK) {
    float_t dx = (dst.w-bitmap.w)/2;
    float_t dy = 2;

    rotation = (2 * M_PI * time_clock->second)/60.0f;
    anchor_x = bitmap.w/2;
    anchor_y = dst.h/2 - 2;
    vgcanvas_save(vg);
    vgcanvas_translate(vg, c->ox+dx, c->oy+dy);
    vgcanvas_translate(vg, anchor_x, anchor_y);
    vgcanvas_rotate(vg, rotation);
    vgcanvas_translate(vg, -anchor_x, -anchor_y);
    vgcanvas_draw_image(vg, &bitmap, 0, 0, bitmap.w, bitmap.h, 0, 0, bitmap.w, bitmap.h);

    vgcanvas_restore(vg);
  }

  if(time_clock_load_image(time_clock->image, &bitmap) == RET_OK) {
    canvas_draw_image_ex(c, &bitmap, IMAGE_DRAW_CENTER, &dst);
  }
  

  return RET_OK;
}

static const char* s_time_clock_properties[] = {WIDGET_PROP_REPEAT, NULL};

static const widget_vtable_t s_time_clock_vtable = {
    .size = sizeof(time_clock_t),
    .type = WIDGET_TYPE_TIME_CLOCK,
    .clone_properties = s_time_clock_properties,
    .persistent_properties = s_time_clock_properties,
    .create = time_clock_create,
    .on_paint_self = time_clock_on_paint_self,
    .set_prop = time_clock_set_prop,
    .get_prop = time_clock_get_prop,
    .destroy = time_clock_destroy
};

widget_t* time_clock_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  time_clock_t* time_clock = TKMEM_ZALLOC(time_clock_t);
  widget_t* widget = WIDGET(time_clock);
  return_value_if_fail(time_clock != NULL, NULL);

  return widget_init(widget, parent, &s_time_clock_vtable, x, y, w, h);
}

widget_t* time_clock_cast(widget_t* widget) {
  return_value_if_fail(widget != NULL && widget->vt == &s_time_clock_vtable, NULL);

  return widget;
}
