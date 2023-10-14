/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomCAPI.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomCAPI.h"

#if !ATOM_SYSTEM_OS_WASM
#include <cmath>
#include <iostream>

#if defined(ATOM_SYSTEM_OS_WINDOWS)
#include <Windows.h>
#endif

#include "AtomDOM/AtomDOM.h"

ATOM_C_ENV_OPEN

void atom_sleep(Auint32 ms) {
#if defined(ATOM_SYSTEM_OS_WINDOWS)
	Sleep(ms);
#endif
}

ATOM_TICK atom_get_now() {
#if defined(ATOM_SYSTEM_OS_WINDOWS)
	return GetTickCount();
#else
	return (ATOM_TICK)0;
#endif
}

void atom_clear_console() {
	std::system("CLS");
}

void atom_application_init() {
	std::cout << "init atom application!" << std::endl;
	atom_dom_init();
}

void atom_application_uninit() {
	atom_dom_uninit();
}

ATOM_ELEMENT_REFERENCE atom_get_document_head() {
	return 0;
}

ATOM_ELEMENT_REFERENCE atom_get_document_body() {
	return 0;
}

ATOM_ELEMENT_REFERENCE atom_create_element(const char* type, const char* Namespace) {
	return 0;
}

bool atom_element_exists(ATOM_ELEMENT_REFERENCE element) {
	return false;
}

void atom_destroy_element(ATOM_ELEMENT_REFERENCE element) {

}

void atom_free_element(ATOM_ELEMENT_REFERENCE element) {

}

bool atom_is_same_element(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target) {
	return false;
}

void atom_set_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute, const char* value) {

}

char* atom_get_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute) {
	return NULL;
}

bool atom_has_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute) {
	return false;
}

void atom_remove_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute) {

}

void atom_toggle_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute) {

}

void atom_set_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value) {

}

char* atom_get_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName) {
	return NULL;
}

void atom_element_append_child(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target) {

}

void atom_set_element_style(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value) {

}

char* atom_get_element_style(ATOM_ELEMENT_REFERENCE element, const char* propertyName) {
	return NULL;
}

void atom_add_element_class(ATOM_ELEMENT_REFERENCE element, const char* className) {

}

bool atom_element_class_exists(ATOM_ELEMENT_REFERENCE element, const char* className) {
	return false;
}

void atom_remove_element_class(ATOM_ELEMENT_REFERENCE element, const char* className) {

}

char* atom_get_element_node_name(ATOM_ELEMENT_REFERENCE element) {
	return NULL;
}

ATOM_ELEMENT_REFERENCE atom_get_element_parent(ATOM_ELEMENT_REFERENCE element) {
	return 0;
}

Auint32 atom_get_element_child_count(ATOM_ELEMENT_REFERENCE element) {
	return 0;
}

void atom_scroll_to_element(ATOM_ELEMENT_REFERENCE element, const char* viewType) {

}

ATOM_ANIMATION_FRAME atom_request_animation_frame(ATOM_ANIMATION_FRAME_HANDLER handler, ATOM_POINTER value) {
	return 0;
}

bool atom_exists_animation_frame(ATOM_ANIMATION_FRAME id) {
	return false;
}

void atom_cancel_animation_frame(ATOM_ANIMATION_FRAME id) {

}

ATOM_ANIMATION_FRAME_HANDLER atom_get_animation_frame_handler(ATOM_ANIMATION_FRAME id) {
	return NULL;
}

double atom_mod_number(double a, double b) {
	return std::fmod(a, b);
}

ATOM_TIMER_REFERENCE atom_set_timeout(ATOM_TIMER_HANDLE func, Auint32 ms, ATOM_POINTER arg) {
	return 0;
}

void atom_clear_timeout(ATOM_TIMER_REFERENCE timer) {

}

ATOM_TIMER_REFERENCE atom_set_interval(ATOM_TIMER_HANDLE func, Auint32 ms, ATOM_POINTER arg) {
	return 0;
}

void atom_clear_interval(ATOM_TIMER_REFERENCE timer) {

}

float atom_get_pixel_ratio() {
	return 0.0f;
}

ATOM_ELEMENT_REFERENCE atom_create_render_target(Auint32 width, Auint32 height, float ratio, bool alpha, const char* colorSpace, bool desynchronized, bool willReadFrequently) {
	return 0;
}

ATOM_ELEMENT_REFERENCE atom_create_path2D() {
	return 0;
}

bool atom_is_element_render_target(ATOM_ELEMENT_REFERENCE element) {
	return false;
}

