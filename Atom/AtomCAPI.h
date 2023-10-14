/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomCAPI.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_JS_DEFINITIONS_HEADER
#define ATOM_JS_DEFINITIONS_HEADER

#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#include "AtomSystemDefinitions.h"

#if ATOM_SYSTEM_OS_WASM
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#else
#include "AtomVal.h"
#endif

#define ATOM_HEAD_ELEMENT_REFERENCE 1
#define ATOM_BODY_ELEMENT_REFERNECE 2

#define ATOM_EVENT_FUNCTION_NAME "8&f7&j$+ea63i^["
#if ATOM_SYSTEM_OS_WASM
#define ATOM_EVENT_VARIABLE(event) ATOM_OBJECT::take_ownership((emscripten::EM_VAL)event)
#else
#define ATOM_EVENT_VARIABLE(event) ATOM_OBJECT::take_ownership(event)
#endif

#define ATOM_AS(variable) .as<variable>()
#define ATOM_AS_STRING ATOM_AS(std::string)
#define ATOM_AS_CSTRING ATOM_AS(char*)
#define ATOM_AS_CHAR ATOM_AS(char)
#define ATOM_AS_UCHAR ATOM_AS(ATOM_BYTE)
#define ATOM_AS_BYTE ATOM_AS_UCHAR
#define ATOM_AS_POINTER ATOM_AS(void*)
#define ATOM_AS_INT ATOM_AS(int)
#define ATOM_AS_FLOAT ATOM_AS(float)
#define ATOM_AS_DOUBLE ATOM_AS(double)
#define ATOM_AS_SHORT ATOM_AS(short)
#define ATOM_AS_USHORT ATOM_AS(unsigned short)
#define ATOM_AS_LONG ATOM_AS(long)
#define ATOM_AS_LONGLONG ATOM_AS(long long)
#define ATOM_AS_UINT ATOM_AS(unsigned int)
#define ATOM_AS_ULONG ATOM_AS(unsigned long)
#define ATOM_AS_ULONGLONG ATOM_AS(unsigned long long)
#define ATOM_AS_UNSIGNED ATOM_AS(unsigned)
#define ATOM_AS_ELEMENT ATOM_AS(ATOM_ELEMENT_REFERENCE)
#define ATOM_AS_BOOL ATOM_AS(bool)

#define ATOM_STRING std::string() =

#if ATOM_SYSTEM_OS_WASM
#define ATOM_JS EM_JS
#define ATOM_JS_ASYNC EM_ASYNC_JS

#ifdef ATOM_USE_MULTI_THREAD_DEFINITION
#define ATOM_LOAD_STRING(process, code) atom_loadstring_child_process(process, "" #code "")
#define ATOM_ASM(process, code) atom_eval_child_process(process, "" #code "")
#endif

#define ATOM_DIRECT_ASM EM_ASM_PTR

#ifdef ATOM_USE_MULTI_THREAD_DEFINITION
#define ATOM_SHARED_FUNCTION_TYPE(type, ...) typedef ATOM_SHARED_FUNCTION_RETURN (*type)(__VA_ARGS__)
#define ATOM_SHARED_FUNCTION(...) [](__VA_ARGS__) -> ATOM_SHARED_FUNCTION_RETURN
#endif
#endif

#if ATOM_SYSTEM_OS_WASM
typedef emscripten::val ATOM_OBJECT;
#else
typedef AtomVal ATOM_OBJECT;
#endif

ATOM_C_ENV_OPEN

typedef signed char Aint8;
typedef signed short Aint16;
typedef signed int Aint32;
typedef signed long long Aint64;
typedef unsigned char Auint8;
typedef unsigned short Auint16;
typedef unsigned int Auint32;
typedef unsigned long long Auint64;

typedef Auint8 ATOM_BYTE;

typedef Auint32 ATOM_TICK;

typedef Auint32 ATOM_ELEMENT_REFERENCE;
typedef ATOM_ELEMENT_REFERENCE* ATOM_ELEMENT_REFERENCE_LIST;
//typedef std::vector<ATOM_ELEMENT_REFERENCE> ATOM_ELEMENT_REFERENCE_LIST;

typedef void* ATOM_POINTER;
#ifdef ATOM_SYSTEM_64_BIT
typedef Auint64 ATOM_POINTER_REFERENCE;
#else
typedef Auint32 ATOM_POINTER_REFERENCE;
#endif
typedef ATOM_POINTER ATOM_FUNCTION;

#if ATOM_SYSTEM_OS_WASM
typedef ATOM_POINTER ATOM_OBJECT_HANDLE;
typedef ATOM_OBJECT_HANDLE ATOM_EVENT;
typedef void (*ATOM_EVENT_HANDLER)(ATOM_EVENT);

#ifdef ATOM_USE_MULTI_THREAD_DEFINITION
typedef void ATOM_SHARED_FUNCTION_RETURN;
#endif
#else
typedef AtomValHandle ATOM_OBJECT_HANDLE;
typedef ATOM_OBJECT_HANDLE ATOM_EVENT;
typedef void (*ATOM_EVENT_HANDLER)(ATOM_EVENT);
#endif

typedef Auint32 ATOM_ANIMATION_FRAME;
typedef double ATOM_ANIMATION_TICK;
typedef void (*ATOM_ANIMATION_FRAME_HANDLER)(ATOM_ANIMATION_TICK, ATOM_POINTER);

typedef Auint32 ATOM_TIMER_REFERENCE;
typedef void (*ATOM_TIMER_HANDLE)(ATOM_POINTER);

typedef float ATOM_POINT;

struct ATOM_BOUNDING_BOX {
	double x;
	double y;
	double width;
	double height;
	double left;
	double top;
	double right;
	double bottom;
};

struct ATOM_RT_ATTRIBUTES {
	bool alpha;
	bool desynchronized;
	bool willReadFrequently;

	char* colorSpace;
};

struct ATOM_RT_PIXEL {
	ATOM_BYTE r;
	ATOM_BYTE g;
	ATOM_BYTE b;
	ATOM_BYTE a;
};

struct ATOM_TEXT_METRICS {
	double actualBoundingBoxAscent;
	double actualBoundingBoxDescent;
	double actualBoundingBoxLeft;
	double actualBoundingBoxRight;
	double fontBoundingBoxAscent;
	double fontBoundingBoxDescent;
	double width;
};

struct ATOM_MATRIX_4 {
	ATOM_POINT m00;
	ATOM_POINT m01;
	ATOM_POINT m02;
	ATOM_POINT m03;
	ATOM_POINT m10;
	ATOM_POINT m11;
	ATOM_POINT m12;
	ATOM_POINT m13;
	ATOM_POINT m20;
	ATOM_POINT m21;
	ATOM_POINT m22;
	ATOM_POINT m23;
	ATOM_POINT m30;
	ATOM_POINT m31;
	ATOM_POINT m32;
	ATOM_POINT m33;
};

ATOM_LIB_SHARE void atom_sleep(Auint32 ms);

ATOM_LIB_SHARE ATOM_TICK atom_get_now();

ATOM_LIB_SHARE void atom_clear_console();

ATOM_LIB_SHARE void atom_application_init();
#if !ATOM_SYSTEM_OS_WASM
ATOM_LIB_SHARE void atom_application_uninit();
#endif

#if ATOM_SYSTEM_OS_WASM
ATOM_LIB_SHARE char* atom_get_main_script_path();
ATOM_LIB_SHARE char* atom_get_worker_script_path();

ATOM_LIB_SHARE bool atom_is_inside_worker();