ATOM_ELEMENT_REFERENCE atom_get_render_target_canvas(ATOM_ELEMENT_REFERENCE element) {
	return 0;
}

float atom_get_render_target_ratio(ATOM_ELEMENT_REFERENCE element) {
	return 0.0f;
}

void atom_resize_render_target(ATOM_ELEMENT_REFERENCE element, Auint32 width, Auint32 height, float ratio) {

}

Auint32 atom_get_render_target_width(ATOM_ELEMENT_REFERENCE element) {
	return 0;
}

Auint32 atom_get_render_target_height(ATOM_ELEMENT_REFERENCE element) {
	return 0;
}

Auint32 atom_get_render_target_real_width(ATOM_ELEMENT_REFERENCE element) {
	return 0;
}

Auint32 atom_get_render_target_real_height(ATOM_ELEMENT_REFERENCE element) {
	return 0;
}

ATOM_RT_PIXEL* atom_get_render_target_pixels(ATOM_ELEMENT_REFERENCE element, Auint32 x, Auint32 y, Auint32 width, Auint32 height, Auint32* size) {
	return NULL;
}

void atom_set_render_target_pixels(ATOM_ELEMENT_REFERENCE element, ATOM_RT_PIXEL* pixels, Auint32 x, Auint32 y, Auint32 width, Auint32 height, Aint32 dirtyX, Aint32 dirtyY, Aint32 dirtyWidth, Aint32 dirtyHeight) {

}

void atom_set_render_target(ATOM_ELEMENT_REFERENCE element) {

}

ATOM_ELEMENT_REFERENCE atom_get_selected_render_target() {
	return 0;
}

void atom_set_render_target_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value) {

}

char* atom_get_render_target_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName) {
	return NULL;
}

void atom_rt_set_direction(const char* direction) {

}

char* atom_rt_get_direction() {
	return NULL;
}

void atom_rt_set_fill_style(const char* style) {

}

char* atom_rt_get_fill_style() {
	return NULL;
}

void atom_rt_set_filter(const char* style) {

}

char* atom_rt_get_filter() {
	return NULL;
}

void atom_rt_set_font(const char* style) {

}

char* atom_rt_get_font() {
	return NULL;
}

void atom_rt_set_font_kerning(const char* style) {

}

char* atom_rt_get_font_kerning() {
	return NULL;
}

void atom_rt_set_global_alpha(float alpha) {

}

float atom_rt_get_global_alpha() {
	return 0.0f;
}

void atom_rt_set_global_composite_operation(const char* op) {

}

char* atom_rt_get_global_composite_operation() {
	return NULL;
}

void atom_rt_set_image_smoothing_enabled(bool state) {

}

bool  atom_rt_is_image_smoothing_enabled() {
	return false;
}

void atom_rt_set_image_smoothing_quality(const char* quality) {

}

char* atom_rt_get_image_smoothing_quality() {
	return NULL;
}

void atom_rt_set_letter_spacing(const char* style) {

}

char* atom_rt_get_letter_spacing() {
	return NULL;
}

void atom_rt_set_line_cap(const char* style) {

}

char* atom_rt_get_line_cap() {
	return NULL;
}

void atom_rt_set_line_dash_offset(float offset) {

}

float atom_rt_get_line_dash_offset() {
	return 0.0f;
}

void atom_rt_set_line_join(const char* style) {

}

char* atom_rt_get_line_join() {
	return NULL;
}

void atom_rt_set_line_width(float width) {

}

float atom_rt_get_line_width() {
	return 0.0f;
}

void atom_rt_set_miter_limit(float limit) {

}

float atom_rt_get_miter_limit() {
	return 0.0f;
}

void atom_rt_set_shadow_blur(float level) {

}

float atom_rt_get_shadow_blur() {
	return 0.0f;
}

void atom_rt_set_shadow_color(const char* style) {

}

char* atom_rt_get_shadow_color() {
	return NULL;
}

void atom_rt_set_shadow_offset(float x, float y) {

}

float atom_rt_get_shadow_offset_x() {
	return 0.0f;
}

float atom_rt_get_shadow_offset_y() {
	return 0.0f;
}

void atom_rt_set_stroke_style(const char* style) {

}

char* atom_rt_get_stroke_style() {
	return NULL;
}

void atom_rt_set_text_align(const char* style) {

}

char* atom_rt_get_text_align() {
	return NULL;
}

void atom_rt_set_text_baseline(const char* style) {

}

char* atom_rt_get_text_baseline() {
	return NULL;
}

void atom_rt_set_text_rendering(const char* style) {

}

char* atom_rt_get_text_rendering() {
	return NULL;
}

void atom_rt_set_word_spacing(const char* style) {

}

char* atom_rt_get_word_spacing() {
	return NULL;
}

void atom_rt_arc(float x, float y, float radius, float startAngle, float endAngle, bool clockwise) {

}

void atom_rt_arc_to(float x1, float y1, float x2, float y2, float radius) {

}

void atom_rt_begin_path() {

}

void atom_rt_bezier_curve_to(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) {

}

void atom_rt_clear_rect(float x, float y, float width, float height) {

}

void atom_rt_clip(ATOM_ELEMENT_REFERENCE path, const char* fillRule) {

}

void atom_rt_close_path() {

}

void atom_rt_draw_focus_if_needed(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE path) {

}

void atom_rt_draw_image(float x, float y, float width, float height, ATOM_ELEMENT_REFERENCE image) {

}

void atom_rt_draw_image_section(float x, float y, float width, float height, float dx, float dy, float dWidth, float dHeight, ATOM_ELEMENT_REFERENCE image) {

}

void atom_rt_ellipse(float x, float y, float radiusX, float radiusY, float rotation, float startAngle, float endAngle, bool clockwise) {

}

void atom_rt_fill(ATOM_ELEMENT_REFERENCE path, const char* fillRule) {

}

void atom_rt_fill_rect(float x, float y, float width, float height) {

}

void atom_rt_fill_text(const char* text, float x, float y, float maxWidth) {

}

int* atom_rt_get_line_dash(Auint32* length) {
	return NULL;
}

bool atom_rt_is_context_lost() {
	return false;
}

bool atom_rt_is_point_in_path(float x, float y, ATOM_ELEMENT_REFERENCE path, const char* fillRule) {
	return false;
}

bool atom_rt_is_point_in_stroke(float x, float y, ATOM_ELEMENT_REFERENCE path) {
	return false;
}

void atom_rt_line_to(float x, float y) {

}

void atom_rt_move_to(float x, float y) {

}

void atom_rt_quadratic_curve_to(float cpx, float cpy, float x, float y) {

}

void atom_rt_rect(float x, float y, float width, float height) {

}

void atom_rt_reset() {

}

void atom_rt_reset_transform() {

}

void atom_rt_restore() {

}

void atom_rt_rotate(float angle) {

}

void atom_rt_round_rect(float x, float y, float width, float height, float* radii, Auint32 size) {

}

void atom_rt_save() {

}

void atom_rt_scale(float x, float y) {

}

void atom_rt_scroll_path_into_view(ATOM_ELEMENT_REFERENCE path) {

}

void atom_rt_set_line_dash(Aint32* dash, Auint32 size) {

}

void atom_rt_stroke(ATOM_ELEMENT_REFERENCE path) {

}

void atom_rt_stroke_rect(float x, float y, float width, float height) {

}

void atom_rt_stroke_text(const char* text, float x, float y, float maxWidth) {

}

void atom_rt_translate(float x, float y) {

}

ATOM_ELEMENT_REFERENCE atom_query_selector(ATOM_ELEMENT_REFERENCE element, const char* query) {
	return 0;
}

ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all(ATOM_ELEMENT_REFERENCE element, const char* query, Auint32* size) {
	return NULL;
}

void atom_free_element_list(ATOM_ELEMENT_REFERENCE_LIST list, Auint32 size) {

}

char* atom_generage_random_key(const Aint32& count) {
	return NULL;
}

ATOM_BOUNDING_BOX atom_get_element_bounding_box(ATOM_ELEMENT_REFERENCE element) {
	ATOM_BOUNDING_BOX box = {0};

	return box;
}

void atom_add_event_listener(ATOM_ELEMENT_REFERENCE element, const char* eventName, ATOM_EVENT_HANDLER handler) {

}

ATOM_RT_ATTRIBUTES* atom_get_render_target_attributes(ATOM_ELEMENT_REFERENCE element) {
	return NULL;
}

ATOM_TEXT_METRICS atom_rt_measure_text(const char* text) {
	ATOM_TEXT_METRICS meterics;

	return meterics;
}

ATOM_MATRIX_4* atom_rt_get_transform() {
	return NULL;
}

void atom_rt_set_transform(ATOM_MATRIX_4* matrix) {

}

void atom_exit(int status, bool pthread) {

}

ATOM_C_ENV_CLOSE

#endif