ATOM_LIB_SHARE Auint32 _atom_get_temp_value();
#endif

ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_get_document_head();
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_get_document_body();

ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_create_element(const char* type, const char* Namespace = NULL);
ATOM_LIB_SHARE bool                   atom_element_exists(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE void                   atom_destroy_element(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE void                   atom_free_element(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE bool                   atom_is_same_element(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target);
ATOM_LIB_SHARE void                   atom_set_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute, const char* value);
ATOM_LIB_SHARE char*                  atom_get_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute);
ATOM_LIB_SHARE bool                   atom_has_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute);
ATOM_LIB_SHARE void                   atom_remove_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute);
ATOM_LIB_SHARE void                   atom_toggle_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute);
ATOM_LIB_SHARE void                   atom_set_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value);
ATOM_LIB_SHARE char*                  atom_get_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName);
ATOM_LIB_SHARE void                   atom_element_append_child(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target);
ATOM_LIB_SHARE void                   atom_set_element_style(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value);
ATOM_LIB_SHARE char*                  atom_get_element_style(ATOM_ELEMENT_REFERENCE element, const char* propertyName);
ATOM_LIB_SHARE void                   atom_add_element_class(ATOM_ELEMENT_REFERENCE element, const char* className);
ATOM_LIB_SHARE bool                   atom_element_class_exists(ATOM_ELEMENT_REFERENCE element, const char* className);
ATOM_LIB_SHARE void                   atom_remove_element_class(ATOM_ELEMENT_REFERENCE element, const char* className);
ATOM_LIB_SHARE char*                  atom_get_element_node_name(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_get_element_parent(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE Auint32                atom_get_element_child_count(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE void                   atom_scroll_to_element(ATOM_ELEMENT_REFERENCE element, const char* viewType = NULL);

#if ATOM_SYSTEM_OS_WASM
ATOM_LIB_SHARE bool          atom_is_function_registered(const char* name);
ATOM_LIB_SHARE void          atom_unregister_function(const char* name);
ATOM_LIB_SHARE ATOM_FUNCTION atom_get_function(const char* name);

ATOM_LIB_SHARE bool  atom_is_multi_thread_enabled();
ATOM_LIB_SHARE char* atom_get_process_name();
ATOM_LIB_SHARE bool  atom_is_main_process();

ATOM_LIB_SHARE void atom_fork(const char* name);
ATOM_LIB_SHARE void atom_post_child_process(const char* name, ATOM_OBJECT_HANDLE data);
ATOM_LIB_SHARE bool atom_child_process_exists(const char* name);
ATOM_LIB_SHARE bool atom_child_process_is_ready(const char* name);

#ifdef ATOM_WASM_USE_MULTI_THREAD_DEFINITION
ATOM_LIB_SHARE void atom_wait_till_process_be_ready(const char* name);
#endif

ATOM_LIB_SHARE void atom_terminate_child_process(const char* name);

#ifdef ATOM_USE_MULTI_THREAD_DEFINITION
ATOM_LIB_SHARE ATOM_FUNCTION           atom_loadstring_child_process(const char* name, const char* code);
ATOM_LIB_SHARE ATOM_OBJECT_HANDLE atom_eval_child_process(const char* name, const char* code);

ATOM_LIB_SHARE void atom_yield();
#endif

ATOM_LIB_SHARE void atom_resume(const char* name);

ATOM_LIB_SHARE bool atom_function_pointer_exists(ATOM_FUNCTION func);
ATOM_LIB_SHARE void atom_delete_function_pointer(ATOM_FUNCTION func);

#ifdef ATOM_WASM_USE_MULTI_THREAD_DEFINITION

ATOM_LIB_SHARE void          atom_register_shared_function(const char* name, ATOM_FUNCTION func, bool clearMemory);
ATOM_LIB_SHARE bool          atom_shared_function_exists(const char* name);
ATOM_LIB_SHARE void          atom_remove_shared_function(const char* name);
ATOM_LIB_SHARE char*         atom_get_shared_function_process(const char* name);
ATOM_LIB_SHARE ATOM_FUNCTION atom_get_shared_function(const char* name);

ATOM_LIB_SHARE void                   atom_allocate_shared_memory(const char* name, size_t size);
ATOM_LIB_SHARE bool                   atom_shared_memory_exists(const char* name);
ATOM_LIB_SHARE ATOM_POINTER_REFERENCE atom_get_shared_memory_pointer(const char* name);
ATOM_LIB_SHARE size_t                 atom_get_shared_memory_size(const char* name);
ATOM_LIB_SHARE void                   atom_free_shared_memory(const char* name);
ATOM_LIB_SHARE ATOM_POINTER           atom_get_shared_memory(const char* name);
ATOM_LIB_SHARE void                   atom_update_shared_memory(const char* name, const char* process);
ATOM_LIB_SHARE void                   atom_update_main_shared_memory(const char* name);

#endif

ATOM_LIB_SHARE ATOM_POINTER           atom_get_pointer_from_reference(ATOM_POINTER_REFERENCE reference);
ATOM_LIB_SHARE ATOM_POINTER_REFERENCE atom_get_pointer_reference(ATOM_POINTER pointer);
#endif

ATOM_LIB_SHARE ATOM_ANIMATION_FRAME         atom_request_animation_frame(ATOM_ANIMATION_FRAME_HANDLER handler, ATOM_POINTER value);
ATOM_LIB_SHARE bool                         atom_exists_animation_frame(ATOM_ANIMATION_FRAME id);
ATOM_LIB_SHARE void                         atom_cancel_animation_frame(ATOM_ANIMATION_FRAME id);
ATOM_LIB_SHARE ATOM_ANIMATION_FRAME_HANDLER atom_get_animation_frame_handler(ATOM_ANIMATION_FRAME id);

ATOM_LIB_SHARE double atom_mod_number(double a, double b);

ATOM_LIB_SHARE ATOM_TIMER_REFERENCE atom_set_timeout(ATOM_TIMER_HANDLE func, Auint32 ms, ATOM_POINTER arg);
ATOM_LIB_SHARE void                 atom_clear_timeout(ATOM_TIMER_REFERENCE timer);
ATOM_LIB_SHARE ATOM_TIMER_REFERENCE atom_set_interval(ATOM_TIMER_HANDLE func, Auint32 ms, ATOM_POINTER arg);
ATOM_LIB_SHARE void                 atom_clear_interval(ATOM_TIMER_REFERENCE timer);

ATOM_LIB_SHARE float atom_get_pixel_ratio();

ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_create_render_target(Auint32 width, Auint32 height, float ratio = NULL, bool alpha = NULL, const char* colorSpace = NULL, bool desynchronized = NULL, bool willReadFrequently = NULL);
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_create_path2D();
ATOM_LIB_SHARE bool                   atom_is_element_render_target(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_get_render_target_canvas(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE float                  atom_get_render_target_ratio(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE void                   atom_resize_render_target(ATOM_ELEMENT_REFERENCE element, Auint32 width, Auint32 height, float ratio = NULL);
ATOM_LIB_SHARE Auint32                atom_get_render_target_width(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE Auint32                atom_get_render_target_height(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE Auint32                atom_get_render_target_real_width(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE Auint32                atom_get_render_target_real_height(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE ATOM_RT_PIXEL*         atom_get_render_target_pixels(ATOM_ELEMENT_REFERENCE element, Auint32 x, Auint32 y, Auint32 width, Auint32 height, Auint32* size = NULL);
ATOM_LIB_SHARE void                   atom_set_render_target_pixels(ATOM_ELEMENT_REFERENCE element, ATOM_RT_PIXEL* pixels, Auint32 x, Auint32 y, Auint32 width, Auint32 height, Aint32 dirtyX = -1, Aint32 dirtyY = -1, Aint32 dirtyWidth = -1, Aint32 dirtyHeight = -1);
ATOM_LIB_SHARE void                   atom_set_render_target(ATOM_ELEMENT_REFERENCE element = NULL);
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_get_selected_render_target();
ATOM_LIB_SHARE void                   atom_set_render_target_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value);
ATOM_LIB_SHARE char*                  atom_get_render_target_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName);

ATOM_LIB_SHARE void  atom_rt_set_direction(const char* direction);
ATOM_LIB_SHARE char* atom_rt_get_direction();
ATOM_LIB_SHARE void  atom_rt_set_fill_style(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_fill_style();
ATOM_LIB_SHARE void  atom_rt_set_filter(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_filter();
ATOM_LIB_SHARE void  atom_rt_set_font(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_font();
ATOM_LIB_SHARE void  atom_rt_set_font_kerning(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_font_kerning();
ATOM_LIB_SHARE void  atom_rt_set_global_alpha(float alpha);
ATOM_LIB_SHARE float atom_rt_get_global_alpha();
ATOM_LIB_SHARE void  atom_rt_set_global_composite_operation(const char* op);
ATOM_LIB_SHARE char* atom_rt_get_global_composite_operation();
ATOM_LIB_SHARE void  atom_rt_set_image_smoothing_enabled(bool state);
ATOM_LIB_SHARE bool  atom_rt_is_image_smoothing_enabled();
ATOM_LIB_SHARE void  atom_rt_set_image_smoothing_quality(const char* quality);
ATOM_LIB_SHARE char* atom_rt_get_image_smoothing_quality();
ATOM_LIB_SHARE void  atom_rt_set_letter_spacing(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_letter_spacing();
ATOM_LIB_SHARE void  atom_rt_set_line_cap(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_line_cap();
ATOM_LIB_SHARE void  atom_rt_set_line_dash_offset(float offset);
ATOM_LIB_SHARE float atom_rt_get_line_dash_offset();
ATOM_LIB_SHARE void  atom_rt_set_line_join(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_line_join();
ATOM_LIB_SHARE void  atom_rt_set_line_width(float width);
ATOM_LIB_SHARE float atom_rt_get_line_width();
ATOM_LIB_SHARE void  atom_rt_set_miter_limit(float limit);
ATOM_LIB_SHARE float atom_rt_get_miter_limit();
ATOM_LIB_SHARE void  atom_rt_set_shadow_blur(float level);
ATOM_LIB_SHARE float atom_rt_get_shadow_blur();
ATOM_LIB_SHARE void  atom_rt_set_shadow_color(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_shadow_color();
ATOM_LIB_SHARE void  atom_rt_set_shadow_offset(float x, float y);
ATOM_LIB_SHARE float atom_rt_get_shadow_offset_x();
ATOM_LIB_SHARE float atom_rt_get_shadow_offset_y();
ATOM_LIB_SHARE void  atom_rt_set_stroke_style(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_stroke_style();
ATOM_LIB_SHARE void  atom_rt_set_text_align(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_text_align();
ATOM_LIB_SHARE void  atom_rt_set_text_baseline(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_text_baseline();
ATOM_LIB_SHARE void  atom_rt_set_text_rendering(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_text_rendering();
ATOM_LIB_SHARE void  atom_rt_set_word_spacing(const char* style);
ATOM_LIB_SHARE char* atom_rt_get_word_spacing();

ATOM_LIB_SHARE void atom_rt_arc(float x, float y, float radius, float startAngle, float endAngle, bool clockwise = false);
ATOM_LIB_SHARE void atom_rt_arc_to(float x1, float y1, float x2, float y2, float radius);
ATOM_LIB_SHARE void atom_rt_begin_path();
ATOM_LIB_SHARE void atom_rt_bezier_curve_to(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y);
ATOM_LIB_SHARE void atom_rt_clear_rect(float x, float y, float width, float height);
ATOM_LIB_SHARE void atom_rt_clip(ATOM_ELEMENT_REFERENCE path = NULL, const char* fillRule = NULL);
ATOM_LIB_SHARE void atom_rt_close_path();
ATOM_LIB_SHARE void atom_rt_draw_focus_if_needed(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE path = NULL);
ATOM_LIB_SHARE void atom_rt_draw_image(float x, float y, float width, float height, ATOM_ELEMENT_REFERENCE image);
ATOM_LIB_SHARE void atom_rt_draw_image_section(float x, float y, float width, float height, float dx, float dy, float dWidth, float dHeight, ATOM_ELEMENT_REFERENCE image);
ATOM_LIB_SHARE void atom_rt_ellipse(float x, float y, float radiusX, float radiusY, float rotation, float startAngle, float endAngle, bool clockwise = false);
ATOM_LIB_SHARE void atom_rt_fill(ATOM_ELEMENT_REFERENCE path = NULL, const char* fillRule = NULL);
ATOM_LIB_SHARE void atom_rt_fill_rect(float x, float y, float width, float height);
ATOM_LIB_SHARE void atom_rt_fill_text(const char* text, float x, float y, float maxWidth = -1.0f);
ATOM_LIB_SHARE int* atom_rt_get_line_dash(Auint32* length);
ATOM_LIB_SHARE bool atom_rt_is_context_lost();
ATOM_LIB_SHARE bool atom_rt_is_point_in_path(float x, float y, ATOM_ELEMENT_REFERENCE path = NULL, const char* fillRule = NULL);
ATOM_LIB_SHARE bool atom_rt_is_point_in_stroke(float x, float y, ATOM_ELEMENT_REFERENCE path = NULL);
ATOM_LIB_SHARE void atom_rt_line_to(float x, float y);
ATOM_LIB_SHARE void atom_rt_move_to(float x, float y);
ATOM_LIB_SHARE void atom_rt_quadratic_curve_to(float cpx, float cpy, float x, float y);
ATOM_LIB_SHARE void atom_rt_rect(float x, float y, float width, float height);
ATOM_LIB_SHARE void atom_rt_reset();
ATOM_LIB_SHARE void atom_rt_reset_transform();
ATOM_LIB_SHARE void atom_rt_restore();
ATOM_LIB_SHARE void atom_rt_rotate(float angle);
ATOM_LIB_SHARE void atom_rt_round_rect(float x, float y, float width, float height, float* radii, Auint32 size);
ATOM_LIB_SHARE void atom_rt_save();
ATOM_LIB_SHARE void atom_rt_scale(float x, float y);
ATOM_LIB_SHARE void atom_rt_scroll_path_into_view(ATOM_ELEMENT_REFERENCE path = NULL);
ATOM_LIB_SHARE void atom_rt_set_line_dash(Aint32* dash, Auint32 size);
ATOM_LIB_SHARE void atom_rt_stroke(ATOM_ELEMENT_REFERENCE path = NULL);
ATOM_LIB_SHARE void atom_rt_stroke_rect(float x, float y, float width, float height);
ATOM_LIB_SHARE void atom_rt_stroke_text(const char* text, float x, float y, float maxWidth = -1.0f);
ATOM_LIB_SHARE void atom_rt_translate(float x, float y);

#if ATOM_SYSTEM_OS_WASM
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_document_query_selector(const char* query);
#endif
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE atom_query_selector(ATOM_ELEMENT_REFERENCE element, const char* query);

#if ATOM_SYSTEM_OS_WASM
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE_LIST atom_document_query_selector_all(const char* query, Auint32* size);
#endif
ATOM_LIB_SHARE ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all(ATOM_ELEMENT_REFERENCE element, const char* query, Auint32* size);

ATOM_LIB_SHARE void atom_free_element_list(ATOM_ELEMENT_REFERENCE_LIST list, Auint32 size);

#if ATOM_SYSTEM_OS_WASM
ATOM_LIB_SHARE void atom_register_function(const char* name, ATOM_FUNCTION handler);
#endif

ATOM_LIB_SHARE char* atom_generage_random_key(const Aint32& count);

ATOM_LIB_SHARE ATOM_BOUNDING_BOX atom_get_element_bounding_box(ATOM_ELEMENT_REFERENCE element);

#if ATOM_SYSTEM_OS_WASM
ATOM_LIB_SHARE void atom_document_add_event_listener(const char* eventName, ATOM_EVENT_HANDLER handler);
#endif
ATOM_LIB_SHARE void atom_add_event_listener(ATOM_ELEMENT_REFERENCE element, const char* eventName, ATOM_EVENT_HANDLER handler);

ATOM_LIB_SHARE ATOM_RT_ATTRIBUTES* atom_get_render_target_attributes(ATOM_ELEMENT_REFERENCE element);
ATOM_LIB_SHARE void                atom_free_rt_attributes(ATOM_RT_ATTRIBUTES* attributes);

ATOM_LIB_SHARE ATOM_TEXT_METRICS atom_rt_measure_text(const char* text);
ATOM_LIB_SHARE ATOM_MATRIX_4*    atom_rt_get_transform();
ATOM_LIB_SHARE void              atom_rt_set_transform(ATOM_MATRIX_4* matrix);

ATOM_LIB_SHARE void atom_exit(int status, bool pthread = false);

ATOM_C_ENV_CLOSE

#endif